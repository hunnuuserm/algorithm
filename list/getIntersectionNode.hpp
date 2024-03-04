//https://leetcode.cn/problems/intersection-of-two-linked-lists/

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