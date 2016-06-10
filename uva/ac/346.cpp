#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;
const vector< vector<string> > notes = {{"A"}, {"A#", "Bb"}, {"B"}, {"C"}, {"C#", "Db"}, {"D"}, {"D#", "Eb"}, {"E"}, {"F"}, {"F#", "Gb"}, {"G"}, {"G#", "Ab"}};
const int M = notes.size();

bool equal(const string & a, const string & b) {
    if (a.size() != b.size())
        return false;
    for (int i = 0; i < a.size(); ++i)
        if (toupper(a[i]) != toupper(b[i]))
            return false;
    return true;
}

int getid(const string & s)
{
    for (int i = 0; i < notes.size(); ++i)
        for (const auto & n : notes[i]) {
            if (equal(n, s))
                return i;
#ifdef PP
            else
                cout << n << "!=" << s << '\n';
#endif
        }
    return -1;
}

int sub(int a, int b)
{
    return (a -= b) < 0 ? a + M : a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    string seq[3];
    int ids[3];
    int d[2];
    while (cin >> seq[0]) {
        cin >> seq[1] >> seq[2];

        for (auto & s : seq)
            cout << s << ' ';
        cout << "is ";
        
        for (int i = 0; i < 3; ++i) {
            ids[i] = getid(seq[i]);
            if (ids[i] < 0)
                goto fail;
#ifdef PP
            cout << "ids[" << i << "] = " << ids[i] << '\n';
#endif
        }
        sort(ids, ids + 3);

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 2; ++j) {
                d[j] = sub(ids[(i + j + 1) % 3], ids[(i + j) % 3]) - 1;
#ifdef PP
                cout << "d[" << i << "] = " << d[i] << '\n';
#endif
            }

            if (d[0] == 3 && d[1] == 2) {
                cout << "a " << notes[ids[i]][0] << " Major chord.\n";
                goto finish;
            } else if (d[0] == 2 && d[1] == 3) {
                cout << "a " << notes[ids[i]][0] << " Minor chord.\n";
                goto finish;
            }
        }

fail:
        cout << "unrecognized.\n";
finish:
        ;
    }
}
