class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hm;
        for (string &word : words) hm[word] ++;
        
        auto comp = [](const pair<string, int> &p1, pair<string, int> &p2) {
            return p1.second < p2.second || (p1.second == p2.second && p1.first > p2.first);  
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(hm.begin(), hm.end(), comp);
        
        vector<string> res;
        while (k) {
            res.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        return res;
    }
};