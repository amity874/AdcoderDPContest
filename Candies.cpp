#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
ll dp[105][100005];
ll Candies(std::vector<ll>&arr,ll n,ll k){
    for(int j=0;j<=k;j++){
        dp[1][j]=(j>arr[1])?0:1;
    }
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            if(j==0){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = (mod + dp[i][j - 1] % mod + dp[i - 1][j] % mod - ((j - arr[i] - 1 >= 0) ? dp[i - 1][j - arr[i] - 1] % mod : 0)) % mod;
            }
        }
    }
    return dp[n][k];
}
int main(int argc, char const *argv[])
{
    ll n,k;
    std::cin>>n>>k;
    memset(dp,0,sizeof(dp));
    std::vector<ll>arr(n+1,0);
    for(int i=1;i<=n;i++){
        std::cin>>arr[i];
    }
    std::cout<<Candies(arr,n,k);
return 0;
}