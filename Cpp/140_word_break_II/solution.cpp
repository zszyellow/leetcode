#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<string> wordBreak(string s, vector<string>& wordDict)
    {
        vector<string> result_dict;
        int len = s.size();
        string path = "";
        unordered_set<string> hash_table;
        vector<int> cache(len, -1);

        for (int i = 0; i < wordDict.size(); i++)
            hash_table.insert(wordDict[i]);

        check(s, hash_table, 0, path, cache, result_dict);
        return result_dict;
    }

    bool check(string s,
                unordered_set<string> hash_table,
                int idx,
                string& path,
                vector<int>& cache,
                vector<string>& result_dict)
    {
        if (idx == s.size())
        {
            path.pop_back();
            result_dict.push_back(path);
            return true;
        }

        if (cache[idx] == 0)
            return false;

        string cur = "";
        bool hasResult = false;
        for (int i = idx; i < s.size(); i++)
        {
            cur += s[i];
            if (hash_table.find(cur) != hash_table.end())
            {
                string tmp = path;
                path += (cur + " ");
                if (check(s, hash_table, i+1, path, cache, result_dict))
                    hasResult = true;
                path = tmp;
            }
        }

        cache[idx] = hasResult ? 1 : 0;
        return hasResult;
    }
};

// test cases
int main(int argc, char const* argv[])
{
    Solution solution1;
    string test_str = "catsanddog";
    vector<string> test_dict{"cat", "cats", "and", "sand", "dog"};
    vector<string> result_dict{"cat sand dog", "cats and dog"};

    // test case1
    cout << "start test case1:" << endl;
    if (result_dict == solution1.wordBreak(test_str, test_dict))
        cout << "test case1 passed" << endl;
    else
        cout << "test case1 failed" << endl;

    return 0;
}
