#define ll long long
#define forn(i, n) for (int i = 0; i < int(n); i++)
const int SIZE = 1e5 + 10;
class Solution {
public:
struct BIT {
    vector<int> bit;
    int n;
    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void update(int i, int val) {
        for (++i; i <= n; i += i & -i)
            bit[i] += val;
    }
    int query(int i) {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += bit[i];
        return res;
    }
};

ll goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> pos2(n);
    forn(i, n) pos2[nums2[i]] = i;

    vector<int> mapped(n);
    forn(i, n) mapped[i] = pos2[nums1[i]];

    BIT bitL(SIZE), bitR(SIZE);
    vector<int> rightCount(n, 0), leftCount(n, 0);

    // Count right counts
    for (int i = n - 1; i >= 0; --i) {
        rightCount[i] = bitR.query(SIZE - 1) - bitR.query(mapped[i]);
        bitR.update(mapped[i], 1);
    }

    ll res = 0;
    forn(i, n) {
        leftCount[i] = bitL.query(mapped[i] - 1);
        bitL.update(mapped[i], 1);
        res += (ll)leftCount[i] * rightCount[i];
    }

    return res;
}
};