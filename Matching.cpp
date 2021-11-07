#include<bits/stdc++.h>
#define mod     1000000007
#define ll long long int
ll dp[22][1<<22];
ll matching(std::vector<std::vector<int>>&compat,int i,int mask,int n){
if(i==n+1){
    if(mask==0){
        return 1;
    }
    return 0;
}
if(dp[i][mask]!=-1){
    return dp[i][mask];
}
ll ans=0;
for(int w=0;w<n;w++){
    bool isavailable=(((1<<w)&(mask))==0)?0:1;
    if(isavailable && compat[i][w+1]){
        ans=((ans%mod)+(matching(compat,i+1,mask^(1<<w),n)%mod))%mod;
    }
}
return dp[i][mask]=ans;
}
int main(int argc, char const *argv[])
{
    ll n;
    std::cin>>n;
    memset(dp,-1,sizeof(dp));
    std::vector<std::vector<int>>compat(n+1,std::vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            std::cin>>compat[i][j];
        }
    }
    std::cout<<matching(compat,1,((1<<n)-1),n);
return 0;
}