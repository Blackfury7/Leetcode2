class Solution {
public:
    static int countValidSelections(vector<int>& nums) {
        const int n=nums.size();
        partial_sum(nums.begin(), nums.end(), nums.begin());
        int sum=nums.back(), h=sum/2;
        bool no0=h!=0;
        if ((sum&1)==0){
            auto [l, r]=equal_range(nums.begin(), nums.end(), h);
            return l==r?0:(r-l-no0)*2;
        }
        auto [l0, r0]=equal_range(nums.begin(), nums.end(), h);
        auto [l1, r1]=equal_range(nums.begin(), nums.end(), h+1);
        return (l0==r0?0:r0-l0-no0)+(l1==r1?0:r1-l1-1);
    }
};