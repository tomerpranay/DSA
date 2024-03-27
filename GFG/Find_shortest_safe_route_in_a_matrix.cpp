//User function Template for C++

class Solution
{
public:
    // bool chk(vector<vector<int>> &mat,int i,int j){
    //     if(mat[i][j]==0) return false;
    //     if(i>0 && mat[i-1][j]==0) return false;
    //     if( i<mat.size()-1 && mat[i+1][j]==0) return false;
    //     if(j>0 && mat[i][j-1]==0) return false;
    //     if(j<mat[0].size()-1 && mat[i][j+1]==0) return false;
        
    //     return true;
    // }
    // int sol(vector<vector<int>> &mat,int i,int j){
    //     if(i>=mat.size() || j>mat[0].size() || i<0) return 0;
    //     if(chk(mat,i,j)==false) return -1;
    //     int up=sol(mat,i-1,j);
    //     int down=sol(mat,i+1,j);
    //     int right=sol(mat,i,j+1);
    //     int ans=min(up,min(down,right));
    //     if(ans==-1) return -1;
    //     return 1+ans;
        
        
    // }
    // int findShortestPath(vector<vector<int>> &mat)
    // {
    //   int ans=INT_MAX;
    //   for(int i=0;i<mat.size();i++){
    //       if(chk(mat,i,0)==false) continue;
    //       ans=min(ans,sol(mat,i,1));
           
    //   }
    //   return ans;
     int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int findShortestPath(vector<vector<int>> &mat){
        int ans = 0;
        int m = mat.size(), n = mat[0].size();
        
        vector<pair<int, int>> bombs;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(mat[i][j] == 0) 
                    bombs.push_back({i, j}); 
                    
        for(auto itr : bombs){
            for(int d = 0; d < 4; ++d){
                int x = itr.first + dx[d];
                int y = itr.second + dy[d];
                if(x >= 0 && y >= 0 && x < m && y < n)
                    mat[x][y] = 0;
            }
        }
        
        queue<pair<int,int>> q;
        for(int i = 0; i < m; ++i) 
            if(mat[i][0]){ 
                mat[i][0] = 0;
                q.push({i, 0});
            }
        
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                auto f = q.front();
                q.pop();
                
                if(f.second == n-1) 
                    return ans;
                    
                for(int d = 0; d < 4; ++d){
                    int x = f.first + dx[d];
                    int y = f.second + dy[d];
                    if(x >= 0 && y >= 0 && x < m && y < n && mat[x][y]){
                        mat[x][y] = 0;
                        q.push({x,y});
                    }
                }
            }
        }
        
        return -1;
    
    }
};