
bool hasAlternatingBits(int n)
{
    switch(n)
    {
        case 0x00000001:
        case 0x00000005:
        case 0x00000015:
        case 0x00000055:
        case 0x00000155:
        case 0x00000555:
        case 0x00001555:
        case 0x00005555:
        case 0x00015555:
        case 0x00055555:
        case 0x00155555:
        case 0x00555555:
        case 0x01555555:
        case 0x05555555:
        case 0x15555555:
        case 0x55555555:
        case 0x00000002:
        case 0x0000000a:
        case 0x0000002a:
        case 0x000000aa:
        case 0x000002aa:
        case 0x00000aaa:
        case 0x00002aaa:
        case 0x0000aaaa:
        case 0x0002aaaa:
        case 0x000aaaaa:
        case 0x002aaaaa:
        case 0x00aaaaaa:
        case 0x02aaaaaa:
        case 0x0aaaaaaa:
        case 0x2aaaaaaa:
        case 0xaaaaaaaa:
            return true;
            break;
        default:
            return false;  
    }    
}

/*
执行结果：
通过
显示详情
执行用时 :4 ms, 在所有 C 提交中击败了69.14% 的用户
内存消耗 :6.6 MB, 在所有 C 提交中击败了92.45%的用户
*/
