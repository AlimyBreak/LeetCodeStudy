/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * S, int* returnSize)
{
    int  str_len = strlen(S);
    int* ret_val = (int*)malloc((str_len+1)*sizeof(int));
    int  i       = 0;
    int  num_i   = 0;
    int  num_d   = str_len;
    
    *returnSize = str_len+1;
    for(i = 0; i < str_len; i++)
    {
        //switch (S[i])
        //{
        //    case 'I':
        //        ret_val[i] = num_i++;
        //    break;
        //    case 'D':
        //        ret_val[i] = num_d--;
        //    break;        
        //    default:
        //    break;
        //}
        if (S[i]=='I')
        {
            ret_val[i] = num_i++;
        }
        else
        {
            ret_val[i] = num_d--;
        }
    }
    ret_val[str_len] = num_i;/*此时num_i 和 num_d 应该相等*/

    return ret_val;
}

/*
执行结果(switch)：
通过
显示详情
执行用时 :88 ms, 在所有 C 提交中击败了26.60% 的用户
内存消耗 :12.7 MB, 在所有 C 提交中击败了92.31%的用户
*/


/*
执行结果：
通过
显示详情
执行用时 :84 ms, 在所有 C 提交中击败了30.85% 的用户
内存消耗 :12.8 MB, 在所有 C 提交中击败了90.11%的用户
*/