class Solution {
    static const int MOD = 1'000'000'007;

public:
    int magicalSum(int m, int k, vector<int>& nums) {
        int n = (int)nums.size();

        // Precompute powtab[i][c] = nums[i]^c mod MOD for c in [0..m]
        vector<vector<int>> powtab(n, vector<int>(m + 1, 1));
        for (int i = 0; i < n; i++) {
            for (int c = 1; c <= m; c++) {
                long long v = (1LL * powtab[i][c - 1] * nums[i]) % MOD;
                powtab[i][c] = (int)v;
            }
        }

        // Precompute combinations comb[r][c] = C(r, c) mod MOD for r,c in [0..m]
        vector<vector<int>> comb(m + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= m; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        // dp[rem][carry][ones] holds the running total after processing some prefix of indices:
        // rem picks left to place, current carry value, ones bits produced so far
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
        dp[m][0][0] = 1; // start with all m picks remaining, carry = 0, ones = 0

        for (int i = 0; i < n; i++) {
            vector<vector<vector<int>>> next(m + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
            const vector<int>& powi = powtab[i];
            for (int rem = 0; rem <= m; rem++) {
                for (int carry = 0; carry <= m; carry++) {
                    for (int ones = 0; ones <= k; ones++) {
                        int baseVal = dp[rem][carry][ones];
                        if (baseVal == 0) continue;
                        // Choose c copies of index i among the rem remaining positions
                        for (int c = 0; c <= rem; c++) {
                            int t = c + carry;       // add c to current bit with carry in
                            int bit = t & 1;         // output bit at this position
                            int ones2 = ones + bit;  // update ones count
                            if (ones2 > k) continue;
                            int carry2 = t >> 1;     // carry to the next bit
                            int rem2 = rem - c;

                            // Transition weight = comb[rem][c] (ways to place c copies) * nums[i]^c
                            long long add = baseVal;
                            add = (add * comb[rem][c]) % MOD;
                            add = (add * powi[c]) % MOD;

                            next[rem2][carry2][ones2] = (next[rem2][carry2][ones2] + (int)add) % MOD;
                        }
                    }
                }
            }
            dp.swap(next);
        }

        // Finish: only states with rem = 0 are valid
        // Leftover carry still contributes popcount(carry) ones
        long long ans = 0;
        for (int carry = 0; carry <= m; carry++) {
            int extra = __builtin_popcount((unsigned)carry);
            int need = k - extra;
            if (need >= 0 && need <= k) {
                ans = (ans + dp[0][carry][need]) % MOD;
            }
        }
        return (int)ans;
    }
};