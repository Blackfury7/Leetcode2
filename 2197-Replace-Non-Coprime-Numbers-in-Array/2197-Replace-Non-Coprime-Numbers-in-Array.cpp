class Solution {
public:
    int calculateLCM(int &f,int &s){

        long long lcm = (1LL*f*s)/(__gcd(f,s));

        return lcm;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        stack<int>st;
        vector<int>ans;
        for(int x:nums){
            int first = x;
            while(!st.empty()){
                int second = st.top();
                if(__gcd(first,second) == 1) break;
                st.pop();
                int lcm = calculateLCM(first,second);
                first = lcm;
            }
            st.push(first);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};