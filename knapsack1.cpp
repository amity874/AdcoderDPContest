#include<bits/stdc++.h>
#define ll long long int
int main(int argc, char const *argv[])
{
ll n,w;
std::cin>>n>>w;
std::vector<ll>wt(n,0);
std::vector<ll>val(n,0);
for(int i=0;i<n;i++){
    std::cin>>wt[i];
    std::cin>>val[i];
}
std::vector<ll>dp1(w+1,0);
std::vector<ll>dp2(w+1,0);
for(int i=0;i<n;i++){
    for(int j=1;j<=w;j++){
        if(wt[i]>j){
            dp2[j]=dp1[j];
        }
        else{
            dp2[j]=std::max({dp2[j],dp1[j],dp1[j-wt[i]]+val[i]});
        }
    }
    dp2.swap(dp1);
    dp2.clear();
}
std::cout<<dp1[w];
return 0;
}