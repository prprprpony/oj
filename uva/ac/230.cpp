#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Book
{
    string author;
    string title;
    bool borrow;
    bool stash;

    Book() : borrow(false), stash(false) {};

    friend bool operator < (const Book &a, const Book &b)
    {
        return (a.author != b.author) ? (a.author < b.author) : (a.title < b.title);
    }

    bool GetTitle()
    {
        title.clear();
        int c;
        if ((c = getchar()) == '"') {
            while ((c = getchar()) != '"')
                title.push_back(c);
            return true;
        }
        return false;
    }

    bool Get()
    {
        int c;
        if (GetTitle()) {
            author.clear();
            scanf(" %*s "); // filters " by "
            while ((c = getchar()) != '\n')
                author.push_back(c);
            return true;
        } else {
            while ((c = getchar()) != '\n');
            return false;
        }
    }
};

int main(void)
{
    vector<Book> shelf;
    string op;
    Book t;
    int i;
    map<string, int> t2i;
    while (t.Get())
        shelf.push_back(t);
    sort(shelf.begin(), shelf.end());
    for (i = 0; i < shelf.size(); i++)
        t2i[shelf[i].title] = i;
// for (i = 0 ;i < shelf.size(); i++)
//     cout << shelf[i].title << " " << shelf[i].author << endl;
    while (cin >> op) {
        getchar();
        switch (op[0]) {
        case 'B':
            t.GetTitle();
            i = t2i[t.title];
            shelf[i].borrow = true;
            shelf[i].stash = false;
// cout << "B " <<  shelf[i].title << endl;
            break;
        case 'R':
            t.GetTitle();
            i = t2i[t.title];
            shelf[i].borrow = false;
            shelf[i].stash = true;
// cout << "R " <<  shelf[i].title << endl;
            break;
        case 'S':
            int last = -1;
            for (i = 0; i < shelf.size(); i++) {
                if (!shelf[i].borrow && !shelf[i].stash)
                    last = i;
                if (shelf[i].stash) {
                    if (last != -1)
                        printf("Put \"%s\" after \"%s\"\n", shelf[i].title.c_str(), shelf[last].title.c_str());
                    else
                        printf("Put \"%s\" first\n", shelf[i].title.c_str());
                    shelf[i].stash = false;
                    last = i;
                }
            }
            puts("END");
            break;
        }
    }

    return 0;
}
