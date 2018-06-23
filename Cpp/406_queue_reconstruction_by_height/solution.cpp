class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        std::sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> res;
        for (auto p : people) {
            res.insert(res.begin() + p.second, p);
            // display(res);
        }
        return res;
    }
    
    // void display(vector<pair<int, int>> tmp) {
    //     for (auto it = tmp.begin(); it != tmp.end(); it ++)
    //         std::cout << (*it).first << "," << (*it).second << " ";
    //     std::cout << std::endl;
    // }
};