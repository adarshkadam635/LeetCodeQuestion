
// https://leetcode.com/problems/total-characters-in-string-after-transformations-i/?envType=daily-question&envId=2025-05-13

class Solution {
    public:
        int lengthAfterTransformations(string s, int t) {
            int MOD = 1e9 + 7;
            vector<int> freq(26);
            for(char c: s){
                freq[c-'a']++;
            }
            while(t>=26){
                int prev = freq[25];
                for(int i=0; i<25; i++){
                    int temp = freq[i];
                    freq[i] = (freq[i] +  prev) % MOD;
                    prev = temp;
                }
                // z adding its own freq to b
                freq[1] = (freq[1] +  freq[25]) % MOD;
                freq[25] = (freq[25] +  prev) % MOD;
                t -= 26;
            }
            int res = 0;
            for(int i=0; i<26; i++){
                res = (res + freq[i]) % MOD;
                // checking what can reach 26
                // if it reaches it will create it same freq more characters
                if(i + t >= 26){
                    res = (res + freq[i]) % MOD;
                }
            }
            return res;
        }
    };