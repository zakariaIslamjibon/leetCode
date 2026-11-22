/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/



class Solution {
public:
    Node* flatten(Node* head, Node* &tail)
    {
        if (head == NULL)
        {
            tail = NULL;
            return NULL;
        }

        Node* curr = head;

        while (curr != NULL)
        {
            Node* next = curr->next;

            if (curr->child != NULL)
            {
                Node* childTail = NULL;

                curr->next = flatten(curr->child, childTail);
                curr->next->prev = curr;

                curr->child = NULL;

                if (next != NULL)
                {
                    childTail->next = next;
                    next->prev = childTail;
                }

                tail = childTail;
            }
            else
            {
                tail = curr;
            }

            curr = next;
        }

        return head;
    }

    Node* flatten(Node* head)
    {
        Node* tail = NULL;

        flatten(head, tail);

        return head;
    }
};
