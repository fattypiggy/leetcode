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
#include <iostream>
#include "../Utils/ListNode.h"
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pHead = new ListNode(0), *pTail = pHead;
        int tmp = 0, flag = 0;
        while (l1 && l2)
        {
            tmp = (l1->val + l2->val + flag) % 10;
            flag = (l1->val + l2->val + flag) / 10;
            ListNode *node = new ListNode(tmp);
            l1 = l1->next;
            l2 = l2->next;
            pTail->next = node;
            pTail = pTail->next;
        }
        while (l1)
        {
            tmp = (l1->val + flag) % 10;
            flag = (l1->val + flag) / 10;
            ListNode *node = new ListNode(tmp);
            l1 = l1->next;
            pTail->next = node;
            pTail = pTail->next;
        }
        while (l2)
        {
            tmp = (l2->val + flag) % 10;
            flag = (l2->val + flag) / 10;
            ListNode *node = new ListNode(tmp);
            l2 = l2->next;
            pTail->next = node;
            pTail = pTail->next;
        }
        if (flag)
        {
            ListNode *node = new ListNode(flag);
            pTail->next = node;
        }
        return pHead->next;
    }
};
using namespace std;
int main()
{
    
}