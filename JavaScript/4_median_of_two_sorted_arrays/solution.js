/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function(nums1, nums2) {
    function sortNumber(a,b){
        return a - b;
    }

    var nums3 = nums1.concat(nums2).sort(sortNumber),
        m = nums1.length,
        n = nums2.length,
        flag = (m+n) % 2 === 0;
    if (flag) {
        return (nums3[(m+n)/2]+nums3[(m+n)/2-1])/2;
    } else {
        return (nums3[parseInt((m+n)/2)]);
    }
};
