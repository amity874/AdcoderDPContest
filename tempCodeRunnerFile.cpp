#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define vvi		std::vector<std::vector<ll>>
vvi Multiply(vvi &a1,vvi &a2){
    int n=a1.size();
    vvi ans(n,std::vector<ll>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ans[i][j]=(ans[i][j]%mod+(a1[i][k]*a2[k][j])%mod)%mod;
            }
        }
    }
    return ans;
}
vvi power_(vvi &mat,ll exp){
    if(exp==1){
        return mat;
    }
    vvi ans1=power_(mat,exp/2);
    vvi res=Multiply(ans1,ans1);
    if(exp%2==0){
        return res;
    }
    else{
        return Multiply(mat,res);
    }
}
ll walk(vvi &adj,int n,int k){
    vvi ans=power_(adj,k);
    ll res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res=(res%mod+ans[i][j]%mod)%mod;
        }
    }
    return res;
}
int main(int argc, char const *argv[])
{
    ll n,k;
    std::cin>>n>>k;
    vvi adj(n,std::vector<ll>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            std::cin>>adj[i][j];
        }
    }
    std::cout<<walk(adj,n,k);
return 0;
}