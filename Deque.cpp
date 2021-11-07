#include<bits/stdc++.h>
#define ll long long int

ll dp[3005][3005];
ll Deque(std::vector<ll> &arr,int i,int j){
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(i==j){
        return dp[i][j]=arr[i];
    }
    return dp[i][j]=std::max(arr[i]-Deque(arr,i+1,j),arr[j]-Deque(arr,i,j-1));
}
int main(int argc, char const *argv[])
{
    int n;
    std::cin>>n;
    memset(dp,-1,sizeof(dp));
   std::vector<ll> arr(n,0);
    for(int i=0;i<n;i++){
    std::cin>>arr[i];
    }
    std::cout<<Deque(arr,0,n-1);
return 0;
}