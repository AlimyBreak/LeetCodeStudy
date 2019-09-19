
char    ret_val[20];
char*   complexNumberMultiply(char * a, char * b)
{    
    int a1  =   0;
    int b1  =   0;
    int a2  =   0;
    int b2  =   0;
    int a3  =   0;
    int b3  =   0;
    
    sscanf(a,"%d+%di",&a1,&b1);
    sscanf(b,"%d+%di",&a2,&b2);
    a3 = a1*a2-b1*b2;
    b3 = a1*b2+a2*b1;
    memset(ret_val,0,20*sizeof(char));
    sprintf(ret_val,"%d+%di",a3,b3);
    return ret_val;
}

/*
执行结果：
通过
显示详情
执行用时 :0 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :6.8 MB, 在所有 C 提交中击败了77.78%的用户
*/
