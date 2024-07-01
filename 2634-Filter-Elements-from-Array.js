/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let newArr = arr.filter((ele,index) => fn(ele,index))
    return newArr;
};