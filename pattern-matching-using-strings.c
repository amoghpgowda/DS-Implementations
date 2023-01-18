#include<stdio.h>

char str[20],pat[20],rep[20],ans[20];
int i,j,k,m,c,flag=0;

void string_match()
{
    i=j=k=m=c=0;
    while (str[c]!='\0')
    {
        if(str[m]==pat[i])
        {
            m++;i++;
            if(pat[i]=='\0')
            {
                flag=1;
                for (k = 0; rep[k]!='\0'; k++)
                {
                    ans[j]=rep[k];
                    j++;
                }
                i=0;c=m;
            }
        }
        else
        {
            ans[j]=str[c];
            j++;c++;
            m=c;i=0;
        }
    }
    ans[j]='\0';
}

void main()
{
    printf("ENTER THE MAIN STRING: ");
    gets(str);

    printf("ENTER THE PATTERN STRING: ");
    gets(pat);

    printf("ENTER THE REPLACEMENT STRING: ");
    gets(rep);

    string_match();

    if(flag==1)
    {
        printf("\nPATTERN FOUND");
        printf("\nRESULTANT STRING: %s\n",ans);
    }
    else
    {
        printf("\nPATTERN NOT FOUND\n");
    }
}
