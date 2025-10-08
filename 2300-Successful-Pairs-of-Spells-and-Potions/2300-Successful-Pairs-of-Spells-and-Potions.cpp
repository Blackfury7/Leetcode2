class Solution {
public:
    int solve(vector<int> &p, long long tar){
        int m=p.size();
        int l=0,r=m;
        while(l<r){
            int mid=l+(r-l)/2;
            if(p[mid]<tar){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return m-l;
    }
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long sucs) {
        sort(p.begin(),p.end());
        int n=s.size(),m=p.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            long long tar=sucs/s[i];
            tar+=(sucs%s[i]==0?0:1);
            int x=solve(p,tar);
            ans.push_back(x);
        }
        return ans;
    }
};