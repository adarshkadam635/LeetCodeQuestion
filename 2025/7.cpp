// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/?envType=daily-question&envId=2025-05-16
class Solution {
    public:
        int hamming(string& s1, string& s2) {
            if(s1.size() != s2.size()) return 0;
            int d = 0;
            for(int i =0; i <s1.size(); i++)
                d +=(s1[i] != s2[i]);
                if(d > 1) return false;
            return d == 1;
        }
    
        vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
            int n = groups.size();
            // vector<int>dp(n,1);
            vector<vector<string>>dp(n);
    
            for(int i=0;i<n;i++) dp[i].push_back(words[i]);
    
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(hamming(words[i], words[j]) && groups[i] != groups[j] && dp[j].size() >=dp[i].size()){
                        dp[i] = dp[j];
                        dp[i].push_back(words[i]);    
                    }
    
                }
            }
    
            vector<string>res;
            for(const auto& seq: dp){
                if(seq.size()> res.size()) res = seq;
            }
            return res;
        }
    };