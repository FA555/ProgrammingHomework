#include <stdio.h>

/**
 * @brief 将文件指针跳转到指定的行数
 * 
 * @param fp 文件指针
 * @param lineNumber 欲跳转的行数
 */
void jump(FILE *fp, int lineNumber)
{
    /**
     * @brief 应当读取到的'\n'个数
     * 
     */
    int nNumber = lineNumber - 1;
    int number = 0;
    for(;;)
    {
        char temp = fgetc(fp);
        if(temp == '\n')
        {
            number++;
            if(number == nNumber)
            {
                break;
            }
        }else if(temp == EOF)
        {
            return;
        }
    }
}

int main()
{
    int lineNumber[5];
    int input, begin, end;
    int nNumber = 0;


    FILE *fp = fopen("dict.dic", "r");
    for(size_t i = 0; i < 5; i++)
    {
        fscanf(fp, "%d\n", &lineNumber[i]);
    }
    fclose(fp);
    fp = fopen("dict.dic", "r");

    scanf("%d", &input);
    if(input == 1)
    {
        begin = 6;
        end = lineNumber[0];
    }
    else
    {
        begin = lineNumber[input - 2] + 1;
        end = lineNumber[input - 1];
    }

    jump(fp, begin);
    nNumber = begin - 1;

    char temp1, temp2;
    /**
     * @brief 发现//的flag
     * 
     */
    int flag1 = 0;
    /**
     * @brief 发现多行注释的flag
     * 
     */
    int flag2 = 0;
    temp1 = fgetc(fp);
    temp2 = fgetc(fp);
    for(;;)
    {
        if(temp1 == '\n' || temp1 == EOF)
        {
            if(flag1 == 1)//在发现换行符的时候结束单行注释
            {
                flag1 = 0;
            }
            nNumber++;
            if(nNumber == end)
            {
                if(temp1 != EOF)
                {
                    printf("%c", temp1);
                }
                break;
            }
        }
        if(flag1 == 0 && flag2 == 0)
        {
            if(temp1 == '/')
            {
                if(temp2 == '/')
                {
                    flag1 = 1;
                }
                else if(temp2 == '*')
                {
                    flag2 = 1;
                }
            }
        }
        if(temp1 == '*' && temp2 == '/' && flag2 == 1)//结束多行注释
        {
            flag2 = 0;
            temp1 = fgetc(fp);
            temp2 = fgetc(fp);
        }
        else//这里这样处理一下，防止多余的字符
        {
            if(flag1 == 0 && flag2 == 0)
            {
                printf("%c", temp1);
            }
            temp1 = temp2;
            temp2 = fgetc(fp);
        }
    }

    fclose(fp);
    return 0;
}
