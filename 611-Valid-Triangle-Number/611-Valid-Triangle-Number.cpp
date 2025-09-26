class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();int ans=0;
        for(int i =n-1;i>0;i--){
            for(int j =i-1;j>0;j--){
                int ind = upper_bound(nums.begin(),nums.begin()+j,nums[i]-nums[j])-nums.begin();
                if(ind<j){ans+=j-ind;}}}
        return ans;
    }
};