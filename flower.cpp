#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
struct flower{
ll h,a;
};
ll F(flower *arr,int n){
    std::vector<ll>dp(n+1,0);
    std::map<ll,ll> SortedFlower;
    SortedFlower[arr[1].h]=arr[1].a;
    dp[1]=arr[1].a;
    ll ans=dp[1];
    for(int i=2;i<=n;i++){
        dp[i]=arr[i].a;
        auto it=SortedFlower.lower_bound(arr[i].h+1);
        if(it!=SortedFlower.begin()){
            it--;
            dp[i]+=it->second;
        }
        SortedFlower[arr[i].h]=dp[i];
        it=SortedFlower.upper_bound(arr[i].h);
        while (it!=SortedFlower.end()&&it->second<=dp[i]){
            auto temp=it;
            temp++;
            SortedFlower.erase(it);
            it=temp;
        }
       ans=std::max(ans,dp[i]);          
    }
    return ans;
}
int main(int argc, char const *argv[]){
    ll n;
    std::cin>>n;
    flower arr[n+1];
    for(int i=1;i<=n;i++){
        std::cin>>arr[i].h;
    }
    for(int i=1;i<=n;i++){
        std::cin>>arr[i].a;
    }
    std::cout<<F(arr,n);
return 0;
}