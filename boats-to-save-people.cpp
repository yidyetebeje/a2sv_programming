class Solution {
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = 0;
        int l = 0, r = people.size() - 1;
        sort(people.begin(), people.end());
        while(l <= r){
            if(people[l] + people[r] <= limit)
                l++;
            r--;
            n++;
        }   
        return n;
    }
};