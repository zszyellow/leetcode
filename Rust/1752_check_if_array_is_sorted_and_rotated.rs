impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let n = nums.len();
        let mut count = 0;
        for i in 0..n {
            if nums[i] > nums[(i + 1) % n] {
                count += 1;
            }
        }

        return count <= 1;
    }
}

// struct Solution {}

// fn main() {
//     assert!(Solution::check(vec![1, 2, 3, 4, 5]));
//     assert!(Solution::check(vec![3, 4, 5, 1, 2]));
//     assert!(!Solution::check(vec![2, 1, 3, 4, 5]));
// }
