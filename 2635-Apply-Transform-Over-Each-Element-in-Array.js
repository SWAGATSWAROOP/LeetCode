/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let newArray = arr.map((i,index) => fn(i,index));
    return newArray;
};