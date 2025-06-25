class Solution {
public:
    int func1(long long pres, vector<int>& nums2,long long res ){
        int lo = 0,hi = nums2.size()-1,mid,ans = -1;
        while(lo <= hi){
            mid = (lo + hi)/2;
            long long here = pres * 1LL * nums2[mid];
            if(here < res){
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        if(ans == -1) return 0;
        return ans + 1;

    }
    int func2(long long pres, vector<int>& nums2,long long res ){
        int lo = 0,hi = nums2.size()-1,mid,ans = -1;
        while(lo <= hi){
            mid = (lo + hi)/2;
            long long here = pres * 1LL * nums2[mid];
            if(here > res){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }    
        if(ans == -1) return 0;
        return (nums2.size() - ans);

    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n = nums1.size();
        int m = nums2.size();
        long long lo = -1e10,hi = 1e10,mid,ans;
        long long all = (n * 1LL * m);
        while(lo <= hi){
            mid = (lo + hi)/2;
            bool check = true;
            long long total1 = 0;
            long long total2 = 0;
            for(int i = 0;i < nums1.size();i++){
                if(nums1[i] == 0){
                    if(mid > 0){
                        total1 += nums2.size();
                        total2 += 0;
                    }
                    else if(mid < 0){
                        total1 += 0;
                        total2 += nums2.size();
                    }
                    continue;
                }
                if(nums1[i] > 0){
                    total1 += func1(nums1[i],nums2,mid);
                    total2 += func2(nums1[i],nums2,mid);                    
                }
                else if(nums1[i] < 0){
                    total1 += func2(nums1[i] * -1,nums2,mid * -1);
                    total2 += func1(nums1[i] * -1,nums2,mid * -1);
                }        
            }
            if(total1 >= k){
                hi = mid - 1;
            }
            else if(all -total2 < k){
                lo = mid + 1;
            }
            else{
                ans = mid;
                break;
            }
        }
        return ans;
    }
};