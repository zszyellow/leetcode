class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> cnts;
        for (int &barcode : barcodes) cnts[barcode] ++;
        
        auto comp = [](const pair<int, int> p1, const pair<int, int> &p2) {
            return p1.second < p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (auto &cnt : cnts) pq.push(cnt);
        
        vector<int> res;
        while (pq.size() >= 2) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            
            res.push_back(p1.first);
            res.push_back(p2.first);
            p1.second --;
            p2.second --;
            if (p1.second > 0) pq.push(p1);
            if (p2.second > 0) pq.push(p2);
        }
        if (!pq.empty()) res.push_back(pq.top().first);
        return res;
    }
};