/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
  const n = triangle.length
  if (n == 0) {
      return 0
  }
  if (n == 1) {
      return triangle[0][0]
  }

  const max = 2 << 21
  let dp = [triangle[0][0], max]
  let temp = []

  for (let i = 1; i < n; i++) {
      temp = [...dp, max]
      for (let j = 0; j < triangle[i].length; j++) {
          if (j - 1 >= 0) {
              dp[j] = Math.min(temp[j] + triangle[i][j], temp[j - 1] + triangle[i][j])
          } else {
              dp[j] = temp[j] + triangle[i][j]
          }
      }
  }

  return Math.min(...dp)
};