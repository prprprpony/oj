#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
    char str[151];
    int letter[26],i;
    for(i=0;i<26;i++)
        letter[i]=0;
    gets(str);
    for(i=0;i<strlen(str);i++)
    {
        int l=toupper(str[i]);
        if(l>='A'&&l<='Z')
            letter[l-'A']++;
    }

    for(i='A';i<'Z';i++)
    {
        printf("%c ",i);
    }
    printf("Z\n");

    for(i=0;i<25;i++)
    {
        printf("%d ",letter[i]);
    }
    printf("%d\n",letter[25]);

    return 0;
}
