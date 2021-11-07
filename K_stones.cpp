#include<bits/stdc++.h>
#define ll long long int
std::string KStones(std::vector<int>&arr,int k){
 std::vector<bool>dp(k+1,false);
 for(int i=1;i<=k;i++){
     for(auto el:arr){
         if(i<el){
             continue;
         }
             if(!dp[i-el]){
                 dp[i]=true;
             }
     }
 }
 return dp[k]?"First":"Second";
}
int main(int argc, char const *argv[])
{
    ll n;
    ll k;
    std::cin>>n>>k;
    std::vector<int>arr(n,0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::cout<<KStones(arr,k);
return 0;
}