class RandomizedSet {
private:
    std::unordered_map<int, int> mymap;
    std::vector<int> list;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mymap.count(val)!= 0) return false;
        mymap[val] = list.size(); 
        list.push_back(val); 
        return true;
    }
    
    bool remove(int val) {
        if(mymap.count(val)!=0)
        {
            int index = mymap[val]; 
            int lastvalue = list.back();   
            list[index] = lastvalue; 
            list.pop_back();
            mymap[lastvalue] = index;
            mymap.erase(val);
            return true;
        }
        return false;
        
    }
    
    int getRandom() {
        int randomIndex = std::rand() % list.size();
        return list[randomIndex];
    }
};