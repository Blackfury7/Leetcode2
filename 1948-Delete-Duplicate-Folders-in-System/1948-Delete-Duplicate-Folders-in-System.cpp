class Node {
public:
    string name;
    map<string, Node*> children;
    string signature;
    Node(string name) : name(name), signature(""){}
};
class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node("");
        for (auto& path : paths){
            Node* node = root;
            for (auto& folder : path){
                if (!node -> children.count(folder)){
                    node -> children[folder] = new Node(folder);
                }
                node = node -> children[folder];
            }
        }
        unordered_map<string, int> count;
        function<string(Node*)> DFS1 = [&](Node* node) -> string{
            if (node -> children.empty())
                return "";
            vector<string> subs;
            for (auto& [name, child] : node -> children){
                string subSign = DFS1(child);
                subs.push_back(name + "(" + subSign + ")");
            }
            sort(subs.begin(), subs.end());
            node -> signature = "";
            for (auto& s : subs)
                node -> signature += s;
            count[node -> signature]++;
            return node -> signature;
        };
        DFS1(root);
        vector<vector<string>> res;
        vector<string> current;
        function<void(Node*)> DFS2 = [&](Node* node){
            if (!node -> signature.empty() && count[node -> signature] > 1)
                return;
            if (!node -> name.empty()){
                current.push_back(node -> name);
                res.push_back(current);
            }
            for (auto& [name, child] : node -> children){
                DFS2(child);
            }
            if (!node -> name.empty()){
                current.pop_back();
            }
        };
        for (auto& [name, child] : root -> children){
            DFS2(child);
        }
        return res;
    }
};