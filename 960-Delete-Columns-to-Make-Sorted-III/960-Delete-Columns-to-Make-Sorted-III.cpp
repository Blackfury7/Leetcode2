class Solution {
public:
    static int minDeletionSize(vector<string>& strs) {
        const int n=strs.size(), m=strs[0].size();

        // dp[col][last]
        int dp[2][101]={0};

        // Base case: col=0
        for (int last=1; last<=m; last++) {
            bool ok=(last==m)|| all_of(strs.begin(),strs.end(),
                [&](const string& s) {return s[0]<=s[last];}
            );
            dp[0][last]=ok;
        }

        // Fill DP
        for (int col=1; col<m; col++) {
            const bool b=col&1;
            for (int last=col+1; last<=m; last++) {
                // skip col
                dp[b][last]=dp[!b][last];

                // take col
                bool ok=(last==m) || all_of(strs.begin(),strs.end(),
                    [&](const string& s) { return s[col]<=s[last];}
                );

                if(ok)
                    dp[b][last]=max(dp[b][last], 1+dp[!b][col]);
            }
        }
        return m-dp[(m-1)&1][m];
    }
};
