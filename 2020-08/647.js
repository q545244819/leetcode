/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
  // 暴力法
  let ans = 0
  let book = []

  for (let i = 0; i < s.length; i++) {
      book.push((new Array(s.length)).fill(false))
  }

  function dfs (l, r) {
      //console.log(l, r, book[l][r], ans)
      if (book[l][r]) {
          return
      }
      book[l][r] = true
      if (l == r) {
          ans++
          return
      }
      ans += check(l, r)
      const k = r - l - 1
      for (let i = l; i + k <= r; i++) {
          dfs(i, i + k)
      }
  }

  function check (l, r) {
      while (l < r) {
          if (s[l] === s[r]) {
              l++;
              r--;
          } else {
              return 0
          }
      }

      return 1
  }

  dfs(0, s.length - 1)

  return ans
};