class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int min_salary = *min_element(salary.begin(), salary.end());
        int max_salary = *max_element(salary.begin(), salary.end());
        int sum_salary = accumulate(salary.begin(), salary.end(), 0);
        return static_cast<double>(sum_salary - min_salary - max_salary) / (n - 2);
    }
};