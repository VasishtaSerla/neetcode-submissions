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
public:
    Node*head = NULL;
    unordered_map<int,Node*>m;
    void dfs(Node*node,Node*new_node,vector<int>&visited){
        visited[node->val] = 1;
        m[node->val] = new_node;
        for(auto x:node->neighbors){
         if(!visited[x->val]){
            Node*temp = new Node(x->val);
            new_node->neighbors.push_back(temp);
            dfs(x,temp,visited);
         }
         else {
            new_node->neighbors.push_back(m[x->val]);
         }
        }
    }
    Node* cloneGraph(Node* node) {
        vector<int>visited(101,0);
        if(!node)return NULL;
        Node*new_node = new Node(node->val);
        dfs(node,new_node,visited);
        return new_node;
    }
};
