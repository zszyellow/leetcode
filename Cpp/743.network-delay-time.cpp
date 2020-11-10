class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Dijkstra's algorithm, TC: O(ElogE) SC: O(N+E)
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto &edge : times) graph[edge[0]].push_back({edge[1], edge[2]});
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({0, K});
        unordered_map<int, int> dist;
        
        while (!min_heap.empty()) {
            auto info = min_heap.top();
            min_heap.pop();
            int d = info.first, vertex = info.second;
            if (dist.find(vertex) != dist.end()) continue;
            dist[vertex] = d;
            for (auto &edge : graph[vertex]) {
                int next_vertex = edge.first, d2 = edge.second;
                if (dist.find(next_vertex) == dist.end()) 
                    min_heap.push({d+d2, next_vertex});
            }
        }
        
        if (dist.size() != N) return -1;
        int res = 0;
        for (auto &&[key, val] : dist) res = max(res, val);
        return res;
    }
};