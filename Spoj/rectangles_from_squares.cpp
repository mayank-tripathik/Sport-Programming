/*
 * Problem : http://www.spoj.com/problems/AE00/
 * Solution: Simple pattern
 */

#include<iostream>
using namespace std;

int main(){
    int n,incr,i=2;
    cin>>n;
    int rec=n;
    incr=0;
    do
    {
        rec=rec+incr;
        incr=(n/i)-(i-1);
        i++;
    }while(incr>0);
    cout<<rec<<endl;
}
