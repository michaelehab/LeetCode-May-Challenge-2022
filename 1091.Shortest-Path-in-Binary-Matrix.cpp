class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n - 1][n - 1]) return -1;
        
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        vector<vector<int>> directions = {{1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, -1}, {-1, 1}};
        grid[0][0] = 1;
        while(!q.empty()){
            auto curr = q.front();
            int x = curr.first, y = curr.second;
            if(x == n - 1 && y == n - 1) return grid[x][y];

            for(auto d : directions){
                int dx = x + d[0];
                int dy = y + d[1];
                if(dx >= 0 && dx < n && dy >= 0 && dy < n && grid[dx][dy] == 0){
                    q.push({dx, dy});
                    grid[dx][dy] = grid[x][y] + 1;
                }
            }
            q.pop();
        }
        return -1;
    }
};