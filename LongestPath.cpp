#include<bits/stdc++.h>
std::vector<int>graph[100005];
std::vector<int>dp(100005,-1);
int findLongest(int src){
    if(dp[src]!=-1){
        return dp[src];
    }
    int result=INT_MIN;
    int noneighbour=true;
   for(auto i:graph[src]){
       noneighbour=false;
       result=std::max(result,findLongest(i));
   }
   return dp[src]=noneighbour?0:1+result;
}
int main(int argc, char const *argv[])
{
    int n,m;
    std::cin>>n>>m;
    while (m--){
        int x,y;
        std::cin>>x>>y;
        graph[x].push_back(y);
    }
    int result=INT_MIN;
    for(int i=1;i<=n;i++){
        result=std::max(result,findLongest(i));
    }
    std::cout<<result;
    
return 0;
}