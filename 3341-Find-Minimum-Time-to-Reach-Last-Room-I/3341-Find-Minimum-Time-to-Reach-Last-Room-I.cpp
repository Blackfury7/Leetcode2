class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n=moveTime.size();
            int m=moveTime[0].size();
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
            q.push({0,{0,0}});
            vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
            while(!q.empty()){
                auto node=q.top();
                q.pop();
                int i=node.second.first;
                int j=node.second.second;
                int tim=node.first;
                if(dis[i][j]>tim){
                    dis[i][j]=tim;
                    if(i+1<n){q.push({max(tim+1,moveTime[i+1][j]+1),{i+1,j}});}
                    if(j+1<m){ q.push({max(tim+1,moveTime[i][j+1]+1),{i,j+1}});}
                    if(i>0){ q.push({max(tim+1,moveTime[i-1][j]+1),{i-1,j}});}
                    if(j>0){ q.push({max(tim+1,moveTime[i][j-1]+1),{i,j-1}});}
                    }
            }
            return dis[n-1][m-1];
        }
    };