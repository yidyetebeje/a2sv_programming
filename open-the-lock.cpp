class Solution {
public:
    int openLock(const vector<string>& deadends, const string& target) {
        unordered_set<string> deads(deadends.begin(), deadends.end()), visited{"0000"};
        if (deads.find("0000") != deads.end()) return -1;
        queue<string> q;
        q.push("0000");
        int count = 0, s;
        string tmp;

        while (q.empty() == false)
        {
            s = q.size();

            while (s--)
            {
                tmp = q.front();
                q.pop();

                if (tmp == target)
                    return count;
                
                for (char& c : tmp)
                {
                    c = Inc(c);

                    if (deads.find(tmp) == deads.end() && visited.find(tmp) == visited.end())
                        q.push(tmp), visited.insert(tmp);

                    c = Dec(Dec(c)); 

                    if (deads.find(tmp) == deads.end() && visited.find(tmp) == visited.end())
                        q.push(tmp), visited.insert(tmp);

                    c = Inc(c); // Return to inital value
                }
            }

            ++count;
        }

        return -1;
    }

private:
    inline char Inc(char c) { return c == '9' ? '0' : c + 1;  }
    inline char Dec(char c) { return c == '0' ? '9' : c - 1; }
};