class Solution {
public:
    // union find in emails
    int find(int i,vector<int>&parent,int &deep,vector<int>&rank){
        if(i==parent[i]) return i;
        parent[i]=find(parent[i],parent,++deep,rank);
        rank[i]+=deep;
        return parent[i];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
              //  email name
        vector<pair<string,string>>v;
        for(auto &vec:accounts)
          for(int i=1;i<vec.size();i++)
		     v.push_back({vec[i],vec[0]});
             
        vector<int>parent(v.size());
        vector<int>rank(v.size(),1);
		
        for(int i=0;i<parent.size();i++) parent[i]=i;
        
        unordered_map<string,int>mp;
        vector<bool>vis(parent.size());
        
        int cnt=0,tp;
         // cnt  uniquely differentiate each email (for ex= first email key is 1 ,second has 2 and so on)
        for(auto &vec:accounts){
             int p;
             if(mp.count(v[cnt].first)==0) p=find(cnt,parent,tp=0,rank),mp[v[cnt].first]=cnt;
             else p=find(mp[v[cnt].first],parent,tp=0,rank),vis[cnt]=1;  // if already email comes we skip it by making it visited
             cnt++;
            
             for(int i=2;i<vec.size();i++,cnt++){
                 int t;
                 if(mp.count(v[cnt].first)==0) t=find(cnt,parent,tp=0,rank),mp[v[cnt].first]=cnt;
                 else t=find(mp[v[cnt].first],parent,tp=0,rank),vis[cnt]=1;
                 if(t==p) continue;
                 else if(rank[p]<rank[t]) parent[p]=t;
                 else parent[t]=p;
             }
        }
        vector<vector<string>>ans;
        // print name of corresponding parent email
        for(int i=0;i<parent.size();i++){
            if(vis[i]) continue;
            int p=find(i,parent,tp=0,rank);
            string ofp=v[p].second;
            vector<string>ss; ss.push_back(ofp);
            vector<string>temp;
             for(int j=0;j<parent.size();j++)
                 if(!vis[j] and find(j,parent,tp=0,rank)==p)
                     temp.push_back(v[j].first), vis[j]=1;
            sort(temp.begin(),temp.end());
            for(auto &str:temp) ss.push_back(str);
            ans.push_back(ss);
        }
        return ans;
    }
};