class Solution {
public:
    
    bool func(string s,unsigned long long prev)
    {
        if(s=="") return true; 
        for(int i=0;i<s.length();i++)
        {
            if(stoull(s.substr(0,i+1))==prev-1) 
                if(func(s.substr(i+1),prev-1)) 
                    return true; 
        }
        return false;
    }
    bool splitString(string s) {       
        for(int i=0;i<s.length()-1;i++)
        {
            if(func(s.substr(i+1),stoull(s.substr(0,i+1)))) return true;
        }
        return false;
    }
};