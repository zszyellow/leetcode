/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array 
 */

class SnapshotArray {
private:
    vector<vector<pair<int,int>>> arr;
    int cur_snap_id;
    
public:
    SnapshotArray(int length) {
        arr.resize(length);
        for (int i = 0; i < length; i ++) {
            arr[i].push_back(make_pair(-1, 0));
        }
        cur_snap_id = 0;
    }
    
    void set(int index, int val) {
        arr[index].push_back(pair<int, int>(cur_snap_id, val));
    }
    
    int snap() {
        cur_snap_id ++;
        return cur_snap_id - 1;
    }
    
    int get(int index, int snap_id) {
        auto& v = arr[index];
        int i = lower_bound(v.begin(), v.end(), make_pair(snap_id+1, 0)) - v.begin();
        return v[i-1].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
