# LeetCode Array Part

LeetCode 数组刷题。


二分法是非常重要的基础算法,
主要就是要对对区间的定义理解清楚，在循环中始终坚持根据查找区间的定义来做边界处理。

区间的定义就是不变量，那么在循环中坚持根据查找区间的定义来做边界处理，就是循环不变量规则。

本篇根据两种常见的区间定义，给出了两种二分法的写法，每一个边界为什么这么处理，都根据区间的定义做了详细介绍。

---------------------------------------------------------------

## No.35
```
< 搜索插入位置 >： 

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。  
你可以假设数组中无重复元素。
```


### version_0
采用暴力解法，时间复杂度 O(n)，空间复杂度 O(1)； 执行用时: 8 ms, 内存消耗: 9.3 MB。

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return 0;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (target <= nums[i]) 
            {
                return i;
            }
        }

        if (target < nums[0]) 
        {
            return 0;
        }
        else
        {
            return nums.size();
        }

    }
};
```

### version_1
采用暴力解法，时间复杂度 O(n)，空间复杂度 O(1)； 执行用时: 8 ms, 内存消耗: 9.4 MB。

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (target <= nums[i])
            {
                return i;
            }
        }

        return nums.size();
    }
};
```

### version_2
二分法，时间复杂度 O(logn)，空间复杂度 O(1)； 执行用时: 4 ms, 内存消耗: 9.4 MB。

因为我们面对的时一个**有序无重复的数组**，所以通常可以考虑二分法的思路（如果数组有重复，需要额外处理）。  
在采用二分法处理数组问题时，一是要确定**区间边界**，二是要确定**循环不变式**。

```cpp
target 位于左闭右闭区间。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;

        while (left <= right)  // 这里表明算法可以处理[left, right]区间。
        {
            int middle = left + (right - left)/2;  // 防止(left + right)可能的数值溢出。

            // 搜索方向在左右横跳中逐渐缩小范围，定位目标。
            if (target > nums[middle])
            {
                left = middle + 1;  // 更新左边界。
            }
            else if (target < nums[middle])
            {
                right = middle - 1;  // 更新有边界。
            }
            else
            {
                return middle;  // 相同元素，挤占原有元素位置。
            }
        }
		
	    // 这里要考虑的三种情况：
		// target 位于所有元素之前，[0, -1]；
		// target 位于所有元素之后，[size, size -1]；
		// target 位于数组之中，[left, right]；
        return right + 1;  
    }
};
```

```cpp
// target 位于左闭右开区间。
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0;
        int right = size;  // 右侧为开边界。

        while (left < right)  // right - left >= 1。
        {
            int middle = left + ((right - left) >> 1);  

            if (target > nums[middle])
            {
                left = middle + 1;  // target 在左区间，在[left, middle)中
            }
            else if (target < nums[middle])
            {
                right = middle;  // target 在右区间，在 [middle+1, right)中
            }
            else
            {
                return middle;
            }
        }
		
        // 分别处理如下三种情况:
        // 目标值在数组所有元素之前 [0,0)；
        // 目标值插入数组中的位置 [left, right) ；
        // 目标值在数组所有元素之后的情况 [left, right)；	
        return right;
    }
};
```

---------------------------------------------------------------

## No.704
```
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 
提示：
你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。
```

### version_0
二分查找， 执行用时: 44 ms, 内存消耗: 26.9 MB。

```cpp
// [left, right)， 左闭右开区间。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (true){
            if (right < left) return -1;
            int midd = (left + right)/2;

            if (target == nums[midd]) {
                return midd;
            }
            else if (left == right)
            {
                return -1;
            }
            else if (target < nums[midd]) {
                right = midd;
            } 
            else{
                left = (midd == left)?right:midd;
            }
        }
    }
};
```

### version_1
二分查找， 执行用时: 40 ms, 内存消耗: 26.7 MB。

```cpp
// [left, right)， 左闭右开区间。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right){                    // 判断条件
            int midd = left + (right - left)/2;  // 防溢出计算

            if (target == nums[midd]) {
                return midd;
            }
            else if (target < nums[midd]) {
                right = midd;
            } 
            else{
                left = midd + 1;                // 更新左边界
            }
        }
        return -1;
    }
};
```

```cpp
// [left, right]， 左闭右闭区间。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;  // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) {       // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + ((right - left) / 2);  // 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1;                    // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1;                     // target 在右区间，所以[middle + 1, right]
            } else {                                   // nums[middle] == target
                return middle;                         // 数组中找到目标值，直接返回下标
            }
        }        
        return -1;
    }
};
```

---------------------------------------------------------------

## No.34
```
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。


示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
 

提示：
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums 是一个非递减数组
-10^9 <= target <= 10^9
```

### version_0
采用暴力解法，执行用时: 12 ms, 内存消耗: 13.4 MB

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> indexs;
        for (int i=0; i<nums.size(); ++i)
        {
            if (nums[i] == target)
            indexs.push_back(i);
        }
        if (indexs.empty()) 
            return vector<int>{-1, -1};
        else if (indexs.size() == 1) 
            return vector<int>{indexs[0], indexs[0]};
        else 
            return vector<int>{indexs.front(), indexs.back()};        
    }
};
```

### version_1
采用二分法，执行用时: 12 ms, 内存消耗: 13.4 MB

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0, right=nums.size();
        int start=-1, end=-1;

        while (left < right)
        {
            int midd = left + (right - left)/2;
            if (nums[midd] == target)  
            {
                end = midd;
                left = midd + 1;
            }
            else if (nums[midd] > target)
            {
                right = midd;
            }
            else
            {
                left = midd + 1;
            }
        }
        right = end;
        left = 0;
        while (left < right)
        {
            int midd = left + (right - left)/2;
            if (nums[midd] == target)
            {
                start = midd;
                right = midd;
            }
            else if (nums[midd] > target)
            {
                right = midd;
            }
            else
            {
                left = midd + 1;
            }
        }
        if (end >= 0 && start < 0) 
            start = end;
        return vector<int>{start, end};
    }
};
```

### version_2
采用二分法，执行用时: 8 ms, 内存消耗: 13.3 MB

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);

        if(nums.empty()) 
            return res;
        // 先找左边界
        int n=nums.size(), l=0, r=n-1;
        while(l < r){
            int m = l + (r - l)/2;
            if(nums[m] >= target) 
                r = m;
            else 
                l = m + 1;
        }
        if(nums[l] != target) return res;
        res[0]=l;
        r=n;
        // 再找右边界
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]<=target) l=m+1;
            else r=m;
        }
        res[1]=l-1;
        return res;
    }
};
```

---------------------------------------------------------------

## No.69
```
实现 int sqrt(int x) 函数。计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入: 4
输出: 2

示例 2:
输入: 8
输出: 2
```

采用二分法，执行用时: 0 ms, 内存消耗: 5.6 MB

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        int left=0, right=x;
        while (right - left > 1)  // 区间长度最小为1
        {
            int midd = left + (right - left)/2.0;
            if (x/midd < midd)    // 区间判断，防止数值溢出
            {
                right = midd;
            }
            else
            {
                left = midd;
            }
        }
        return left;
    }
};
```


---------------------------------------------------------------

## No.367

```
给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
 

示例 1：
输入：num = 16
输出：true

示例 2：
输入：num = 14
输出：false
 

提示：
1 <= num <= 2^31 - 1
```

采用二分法，执行用时: 0 ms, 内存消耗: 5.6 MB

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;

        int left=0, right=num;
        while (right - left > 1)
        {
            int midd = left + (right - left)/2;
            if (num/midd < midd) right = midd;
            else if (num/midd > midd) left = midd;
            else           // 判断是否为根
            {
                if (num%midd == 0) return true;
                else return false;
            }
        }
        return false;
    }
};
```

---------------------------------------------------------------