#include <cstdio>
#include <stack>
#include <cctype>
using namespace std;
const char operators[] = {'(', '+', '-', '*'};
const int  p[]         = { 0 ,  1 ,  1 ,  2 };
int priority(char c)
{
    for (int i = 0; i < sizeof(operators) / sizeof(char); i++)
        if (operators[i] == c)
            return p[i];
}

struct Exp // ax + b
{
    int a;
    int b;
    Exp(int c = 0, int k = 0) : a(c), b(k) {}

    void cal(stack<Exp> &exp, stack<char> &op) {
        Exp t = exp.top();
        exp.pop();
        switch (op.top()) {
            case '+':
                exp.top().a += t.a;
                exp.top().b += t.b;
                break;
            case '-':
                exp.top().a -= t.a;
                exp.top().b -= t.b;
                break;
            case '*':
                if (t.a != 0)
                    swap(exp.top(), t);
                exp.top().a *= t.b;
                exp.top().b *= t.b;
                break;
        }
        op.pop();
    }

    Exp(char *first, char *last) // parse [fisrt, last)
    {
        Exp e(0, 0);
        stack<char> op;
        int pr;
        stack<Exp> exp;
        bool counting = false;

        for ( ; first != last; first++) {
            if (isdigit(*first)) {
                e.b = 10 * e.b + (*first - '0');
                counting = true;
            } else if (*first == 'x') {
                exp.push(Exp(1, 0));
            } else {
                switch (*first) {
                    case ')':
                        if (counting) {
                            exp.push(e);
                            e = Exp(0, 0);
                            counting = false;
                        }
                        while (op.top() != '(')
                            cal(exp, op);
                        op.pop();
                        break;
                    case '(':
                        op.push('(');
                        break;
                    default:
                        if (counting) {
                            exp.push(e);
                            e = Exp(0, 0);
                            counting = false;
                        }
                        pr = priority(*first);
                        while (!op.empty() && priority(op.top()) >= pr)
                            cal(exp, op);
                        op.push(*first);
                        break;
                }
            }
        }
        if (counting) {
            exp.push(e);
            e = Exp(0, 0);
            counting = false;
        }
        while (!op.empty())
            cal(exp, op);
        *this = exp.top();
    }
};



int main()
{
    char s[106];
    int cases = 0;
    Exp e[2];
    char *c, *m;
    while (fgets(s, sizeof(s), stdin) != NULL) {
        for (c = s; *c != '\0'; c++)
            if (*c == '=')
                m = c;
        e[0] = Exp(s, m);
        e[1] = Exp(m + 1, c - 1); // "=...\n\0"
        if (cases)
            putchar('\n');
        printf("Equation #%d\n", ++cases);
        if (e[0].a == e[1].a) {
            if (e[0].b == e[1].b)
                puts("Infinitely many solutions.");
            else
                puts("No solution.");
        } else {
            printf("x = %.6f\n", (double)(e[1].b - e[0].b) / (double)(e[0].a - e[1].a));
        }
    }
    return 0;
}
