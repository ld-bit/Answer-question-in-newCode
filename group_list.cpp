//合并单链表
#include<iostream>
using namespace std;
class Group_List
{
  struct ListNode{
    int _val;
    ListNode* _next;
    ListNode(int  val = 0)
      :_val(val)
       ,_next(nullptr)
    {}
  };
 public:
   ListNode* gp_list(ListNode* root1 , ListNode* root2)
   {
     if(root1==nullptr && root2 == nullptr)
     {
       return nullptr;
     }
     ListNode* newHead = new ListNode;
     ListNode* cur = newHead; 
     while(root1 || root2 )
     {
       if(root1 && root2)
       {
         if(root1 -> _val  < root2 -> _val)
         {
           ListNode* next = root1 -> _next;
           cur->_next=root1;
           root1->_next=nullptr;
           root1 = next;
         }
         else{
           ListNode* next = root2 -> _next;
           cur->_next=root2;
           root2->_next=nullptr;
           root2 = next;
         }
       }
       else if(root1)
       {
           ListNode* next = root1 -> _next;
           cur->_next=root1;
           root1->_next=nullptr;
           root1 = next;
       }
       else if(root2)
       {
           ListNode* next = root2 -> _next;
           cur->_next=root2;
           root2->_next=nullptr;
           root2 = next;
       }
       cur = cur->_next;
     }
     cur = newHead->_next;
     delete newHead;
     return cur;
   }
};
