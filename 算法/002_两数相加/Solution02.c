/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers( struct ListNode* l1 ,
                                struct ListNode* l2
                              )
{

    struct ListNode     head            =   {0,NULL}    ;
    struct ListNode*    tail_node       =   NULL        ;
    struct ListNode*    temp            =   NULL        ;
    int                 carry_flag      =   0           ;
    int                 state_words     =   0           ;
    
    head.next    = NULL; 
    tail_node    = &head;
    
    state_words  = (l1!=NULL)? 1 : 0;
    state_words += (l2!=NULL)? 2 : 0;     
    while(state_words)
    {
        temp            =   (struct ListNode*)malloc(sizeof(struct ListNode))       ;
        temp->next      =   NULL                                                    ;
        switch(state_words)
        {
            // (l1 != NULL) && (l2 == NULL)
            case 1: 
                temp->val       =   l1->val + carry_flag            ;
                l1              =   l1->next                        ;
            break;
            // (l1 == NULL) && (l2 != NULL)
            case 2: 
                temp->val       =   l2->val + carry_flag            ;
                l2              =   l2->next                        ;
            break;
            // (l1 != NULL ) && (l2 != NULL)
            case 3: 
                temp->val       =   l1->val + l2->val + carry_flag  ;
                l1              =   l1->next                        ;
                l2              =   l2->next                        ;
            break;
             // case 0: (l1 == NULL) && (l2 == NULL)
            default:
            break;
        } 
        
        carry_flag      =   temp->val / 10                                      ;
        temp->val       %=  10                                                  ;       
        
        tail_node->next =   temp;
        tail_node       =   temp;
            
        state_words     =   (l1!=NULL)? 1 : 0;
        state_words     +=  (l2!=NULL)? 2 : 0;   
    }
    
    if(carry_flag !=0)
    {
        temp            =   (struct ListNode*)malloc(sizeof(struct ListNode))       ;
        temp->next      =   NULL                                                    ; 
        temp->val       =   1                                                       ;
        tail_node->next =   temp                                                    ;
        tail_node       =   temp                                                    ;
    }
    
    return head.next;
}


/*
执行结果：
通过
显示详情
执行用时 :36 ms, 在所有 C 提交中击败了11.83% 的用户
内存消耗 :8.8 MB, 在所有 C 提交中击败了95.33%的用户
*/
