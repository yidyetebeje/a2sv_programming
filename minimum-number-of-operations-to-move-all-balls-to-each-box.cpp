class Solution
{
public:
    vector<int> minOperations(string boxes) {
        vector<int> prefix(boxes.size());
        prefix[0] = (boxes[0] == '0' ? 0 : 1);
        for(int i = 1; i < boxes.size(); i++){
            prefix[i] = prefix[i -1] + (boxes[i] == '0' ? 0 : 1);
        }
        int operation = 0;
        vector<int> vb;
        vb.reserve(boxes.size());
        for(int i = 0; i < boxes.size(); i++){
            if(boxes[i] == '1'){
                operation += i;
            }     
        }
        vb.push_back(operation);
        for(int i = 1; i < boxes.size(); i++){
            int countBefore = prefix[i - 1];
            int countAfter = prefix[boxes.size() - 1] - prefix[i - 1];
            operation = operation + countBefore - countAfter ;
            vb.push_back(operation);
        }
            return vb;
    }
};