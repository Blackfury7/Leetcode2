struct cmp{
    bool operator()(const pair<int, int> &p) const{
        return hash<long>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
private:
    void reverse(string &s, int flag){
        string temp = "";
        for(int i = (int)s.length() - flag - 1; i >= 0; i--)
            if(s[i] == '1')
                temp += '0';
            else
                temp += '1';
        s += temp;
    }
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        unordered_set<pair<int, int>, cmp> st;
        st.insert({firstPlayer - 1, secondPlayer - 1});

        bool found = false;
        vector<int> res;
        int round = 1;
        int count = n;

        while(!st.empty()){
            unordered_set<pair<int, int>, cmp> tempSt;
            int newCount = n / 2 + n % 2;
            int val = 1 << (n / 2);
            for(auto i : st){
                int pos1 = i.first, pos2 = i.second;
                for(int j = 0; j < val; j++){
                    int j1 = j, j2 = (val - 1) ^ j;
                    bitset<32> b(j);
                    string s = b.to_string();
                    s = s.substr(32 - n / 2);
                    if(n % 2)
                        s += '1';
                    reverse(s, n % 2);
                    if(n - 1 - pos1 == pos2){
                        if(s[pos1] == '0' && s[pos2] == '0')
                            continue;
                        else if(found)
                            continue;
                        res.push_back(round);
                        found = 1;
                        continue;
                    }
                    else if(s[pos1] == '0' || s[pos2] == '0')
                        continue;
                    int ct = 0;
                    vector<int> temppos;
                    for(int k = 0; k < s.length(); k++){
                        if(k == pos1)
                            temppos.push_back(ct);
                        else if(k == pos2)
                            temppos.push_back(ct);
                        ct += (s[k] == '1');
                    }
                    tempSt.insert({temppos[0], temppos[1]});
                }
            }
            round++;
            st = tempSt;
            n = newCount;
        }

        res.push_back(round - 1);
        return res;
    }
};