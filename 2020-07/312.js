/**
 * @param {number[]} nums
 * @return {number}
 */
var maxCoins = function(nums) {
  // 首先创建一个前后都有 1 的新数组
  const data = [1, ...nums, 1]
  // dp[i][j] 表示 i ～ j 范围内的最大硬币数量
  const dp = []

  for (let i = 0; i < data.length; i++) {
      dp.push([])
      for (let j = 0; j < data.length; j++) {
          dp[i].push(0)
      }
  }

  for (let i = 2; i < data.length; i++) {
      for (let l = 0; l < data.length - i; l++) {
          let r = l + i
          let res = 0

          for (let k = l + 1; k < r; k++) {
              res = Math.max(res, dp[l][k] + dp[k][r] + data[k] * data[l] * data[r])
          }

          dp[l][r] = res
      }
  }

  return dp[0][data.length - 1]
};