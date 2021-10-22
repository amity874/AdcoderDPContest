#include<bits/stdc++.h>
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    int a1,b1,c1;
    std::cin>>a1>>b1>>c1;
    std::vector<std::vector<int>>dp(3,std::vector<int>(n,0));
    //Base cases
    dp[0][0]=a1;
    dp[1][0]=b1;
    dp[2][0]=c1;
    for(int i=1;i<n;i++){
        std::cin>>a1>>b1>>c1;
        dp[0][i]=a1+std::max(dp[1][i-1],dp[2][i-1]);
        dp[1][i]=b1+std::max(dp[0][i-1],dp[2][i-1]);
        dp[2][i]=c1+std::max(dp[1][i-1],dp[0][i-1]);
    }
    std::cout<<std::max({dp[0][n-1],dp[1][n-1],dp[2][n-1]});
return 0;
}