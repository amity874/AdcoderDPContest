#include<bits/stdc++.h>
int main(int argc, char const *argv[]){
    int n;
    std::cin>>n;
    std::vector<int>height(n,0);
    for(int i=0;i<n;i++){
        std::cin>>height[i];
    }
    std::vector<int>dp(n,INT_MAX);
    dp[0]=0;
    dp[1]=std::abs(height[0]-height[1]);
    for(int i=2;i<n;i++){
        dp[i]=std::min(dp[i-1]+(std::abs(height[i-1]-height[i])),dp[i-2]+(std::abs(height[i-2]-height[i])));
    }
    std::cout<<dp[n-1];
return 0;
}