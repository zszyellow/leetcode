/*
 * @lc app=leetcode id=702 lang=cpp
 *
 * [702] Search in a Sorted Array of Unknown Size
 */
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int r = 1;
        while (reader.get(r) < target) r = r << 1;
        int l = r >> 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (reader.get(mid) == target) return mid;
            else if (reader.get(mid) > target) r = mid - 1;
            else l = mid + 1;
        }

        return -1;
    }
};

