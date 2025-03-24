//https://atcoder.jp/contests/dp/tasks/dp_g
#include<bits/stdc++.h>
using namespace std;
vector<int>dp(2e5+1,-1);
int dfs(int i,unordered_map<int,list<int>>&adj){
    if(adj[i].empty()){
      return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int ans=0;
    for(auto nbr:adj[i]){
        ans=max(ans,1+dfs(nbr,adj));
    }
    return dp[i]=ans;
}
int main(){
int n,m;
cin>>n>>m;
unordered_map<int,list<int>>adj;
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
}
   int ans=0;
   for(int i=1;i<=n;i++){
        ans=max(ans,dfs(i,adj));
   }
   cout<<ans;
    return 0;
}