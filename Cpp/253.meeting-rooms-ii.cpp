/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 *
 * https://leetcode.com/problems/meeting-rooms-ii/description/
 *
 * algorithms
 * Medium (42.03%)
 * Total Accepted:    125.9K
 * Total Submissions: 299.6K
 * Testcase Example:  '[[0,30],[5,10],[15,20]]'
 *
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
 * required.
 * 
 * Example 1:
 * 
 * 
 * Input: [[0, 30],[5, 10],[15, 20]]
 * Output: 2
 * 
 * Example 2:
 * 
 * 
 * Input: [[7,10],[2,4]]
 * Output: 1
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), cmp);
        vector<int> rooms;

        for (int i = 0; i < intervals.size(); i ++) {
            if (rooms.empty()) {
                rooms.push_back(intervals[i].end);
            } else {
                bool flag = false;
                for (int r = 0; r < rooms.size(); r ++) {
                    if (rooms[r] <= intervals[i].start) {
                        flag = true;
                        rooms[r] = intervals[i].end;
                        break;
                    }
                }
                if (!flag) rooms.push_back(intervals[i].end);
            }
        }

        return rooms.size();
    }
    
    static bool cmp(Interval i1, Interval i2) {
        return i1.start < i2.start;
    }
};
