class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& arr) {
          vector<int> vi;
          for(int i = 0; i < arr.size(); i++){
              int count = 0;
              for(int j = 0; j < arr.size(); j++){
                  if(i == j) continue;
                  if(arr[i] > arr[j]) count++;
              }
                vi.push_back(count);
          }
         return vi;
    }
};