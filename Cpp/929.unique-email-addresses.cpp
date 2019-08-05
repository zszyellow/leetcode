/*
 * @lc app=leetcode id=929 lang=cpp
 *
 * [929] Unique Email Addresses
 */
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique_emails;
        for (auto& email : emails) {
            auto pivot = email.find_first_of('@');
            string name = email.substr(0, pivot); 
            string domain = email.substr(pivot);
            name.erase(remove(name.begin(), name.end(), '.'), name.end());
            auto pos = name.find_first_of('+');
            if (pos != string::npos) {
                name.erase(pos);
            }
            unique_emails.insert(name + domain);
        }
        return unique_emails.size();
    }
};

