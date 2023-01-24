class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int sum = skill[0] + skill[skill.size() - 1];
       long long  chemistry = 0;
        int l = 0, r =  skill.size() - 1;
        while(l < r){
            if(skill[l] + skill[r] != sum){
                return -1;
            }
            chemistry += skill[l] * skill[r];
            l++;
            r--;
        }
        return chemistry;
    }
};