/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    var start = 0,
        maxLen = 0,
        dict = {};
    
    for (var i=0; i<s.length; i++) {
        dict[s[i]] = -1;
    }   
    for (var i=0; i<s.length; i++) {
        if (dict[s[i]] !== -1) {
            while (start <= dict[s[i]]) {
                dict[s[start]] = -1;
                start += 1;
            }
        }
        if (i-start+1 > maxLen) {
           maxLen = i - start + 1;  
        }
        dict[s[i]] = i;
    } 
    return maxLen;
};
