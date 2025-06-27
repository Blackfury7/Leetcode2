class Solution {
public:
    int k ;
    string longestSubsequenceRepeatedK(string s, int k) {
        this->k = k;
        map<char,int> freq;
        for(auto i : s){
            freq[i]++;
        }
        vector<char> v;
        queue<string> q;
        for(auto [i,j] : freq){
            if(j >= k){
                v.push_back(i);
                // cout << i << "---\n";
                q.push(string(1,i));
            }
        }
        string ans = "";
        while(!q.empty()){
            auto str = q.front();
            // cout << str << " " << endl;
            q.pop();
            if(str.size() >= ans.size()){
                ans = str;
            }
            for(auto ch : v){
                string perm = str + ch;
                if(occursK(s,perm)){
                    q.push(perm);
                }
            }
        }
        return ans;
    }
    bool occursK(string s, string perm){
        int idx = 0;
        int count = 0;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] == perm[idx]){
                idx++;
            }
            if(idx == perm.size()){
                count++;
                idx = 0;
            }
            if(count == k){
                return true;
            }
        }
        return false;
    }

};