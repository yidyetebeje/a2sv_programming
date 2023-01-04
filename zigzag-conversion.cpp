class Solution {
public:
    string convert(string s, int numRows) {
        bool down = true;
        int row = 0;
        if (numRows == 1){
            return s;
        }
        vector<string> zig(numRows, "");
        for(int i = 0; i < s.size(); i++){
            zig[row].push_back(s[i]);
            if (row == numRows-1) down = false;
            else if(row == 0) down = true;
            if(down) row++;
            else row--;
        }
        string p = "";
        for(int i = 0; i < zig.size();i++){
            p += zig[i];
        }
        return p;

    }
};