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
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto el:graph[i]){
            cout<<el<<",";
        }
        cout<<"\n";
    }
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
display();
return 0;
}