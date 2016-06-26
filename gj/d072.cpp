#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, int> PlacesId;
vector< map<string, int> > AnimalsId;

vector<string> Places;
vector< vector<string> > Animals;

vector< vector<int> > PAN;

int PID(string &a)
{
    if (PlacesId.count(a)) {
        return PlacesId[a];
    } else {
        Places.push_back(a);
        AnimalsId.push_back(map<string, int>());
        Animals.push_back(vector<string>());
        PAN.push_back(vector<int>());
        return PlacesId[a] = PlacesId.size() - 1;
    }
}

int AID(int p, string& a)
{
    if (AnimalsId[p].count(a)) {
        return AnimalsId[p][a];
    } else {
        Animals[p].push_back(a);
        PAN[p].push_back(0);
        return AnimalsId[p][a] = AnimalsId[p].size() - 1;
    }
}

int main()
{
    string ani, pla;
    int n, num;
    cin >> n;
    while (n--) {
        cin >> ani >> num >> pla;
        int pid = PID(pla);
        int aid = AID(pid, ani);
        PAN[pid][aid] += num;
    }

    for (int i = 0; i < Places.size(); i++) {
        cout << Places[i] << ':';
        for (int j = 0; j < Animals[i].size(); j++)
            cout << Animals[i][j] << ' ' << PAN[i][j] << (j != Animals[i].size() - 1 ? ',' : '\n');
    }

    return 0;
}
