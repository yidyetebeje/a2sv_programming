class LockingTree {
public:
  unordered_map<int,int>islocked;
    unordered_map<int,set<int>>lockedchild;
    vector<int>node;
    LockingTree(vector<int>& parent)
    {
        node=parent;
    }
    
    bool lock(int num, int user) 
    {
        if(islocked.find(num)!=islocked.end())return 0;
        islocked[num]=user;
        int i=node[num];
        while(i!=-1)
        {
            lockedchild[i].insert(num);
            i=node[i];
        }
        return 1;
    }
    
    bool unlock(int num, int user)
    {
        if(islocked.find(num)==islocked.end()||islocked[num]!=user)return 0;
        islocked.erase(num);
        int i=num;
        while(i!=-1)
        {
            i=node[i];
            lockedchild[i].erase(num);
        }
        return 1;
    }
    void unlocked(int num)
    {
        islocked.erase(num);
        int i=num;
        while(i!=-1)
        {
            i=node[i];
            lockedchild[i].erase(num);
        }
    }
    bool upgrade(int num, int user)
    {
        if(islocked.find(num)!=islocked.end())return 0;
        int i=node[num];
        while(i!=-1)
        {
            if(islocked.find(i)!=islocked.end())return 0;
            i=node[i];
        }
        if(lockedchild[num].size()==0)
        {
            return 0;
        }
        for(auto it:lockedchild[num])
        {
            unlocked(it);
        }
        return lock(num,user);
    }
};