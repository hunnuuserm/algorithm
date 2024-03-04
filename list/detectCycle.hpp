//https://leetcode.cn/problems/linked-list-cycle-ii/submissions/507597151/

//方法一:哈希(空间复杂度O(N))
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_map<ListNode*, int> m;
        ListNode* cur = head;
        while (cur)
        {
            m[cur]++;
            if (m[cur] > 1) return cur;
            cur = cur->next;
        }

        return nullptr;
    }
};

//方法二:转换成链表相交(空间复杂度(1))
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)//相遇
            {
                ListNode* head1 = slow->next;
                slow->next = nullptr;
                ListNode* head2 = head;
                return getIntersectionNode(head1, head2);
            }
        }
        return nullptr;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int countA = 0;
        int countB = 0;
        while (curA)
        {
            countA++;
            curA = curA->next;
        }
        while (curB)
        {
            countB++;
            curB = curB->next;
        }
        ListNode* longList;
        ListNode* shortList;
        int longCount, shortCount;
        if (countA > countB)
        {
            longList = headA;
            shortList = headB;
            longCount = countA;
            shortCount = countB;
        }
        else
        {
            longList = headB;
            shortList = headA;
            longCount = countB;
            shortCount = countA;
        }

        int step = longCount - shortCount;
        while (step--)
        {
            longList = longList->next;
        }

        while (longList)
        {
            if (longList == shortList) return longList;

            longList = longList->next;
            shortList = shortList->next;
        }

        return nullptr;

    }
};