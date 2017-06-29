#include <stdio.h>
#include <stdlib.h>
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *ret;
    ListNode *l3;
    int duoyu = 0;
    while(l1!=NULL && l2 !=NULL){
      int x = l1->val + l2->val + duoyu;
      if(x>10){
        x = x-10;
        duoyu = 1;
      }else{
        duoyu = 0;     
         
      }
      ListNode *tmp = new ListNode(x);
      if(l3==NULL){
        l3 = tmp;
        ret = l3;
      }else{
        l3->next = tmp;
        l3 = tmp;
      }
      l1 = l1->next;
      l2 = l2->next;
    }
    
    return ret;
  }
};
int main(){

}
