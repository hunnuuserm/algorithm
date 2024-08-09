//https://leetcode.cn/problems/linked-list-cycle/

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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, int> m;
        ListNode* cur = head;
        while (cur)
        {
            m[cur]++;
            if (m[cur] > 1) return true;
            cur = cur->next;
        }
        return false;
    }
};

//方法二:快慢指针(空间复杂度O(1))
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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};