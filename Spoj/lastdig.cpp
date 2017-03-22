/*
 * Problem : http://www.spoj.com/problems/LASTDIG/
 * Solution : Simple application of cyclicity
 */
 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> c(10);
    c[0]=c[1]=c[5]=c[6]=1;
    c[2]=c[3]=c[7]=c[8]=4;
    c[4]=c[9]=2;
    while(t--){
        long long b,a;
        cin>>a>>b;
        if(b==0)
            cout<<'1'<<endl;
        else
        {
            int d=a%10;
            if(c[d]==1)
                cout<<d<<endl;
            else
            {
                int x,ans;
                x=b%c[d];
                if(x==0)
                    ans=pow(d,c[d]);                                      
                else
                    ans=pow(d,x);
                cout<<ans%10<<endl; 
            }
        }
    }
}
