# LeetCode Array Part

LeetCode 链表刷题。

---------------------------------------------------------------

## 

```
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？

示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

```
双指针的经典应用，如果要删除倒数第n个节点，让fast移动n步，然后让fast和slow同时移动，直到fast指向链表末尾。
删掉slow所指向的节点就可以了。
fast首先走n + 1步 ，为什么是n+1呢，因为只有这样同时移动的时候slow才能指向删除节点的上一个节点（方便做删除操作）。
fast和slow同时移动，之道fast指向末尾。
删除slow指向的下一个节点。

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;

        ListNode *fast, *slow, *virHead;
        virHead = new ListNode(0);
        virHead->next = head;
        fast = virHead;
        slow = virHead;
        while (n-- && fast)
        {
            fast = fast->next;
        }
        fast = fast->next;   // n+1 节点
        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        delete fast;
        return virHead->next;
    }
};
```

---------------------------------------------------------------
