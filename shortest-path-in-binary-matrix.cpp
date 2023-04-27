class Solution {
public:
    vector<pair<int,int>> directions {make_pair(0,1),
    make_pair(1,0), make_pair(0,-1), make_pair(-1, 0),
    make_pair(1,1),make_pair(-1,-1), make_pair(1,-1), make_pair(-1, 1)
    };
    bool inbound(pair<int, int> p, int row, int col){
        return ((p.first >= 0 && p.first < row) && (p.second >= 0 && p.second < col));
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        deque<pair<int,int>> dq;
        dq.push_back(make_pair(0,0));
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
        if(grid[0][0] == 1) return -1;
        int count = 0;
        while(!dq.empty()){
            int sz = dq.size();
            while(sz--){
                auto p = dq.front();
                dq.pop_front();
                cout << p.first << " " << p.second << endl;
                if(p.first == grid.size() - 1 && p.second == grid[0].size() - 1) return count + 1;
                for(auto dr: directions){
                    auto newCor = make_pair(p.first + dr.first, p.second + dr.second);
                    if(inbound(newCor,  grid.size(), grid[0].size()) && !visited[newCor.first][newCor.second] &&
                    grid[newCor.first][newCor.second] == 0){
                        visited[newCor.first][newCor.second] = true;
                        dq.push_back(newCor);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};