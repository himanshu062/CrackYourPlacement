/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || m == n)
            return head;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        for (int i = 0; i < m - 1; ++i)
            prev = prev->next;
        ListNode* tail = prev->next;
        for (int i = 0; i < n - m; ++i) {
            ListNode* cache = tail->next;
            tail->next = cache->next;
            cache->next = prev->next;
            prev->next = cache;
        }
        return dummy.next;
    }
};