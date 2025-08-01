#include<bits/stdc++.h>
using namespace std;
vector<list<pair<int,int>>>graph;
int v;
void add_edges(int src,int dest,int wt,bool bi_dir=true){
   graph[src].push_back({dest,wt});
   if(bi_dir){
    graph[dest].push_back({src,wt});
   }
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto it:graph[i]){
            cout<<'{'<<it.first<<","<<it.second<<'}'<<",";
        }
        cout<<"\n";
    }
}
int main(){
cout<<"Enter number of vertices";
cin>>v;
graph.resize(v,list<pair<int,int>>());
cout<<"Enter number of edges";
int e;//number of edges
cin>>e;
while(e--){
    cout<<"Enter source and dest and wt";
    int s,d,wt;
    cin>>s>>d>>wt;
    add_edges(s,d,wt); //if you want directional pass false
}
display();
return 0;
}
