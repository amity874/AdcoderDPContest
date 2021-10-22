#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[])
{
    int n;
    int k;
    std::cin>>n>>k;
    std::vector<ll> height(n,0);
    std::vector<ll> dp(n,INT_MAX);
    for(int i=0;i<n;i++){
        std::cin>>height[i];
    }
    dp[0]=0;
    dp[1]=std::abs(height[0]-height[1]);
    for(int i=2;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i-j<0){
                break;
            }
            dp[i]=std::min(dp[i], dp[i - j] + abs(height[i] - height[i - j]));
        }
    }
    std::cout<<dp[n-1];
return 0;
}