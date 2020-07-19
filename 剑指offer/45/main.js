/**
 * @param {number[]} nums
 * @return {string}
 */
var minNumber = function(nums) {
  // 比较函数的返回值需要查询 mdn
  // https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Array/sort
  return nums.sort((n, m) => {
      n = n.toString()
      m = m.toString()
      if (m + n < n + m) {
          return 1
      } else if (m + n > n + m) {
          return -1
      } else {
          return 0
      }
  }).join('')
};