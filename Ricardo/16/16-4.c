#include <stdio.h>
#define MAX_LENGTH 110

int main()
{
    char result[10][10];
    int number = 0;
    FILE* fp = fopen("dict.dic", "r");

    for(size_t i = 0; i < 10; i++)
    {
        char* temp = fgets(result[i], 10, fp);
        if(temp == NULL)
        {
            break;
        }
        number++;
        char* p = result[i];
        for(;;)
        {
            if(*p == '\n')
            {
                *p = '\0';
                break;
            }
            p++;
        }
    }

    for(;;)
    {
        char string[MAX_LENGTH];
        char *what;
        what = fgets(string, MAX_LENGTH, stdin);
        if(what == NULL)
        {
            break;
        }
        for(size_t i = 0; string[i] != '\0'; i++)
        {
            for(size_t j = 0; j < number; j++)
            {
                int flag = 0;
                int length = 0;
                int temp = i;
                for(size_t k = 0; k < 10; k++)
                {
                    if(result[j][k] == '\0')
                    {
                        break;
                    }
                    length++;
                    if(string[temp] == result[j][k])
                    {
                        temp++;
                        flag = 1;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                {
                    printf("!@#$%%^&*");
                    i = i + length - 1;//这里注意循环还有一次自增
                    break;
                }
                if(j == number - 1)//到达这个地方说明没有一个敏感词被匹配
                {
                    printf("%c", string[i]);
                }
            }
        }
    }

    return 0;
}