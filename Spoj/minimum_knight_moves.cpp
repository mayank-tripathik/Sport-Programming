/*
 * Problem : http://www.spoj.com/problems/NAKANJ/
 */

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

vector<P> knight_move_calculator(int i,int j){
    vector<P> pos;
    if(i+1<9){
        if(j-2>0)
            pos.push_back({i+1,j-2});
        if(j+2<9)
            pos.push_back({i+1,j+2});       
    }
    if(i+2<9){
        if(j-1>0)
            pos.push_back({i+2,j-1});
        if(j+1<9)
            pos.push_back({i+2,j+1});       
    }
    if(i-1>0){
        if(j-2>0)
            pos.push_back({i-1,j-2});
        if(j+2<9)
            pos.push_back({i-1,j+2});       
    }
    if(i-2>0){
        if(j-1>0)
            pos.push_back({i-2,j-1});
        if(j+1<9)
            pos.push_back({i-2,j+1});       
    }
    return pos;
}

P convert_string_into_cell_number(string str){
    P cell;
    cell.first=str[1]-'0';
    cell.second=str[0]-96;
    return cell;
    
}

void bfs(string st, string des)
{
    int chess[9][9];
    int moves=0;
    bool dest_found=false;
    P start=convert_string_into_cell_number(st);
    P dest=convert_string_into_cell_number(des);
    P parent[9][9];
    bool visited[9][9];
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            visited[i][j]=false;
    queue<P> myqueue;
    myqueue.push(start);
    visited[start.first][start.second]=true;
    parent[start.first][start.second]=start;
    while(!myqueue.empty() && !dest_found)
    {
        P u=myqueue.front();
        myqueue.pop();
        vector<P> possible_moves;
        possible_moves=knight_move_calculator(u.first,u.second);
        for(int i=0;i<possible_moves.size();i++){
            int cell_row=possible_moves[i].first;
            int cell_col=possible_moves[i].second;
            if (!visited[cell_row][cell_col]){
                if(cell_row==dest.first && cell_col==dest.second)
                {
                    dest_found=true;
                    parent[cell_row][cell_col]=u;
                    break;   
                }
                visited[cell_row][cell_col]=true;
                parent[cell_row][cell_col]=u;
                myqueue.push(possible_moves[i]);
            }
        }
        
    }
    P child;
    child=dest;
    while(1)
    {
        if(child.first==start.first && child.second==start.second)
            break;
        else
        {
            child=parent[child.first][child.second];
            moves++;
        }
            
    }
    cout<<moves<<endl;
    
}

int main(){
    int test;
    cin>>test;
    while(test--){
        string start,dest;
        cin>>start>>dest;
        bfs(start,dest);
    }
    
}
