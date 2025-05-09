class Solution {
    public:
        int countBalancedPermutations(string num) {
            sort(num.begin(), num.end());
            vector<bool> used(num.size(), false);
            int count = 0;
            string path;
            dfs(num, used, path, count);
            return count;
        }
    
        void dfs(string& num, vector<bool>& used, string& path, int& count) {
            if (path.size() == num.size()) {
                int sum = 0;
                for (int i = 0; i < path.size(); i++) {
                    if (i % 2 == 0) sum += (path[i] - '0');
                    else sum -= (path[i] - '0');
                }
                if (sum == 0) count++;
                return;
            }
    
            for (int i = 0; i < num.size(); i++) {
                if (used[i]) continue;
                if (i > 0 && num[i] == num[i - 1] && !used[i - 1]) continue;
                used[i] = true;
                path.push_back(num[i]);
                dfs(num, used, path, count);
                path.pop_back();
                used[i] = false;
            }
        }
    };