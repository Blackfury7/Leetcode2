class Solution {
public:
    int dp[601][101][101];

    int solve(int i, int used0, int used1, const vector<pair<int,int>>& cost, int m, int n) {
        if (used0 > m || used1 > n) return -1e9;
        if (i == cost.size()) return 0;

        if (dp[i][used0][used1] != -1)
            return dp[i][used0][used1];

        int take = 1 + solve(i + 1, used0 + cost[i].first, used1 + cost[i].second, cost, m, n);
        int skip = solve(i + 1, used0, used1, cost, m, n);

        return dp[i][used0][used1] = max(take, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));

        vector<pair<int,int>> cost;
        for (auto& s : strs) {
            int zero = 0, one = 0;
            for (char c : s) (c == '0' ? zero : one)++;
            cost.push_back({zero, one});
        }

        return solve(0, 0, 0, cost, m, n);
    }
};