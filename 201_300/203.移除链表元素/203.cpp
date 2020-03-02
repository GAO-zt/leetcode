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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* header = new ListNode(-1);
        header->next = head;        
        ListNode* currNode = header;  
        while(currNode != NULL && currNode->next != NULL) {
           if (currNode->next->val == val) {
                currNode->next = currNode->next->next;         
            }            
            else {
                currNode = currNode->next; 
            }
        }
        return header->next;   
    }
};



          