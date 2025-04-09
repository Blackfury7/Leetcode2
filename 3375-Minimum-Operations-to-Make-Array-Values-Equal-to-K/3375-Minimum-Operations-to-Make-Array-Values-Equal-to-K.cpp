class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            bitset<101> hasX=0;
            for(int x: nums){
                if (x<k) return -1;
                hasX[x]=1;
            }
            return hasX.count()-hasX[k];
        }
    
        // set
       
            // int minOperations(vector<int>& nums, int k) {
            //     int mini = *min_element(nums.begin(), nums.end());
            //     if (mini < k) return -1;
                
            //     unordered_set<int> st(nums.begin(), nums.end());
            //     return st.size() - (mini == k);
            // }
    
            // hashmap
            // int minOperations(vector<int>& nums, int k) {
            //     unordered_map<int,int> mpp;
            //     for (int i : nums) 
            //         if (i < k) return -1;
            //         else if (i > k) mpp[i]++;
            //     return mpp.size();
            // }
     
    };