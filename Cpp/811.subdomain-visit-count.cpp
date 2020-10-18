class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counts;
        for (string &cp: cpdomains) {
            auto blank_pos = cp.find(' ');
            int count = std::stoi(cp.substr(0, blank_pos));
            string domain = cp.substr(blank_pos+1, cp.size()-blank_pos-1);
            counts[domain] += count;
            while (domain.find('.') != string::npos) {
                auto dot_pos = domain.find('.');
                domain = domain.substr(dot_pos+1, domain.size()-dot_pos-1);
                counts[domain] += count;
            }
        } 
        
        vector<string> res;
        for (auto &new_cp : counts) {
            res.push_back(std::to_string(new_cp.second) + " " + new_cp.first);
        }
        return res;
    }
};