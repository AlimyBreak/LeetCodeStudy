/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode    bhead(0)        ;   /*方便利用bhead.next做返回值*/
        ListNode*   p1      = NULL  ;   /*两个节点的头节点*/
        ListNode*   p2      = NULL  ;   /*两个节点的尾节点*/
        ListNode*   temp    = NULL  ;   /*临时变量,保存当前要交换的两个节点的前驱节点*/
        
        bhead.next      =   head;   
        do
        {
            p1 = bhead.next;
            if (p1 && p1->next)
            {
                p2 = p1->next;
            }
            /*链表只有一个节点或者没有节点,直接返回*/
            else
            {
                break;
            }
            
            
            temp = &bhead;
            while(1)
            {
                temp ->next =   p2          ;   /*修改"头"指针指向*/
                p1->next    =   p2->next    ;   /*交换两个节点*/
                p2->next    =   p1          ;
                temp        =   p1          ;   /*保存下次交换节点的头前节点*/
                p1          =   p1->next    ;
                
                if(p1 == NULL)
                {
                    break;
                }
                else
                {
                    if(p1->next == NULL)
                    {
                        break;
                    }
                    p2 = p1->next;
                }
            }
        }while (0);
        return bhead.next;
    }
};


/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :8.5 MB, 在所有 cpp 提交中击败了89.28%的用户
*/
