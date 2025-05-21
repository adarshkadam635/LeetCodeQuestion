// https://leetcode.com/problems/set-matrix-zeroes/?envType=daily-question&envId=2025-05-21

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            vector<int> zero_rows;
            vector<int> zero_cols;
            // std::cout<<"Size of matrix"<<matrix.size();
            for (int i=0;i<matrix.size();i++) {
                for (int j=0;j<matrix[0].size();j++) {
                    // std::cout<<"matrix value "<<matrix[i][j]<<" "<<matrix.size()<<" "<<matrix[0].size()<<endl;
                    if (matrix[i][j] == 0) {
                        zero_rows.push_back(i);
                        zero_cols.push_back(j);
    
                        
                    }
                }
            }
            while (!zero_rows.empty()) {
                int row = zero_rows.back();
                zero_rows.pop_back();
                for (int i=0;i<matrix[0].size();i++) {
                    matrix[row][i] = 0;
                }
            }
            while (!zero_cols.empty()) {
                int col = zero_cols.back();
                zero_cols.pop_back();
                for (int i=0;i<matrix.size();i++) {
                    matrix[i][col] = 0;
                }
            }
            
        }
    };