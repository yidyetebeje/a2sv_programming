class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> letter;
        int maxCount=0, l = 0, maxf = 0, r=0;
        while(r < s.size()){
            letter[s[r]]++;
            maxf = max(maxf, letter[s[r]]);
            while((r - l + 1) - maxf > k){
                letter[s[l]]--;
                l++;
            }
            maxCount = max(maxCount,r - l + 1);
            r++;
        }
        return maxCount;
    }
};