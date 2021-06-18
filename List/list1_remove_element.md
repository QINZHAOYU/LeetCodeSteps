# LeetCode Array Part

LeetCode 链表刷题。


那么因为单链表的特殊性，只能指向下一个节点，刚刚删除的是链表的中第二个，和第四个节点，那么如果删除的是头结点又该怎么办呢？

这里就涉及如下链表操作的两种方式：

1. 直接使用原来的链表来进行删除操作。
2. 设置一个虚拟头结点在进行删除操作。

**方案一**:
移除头结点和移除其他节点的操作是不一样的，因为链表的其他节点都是通过前一个节点来移除当前节点，而头结点没有前一个节点。
所以头结点如何移除呢，其实只要将头结点向后移动一位就可以，这样就从链表中移除了一个头结点。
不要忘了还要从内存中删除这两个移除的节点。

**方案二**：
这里来给链表添加一个虚拟头结点为新的头结点，此时要移除这个旧头结点元素1。
这样是不是就可以使用和移除链表其他节点的方式统一了呢？
来看一下，如何移除元素1 呢，还是熟悉的方式，然后从内存中删除元素1。
最后呢在题目中，return 头结点的时候，别忘了 return dummyNode->next;， 这才是新的头结点。
不要忘了还要从内存中删除这两个移除的节点。

---------------------------------------------------------------

## No.203
```
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]

示例 2：
输入：head = [], val = 1
输出：[]

示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]
```


执行用时：28 ms, 内存消耗：14.7 MB

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}                    // 结构体的构造函数，实现初始化赋值
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* virNode = new ListNode(0, head);   // 初始化赋值，new 开辟内存返回地址
        ListNode* node = virNode;                    // 当前节点
        while (node->next != nullptr)
        {
            ListNode* temp = node->next; 
            if (temp->val == val)
            {
                node->next = temp->next;             // 链表中移除节点
                delete temp;                         // 删除节点，防止内存泄漏
            }
            else                                     // else, 否则会导致node->next更新两次，循环中漏掉元素
            {
                node = node->next;
            }
        }
        
        head = virNode->next;
        delete virNode;                              // 防止内存泄漏
        return head;
    }
};
```

---------------------------------------------------------------