// AddTwoNums.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
  struct ListNode {
    int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  class Solution {
  public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
          ListNode* res = new ListNode();
          int first, second;
          int buffer = 0;
          int sum = 0;
          ListNode* prev_node = res;
          ListNode* new_node;
          sum = l1->val + l2->val + buffer;
          prev_node->val = sum % 10;
          buffer = sum / 10;
          l1 = l1->next;
          l2 = l2->next;
          while (l1 || l2) {
              new_node = new ListNode();
              prev_node->next = new_node;
              if (l1 == NULL) {
                  first = 0;
                  second = l2->val;
              }
              else if (l2 == NULL) {
                  second = 0;
                  first = l1->val;
              }
              else {
                  second = l2->val;
                  first = l1->val;
              }
              sum = first + second + buffer;
              new_node->val = sum % 10;
              buffer = sum / 10;
              prev_node = new_node;
              if (l1 != NULL) {
                  l1 = l1->next;
              }
              if (l2 != NULL) {
                  l2 = l2->next;
              }
          }
          if (buffer != 0) {
              prev_node->next = new ListNode(buffer);
          }
          return res;
      }
  };
 
int main()
{
    Solution* sol = new Solution();
    ListNode* l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9,new ListNode(9, new ListNode(9, new ListNode(9, nullptr)))))));
    ListNode* l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, nullptr))));
    ListNode* l3 = sol->addTwoNumbers(l1, l2);
    std::cout << l3->val;
}