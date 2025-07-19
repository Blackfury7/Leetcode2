class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;

        sort(folder.begin(), end(folder));

        unordered_set<string> parent;

        for(int i=0;i<folder.size();i++){
            string cur = "";
            bool fl = true;

            // start scanning the given directory level by level
            for(int j=0;j<folder[i].size();j++){
                if(folder[i][j] == '/'){
                    // move to next level, but first search current level
                    if(parent.count(cur)){
                        fl = false;
                        break;
                    }
                    cur += '/';
                }
                else{
                    cur += folder[i][j];
                }
            }

            if(fl){
                parent.insert(cur);
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};