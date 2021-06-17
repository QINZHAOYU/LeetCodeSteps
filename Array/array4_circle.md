# LeetCode Array Part

LeetCode 数组刷题。

**螺旋排列**

考查对代码的控制能力，以及逻辑清晰度。

---------------------------------------------------------------

## No.56
```
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例:
输入: 3 输出: [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]
```

模拟顺时针画矩阵的过程:

填充上行从左到右
填充右列从上到下
填充下行从右到左
填充左列从下到上
由外向内一圈一圈这么画下去。

可以发现这里的边界条件非常多，在一个循环中，如此多的边界条件，如果不按照固定规则来遍历，那就是一进循环深似海，从此offer是路人。

这也是坚持了每条边左闭右开的原则。
一些同学做这道题目之所以一直写不好，代码越写越乱。
就是因为在画每一条边的时候，一会左开又闭，一会左闭右闭，一会又来左闭右开，岂能不乱。


执行用时：0 ms, 内存消耗：6.5 MB

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n, vector<int>(n, 0));
        int loop = n/2;             // 螺旋圈数
        int offset = 1;             // 每圈边长度控制
        int i, j;         
        int count = 1;              // 递增数
        int startx=0, starty=0;     // 每圈起始位置
        while (loop--)
        {
            i = startx;
            j = starty;

            for (; j < starty + n - offset; ++j)  // 从左往右行填充，不包括拐角处（下同）
                arr[i][j] = count++;
            for (; i < startx + n - offset; ++i)  // 从上往下列填充
                arr[i][j] = count++;
            for (; j > starty; --j)               // 从右往左行填充
                arr[i][j] = count++;
            for (; i > startx; --i)               // 从下往上列填充
                arr[i][j] = count++;

            startx += 1;
            starty += 1;
            offset += 2;                          // +2，左右同时缩减
        }
        if (n % 2)                                // 处理中央元素
        {
            int mid = n/2;
            arr[mid][mid] = count;
        }

        return arr;
    }
};
```


---------------------------------------------------------------

## No.54
```
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
```


执行用时：0 ms, 内存消耗：6.7 MB

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nrow = matrix.size();
        int ncol = matrix[0].size();
        vector<int> arr(nrow*ncol, 0);
        
        int loop = min(nrow, ncol)/2;      // 螺旋圈数
        int startx=0, starty=0;
        int i, j;
        int offset=1;
        int count=0;
        while (loop--)
        {
            i = startx;
            j = starty;
            for (;j < starty + ncol - offset; ++j)        // 左闭右开，下同
                arr[count++] = matrix[i][j];
            for (;i < startx + nrow - offset; ++i)        // 上闭下开，下同
                arr[count++] = matrix[i][j];
            for (;j > starty; --j)
                arr[count++] = matrix[i][j];
            for (;i > startx; --i)
                arr[count++] = matrix[i][j];
            
            startx += 1;
            starty += 1;
            offset += 2;
        }
        if (startx == nrow/2 && count < arr.size())       // 剩余中间行未读取
        {
            for (j = starty ;j <= starty + ncol - offset; ++j)  // 左闭右闭
                arr[count++] = matrix[startx][j];
        }
        else if (starty == ncol/2 && count < arr.size())  // 剩余中间列未读取
        {
            for (i = startx;i <= startx + nrow - offset; ++i)   // 上闭下闭
                arr[count++] = matrix[i][starty];            
        }
        return arr;
    }
};
```

---------------------------------------------------------------
