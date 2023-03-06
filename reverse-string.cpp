class Solution {
public:
    void reverse(vector<char>& s, int l, int r){
        if(l >= r) return;
        swap(s[r], s[l]);
        l++, r--;
        reverse(s,l,r);
    }
    void reverseString(vector<char>& s) {
        int len = s.size();
        int l = 0, r = len - 1;
       reverse(s,l,r);
    }
};