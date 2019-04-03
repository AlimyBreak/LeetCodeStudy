char* toLowerCase(char* str)
{
    char* head = str;
    while(*str)
    {
        switch(*str)
        {
            case 'A':
                *str = 'a';
            break;
            case 'B':
                *str = 'b';
            break;
            case 'C':
                *str = 'c';
            break;
            case 'C':
                *str = 'c';
            break;
            case 'D':
                *str = 'd';
            break;
            case 'E':
                *str = 'e';
            break;
            case 'F':
                *str = 'f';
            break;
            case 'G':
                *str = 'g';
            break;
            case 'H':
                *str = 'h';
            break;
            case 'I':
                *str = 'i';
            break;
            case 'J':
                *str = 'j';
            break;
            case 'K':
                *str = 'k';
            break;
            case 'L':
                *str = 'l';
            break;
            case 'M':
                *str = 'm';
            break;
            case 'N':
                *str = 'n';
            break;
            case 'O':
                *str = 'o';
            break;
            case 'P':
                *str = 'p';
            break;
            case 'Q':
                *str = 'q';
            break;
            case 'R':
                *str = 'r';
            break;
            case 'S':
                *str = 's';
            break;
            case 'T':
                *str = 't';
            break;
            case 'U':
                *str = 'u';
            break;
            case 'V':
                *str = 'v';
            break;
            case 'W':
                *str = 'w';
            break;
            case 'X':
                *str = 'x';
            break;                
            case 'Y':
                *str = 'y';
            break;
            case 'X':
                *str = 'z';                
            break;
            default:
            break;
            
        }
        str++;
    }
    return head;   
}