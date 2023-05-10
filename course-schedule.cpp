class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjList;
        vector<int> inDegree(numCourses);
        for(auto node: prerequisites){
            adjList[node[0]].push_back(node[1]); 
            inDegree[node[1]]++;
        }
        vector<bool> visited(numCourses, false);
        deque<int> dq;
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) dq.push_back(i);
        }
        int count = 0;
        while(!dq.empty()){
            int x = dq.front();
            dq.pop_front();
            count++;
            visited[x] = true;
            for(auto node: adjList[x]){
                cout << node << endl;
                if(!visited[node]){
                    inDegree[node]--;
                    if(inDegree[node] == 0) dq.push_back(node);
                }
            }
        }
        if(count != numCourses) return false;
        return true;
    }
};