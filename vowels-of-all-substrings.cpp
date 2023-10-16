class Solution {
public:
    long long countVowels(string word) {
        set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        long long ans = 0;
        int n = word.size();
        for(int i = 0; i < n; i++){
            if(vowels.count(word[i])){
                ans += (long long)(i + 1) * (long long)(n - i);
            }
        }
        return ans;
    }
};