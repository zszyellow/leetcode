class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> hm;
        for (char &c : S) hm[c] ++;
        
        auto comp = [](const pair<char, int> p1, const pair<char, int> &p2) {
            return p1.second < p2.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)> pq(hm.begin(), hm.end(), comp);
        if (pq.top().second > (S.size()+1) / 2) return "";
        
        string res;
        while (pq.size() >= 2) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            
            res += p1.first;
            res += p2.first;
            p1.second --;
            p2.second --;
            if (p1.second > 0) pq.push(p1);
            if (p2.second > 0) pq.push(p2);
        }
        if (!pq.empty()) res += pq.top().first;
        return res;
    }
};