# LeetCode Array Part

LeetCode 数组刷题。

**滑动窗口:**

所谓滑动窗口，就是不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果

---------------------------------------------------------------

## No.209
```
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
 
提示：
1 <= target <= 10^9
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^5
```

其实可以发现滑动窗口也可以理解为双指针法的一种！只不过这种解法更像是一个窗口的移动，所以叫做滑动窗口更适合一些。
在本题中实现滑动窗口，主要确定如下三点：

窗口内是什么？
如何移动窗口的起始位置？
如何移动窗口的结束位置？
窗口就是 满足其和 ≥ s 的长度最小的 连续 子数组。

窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。
窗口的结束位置如何移动：窗口的结束位置就是遍历数组的指针，窗口的起始位置设置为数组的起始位置就可以了。


执行用时：8 ms, 内存消耗：10.3 MB;时间复杂度：O(n)， 空间复杂度：O(1)。

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT32_MAX;                // 没有INT64_MAX...
        int sum = 0;
        int len = 0;
        int left= 0;
        for (int right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];             // 窗口内数组和
            while (sum >= target)           // 窗口内数组是否满足要求
            {
                len = right - left + 1;     // 窗口长度
                res = (res > len)?len:res;  // 是否更短
                sum -= nums[left++];        // 精髓，移动窗口左端并修改窗口数组和
            }
        }

        res = (res == INT32_MAX)?0:res;     // 判断
        return res;
    }
};
```

---------------------------------------------------------------

## No.904
```
在一排树中，第 i 棵树产生 tree[i] 型的水果。你可以从你选择的任何树开始，然后重复执行以下步骤：

  1. 把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
  2. 移动到当前树右侧的下一棵树。如果右边没有树，就停下来。

请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。

你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
用这个程序你能收集的水果树的最大总量是多少？
 

示例 1：
输入：[1,2,1]
输出：3

示例 2：
输入：[0,1,2,2]
输出：3
解释：我们可以收集 [1,2,2]
如果我们从第一棵树开始，我们将只能收集到 [0, 1]。

示例 3：
输入：[1,2,3,2,2]
输出：4
解释：我们可以收集 [2,3,2,2]
如果我们从第一棵树开始，我们将只能收集到 [1, 2]。


提示：
1 <= tree.length <= 40000
0 <= tree[i] < tree.length
```

---------------------------------------------------------------

## No.76
```
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

示例 2：
输入：s = "a", t = "a"
输出："a"
 
提示：
1 <= s.length, t.length <= 10^5
s 和 t 由英文字母组成
```

1. 注意到题目的关键："所有字母的最小子串"，也就是说两个串都只能是字母。
2. 于是，可以开辟一个大小为64的数组，来存放数组中字母的频率(Frequency)。准确的说，
   通过字母的ASCII码作为数组的索引，开辟空间的大小为26+6+26=58：26个大写字母，26个小写字母，
   还有中间的6个非字母  A~Z[65~90]  非字母[91~96]  a~z[97~122]
3. 滑动窗口的使用：分三种情况来移动窗口：（这里令当前窗口的左右边界分别为l，r，窗口的大小为winSize=r-l+1）
   1) 当winSize < t.size()  r++;  也就是窗口右边界向右移动
   2) 当winSize == t.size() :
	   2.1) 当窗口中的字符已经符合要求了，直接返回return，已经找到了
	   2.2) 否则r++，窗口右边界向右移动
   3) 当winSize > t.size()
	   3.1) 当窗口中的字符已经符合要求了，l++，窗口左边界向右移动
	   3.2) 否则r++，窗口右边界向右移动
4. 上面是滑动窗口的使用思路，具体实现上有一定的不同，下面是需要考虑到的要点：
   1) 啥叫作窗口中的字符已经符合要求了？
   2) 窗口滑动时的操作是关键
   3) 要考虑到数组越界的问题


```cpp
class Solution {
public:
    string minWindow(string s, string t) {
    if (s.size() < t.size()) return "";

	int sFreq[64] = { 0 }, tFreq[64] = { 0 };  // frequency数组
	for (int i = 0; i < t.size(); i++) tFreq[t[i] - 'A']++;

	int l = 0, r = -1;
    int edge[2];                              // edge数组表示要求的串的左右边界
    edge[0] = -1;
    edge[1] = s.size()+1;
	while (l <= s.size() - t.size()) {

		// < t.size()  直接窗口右边界右移，循环continue
		if (r - l + 1 < t.size()) {
			if (r + 1 < s.size()) {           // 这里注意到数组越界
				sFreq[s[++r] - 'A']++; continue;
			}
			else break;
		}

		// >= t.size() 先判断当前窗口中的字符是否满足“题目要求”
		int i = 0;
		while (i < 64) {
			if (sFreq[i] < tFreq[i]) break;
			i++;
		}
		if (i < 64) {
                        
			if (r + 1 < s.size()) sFreq[s[++r] - 'A']++; // 这里注意到数组越界
			else sFreq[s[l++] - 'A']--;
		}
		else {
			if (r - l + 1 == t.size()) return string(s.begin() + l, s.begin() + r + 1); 
			else {
				if (r - l < edge[1] - edge[0]) {
					edge[0] = l;
					edge[1] = r;
				}
				sFreq[s[l++] - 'A']--;
			}
		}
	}
	return edge[0] == -1 ? "" : string(s.begin() + edge[0], s.begin() + edge[1] + 1);
    }
};
```

---------------------------------------------------------------