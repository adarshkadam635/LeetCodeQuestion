# https://leetcode.com/problems/painting-a-grid-with-three-different-colors/description/?envType=daily-question&envId=2025-05-18

class Solution {
public:
    int colorTheGrid(int m, int n) {
        const auto MOD = size_t(1e9 + 7);

        auto combs = std::vector<int>();

        for (int comb = 0; comb < 256; ++comb) {
            bool skip = false;

            int prev_color = -1;
            int curr_color = -1;
            int curr_value = comb;

            for (int r = 0; r < m; ++r) {
                curr_color = curr_value % 3;

                if (prev_color == curr_color) {
                    skip = true;
                    break;
                }

                prev_color = curr_color;
                curr_value = curr_value / 3;
            }


            if (!skip && curr_value == 0) {
                combs.emplace_back(comb);
            }
        }

        const auto k = combs.size();

        auto combs_to_combs = std::vector(k, std::vector<int>(0));

        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                bool skip = false;

                int comb1 = combs[i];
                int comb2 = combs[j];

                for (int i = 0; i < m; ++i) {
                    if (comb1 % 3 == comb2 % 3) {
                        skip = true;
                        break;
                    }

                    comb1 /= 3;
                    comb2 /= 3;
                }

                if (!skip) {
                    combs_to_combs[i].emplace_back(j);
                    combs_to_combs[j].emplace_back(i);
                }
            }
        }

        auto dp = std::vector(n, std::vector(k, size_t(0)));

        for (int i = 0; i < k; ++i) {
            dp[0][i] = 1;
        }

        for (int c = 1; c < n; ++c) {
            for (int i = 0; i < k; ++i) {
                for (const auto j : combs_to_combs[i]) {
                    dp[c][i] += dp[c-1][j];
                    dp[c][i] %= MOD;
                }
            }
        }

        int result = 0;

        for (int i = 0; i < k; ++i) {
            result += dp[n-1][i];
            result %= MOD;
        }

        return result;
    }
};