/**
 * @param {string} s
 * @return {string}
 */
var shortestPalindrome = function(s) {
  // 思路
  // 该思路使用 cpp 会超时
  // 1.先将原字符串反转，若一个字符串是回文，反转后还是等于原来的字符串，例如 aba
  // 2.原字符串和反转后的字符串里找到回文中心串的位置
  // 3.反转后的字符串 0 ～ 回文中心串的位置的子字符串添加到原字符串前面，返回正确答案
  const rs = s.split('').reverse().join('') // 1
  const n = s.length

  for (let i = 0; i < n; i++) {
      if (s.slice(0, n - i) === rs.slice(i)) { // 2
          return rs.slice(0, i) + s // 3
      }
  }

  return s
};