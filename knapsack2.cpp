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
std::vector<ll>dp1(n*1000+1,INT_MAX);
std::vector<ll>dp2(n*1000+1,INT_MAX);
dp1[0]=0;
dp1[val[0]]=wt[0];
for(int i=1;i<n;i++){
    for(int j=0;j<=n*1000;j++){
        if(val[i]>j){
            dp2[j]=dp1[j];
        }
        else{
            dp2[j]=std::min({dp2[j],dp1[j],(dp1[j-val[i]])+wt[i]});
        }
    }
    dp2.swap(dp1);
    dp2.clear();
}
ll res=0;
for(int i=0;i<=n*1000;i++){
    if(dp1[i]<=w){
        res=i;
    }
}
std::cout<<res;
return 0;
}