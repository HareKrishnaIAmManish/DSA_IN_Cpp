class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>visiteda(m,vector<int>(n,0));
        vector<vector<int>>visitedb(m,vector<int>(n,0));
        vector<vector<int>>ansa(m,vector<int>(n,0));
        vector<vector<int>>ansb(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int j=0;j<n;j++){
            visiteda[0][j]=1;
            ansa[0][j]=1;
            q.push({0,j});
        }
        for(int i=0;i<m;i++){
            visiteda[i][0]=1;
            ansa[i][0]=1;
            q.push({i,0});
        }
        while(!q.empty()){
            auto topnode=q.front();
            q.pop();
            int x=topnode.first;
            int y=topnode.second;
            //up
            if(x-1>=0 and visiteda[x-1][y]==0 and (heights[x-1][y]>=heights[x][y])){
            visiteda[x-1][y]=1;
            ansa[x-1][y]=1;
            q.push({x-1,y});
            }
            //right
            if(y+1<n and visiteda[x][y+1]==0 and (heights[x][y+1]>=heights[x][y])){
            visiteda[x][y+1]=1;
            ansa[x][y+1]=1;
            q.push({x,y+1});
            }
            //left
            if(y-1>=0 and visiteda[x][y-1]==0 and (heights[x][y-1]>=heights[x][y])){
            visiteda[x][y-1]=1;
            ansa[x][y-1]=1;
            q.push({x,y-1});
            }
            //down
            if(x+1<m and visiteda[x+1][y]==0 and (heights[x+1][y]>=heights[x][y])){
            visiteda[x+1][y]=1;
            ansa[x+1][y]=1;
            q.push({x+1,y});
            }
        }//---
        for(int j=0;j<n;j++){
            visitedb[m-1][j]=1;
            ansb[m-1][j]=1;
            q.push({m-1,j});
        }
        for(int i=0;i<m;i++){
            visitedb[i][n-1]=1;
            ansb[i][n-1]=1;
            q.push({i,n-1});
        }
        while(!q.empty()){
            auto topnode=q.front();
            q.pop();
            int x=topnode.first;
            int y=topnode.second;
            //up
            if(x-1>=0 and visitedb[x-1][y]==0 and (heights[x-1][y]>=heights[x][y])){
            visitedb[x-1][y]=1;
            ansb[x-1][y]=1;
            q.push({x-1,y});
            }
            //right
            if(y+1<n and visitedb[x][y+1]==0 and (heights[x][y+1]>=heights[x][y])){
            visitedb[x][y+1]=1;
            ansb[x][y+1]=1;
            q.push({x,y+1});
            }
            //left
            if(y-1>=0 and visitedb[x][y-1]==0 and (heights[x][y-1]>=heights[x][y])){
            visitedb[x][y-1]=1;
            ansb[x][y-1]=1;
            q.push({x,y-1});
            }
            //down
            if(x+1<m and visitedb[x+1][y]==0 and (heights[x+1][y]>=heights[x][y])){
            visitedb[x+1][y]=1;
            ansb[x+1][y]=1;
            q.push({x+1,y});
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(ansa[i][j]==ansb[i][j] and ansa[i][j]==1){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};