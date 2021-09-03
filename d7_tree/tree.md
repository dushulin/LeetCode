递归函数什么时候需要返回值？
- 如果需要搜索整颗二叉树，那么递归函数就不要返回值，如果要搜索其中一条符合条件的路径，递归函数就需要返回值，因为遇到符合条件的路径了就要及时返回。

构造二叉树
- 根据后序和中序构造一个二叉树
https://camo.githubusercontent.com/4ed69d4938c961bfb8b4b53cfafff5a5b3671fc663f120009e4724940974207c/68747470733a2f2f696d672d626c6f672e6373646e696d672e636e2f32303231303230333135343234393836302e706e67


后序遍历就是天然的回溯过程，最先处理的一定是叶子节点。

二叉搜索树：合理利用其特性，中序遍历有序
