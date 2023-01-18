#include<stdio.h>
#include<ctype.h>
#include<math.h>

int s[25];
int top=-1;

int operation(char op,int op1,int op2)
{
    switch(op)
    {
        case '+': return(op1+op2);
        case '-': return(op1-op2);
        case '*': return(op1*op2);
        case '/': return(op1/op2);
        case '^': return(pow(op1,op2));
        case '%': return(op1 % op2);
        default: return(0);
    }
}

void main()
{
    char postfix[25],symbol;
    int op1,op2,res;
    int i;
    printf("Enter the Postfix Expression: ");
    scanf("%s",postfix);
    for( i=0; postfix[i]!='\0'; i++ )
    {
        symbol = postfix[i];
        if(isdigit(symbol))
            s[++top]=(symbol-'0');
        else
        {
            op2 = s[top--];
            op1 = s[top--];
            res = operation(symbol,op1,op2);
            s[++top]=res;
        }
    }
    res = s[top--];
    printf("RESULT: %d\n",res);
}
