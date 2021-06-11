# LeetCode Array Part

LeetCode 数组刷题。


要知道数组的元素在内存地址中是连续的，不能单独删除数组中的某个元素，只能覆盖。


**双指针法**  
双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。


---------------------------------------------------------------

## No.27
```
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。

示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

你不需要考虑数组中超出新长度后面的元素。
```



```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowInd = 0;
        for (int fastInd = 0; fastInd < nums.size(); ++fastInd)
        {
            if (nums[fastInd] != val)
            {
                nums[slowInd++] = nums[fastInd];
            }
        }
        return slowInd;
    }
};
```

---------------------------------------------------------------

## No.26
```

给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

示例 1：
输入：nums = [1,1,2]
输出：2, nums = [1,2]

提示：
0 <= nums.length <= 3 * 104
-10^4 <= nums[i] <= 10^4
nums 已按升序排列
```


执行用时: 8 ms, 内存消耗: 13.2 MB。

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int slowInd = 0;
        for (int fastInd = 1; fastInd < nums.size(); ++fastInd)
        {
            if (nums[fastInd] != nums[slowInd])
            {
                nums[++slowInd] = nums[fastInd];
            }
        }
        return slowInd+1;
    }
};
```

---------------------------------------------------------------

## No.283
```
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]

说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数
```


执行用时: 8 ms,    在所有 C++ 提交中击败了91.35%的用户；
内存消耗: 13.2 MB, 在所有 C++ 提交中击败了52.83%的用户。

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowInd = -1;                                 // 考虑首元素为0的情况。
        for (int fastInd=0; fastInd < nums.size(); ++fastInd)
        {
            if (nums[fastInd] != 0)
            {
                nums[++slowInd] = nums[fastInd];
            }
        }
        for (++slowInd; slowInd < nums.size(); ++slowInd) // slowInd 加1.
        {
            nums[slowInd] = 0;           
        }
    }
};
```


---------------------------------------------------------------

## No.844
```
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空。


示例 1：
输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。

示例 2：
输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。

提示：
1 <= S.length <= 200
1 <= T.length <= 200
S 和 T 只含有小写字母以及字符 '#'。
```


执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了77.69%的用户

```cpp
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        shrinkString(s);
        shrinkString(t);
        if (s.size() != t.size()) return false;

        for (int i=0; i<s.size(); ++i)
        {
            if (s[i] != t[i]) return false;
        }
        return true;
    }

    void shrinkString(string &s)
    {
        string temp;
        for (int i=0; i < s.size(); ++i)
        {
            if (s[i] != '#') // 加载字符
            {
                temp.push_back(s[i]);
            }
            else             // 退格
            {
                if(!temp.empty()) temp.pop_back();  // 防止pop_back()空字符串
            }
        }        
        s = temp;
    }
};
```


---------------------------------------------------------------

## No.977
```
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。


示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]

示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]
 
提示：
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums 已按 非递减顺序 排序
```


执行用时：24 ms, 在所有 C++ 提交中击败了98.23%的用户
内存消耗：25.1 MB, 在所有 C++ 提交中击败了95.08%的用户

```cpp
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> temp(nums.size(), 0);
        int frontInd=0, backInd=nums.size()-1;             // 双指针，从后向前填充元素
        int ind=nums.size()-1;                             // 新数组指针

        while(frontInd <= backInd)
        {
            if (abs(nums[frontInd]) < abs(nums[backInd]))  // 对于正负数组，判断两端最大数
            {
                temp[ind] = pow(nums[backInd],2);
                ind--;
                backInd--;                                 // 更新右端
            }
            else
            {
                temp[ind] = pow(nums[frontInd], 2);
                ind--;
                frontInd++;                                // 更新左端
            }
        }
        return temp;
    }
};
```
---------------------------------------------------------------
