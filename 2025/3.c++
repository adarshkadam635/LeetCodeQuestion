# https://leetcode.com/problems/finding-3-digit-even-numbers/submissions/1632127015/?envType=daily-question&envId=2025-05-12#
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> freq(10,0),res;
        int n=digits.size();
        for(int i: digits) freq[i]++;
        for(int i=0;i<10;i+=2){
            if(!freq[i]) continue; //checks if i is an element of digits
            freq[i]--;
            for(int j=1;j<10;j++){
                if(!freq[j]) continue; // if j exists in digits
                freq[j]--;
                int ans = j*100+i;
                for(int k=0;k<10;k++){
                    if(!freq[k]) continue;// if k exist in digits
                    res.push_back(ans+k*10);
                }
                freq[j]++;
            }
            freq[i]++;
        }
        sort(res.begin(),res.end());
        return res;
    }
};