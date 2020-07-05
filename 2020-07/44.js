/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function(s, p) {
  const dp = []

  for (let i = 0; i <= s.length; i++) {
      dp.push([])
      for (let j = 0; j <= p.length; j++) {
          dp[i][j] = -1
      }
  }

  function match (i, j) {
      if (i >= s.length && j >= p.length) {
          return dp[i][j] = 1
      }
      if (j >= p.length) {
          return dp[i][j] = 0
      }
      if (dp[i][j] != -1) {
          return dp[i][j]
      }

      if (p[j] == '*') {
          if (i < s.length) {
              return dp[i][j] = match(i + 1, j) || match(i + 1, j + 1) || match(i, j + 1)
          } else {
              return dp[i][j] = match(i, j + 1)
          }
      }

      if (s[i] == p[j] || (i < s.length && p[j] == '?')) {
          return dp[i][j] = match(i + 1, j + 1)
      }

      return dp[i][j] == 0
  }
  
  return !!match(0, 0)
};