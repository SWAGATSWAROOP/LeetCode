/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    var a = n;
    return function() {
        return a++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */