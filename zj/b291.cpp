#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<string, int> PlacesId;
map<string, int> AnimalsId;

vector<string> Places;
vector<string> Animals;

vector< map<int, int> > PAN;

int PID(string &a)
{
    if (PlacesId.count(a)) {
        return PlacesId[a];
    } else {
        Places.push_back(a);
        PAN.push_back(map<int, int>());
        return PlacesId[a] = PlacesId.size() - 1;
    }
}

int AID(string& a)
{
    if (AnimalsId.count(a)) {
        return AnimalsId[a];
    } else {
        Animals.push_back(a);
        return AnimalsId[a] = AnimalsId.size() - 1;
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
        int aid = AID(ani);
        if (!PAN[pid].count(aid))
            PAN[pid][aid] = 0;
        PAN[pid][aid] += num;
    }

    for (int i = 0; i < Places.size(); i++) {
        cout << Places[i] << " :";
        bool first = true;
        for (map<int, int>::iterator it = PAN[i].begin(); it != PAN[i].end(); it++) {
            if (!first)
                cout << ',';
            else
                first = false;
            cout << ' ' << Animals[it->first] << ' ' << (it->second);
        }
        cout << '\n';
    }

    return 0;
}
