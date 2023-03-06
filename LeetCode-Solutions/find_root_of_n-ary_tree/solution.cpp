/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        unordered_map<Node *, int> inDegree;
        for(int i = 0 ; i<tree.size() ; i++){
            if(inDegree.find(tree[i])==inDegree.end()){
                inDegree[tree[i]] = 0;
            }
            for(int j = 0 ; j<tree[i]->children.size() ; j++){
                inDegree[tree[i]->children[j]]++;
            }
        }
        
        Node * ans;
        
        for(auto it = inDegree.begin() ; it!=inDegree.end() ; it++){
            if(it->second==0){
                ans = it->first;
                break;
            }    
        }
        return ans;
    }
};