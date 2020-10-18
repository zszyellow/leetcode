class Logger {
private:
    unordered_map<string, int> hash_map;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        bool res = true;
        if (this->hash_map.find(message) == this->hash_map.end()) {
            this->hash_map[message] = timestamp;
        } else if (this->hash_map[message] <= timestamp - 10) {
            this->hash_map[message] = timestamp; 
        } else {
            res = false;
        }
        return res;
    }
};

/* Using queue and set */
// class Logger {
// private:
//     queue<pair<string, int>> msg_q;
//     unordered_set<string> hash_set;
// public:
//     /** Initialize your data structure here. */
//     Logger() {
        
//     }
    
//     /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
//         If this method returns false, the message will not be printed.
//         The timestamp is in seconds granularity. */
//     bool shouldPrintMessage(int timestamp, string message) {
//         bool res = true;
//         while (!this->msg_q.empty() && this->msg_q.front().second <= timestamp-10) {
//             this->hash_set.erase(this->msg_q.front().first);
//             this->msg_q.pop();
//         }

//         if (this->hash_set.find(message) != this->hash_set.end()) {
//             res = false;
//         } else {
//             this->msg_q.push(make_pair(message, timestamp));
//             this->hash_set.insert(message);
//         }
//         return res;
//     }
// };


/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */