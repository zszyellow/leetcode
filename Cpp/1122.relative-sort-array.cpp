class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < arr2.size(); ++ i) {
            hash_map[arr2[i]] = i;
        }
        std::sort(arr1.begin(), arr1.end(), [&hash_map](int &a, int &b) -> bool {
            bool AinArr2 = (hash_map.find(a) != hash_map.end());
            bool BinArr2 = (hash_map.find(b) != hash_map.end());
            if (AinArr2 && BinArr2) return hash_map[a] < hash_map[b];
            else if (AinArr2) return true;
            else if (BinArr2) return false;
            else return a < b;
            // return (AinArr2 && BinArr2 && hash_map[a] < hash_map[b]) ||
            //     (AinArr2 && !BinArr2) ||
            //     (!AinArr2 && !BinArr2 && a < b);
        });
        return arr1;
    }
};