class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n);
        for (int i=0; i<n; i++)
            for (auto c: words[i])
                masks[i] |= (1 << (c - 'a'));
        
        int largest = 0;
        for (int i=0; i<n-1; i++) 
            for (int j=i+1; j<n; j++) 
                if ((masks[i] & masks[j]) == 0) {
                    int product =  words[i].size() * words[j].size();
                    largest = max(largest,product);
                }
					
        
        return largest;

    }
};