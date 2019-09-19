class Solution
{
    public:
        string complexNumberMultiply(string a, string b)
        {
            int a1;
            int b1;
            int a2;
            int b2;
            sscanf(a.c_str(),"%d+%di",&a1,&b1);
            sscanf(b.c_str(),"%d+%di",&a2,&b2);
            return string( to_string(a1*a2-b1*b2) + "+" + to_string(a1*b2+a2*b1) + "i");
        
        }
};


/*
执行结果：
通过
显示详情
执行用时 :8 ms, 在所有 C++ 提交中击败了25.00% 的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了53.09%的用户
*/