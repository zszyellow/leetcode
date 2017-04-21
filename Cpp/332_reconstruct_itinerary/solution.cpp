class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> itinerary;
        if (tickets.empty()) return itinerary;
        map<string, multiset<string>> m;
        stack<string> s;
        string start = "JFK";

        for (auto t : tickets)
        {
            m[t.first].insert(t.second);
        }
        s.push(start);
        while(!s.empty())
        {
            string tmp = s.top();
            if (m[tmp].empty())
            {
                s.pop();
                itinerary.push_back(tmp);
            }
            else
            {
                s.push(*(m[tmp].begin()));
                m[tmp].erase(m[tmp].begin());
            }
        }
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
