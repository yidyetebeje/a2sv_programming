class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max = 0, maxIndex = 0;
        int skip = 0;
        int j = 0;
        while(j < arr.size()- 1){
            max = arr[skip + 1];
            for(int i = skip + 1; i < arr.size(); i++){
                if(max <= arr[i]){
                    maxIndex = i;
                    max = arr[i];
                }
            }
            for(int i = skip; i <= maxIndex; i++){
                arr[i] = max;
            }
            skip = maxIndex;
            j = maxIndex;
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};