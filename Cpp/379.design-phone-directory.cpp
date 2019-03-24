/*
 * @lc app=leetcode id=379 lang=cpp
 *
 * [379] Design Phone Directory
 *
 * https://leetcode.com/problems/design-phone-directory/description/
 *
 * algorithms
 * Medium (40.21%)
 * Total Accepted:    21.4K
 * Total Submissions: 53.3K
 * Testcase Example:  '["PhoneDirectory","get","get","check","get","check","release","check"]\n[[3],[],[],[2],[],[2],[2],[2]]'
 *
 * Design a Phone Directory which supports the following operations:
 * 
 * 
 * 
 * get: Provide a number which is not assigned to anyone.
 * check: Check if a number is available or not.
 * release: Recycle or release a number.
 * 
 * 
 * 
 * Example:
 * 
 * // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
 * PhoneDirectory directory = new PhoneDirectory(3);
 * 
 * // It can return any available phone number. Here we assume it returns 0.
 * directory.get();
 * 
 * // Assume it returns 1.
 * directory.get();
 * 
 * // The number 2 is available, so return true.
 * directory.check(2);
 * 
 * // It returns 2, the only number that is left.
 * directory.get();
 * 
 * // The number 2 is no longer available, so return false.
 * directory.check(2);
 * 
 * // Release number 2 back to the pool.
 * directory.release(2);
 * 
 * // Number 2 is available again, return true.
 * directory.check(2);
 * 
 * 
 */
class PhoneDirectory {
private:
    vector<int> directory_list;
    vector<bool> status_list;
    int index;
    int count;

public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) : index(0), count(maxNumbers), directory_list(maxNumbers), status_list(maxNumbers, true) {
        for (int i = 0; i < maxNumbers; i ++) directory_list[i] = i;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        int n = -1;
        if (index < count) {
            n = directory_list[index++];
            status_list[n] = false;
        }
        return n;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number < 0 || number >= count) return false;
        return status_list[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (number < 0 || number >= count || status_list[number])  return;
        directory_list[--index] = number;
        status_list[number] = true;   
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

