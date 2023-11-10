class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int p[101] = {0};
        
        for(int i = 0; i<logs.size(); i++){
            int l = logs[i][0] % 1950;
            int r = logs[i][1] % 1950;

            p[l]+=1;
            p[r]-=1;
        }
        
        int indx = 0;
        for(int i = 1; i<101; i++){
            p[i] = p[i-1] + p[i];
            if(p[i] > p[indx]){
                indx = i;
            }
        }
        return 1950+indx;
    }
};