/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    unordered_map<Node*,Node*> mp;
    public:
    Node* cloneGraph(Node* N) {
        if(N!=NULL){
            if(N->neighbors.size()==0)  
                return new Node(N->val); 
            return dfs(N);
        }
        return NULL;
    }
    Node* dfs(Node* u) {
        Node* clone=new Node(u->val);
        mp[u]=clone;
        
        vector<Node*> neighbour;
        
        for(auto node:u->neighbors) {
            if(mp.find(node)!=mp.end())   
                neighbour.push_back(mp[node]);    
            else
                neighbour.push_back(dfs(node)); 
        }
        clone->neighbors=neighbour;
        return clone;
    }
};