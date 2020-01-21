class Solution
{
    public:
    int maximum69Number (int num)
    {
        switch(num)
        {
            case 6: 
            case 9: return 9;

            case 66: return 96;
            case 69: 
            case 96: 
            case 99: return 99;

            case 666: return 966;
            case 669: return 969;
            case 696: 
            case 966: return 996;
            case 699: 
            case 969: 
            case 996: 
            case 999: return 999;

            case 6666: return 9666;
            case 6669: return 9669;
            case 6696: return 9696;
            case 6699: return 9699;
            case 6966: 
            case 9666: return 9966;
            case 6969: 
            case 9669: return 9969;
            case 6996: 
            case 9696: 
            case 9966: return 9996;
            case 6999: 
            case 9699: 
            case 9969: 
            case 9996: 
            case 9999: return 9999;
        }
        return 0;
    }
};

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C++ 提交中击败了63.54% 的用户
内存消耗 :8 MB, 在所有 C++ 提交中击败了100.00%的用户
*/