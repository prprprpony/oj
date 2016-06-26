#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define LEN 256

const char b[] = "()[]";
char buf[LEN];
int stack[LEN];

int getid(char c)
{
    int i;
    for (i = 0; b[i] != '\0'; i++)
        if (c == b[i])
            return i;
    assert(0);
}

int main(void)
{
    int n;
    char* c;
    int top;
    bool ok;
    int id;

    scanf("%d ", &n);
    while (n--) {
        top = -1;
        ok = true;
        fgets(buf, sizeof(buf), stdin);
        for (c = buf; *c != '\n' && *c != '\0'; ++c) {
            id = getid(*c);
            if (!(id & 1)) {
                stack[++top] = id;
            } else if (top >= 0 && ((stack[top] ^ 1) == id)) {
                --top;
            } else {
                ok = false;
                break;
            }
        }
        puts(ok && top == -1 ? "Yes" : "No");
    }

    return 0;
}
