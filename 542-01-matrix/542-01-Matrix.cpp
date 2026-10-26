class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1) mat[i][j] = -1;
                else{
                    q.push({i,j});
                }
            }
        }

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = i + dr[k];
                int nc = j + dc[k];
                if(nc >= 0 && nr >= 0 && nc < n && nr < m && mat[nr][nc] == -1){
                    mat[nr][nc] = mat[i][j] + 1;
                    q.push({nr,nc});
                }
            }
        }

        return mat;
    }
};