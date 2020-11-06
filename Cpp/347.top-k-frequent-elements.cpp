class Solution {
public:
    string frequencySort(string s) {
        /* Hashmap+Heap, TC: O(NlogN), SC: O(N) */
//         unordered_map<char, int> hm;
//         for (char &c : s) hm[c] ++;
        
//         auto comp = [](const pair<char, int> &p1, pair<char, int> &p2) {
//             return p1.second < p2.second;  
//         };
//         priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(hm.begin(), hm.end(), comp);
        
//         string res;
//         while (!pq.empty()) {
//             res += string(pq.top().second, pq.top().first);
//             pq.pop();
//         }
//         return res;
        
        /* Bucket sort, TC: O(N), SC: O(N) */
        unordered_map<char, int> hm;
        for (char &c : s) hm[c]++;
        
        vector<vector<pair<char, int>>> buckets(s.size()+1);
        for (auto &&[key, val] : hm) buckets[val].push_back({key, val});
        reverse(buckets.begin(), buckets.end());
        
        string res;
        for (auto &v : buckets)
            for (auto &p : v)
                res += string(p.second, p.first);
        
        return res;
    }
};