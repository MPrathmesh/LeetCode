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
    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp != NULL) {
            ListNode* front = temp->next;

            temp->next = prev;

            prev = temp;

            temp = front;
        }
        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        //Decrement K as we already
        //start from the 1st node
        k = k - 1;

        //Derement K until it reaches
        //the desired postion
        while(temp != NULL && k > 0) {
            //Decrement k as temp progresses
            k--;

            //move to the next node
            temp = temp->next;
        }
        //Return the Kth Node
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // Initialize a temporary
        // node to traverse the list
        ListNode* temp = head; 

        // Initialize a pointer to track the
        // Last node of the previous group
        ListNode* prevLast = NULL;

        //traverse through the LL
        while(temp != NULL) {
            //Get the kth node of the current group
            ListNode* kThNode = getKthNode(temp, k);

            //If the kth node is NULL
            //(not a complete group)
            if(kThNode == NULL) {
                //If there was a previous group,
                //Link the last node to  the current node
                if(prevLast) {
                    prevLast->next = temp;
                }

                //Exit the loop
                break;
            }

            //store the next node
            //after the Kth node
            ListNode* nextNode = kThNode->next;

            //Discoonect the ktH node
            //to prepare for reversal
            kThNode->next = NULL;

            //Reverse the nodes from
            //temp to the head
            reverseLL(temp);

            //Adjust the head if the reversal starts from the head
            if(temp == head) {
                head = kThNode;
            }
            else {
                //Link the last node of the previous
                //group to the reversed group
                prevLast->next = kThNode;
            }

            //update the pointer to the
            //Last node of the previous group
            prevLast = temp;

            //move to the next group
            temp = nextNode;
        }

        //return the head of the modified linked list
        return head;
    }
};