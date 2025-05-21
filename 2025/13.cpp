// https://leetcode.com/problems/longest-palindromic-substring/description/?envType=problem-list-v2&envId=dynamic-programming

class Solution {
    public:
        string longestPalindrome(string s) {
            int start = 0, maxLen = 1;
    
            for (int i = 0; i < s.length(); ++i) {
                expand(s, i, i, start, maxLen);     // Odd length
                expand(s, i, i + 1, start, maxLen); // Even length
            }
    
            return s.substr(start, maxLen);
        }
    
        void expand(const string& s, int l, int r, int& start, int& maxLen) {
            while (l >= 0 && r < s.length() && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }
                --l; ++r;
            }
        }
    };