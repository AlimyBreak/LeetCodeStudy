/*
给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false 。
示例 1：
输入： A = "ab", B = "ba"
输出： true
示例 2：
输入： A = "ab", B = "ab"
输出： false
示例 3:
输入： A = "aa", B = "aa"
输出： true
示例 4：
输入： A = "aaaaaaabc", B = "aaaaaaacb"
输出： true
示例 5：
输入： A = "", B = "aa"
输出： false
*/


void swap(char* a, char* b)
{
    char c = *a;
    *a = *b;
    *b = c;
}

bool compareTwoStr(char* A , char* B , int size)
{
    int i = 0;
    bool ret_val = true;
    for(i = 0; i < size;i++)
    {
        if(A[i]!=B[i])
        {
            ret_val = false;
            break;
        }
    }
    
    return ret_val;
}

/*方法1:逐一比较交换情况*/
bool buddyStrings(char* A,char*B)
{
    
    bool ret_val        = false;
    int len_A           = strlen(A);
    int len_B           = strlen(B);
    int i               = 0;
    int j               = 0;
    int no_match_count  = 0;
    int no_match_idx[2] = {0,};
    do
    {
        if(   ( len_A != len_B  )
            ||( len_A < 2       )
            ||( len_B < 2       )
        )
        {
            ret_val = false;
            break; 
        }
        
        for(i = 0; i < len_A;i++)
        {
            if(A[i]!=B[i])
            {
                if(no_match_count<2)
                {
                    no_match_idx[no_match_count] = i;
                    no_match_count++;
                }
                else
                {
                    no_match_count++;
                    break;
                }
            }
        }
        
        
        if(no_match_count==2)
        {
            swap(&A[no_match_idx[0]],&A[no_match_idx[1]]);
            ret_val = compareTwoStr(A,B,len_A);
            break;
        }
        else if (  (no_match_count==1)
                 ||(no_match_count>=3)
         )
        {
            ret_val = false;
            break;
        }
        else /* no_match_count == 0 */
        { /* 逐一遍历交换情况,看是否有满足的情况*/
            for(i = 0; i < len_A;i++)
            {
                for(j = len_B-1; j > i ; j--)
                {
                    swap(&A[i],&A[j]);
                    ret_val = compareTwoStr(A,B,len_A);
                    if(ret_val) /*有满足的情况就连续break两重循环*/
                    {
                        break;
                    }
                    swap(&A[i],&A[j]);
                }
                if(ret_val)
                {
                    break;
                }
            }
        }
    }while(0);
    return ret_val; 
}



/*方法2:检测有无重复元素*/
bool buddyStrings(char* A,char*B)
{
    
    bool ret_val        = false;
    int len_A           = strlen(A);
    int len_B           = strlen(B);
    int i               = 0;
    int j               = 0;
    int no_match_count  = 0;
    int no_match_idx[2] = {0,};
    do
    {
        if(   ( len_A != len_B  )
            ||( len_A < 2       )
            ||( len_B < 2       )
        )
        {
            ret_val = false;
            break; 
        }
        
        for(i = 0; i < len_A;i++)
        {
            if(A[i]!=B[i])
            {
                if(no_match_count<2)
                {
                    no_match_idx[no_match_count] = i;
                    no_match_count++;
                }
                else
                {
                    no_match_count++;
                    break;
                }
            }
        }
        
        
        if(no_match_count==2)
        { // 这里仍可优化
            swap(&A[no_match_idx[0]],&A[no_match_idx[1]]);
            ret_val = compareTwoStr(A,B,len_A);
            break;
        }
        else if(  (no_match_count==1)
                ||(no_match_count>=3)
        )
        {
            ret_val = false;
            break;
        }
        else /* no_match_count == 0 */
        { /* 其实只要检测有无重复元素即可*/
            for(i = 0; i < len_A;i++)
            {
                for(j = len_B-1; j > i ; j--)
                {
                    ret_val = (A[i] == A[j]);
                    if(ret_val)
                    {
                        break;
                    }
                }
                if(ret_val)
                {
                    break;
                }
            }
        }
    }while(0);
    return ret_val; 
}



/*方法3:直接判断对应字符是否相等*/
bool buddyStrings(char* A,char* B)
{
    
    bool ret_val        = false;
    int len_A           = strlen(A);
    int len_B           = strlen(B);
    int i               = 0;
    int j               = 0;
    int no_match_count  = 0;
    int no_match_idx[2] = {0,};
    do
    {
        if(   ( len_A != len_B  )
            ||( len_A < 2       )
            ||( len_B < 2       )
        )
        {
            ret_val = false;
            break; 
        }
        
        for(i = 0; i < len_A;i++)
        {
            if(A[i]!=B[i])
            {
                if(no_match_count<2)
                {
                    no_match_idx[no_match_count] = i;
                    no_match_count++;
                }
                else
                {
                    no_match_count++;
                    break;
                }
            }
        }
        
        if(no_match_count==2)
        { 
            /* 只有两个不相等了*/
            if( (A[no_match_idx[0]]==B[no_match_idx[1]]) 
              &&(A[no_match_idx[1]]==B[no_match_idx[0]]) 
            )
            {
                ret_val = true;
            }
            else
            {
                ret_val = false;
            }
            break;
        }
        else if (  (no_match_count==1)
                 ||(no_match_count==3)
        )
        {
            ret_val = false;
            break;
        }
        else /* no_match_count == 0 */
        { /* 其实只要检测有无重复元素即可*/
            for(i = 0; i < len_A;i++)
            {
                for(j = len_B-1; j > i ; j--)
                {
                    ret_val = (A[i] == A[j]);
                    if(ret_val)
                    {
                        break;
                    }
                }
                if(ret_val)
                {
                    break;
                }
            }
        }
    }while(0);
    return ret_val; 
}



/*
方法1:
执行用时 :12 ms, 在所有 C 提交中击败了23.33%的用户
内存消耗 :7 MB, 在所有 C 提交中击败了39.39%的用户
*/

/*
方法2:
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :7 MB, 在所有 C 提交中击败了39.39%的用户
*/

/*
方法3:
执行用时 :4 ms, 在所有 C 提交中击败了91.67%的用户
内存消耗 :7 MB, 在所有 C 提交中击败了45.45%的用户
*/

/*
理论上方法3
1.不需要对原数组做更改,
2.时间复杂度也应该是最低的(但提交结果貌似不符合.)
*/