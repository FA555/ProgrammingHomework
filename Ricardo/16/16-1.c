#include <stdio.h>

void function1(FILE *fp)
{
    int capitalNumber = 0;
    int lowercaseNumber = 0;
    int digitNumber = 0;
    int othersNumber = 0;

    for(;;)
    {
        int result = fgetc(fp);
        if(result == EOF)
        {
            break;
        }
        if(result >= 'A' && result <= 'Z')
        {
            capitalNumber++;
        }
        else if(result >= 'a' && result <= 'z')
        {
            lowercaseNumber++;
        }
        else if(result >= '0' && result <= '9')
        {
            digitNumber++;
        }
        else
        {
            othersNumber++;
        }
    }

    printf("Task1:\n");
    printf("capital: %d\n", capitalNumber);
    printf("lowercase: %d\n", lowercaseNumber);
    printf("digit: %d\n", digitNumber);
    printf("others: %d\n", othersNumber);
}

void function2(FILE *fp)
{
    int line = 0;
    int maxLine = 0;
    int minLine = -1;
    char temp;
    int length;

    for(;;)
    {
        temp = fgetc(fp);
        length = 0;

        if(temp == EOF)
        {
            break;
        }
        
        for(;;)
        {
            if(temp == '\n')
            {
                
                if(length > maxLine)
                {
                    maxLine = length;
                }
                if(length < minLine || minLine == -1)
                {
                    minLine = length;
                }
                line++;
                break;
            }
            length++;
            temp = fgetc(fp);
        }
    }

    printf("Task2:\n");
    printf("line: %d\n", line);
    printf("%d characters in max line.\n", maxLine);
    printf("%d characters in min line.\n", minLine);
}

void function3(FILE *fp)
{
    int capitalNumber[26] = {0,};
    int lowerCaseNumber[26] = {0,};

    for(;;)
    {
        char temp = fgetc(fp);
        if(temp == EOF)
        {
            break;
        }
        if(temp >= 'A' && temp <= 'Z')
        {
            capitalNumber[temp - 'A']++;
        }
        if(temp >= 'a' && temp <= 'z')
        {
            lowerCaseNumber[temp - 'a']++;
        }
    }

    printf("Task3:\n");

    for(int i = 0; i < 26; i++)
    {
        if(i == 0)
        {
            printf("CAPITAL:\n");
        }
        printf("%c:%d\n", i + 'A', capitalNumber[i]);
    }
    
    for(int i = 0; i < 26; i++)
    {
        if(i == 0)
        {
            printf("LOWERCASE:\n");
        }
        printf("%c:%d\n", i + 'a', lowerCaseNumber[i]);
    }
}

int main()
{
    FILE *fp = fopen("dict.dic", "r");
    int input;
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        function1(fp);
        break;
    case 2:
        function2(fp);
        break;
    case 3:
        function3(fp);
        break;
    default:
        break;
    }

    fclose(fp);
    return 0;
}