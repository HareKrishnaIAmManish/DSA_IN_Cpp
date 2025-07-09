#include<bits/stdc++.h>
using namespace std;
vector<list<int>>graph;
int v;
void add_edges(int src,int dest,bool bi_dir=true){
   graph[src].push_back(dest);
   if(bi_dir){
    graph[dest].push_back(src);
   }
}
void dfs(int node,unordered_set<int>&visited){
    visited.insert(node);
    for(auto nbr:graph[node]){
        if(visited.count(nbr)==0){
            dfs(nbr,visited);
        }
    }
}
int connected_components(){
    int result=0;
    unordered_set<int>visited;
    for(int i=0;i<v;i++){
        if(!visited.count(i)){
            result++;
            dfs(i,visited);
        }
    }
    return result;
}
int main(){
cout<<"Enter number of vertices";
cin>>v;
graph.resize(v,list<int>());
cout<<"Enter number of edges";
int e;//number of edges
cin>>e;
while(e--){
    cout<<"Enter source and dest";
    int s,d;
    cin>>s>>d;
    add_edges(s,d); //if you want directional pass false
}
cout<<"connected components are "<<connected_components()<<endl;
return 0;
}