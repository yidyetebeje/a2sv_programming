vector<int> countingSort(vector<int> arr) {
   int max = *max_element(arr.begin(), arr.end());
    vector<int> count(100);
    for(int i = 0; i < arr.size(); i++){
        count[arr[i]]++;
    }
    return count;
}
