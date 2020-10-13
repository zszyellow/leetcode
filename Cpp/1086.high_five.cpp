class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        vector<vector<int>> res;
        map<int, priority_queue<int>> student_scores;
        for (int i = 0; i < items.size(); i ++) {
            if (student_scores.find(items[i][0]) == student_scores.end()) {
                priority_queue<int> pq;
                pq.push(items[i][1]);
                student_scores[items[i][0]] = pq;
            } else {
              student_scores[items[i][0]].push(items[i][1]);  
            }
        }
        
        for (const auto& pair : student_scores) {
            vector<int> average;
            average.push_back(pair.first);
            priority_queue<int> scores = pair.second;
            int sum = 0;
            for (int i = 0; i < 5; i ++) {
                sum += scores.top();
                scores.pop();
            }
            average.push_back(sum / 5);
            res.push_back(average);
        }
        
        return res;
    }
};