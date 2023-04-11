class Solution {
public:
    
    vector<pair<int,int>> directions {make_pair(0,1),make_pair(1,0), make_pair(0,-1), make_pair(-1, 0)};
    bool inbound(pair<int, int> p, int row, int col){
        return ((p.first >= 0 && p.first < row) && (p.second >= 0 && p.second < col));
    }
    void dfs(vector<vector<int>>& image, int color, int initial, pair<int,int> cor, vector<vector<int>>& visited){
        image[cor.first][cor.second] = color;
        for(auto d: directions){
            auto p = make_pair(cor.first + d.first, cor.second + d.second);
            if(inbound(p, image.size(), image[0].size()) && image[p.first][p.second] == initial && visited[p.first][p.second] == false){
                visited[p.first][p.second] = true;
               
                dfs(image, color,initial, p, visited);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size()));
        dfs(image, color,image[sr][sc],make_pair(sr,sc), visited);
        return image;
    }
};