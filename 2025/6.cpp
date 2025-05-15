// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/?envType=daily-question&envId=2025-05-15
class Solution {
    public:
        vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
            int maxi=INT_MIN;
            vector<string> ans;
            for(int i=0;i<groups.size();i++)
            {
                int k=groups[i],count=1;
                vector<int> v;
                v.push_back(i);
                for(int j=i+1;j<groups.size();j++)
                {
                    if(groups[j]!=k)
                    {
                        count++;
                        k=groups[j];
                        v.push_back(j);
                    }
                }
                if(count>maxi)
                {
                    ans.clear();
                    for(int x=0;x<v.size();x++)
                    ans.push_back(words[v[x]]);
                    maxi=count;
                }
            }
            return ans;
            
        }
    };