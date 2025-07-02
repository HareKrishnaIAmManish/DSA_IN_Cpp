#include<bits/stdc++.h>
using namespace std;
vector<list<int>>graph;
unordered_set<int>visited;
vector<vector<int>>res;
int v;
void add_edge(int src,int dest,bool bi_dir=true){
graph[src].push_back(dest);
if(bi_dir){
    graph[dest].push_back(src);
}
}
void dfs(int curr,int end,vector<int>&path){
    if(curr==end){
        path.push_back(curr);
        res.push_back(path);
        path.pop_back();
        return;
    }
    visited.insert(curr);
    path.push_back(curr);
    for(int nbr:graph[curr]){
        if(!visited.count(nbr)){
          dfs(nbr,end,path);  
        }

    }
    path.pop_back();
    visited.erase(curr);
    return;
}
void allpath(int src,int dest){
    vector<int>path;
    return dfs(src,dest,path);
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
allpath(x,y);
for(auto it:res){
    for(int el:it){
        cout<<el<<" ";
    }
    cout<<"\n";
}
return 0;
}