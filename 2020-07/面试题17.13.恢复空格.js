/**
 * @param {string[]} dictionary
 * @param {string} sentence
 * @return {number}
 */
var respace = function(dictionary, sentence) {
  // dp[i] 表示从 0 到 i 结尾的最短未识别数量
  const dp = (new Array(sentence.length + 1)).fill(0)
  const sset = new Set(dictionary)
  
  for (let i = 1; i <= sentence.length; i++) {
      // 默认加入该字符也会产生一个未识别字符串
      // 从 dp[i - 1] 扩展
      dp[i] = dp[i - 1] + 1
      for (let j = 0; j < i; j++) {
          // 若在 j - i 范围的字符串是在字典里的
          // 那么选择 dp[i] 或 dp[j] 小的那个
          if (sset.has(sentence.substring(j, i))) {
              dp[i] = Math.min(dp[i], dp[j])
          }
      }
  }
  
  return dp[sentence.length]
};