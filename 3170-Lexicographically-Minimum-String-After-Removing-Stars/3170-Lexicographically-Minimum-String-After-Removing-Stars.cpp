class Solution {
struct CustomComp {
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
public:
    string clearStars(string s) {
        int starcount=0;
        priority_queue<pair<char,int>,vector<pair<char,int>>,CustomComp>pq;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(!pq.empty()) pq.pop();
                starcount++;
            }
            else{
                pq.push({s[i],i});
            }
            
        }
        if(!starcount) return s;
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> temp;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            temp.push({top.second, top.first});
        }
        string res="";
        while(!temp.empty()){
            res+=temp.top().second;
            temp.pop();
        }
        return res;
    }
};