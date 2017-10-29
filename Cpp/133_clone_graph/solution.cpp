/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
        if (!node) return NULL;
        if (m.find(node) == m.end()) 
        {
            m[node] = new UndirectedGraphNode(node->label);
            for (UndirectedGraphNode* neighbor : node->neighbors)
                (m[node]->neighbors).push_back(cloneGraph(neighbor));
        }
        return m[node];
    } 
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
};