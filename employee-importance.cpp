/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    void dfs(unordered_map<int, Employee*>& employees, int source, int& res){
        auto v = employees[source]->subordinates;
        res += employees[source]->importance;
        for(auto x: v){
            dfs(employees, x, res);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> emp;
        for(auto v: employees){
            emp[v->id] = v;
        }
        int r = 0;
        dfs(emp, id, r);
        return r;
    }
};