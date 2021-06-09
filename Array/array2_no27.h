/* LeetCode Array Part

LeetCode 数组刷题。

No.27 -- 移除元素

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。  
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。  
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
*/


// version_0
// 采用暴力解法，时间复杂度 O(n^2)，空间复杂度 O(1)； 执行用时: 0 ms, 内存消耗: 8.5 MB。
// 数组的元素在内存地址中是 **连续的** ，不能单独删除数组中的某个元素，只能覆盖。

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();  // 数组初始大小。
		
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] == val)
            {
                for (int j = i; j < size - 1; ++j)  // 通过移动赋值，删除元素，更新数组。
                {
                    nums[j] = nums[j + 1];
                }
                i --;  // 指针实际后退一位。
                size --;  // 当前有效数组长度。
            }
        }

        return size;
    }
};


// version_1
// 采用暴力解法，时间复杂度 O(n)，空间复杂度 O(1)； 执行用时: 4 ms, 内存消耗: 8.4 MB。

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); ++i)  // nums.size()实际上会在nums改变时更新。
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i);  // 删除元素改变数组 size、不改变数组 capacity。
                i --;
            }
        }

        return nums.size();
    }
};


// version_2
// 采用双指针法解法，时间复杂度 O(n)，空间复杂度 O(1)； 执行用时: 8 ms, 内存消耗: 8.4 MB。
// 双指针法（快慢指针法）：通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowInd = 0;
        for (int fastInd = 0; fastInd < nums.size(); ++fastInd)
        {
            if (nums[fastInd] != val)  // 当不是待删除元素时，更新数组。
            {
                nums[slowInd++] = nums[fastInd];  // slowInd ++，更新慢指针。
            }
        }
		
        return slowInd;
    }
};

