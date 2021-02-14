impl Solution {
    pub fn decode(encoded: Vec<i32>, first: i32) -> Vec<i32> {
        let mut cur = first;
        let mut res = vec![first];
        for val in encoded {
            let tmp = cur ^ val;
            res.push(tmp);
            cur = tmp;
        }
        return res;
    }
}

// struct Solution {}

// fn main() {
//     assert!(Solution::decode(vec![1, 2, 3], 1)
//         .iter()
//         .eq(vec![1, 0, 2, 1].iter()));
//     assert!(Solution::decode(vec![6, 2, 7, 3], 4)
//         .iter()
//         .eq(vec![4, 2, 0, 7, 4].iter()));
// }
