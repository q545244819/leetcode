/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var minCameraCover = function(root) {
    let ans = 0;
    // 未被覆盖 0，被覆盖 1，已安置摄像机 2
    function dfs (root) {
        if (root === null) return 1;
        
        let left = dfs(root.left);
        let right = dfs(root.right);

        // 需要安置摄像机到当前的结点
        if (left === 0 || right === 0) {
            ans++;
            return 2;
        }
        // 当前的子节点中有摄像机，所以当前结点已经被覆盖
        if (left === 2 || right === 2) {
            return 1;
        }

        return 0;
    }
    // 根结点没有被观察也需要设置一个摄像机
    if (dfs(root) === 0) {
        ans++;
    }
    return ans;
};