class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int INF = 2147483647;

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ;j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == INF){
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
