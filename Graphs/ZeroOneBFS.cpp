#include<bits/stdc++.h>
using namespace std;
int main(){
int n,m;cin>>n>>m;
vector<vector<pair<int,int>>>edges(m);
for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edges[u].push_back({v,w});
    edges[v].push_back({u,w});
}
vector<int>dist(n,INT_MAX);
deque<int>dq;
dq.push_front(0);
dist[0]=0;
while(!dq.empty()){
    int node=dq.front();
    dq.pop_front();
    for(auto it : edges[node]){
        int edgewt=it.second;
        if(dist[it.first]>dist[node]+edgewt){
            dist[it.first]=dist[node]+edgewt;
            if(edgewt==0){
                dq.push_front(it.first);
            }
            else{
                dq.push_back(it.first);
            }
        }
    }
}
for(auto it:dist){
    cout<<it<<" ";
}
return 0;
}