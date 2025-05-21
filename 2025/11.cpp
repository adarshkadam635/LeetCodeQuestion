// https://leetcode.com/problems/zero-array-transformation-i/?envType=daily-question&envId=2025-05-20

class Solution {
    public:
        bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = nums.size();
            vector<int>vec(n+1, 0);
    
            for(int i = 0; i < queries.size(); i++)
            {
                int l = queries[i][0];
                int r = queries[i][1];
    
                vec[l]++;
                vec[r+1]--; 
            }
            vector<int>v(n, 0);
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += vec[i];
                v[i] = sum;
            }
    
            for(int i = 0; i < n; i++)
            {
                if(v[i] < nums[i])
                return false;
            }
            return true;
        }
    };