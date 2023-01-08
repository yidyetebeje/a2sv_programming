class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string str ="";
        int len = s.size() + spaces.size();
        str.reserve(len + 1);
        int k = 0;
        int j = 0;
        for(int i = 0; i < len; i++){
            if(k < spaces.size() && spaces[k]  == j){
                str += ' ';
                k++;
            } else if(j < s.size()){
                str += s[j];
                j++;
            }
        }
        return str;
    }
};