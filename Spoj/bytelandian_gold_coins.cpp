/*
 * Problem : http://www.spoj.com/problems/COINS/
 * Simple DP Problem. Only trick is how to handle large n
 * Since recusrion is bounded, map can be used
 */
 
 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<ll,ll> dp;
ll look_up(ll x)
{
    unordered_map<ll,ll>::iterator it=dp.find(x);
    if(it==dp.end()){
        return -1;
    }
    else
        return it->second;
}


ll max_change(ll n)
{
    if(n<=4)
        return n;
    else if(look_up(n)!=-1)
        return look_up(n);
    else
    {
        ll max_for_current_n;
        max_for_current_n= max((max_change(floor(n/2))+max_change(floor(n/3))+max_change(floor(n/4))),n);
        dp[n]=max_for_current_n;
        return dp[n];
    }
}

int main(){
    ll  n;
    while(cin>>n){
        cout<<max_change(n)<<endl;
        
    }
}
