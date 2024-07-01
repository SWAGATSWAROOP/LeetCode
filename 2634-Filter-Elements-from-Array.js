/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    return arr.reduce((newArr,ele,index) => {
        if(fn(ele,index)){
            newArr.push(ele);
        }
        return newArr;
    },[]);
};