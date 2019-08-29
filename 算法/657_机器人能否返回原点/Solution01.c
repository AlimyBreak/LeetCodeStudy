
bool judgeCircle(char * moves)
{
    int  i          = 0;
    int count_lr    = 0;
    int count_ud    = 0;
    while (moves[i])
    {
        switch (moves[i])
        {
            case 'R':
                count_lr++;
            break;
            
            case 'L':
                count_lr--;
            break;

            case 'U':
                count_ud++;
            break;

            case 'D':
                count_ud--;
            break;
            default:
            break;
        }
        i++;
    }
    return ((count_lr==0)&&(count_ud == 0));
}

/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C 提交中击败了90.37% 的用户
内存消耗 :7.2 MB, 在所有 C 提交中击败了74.34%的用户
*/

