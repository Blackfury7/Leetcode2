class Solution {
public:
    const int mx = INT_MAX;
    string solve(string s){
        int n = s.size();
        vector<int> v(n+1);
        v[n] = mx;
        for (int i = n - 1; i >= 0; i--) 
            v[i] = min(v[i + 1], (int)s[i]);
        stack<char> st;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (st.size() > 0 and v[i] >= st.top()) {
                ans += st.top();
                st.pop();
                i--;
            }
            else if (v[i] == s[i]) 
                ans += s[i];
            else 
                st.push(s[i]);
        }
        while (st.size() > 0) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
    
    string robotWithString(string s) {
        return solve(s);
    }
};