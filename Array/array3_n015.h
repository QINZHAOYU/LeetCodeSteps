/* LeetCode Array Part

LeetCode 数组刷题。

No.15 -- 三数之和

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。  
注意：答案中不可以包含重复的三元组。

提示：

+ 0 <= nums.length <= 3000
+ -10^5 <= nums[i] <= 10^5
*/


// version_0
// 采用暴力解法(失败)，时间复杂度 O(n^2)，空间复杂度 O(n)； 执行用时: 超时 ms, 内存消耗: -- MB。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size - 1; ++j)
            {
                int obj = nums[i] + nums[j];
                auto it = find(nums.begin()+j+1, nums.end(), -obj);
                if (it != nums.end())
                {
                    res.push_back(vector<int>{nums[i], nums[j], -obj});
                }
            }
        }
        
        int num = res.size();
        for (int i = 0; i < num ; ++i)
        {
            int maxVal = max({res[i][0], res[i][1], res[i][2]});
            int minVal = min({res[i][0], res[i][1], res[i][2]});

            for (int j = i + 1; j < num ; ++j)
            {
                int  maxVal2 = max({res[j][0], res[j][1], res[j][2]});
                int  minVal2 = min({res[j][0], res[j][1], res[j][2]});

                if (maxVal == maxVal2 && minVal == minVal2)
                {
                    res.erase(res.begin() + j);
                    num  --;
                    j --;
                }
            }
        }
        return res;
    }
};


// version_1
// 采用哈希法，时间复杂度 O(n^2)，空间复杂度 O(n)； 执行用时: 1356 ms, 内存消耗: 262 MB。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());  // 首先排序。

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue;  // 排除a的重复值

            unordered_set<int>  set;
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (j > i + 2 && nums[j-1] == nums[j] && nums[j-2] == nums[j-1])  // 排除b的重复值
                continue;

                int c = nums[i] + nums[j];
                if (set.find(-c) != set.end())
                {
                    result.push_back({nums[i], nums[j], -c});
                    set.erase(-c);  // 排除c的重复值
                }
                else
                {
                    set.insert(nums[j]);
                }
            }
        }

        return result;
    }
};


// verion_2
// 采用双指针法，时间复杂度 O(n^2)，空间复杂度 O(n)； 执行用时: 132 ms, 内存消耗: 19.3 MB。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            // 正确去重方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) 
				{
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) 
				{
                    left++;
                } else 
				{
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};
