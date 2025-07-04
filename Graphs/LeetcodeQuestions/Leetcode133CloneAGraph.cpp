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
    void dfs(Node *node,Node *clone,vector<Node*>&visited){
        for(auto nbr:node->neighbors){
            if(!visited[nbr->val]){
                Node *nbrclone=new Node(nbr->val);
                clone->neighbors.push_back(nbrclone);
                visited[nbr->val]=nbrclone;
                dfs(nbr,nbrclone,visited);
            }
            else{
               clone->neighbors.push_back(visited[nbr->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==nullptr){return nullptr;}
    vector<Node*>visited(101,NULL);
    Node* clone=new Node(node->val);
    visited[node->val]=clone;
    dfs(node,clone,visited);    
    return visited[1];
    }
};