class Solution {
public:
    bool isBoundary(int row, int col, pair<int,int> pos){
        return ((pos.first == 0) || (pos.first ==  row - 1) || (pos.second == 0) || (pos.second == col -  1));
    }
    bool isEnclosed(int row, int col , pair<int,int> pos){
        return (pos.first >= 0 && pos.first < row && pos.second >= 0 && pos.second < col);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        deque<pair<int,int>> q;
        int row = maze.size();
        int col = maze[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col));
        q.push_back({entrance[0], entrance[1]});
        vector<pair<int,int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            ans++;
            while(sz--){
                auto pos = q.front();
                q.pop_front();
                visited[pos.first][pos.second] = true;
                for(auto dr: dir){
                    int nx = pos.first + dr.first;
                    int ny = pos.second + dr.second;
                    if(isEnclosed(row, col, make_pair(nx, ny)) && !visited[nx][ny] && maze[nx][ny]== '.'){
                        q.push_back(make_pair(nx,ny));
                        visited[nx][ny] = true;
                        if(isBoundary(row, col,make_pair(nx, ny))){
                        return ans;
                    }
                    }
                }
            }
        }
        return -1;
    }
};