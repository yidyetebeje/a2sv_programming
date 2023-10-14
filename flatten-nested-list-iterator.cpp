/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */


class NestedIterator {
public:
    vector<int> container;
    int i = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        buildInteger(nestedList);
        cout << container.size() << endl;
    }
    void buildInteger(vector<NestedInteger> &nestedList){
        for(auto& v: nestedList){
            if(v.isInteger()){
                container.push_back(v.getInteger());
            } else {
                buildInteger(v.getList());
            }
        }
    }
    
    int next() {
        return container[i++];
    }
    
    bool hasNext() {
       return i != container.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */