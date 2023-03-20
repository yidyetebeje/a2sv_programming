class DataStream {
    unordered_map<int, int> m1;
    int val, size;
public:
    DataStream(int value, int k) {
        val = value, size = k;
        m1[value] = k;
    }
    
    bool consec(int num) {
        if(num==val)    m1[val]--;
        else            m1[val] = size;
        return m1[val]<=0;
    }
};