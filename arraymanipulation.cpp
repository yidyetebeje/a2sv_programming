long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> prefix(n + 1);
    for(auto v : queries){
        prefix[v[0] - 1] += v[2];
        prefix[v[1]] -= v[2];  
    }
    for(int i = 1; i < n; i++){
        prefix[i] += prefix[i - 1];
    }
    long mx = INT64_MIN;
    for(int i = 0; i < n; i++){
        if(mx < prefix[i]){
            mx = prefix[i];
        }
    }
    return mx;
}
