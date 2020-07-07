/**
 * initialize your data structure here.
 */
var MedianFinder = function() {
  this.data = []
};

/** 
* @param {number} num
* @return {void}
*/
MedianFinder.prototype.addNum = function(num) {
  this.data.push(num)
};

/**
* @return {number}
*/
MedianFinder.prototype.findMedian = function() {
  let n = this.data.length
  let ans = 0

  let index = partition(this.data, 0, n - 1)
  
  if ((n & 1) == 0) {
      let p1 = Math.floor(n / 2) - 1, p2 = Math.floor(n / 2)
      let l = 0, r = n - 1, index = partition(this.data, l, r)

      while (index != p1) {
          if (index > p1) {
              r = index - 1
          } else {
              l = index + 1
          }
          index = partition(this.data, l, r)
      }

      l = 0
      r = n - 1
      index = partition(this.data, l, r)

      while (index != p2) {
          if (index > p2) {
              r = index - 1
          } else {
              l = index + 1
          }
          index = partition(this.data, l, r)
      }

      ans = (this.data[p1] + this.data[p2]) / 2
  } else {
      let l = 0, r = n - 1, mid = Math.floor(n / 2), index = partition(this.data, l, r)

      while (index != mid) {
          if (index > mid) {
              r = index - 1
          } else {
              l = index + 1
          }
          index = partition(this.data, l, r)
      }

      ans = this.data[mid]
  }

  return ans
};

function partition (data, l, r) {
  let index = Math.floor((l + r) / 2)
  let small = l

  ;[data[index], data[r]] = [data[r], data[index]]

  for (index = l; index < r; index++) {
      if (data[index] < data[r]) {
          [data[index], data[small]] = [data[small], data[index]]
          small++
      }
  }

  ;[data[small], data[r]] = [data[r], data[small]]
  
  return small
}

/**
* Your MedianFinder object will be instantiated and called as such:
* var obj = new MedianFinder()
* obj.addNum(num)
* var param_2 = obj.findMedian()
*/