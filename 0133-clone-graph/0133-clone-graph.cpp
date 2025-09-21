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

    Node* dfs(unordered_map<Node*, Node*>& cloneMap, Node* node) {
        if (cloneMap[node]) return cloneMap[node];

        cloneMap[node] = new Node(node->val);

        for (Node* neighbor: node->neighbors) {
            cloneMap[node]->neighbors.push_back(dfs(cloneMap, neighbor));
        }

        return cloneMap[node];
    }

    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> cloneMap;

        return dfs(cloneMap, node);
    }
};