class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int j = 0;
        int i;
        for(i = 0; i < players.size(); i++){
            while(j < trainers.size() && trainers[j] < players[i]){
                j++;
            }
            if(j >= trainers.size()) break;
            j++;
        }
        return i;
    }
};