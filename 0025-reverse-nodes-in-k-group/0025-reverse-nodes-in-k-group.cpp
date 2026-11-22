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
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        int cou = 0;

        while (cou < k)
        {
            if (temp == NULL)
            {
                return head;
            }

            temp = temp->next;
            cou++;
        }

        ListNode* newNode = reverseKGroup(temp, k);

        temp = head;
        cou = 0;

        while (cou < k)
        {
            ListNode* next = temp->next;
            temp->next = newNode;
            newNode = temp;
            temp = next;
            cou++;
        }

        return newNode;
    }
};
