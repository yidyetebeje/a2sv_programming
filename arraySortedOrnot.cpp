class Solution {
  public:
    bool arraySortedOrNot(int arr[], int n) {
        // code here
        int l= 0, r = 1;
        while(r < n){
            if(arr[l] > arr[r]){
                return false;
            }
            r++;
            l++;
        }
        return true;
    }
};