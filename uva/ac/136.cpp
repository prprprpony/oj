#include<cstdio>
#include<set>
using namespace std;
int main()
{
    set<int> un;
    un.insert(1);
    int a=1;
    set<int>::iterator n;
    for(n=un.begin();a<1500;n++,a++)
    {
        un.insert(*n*2);
        un.insert(*n*3);
        un.insert(*n*5);
    }
    printf("The %d'th ugly number is %d.\n",a,*n);

    return 0;
}
