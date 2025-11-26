class Solution {
public:
    static constexpr int kMod = 1'000'000'007;
    template<bool transpose = false>
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int h = grid.size();
        int w = grid[0].size();
        if constexpr (transpose) {
            swap(w,h);
        } else if (w > h) {
            return numberOfPaths<true>(grid, k);
        }

        using CellCounters = array<int, 50>;

        std::vector<CellCounters> curr(w+1), prev(w+1);
        prev[1][0] = 1;

        for (int y = 1; y <= h; ++y) {
            for (int x = 1; x <= w; ++x) {
                int v = transpose ? grid[x-1][y-1] : grid[y-1][x-1];
                for (int prev_mod = 0; prev_mod != k; ++prev_mod) {
                    int left_mod_cnt = curr[x-1][prev_mod];
                    int top_mod_cnt = prev[x][prev_mod];
                    int curr_mod = (prev_mod + v) % k;
                    (curr[x][curr_mod] = (left_mod_cnt + top_mod_cnt)) %= kMod;
                }
            }
            swap(curr, prev);
        }

        return prev[w][0];
    }
};