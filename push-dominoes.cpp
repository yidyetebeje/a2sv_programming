class Solution {
public:
    string pushDominoes(string& dominoes) {
        deque<pair<char,int>> dq;
        for (int i = 0; i < dominoes.size(); i++){
            if (dominoes[i] != '.'){
                dq.push_back({dominoes[i], i});
            }
        }
        while (!dq.empty()){
            auto pi = dq.front();
            dq.pop_front();
            if (pi.first == 'L' && pi.second > 0 && dominoes[pi.second - 1] == '.'){
                dq.push_back({'L', pi.second - 1});
                dominoes[pi.second - 1] = 'L';
            } 
            else if(pi.first == 'R'){
                if (pi.second + 1 < dominoes.size() && dominoes[pi.second+ 1] == '.'){
                    if (pi.second + 2 < dominoes.size() && dominoes[pi.second+ 2] == 'L'){
                        dq.pop_front();
                    }
                    else {
                        dq.push_back({'R', pi.second + 1});
                        dominoes[pi.second + 1] = 'R';
                    }
                }
            }
        }
        return dominoes;
    }
};