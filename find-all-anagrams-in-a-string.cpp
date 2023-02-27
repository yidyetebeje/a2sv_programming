class Solution {
public:
    vector<int> findAnagrams(string s, string p)
{
   vector<int> vi;
   unordered_map<char, int> ns;
   unordered_map<char, int> np;
   int n = p.size();
   for(int i = 0; i < n; i++){
       ns[s[i]]++;
       np[p[i]]++;
   }
   int l = 0, r = n;
    while(r < s.size()){
        if(ns  == np){
            vi.push_back(l);
        }
        ns[s[l]]--;
        ns[s[r]]++;
        if(ns[s[l]] == 0){
            ns.erase(s[l]);
        }
        l++;
        r++;
    }
    if(ns == np){
        vi.push_back(l);
    }
    return vi;
}
};