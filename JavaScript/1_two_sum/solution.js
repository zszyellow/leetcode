/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(numbers, target) {
    var map = {},
        i,
        length = numbers.length,
        value,
        neededValue,
        result = [];
        
    for(i = 0; i < length; i++) {
        value = numbers[i];
        neededValue = target - value;
        if (neededValue in map) {
            result.push(map[neededValue] + 1);
            result.push(i + 1);
            break;
        } else {
            map[value] = i;
        }
    }
    return result;
};
