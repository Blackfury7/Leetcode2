class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        unordered_set<int> seen; 
        vector<int> C(n, 0);
        int commonCount{0};
        for (int i{0}; i < n; ++i) {
            if (seen.count(A[i])) ++commonCount;
            else seen.insert(A[i]);
            if (seen.count(B[i])) ++commonCount;
            else seen.insert(B[i]);
            C[i] = commonCount;
        }
        return C;
    }
};