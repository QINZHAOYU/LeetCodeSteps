# LeetCode Array Part

LeetCode 链表刷题。

---------------------------------------------------------------

## No.24

```
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]

示例 2：
输入：head = []
输出：[]

提示：
链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100
```

建议使用虚拟头结点，这样会方便很多，要不然每次针对头结点（没有前一个指针指向头结点），还要单独处理。

接下来就是交换相邻两个元素了，**此时一定要画图，不画图，操作多个指针很容易乱，而且要操作的先后顺序。**


时间复杂度：$O(n)$
空间复杂度：$O(1)$


```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *virHead, *pre, *cur;
        virHead = new ListNode(0);
        virHead->next = head;
        pre = virHead;
        cur = head;

        while (cur && cur->next)
        {
            ListNode *temp = cur->next->next;

            pre->next = cur->next;
            cur->next->next = cur;
            cur->next = temp;
            pre = cur;
            cur = temp;
        }

        return virHead->next;
    }
};
```
---------------------------------------------------------------
