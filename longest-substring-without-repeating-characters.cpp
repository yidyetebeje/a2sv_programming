class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int  size = 0;
    int maxSub = 0;
    string dict = "";
    int l = 0;
    for(int  i = 0; i < s.size(); i++){
        if(dict.find(s[i]) != string::npos){
            while (dict.find(s[i]) != string::npos)
            {
                dict.erase(dict.begin());
                size--;
            }
        }
        dict = dict + s[i];
        size++;
        maxSub = max(size, maxSub);
    }
    return maxSub;
}
        
};