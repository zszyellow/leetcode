/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    var resultHead = new ListNode(0),
        resultNode = resultHead,
        cacheNode = null,
        isBiggerThanTen = 0;
    
    while (isBiggerThanTen || l1!==null || l2!==null) {
        cacheNode = new ListNode(isBiggerThanTen);
        if (l1!==null) {
            cacheNode.val += l1.val; 
            l1 = l1.next;
        }
        if (l2!==null) {
            cacheNode.val += l2.val;
            l2 = l2.next;
        }
        isBiggerThanTen = parseInt(cacheNode.val / 10);
        cacheNode.val %= 10;
        resultNode.next = cacheNode;
        resultNode = resultNode.next;
    }
    return resultHead.next;
};
