class Solution {
public:
    bool dfs(unordered_map<int, list<int>>& mp, int source,vector<bool>& visited, int destination){
        visited[source] = true;
        stack<int> st;
        st.push(source);
        if(destination == source) return true;
        while(!st.empty()){
            auto& v = mp[st.top()];
            visited[st.top()] = true;
            if(visited[destination] == true) return true;
            st.pop();
            for(auto x: v){
                if(visited[x] == false){
                    st.push(x);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, list<int>> mp;
        for(auto v: edges){
            mp[v[0]].push_back(v[1]);
            mp[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        return dfs(mp,source, visited,destination);
    }
};