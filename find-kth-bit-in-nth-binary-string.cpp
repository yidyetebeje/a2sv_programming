class Solution {
public:
    string invert(string s){
        for(auto& l: s){
            if(l == '0') l = '1';
            else l = '0';
        }
        return s;
    }
    string findNthString(int n){
        if(n == 1){
            return "0";
        }
        string prevString = findNthString(n - 1);
        string invertedString = invert(prevString);
        reverse(invertedString.begin(), invertedString.end());
        string curString = prevString + "1" + invertedString;
        return curString;
    }
    char findKthBit(int n, int k) {
        string s = findNthString(n);
        return s[k - 1];
    }
};