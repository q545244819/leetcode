/**
 * @param {number[]} A
 * @return {number}
 */
var largestPerimeter = function (A) {
  const n = A.length;

  if (n === 0) return 0;

  A.sort((a, b) => b - a);

  let ans = 0;

  for (let i = 0; i < n; i++) {
    let l = i + 1,
      r = n - 1;
    while (l < r && A[i] >= A[l] + A[r]) r--;
    while (l < r) ans = Math.max(ans, A[i] + A[l] + A[r--]);
  }

  return ans;
};
