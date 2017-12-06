class Solution 
{
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        auto graph = make_graph(numCourses, prerequisites);
        auto degrees = compute_indegree(graph);
        
        // kahn algorithm
        // detect cycle in the graph
        stack<int> st;
        for (int i = 0; i < numCourses; ++ i)
            if (degrees[i] == 0) st.push(i);

        while (!st.empty())
        {
            int tmp = st.top();
            st.pop();
            degrees[tmp] = -1;
            for (int neigh : graph[tmp])
                if (-- degrees[neigh] == 0) st.push(neigh);
        }

        for (int i = 0; i < numCourses; ++ i)
            if (degrees[i] > 0) return false;
        return true;
    }
    
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }

    vector<int> compute_indegree(vector<unordered_set<int>>& graph) 
    {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
};