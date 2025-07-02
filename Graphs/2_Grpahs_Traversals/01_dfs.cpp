//TC O(V+E)
#include<bits/stdc++.h>
using namespace std;
vector<list<int>>graph;
unordered_set<int>visited;
int v;
void add_edge(int src,int dest,bool bi_dir=true){
graph[src].push_back(dest);
if(bi_dir){
    graph[dest].push_back(src);
}
}
bool dfs(int curr,int end){
    if(curr==end){
        return true;
    }
    visited.insert(curr);
    for(int nbr:graph[curr]){
        if(!visited.count(nbr)){
          bool res=dfs(nbr,end);  
          if(res){return true;}
        }
    }
    return false;
}
bool anypath(int src,int dest){
    return dfs(src,dest);
}
int main(){
cin>>v;
graph.resize(v,list<int>());
int e;cin>>e;
while(e--){
    int s,d;cin>>s>>d;
    add_edge(s,d);
}
int x,y;cin>>x>>y;
cout<<anypath(x,y);
return 0;
}