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
    ListNode *detectCycle(ListNode *head) 
    {
         //get starting point of loop
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }

            if(fast == slow)
            {
                break;
            }
        }
        if(fast == NULL)
        {
            //no cycle present
            return NULL;
        }
        //yaha pohocha, iska matlb slow and fast meet kr chuke hai
        slow = head;

        //slow and fast move karo 1 step se -> 1 step
        while(fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        //return starting point
        return slow;    
    }
};