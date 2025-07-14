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
    int getDecimalValue(ListNode* head) {
        string str="";
        while(head){
            if(head->val==1) str.push_back('1');
            else str.push_back('0');
            head=head->next;
        }
        // cout<<str;
        return stoi(str,nullptr,2);
    }
};