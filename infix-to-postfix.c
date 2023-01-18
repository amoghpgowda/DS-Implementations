#include<stdio.h>
#include<string.h>

int f(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^':
        case '$': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8;
    }
}

int g(char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^':
        case '$': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;
    }
}

void infix_postfix(char infix[], char postfix[])
{
    int i,j,top;
    char s[50],symbol;

    j = 0;
    top = -1;
    s[++top] = '#';

    for(i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        while(f(s[top]) > g(symbol))
        {
            postfix[j] = s[top--];
            j++;
        }
        if(f(s[top]) != g(symbol))
            s[++top] = symbol;
        else
            top--;
    }

    while (s[top] != '#')
    {
        postfix[j] = s[top--];
        j++;
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[50], postfix[50];

    printf("\nENTER THE INFIX EXPRESSION: ");
    gets(infix);

    infix_postfix(infix, postfix);

    printf("\nTHE INFIX EXPRESSION IS: ");
    printf("%s", infix);

    printf("\nTHE POSTFIX EXPRESSION IS: ");
    printf("%s", postfix);

    return 0;
}
