#include<bits/stdc++.h>
#define ll long long int
#define inf             1e18
ll dp[405][405];
ll sum[405][405];
ll Slimes(std::vector<ll>&arr,int i,int j){
if(i==j){
    return 0;
}
if(dp[i][j]!=-1){
    return dp[i][j];
}
ll mincost=inf;
for(int k=i;k<=j-1;k++){
    mincost=std::min({mincost,Slimes(arr,i,k)+Slimes(arr,k+1,j)+sum[i][j]});
}
return dp[i][j]=mincost;
}
int main(int argc, char const *argv[])
{
ll n;
std::cin>>n;
std::vector<ll>arr(n+1,0);
for(int i=1;i<=n;i++){
    std::cin>>arr[i];
}
memset(dp,-1,sizeof(dp));
memset(sum,0,sizeof(sum));
for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j++){
        sum[i][j]=arr[j]+((i==j)?0:sum[i][j-1]);
    }
}
std::cout<<Slimes(arr,1,n);
return 0;
}