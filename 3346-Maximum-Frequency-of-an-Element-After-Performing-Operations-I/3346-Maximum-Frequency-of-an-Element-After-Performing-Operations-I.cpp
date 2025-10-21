class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int o) {
        int s=3*(1e5)+10;
        vector<int> arr(s,0);
        int n=nums.size();
        int limit=1e5, ans=0;

        unordered_map<int,int> mp;
        for(auto x:nums) mp[x+limit]++;

        int min_range=s-1, max_range=0;

        for(int i=0; i<n; i++) {
            int l=nums[i]-k+limit;
            int r=nums[i]+k+limit+1;
            arr[l]++;
            arr[r]--;
            min_range=min(min_range,l);
            max_range=max(max_range,r);
        }

        int temp=0;
        for(int i=min_range; i<=max_range; i++) {
            temp+=arr[i];
            if(mp.find(i)!=mp.end()) {
                ans=max(ans, mp[i]+min(temp-mp[i], o));
            } else {
                ans=max(ans, min(o, temp));
            }
        }
        return ans;
    }
};