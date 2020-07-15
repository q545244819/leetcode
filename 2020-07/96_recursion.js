/**
 * @param {number} n
 * @return {number}
 */
var numTrees = function(n) {
    if (n == 0 || n == 1) {
        return 1
    }
    
    let ans = 0

    for (let i = 0; i < n; i++) {
        ans += numTrees(i) * numTrees(n - 1 - i)
    }

    return ans
};