class Solution 
{
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
    {
        auto graph = make_graph(numCourses, prerequisites);
        auto degrees = compute_indegree(graph);
        stack<int> st;
        vector<int> res;
        for (int i = 0; i < numCourses; ++ i)
            if (degrees[i] == 0) st.push(i);

        while (!st.empty())
        {
            int tmp = st.top();
            st.pop();
            res.push_back(tmp);
            degrees[tmp] = -1;
            for (int neigh : graph[tmp])
                if (-- degrees[neigh] == 0) st.push(neigh);
        }

        if (res.size() != numCourses) 
            res.clear();
        return res;        
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