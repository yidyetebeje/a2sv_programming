#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string largestMerge(string word1, string word2) {
        string ans;
        ans.reserve(word1.size() + word2.size());
        int i = 0, j = 0;
        while (i < word1.size() && j < word2.size())
        {
            if (word1[i] > word2[j])
            {
                ans += word1[i];
                i++;
            }
            else if (word1[i] < word2[j])
            {
                ans += word2[j];
                j++;
            }
            else
            {
                int k = i, l = j;
                while (k < word1.size() && l < word2.size() && word1[k] == word2[l])
                {
                    k++;
                    l++;
                }
                if (k == word1.size())
                {
                    ans += word2[j];
                    j++;
                }
                else if (l == word2.size())
                {
                    ans += word1[i];
                    i++;
                }
                else
                {
                    if (word1[k] > word2[l])
                    {
                        ans += word1[i];
                        i++;
                    }
                    else
                    {
                        ans += word2[j];
                        j++;
                    }
                }
            }
        }
        while (i < word1.size())
        {
            ans += word1[i];
            i++;
        }
        while (j < word2.size())
        {
            ans += word2[j];
            j++;
        }
        return ans;
    }
};