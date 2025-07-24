class Solution {
    vector<vector<int>> tree;
    vector<int> xorVal;
    vector<vector<int>> edgesUsed;
    vector<vector<bool>> isChild;
    vector<bool> visited;
    vector<int> path, nums;

    int dfs(int node) {
        visited[node] = true;
        int val = nums[node];
        for (int parent : path) isChild[parent][node] = true;
        path.push_back(node);

        for (int next : tree[node]) {
            if (!visited[next]) {
                edgesUsed.push_back({node, next});
                val ^= dfs(next);
            }
        }

        path.pop_back();
        return xorVal[node] = val;
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        this->nums = nums;
        tree.assign(n, {});
        xorVal.assign(n, 0);
        isChild.assign(n, vector<bool>(n, false));
        visited.assign(n, false);
        path.clear();
        edgesUsed.clear();

        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        dfs(0);
        int result = INT_MAX;

        for (int i = 0; i < edgesUsed.size(); i++) {
            for (int j = i + 1; j < edgesUsed.size(); j++) {
                int a = edgesUsed[i][1];
                int b = edgesUsed[j][1];
                int x = xorVal[a], y = xorVal[b], z = xorVal[0];

                if (isChild[a][b]) {
                    z ^= x;
                    x ^= y;
                } else if (isChild[b][a]) {
                    z ^= y;
                    y ^= x;
                } else {
                    z ^= x;
                    z ^= y;
                }

                int maxVal = max({x, y, z});
                int minVal = min({x, y, z});
                result = min(result, maxVal - minVal);
            }
        }

        return result;
    }
};