/*
 * Problem : http://www.spoj.com/problems/BUGLIFE/
 */
 
#include<bits/stdc++.h>
using namespace std;
typedef list<int> G;

bool bfs(vector<G> &graph,vector<bool> &visited,int start){
    int nodes=graph.size()-1;
    queue<int> myqueue;
    char sex;
    bool not_suspicious=true;
    vector<char> gender(nodes+1,'n');
    myqueue.push(start);
    visited[start]=true;
    gender[start]='m';
    while(!myqueue.empty() && not_suspicious)
    {
        int u=myqueue.front();
        myqueue.pop();
        if(gender[u]=='m')
            sex='f';
        else
            sex='m';
        for(auto itr=graph[u].begin();itr!=graph[u].end();itr++)
        {
            int v=(*itr);
            if(!visited[v]){
                myqueue.push(v);
                gender[v]=sex;
                visited[v]=true;
            }
            else if(gender[v]==gender[u]){
                not_suspicious=false;
                break;
            }
            
        }
    }
    return not_suspicious;
}

int main(){
    int scenario,count=0;
    cin>>scenario;
    while(scenario--){
        count++;
        int bugs,interaction;
        bool not_suspicious;
        cin>>bugs>>interaction;
        vector<G> graph(bugs+1);
        vector<bool> visited(bugs+1,false);
        for(int i=1;i<=interaction;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        cout<<"Scenario #"<<count<<":"<<endl;
        for(int i=1;i<=bugs;i++){
            if(!visited[i])
                not_suspicious=bfs(graph,visited,i);
                if(!not_suspicious)
                    break;
        }
        if(not_suspicious)
            cout<<"No suspicious bugs found!\n";
        else
            cout<<"Suspicious bugs found!\n";
    }     
}

