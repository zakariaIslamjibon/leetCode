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
    Node* flatten(Node* head) {

        if (head == NULL)
            return NULL;

        stack<Node*> st;

        Node* curr = head;

        while (curr != NULL)
        {
            if (curr->child != NULL)
            {
                if (curr->next != NULL)
                {
                    st.push(curr->next);
                }

                curr->next = curr->child;
                curr->next->prev = curr;

                curr->child = NULL;
            }

            if (curr->next == NULL && !st.empty())
            {
                curr->next = st.top();
                st.pop();

                curr->next->prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};
