// https://leetcode.com/problems/sort-colors/?envType=daily-question&envId=2025-05-17
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int i=0,j=1,n=nums.size();
            while(i<n && j<n){
                if(nums[i]!=0 && nums[j]==0){
                    nums[j] = nums[i];
                    nums[i] = 0;
                    i++;
                } else if(nums[i]==0) {
                    i++;
                }
                j++;
            }
            j= i+1;
            while(i<n && j<n){
                if(nums[i]!=1 && nums[j]==1){
                    nums[j] = nums[i];
                    nums[i] = 1;
                    i++;
                } else if(nums[i]==1) {
                    i++;
                }
                j++;
            }
            j= i+1;
            while(i<n && j<n){
                if(nums[i]!=2 && nums[j]==2){
                    nums[j] = nums[i];
                    nums[i] = 2;
                    i++;
                } else if(nums[i]==2) {
                    i++;
                }
                j++;
            }
        }
    };