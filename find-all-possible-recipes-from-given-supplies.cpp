class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> adjList;
        unordered_set<string> recipy(recipes.begin(), recipes.end());
        unordered_set<string> supply(supplies.begin(), supplies.end());
        unordered_map<string,int> inDegree;
        int i = 0;
        for(auto recipe: recipes){
            auto x = ingredients[i++];
            for(auto y: x){
                if(supply.count(y)) inDegree[y] = 0;
                inDegree[recipe]++;
                adjList[y].push_back(recipe);
            }
        }
        unordered_set<string> st;
        deque<string> dq;
        for(auto v: inDegree){
            if(v.second == 0) {
                dq.push_back(v.first);
            }
        }
        while(!dq.empty()){
            auto x = dq.front();
            dq.pop_front();
            if(recipy.count(x)){
                st.insert(x);
            }
            for(auto neigh: adjList[x]){
                if(recipy.count(neigh) || supply.count(neigh))
                    inDegree[neigh]--;
                if(inDegree[neigh] == 0) dq.push_back(neigh);
            }
        }
        vector<string> res(st.begin(), st.end());
        return res;
    }
};