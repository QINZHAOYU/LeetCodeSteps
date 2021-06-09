/* LeetCode Array Part

LeetCode 数组刷题。

No.35 -- 搜索插入位置： 

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。  
你可以假设数组中无重复元素。

*/




// version_0
// 采用暴力解法，时间复杂度 O(n)，空间复杂度 O(1)； 执行用时: 8 ms, 内存消耗: 9.3 MB。

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


// version_1
// 采用暴力解法，时间复杂度 O(n)，空间复杂度 O(1)； 执行用时: 8 ms, 内存消耗: 9.4 MB。

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


// version_2
// 二分法，时间复杂度 O(logn)，空间复杂度 O(1)； 执行用时: 4 ms, 内存消耗: 9.4 MB。
/*
因为我们面对的时一个**有序无重复的数组**，所以通常可以考虑二分法的思路（如果数组有重复，需要额外处理）。  
在采用二分法处理数组问题时，一是要确定**区间边界**，二是要确定**循环不变式**。
*/


// target 位于左闭右闭区间。
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