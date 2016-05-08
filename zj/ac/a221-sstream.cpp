#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (cin.get() != '\n');
    for (int kase = 1; kase <= t; ++kase) {
        string team, judge;
        getline(cin, team);
        getline(cin, judge);

        cout << "Case " << kase << ": ";
        if (team == judge) {
            cout << "Yes";
        } else {
            stringstream ss(team);
            team = "";
            string t;
            while (ss >> t)
                team += t;
            cout << (team != judge ? "Wrong Answer" : "Output Format Error");
        }
        cout << '\n';
    }
    return 0;
}
