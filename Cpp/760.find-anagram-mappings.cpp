class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int, int> mapping;
        for (int i = 0; i < B.size(); i ++) {
            if (mapping.find(B[i]) == mapping.end()) mapping[B[i]] = i; 
        }
        for (int a : A) {
            res.push_back(mapping[a]);
        }
        return res;
    }
};