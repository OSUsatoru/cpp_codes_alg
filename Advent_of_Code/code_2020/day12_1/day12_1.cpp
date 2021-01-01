#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;

void move(int &x, int &y, char forward, int value){
    switch(forward){
        case 'N':
            y+=value;
            break;
        case 'S':
            y-=value;
            break;
        case 'E':
            x+=value;
            break;
        case 'W':
            x-=value;
            break;
    }
}


void Solve()
{
    ifstream ifs("input.txt");
    if (ifs.fail()) {
        cerr << "Failed to open file." << endl;
        exit(1);
    }
    ofstream ofs("output.txt");
    if (!ofs) {
        cerr << "error" << std::endl;
        exit(1);
    }
    string str;
    char act, facing = 'E';
    int value, pos_x=0,pos_y=0;
    vector<char> dir = {'N','E','S','W'};
    while(getline(ifs, str)){
        act = str[0];
        value = stoi(str.substr(1));
        switch(act){
            case 'N':
            case 'S':
            case 'E':
            case 'W':
                move(pos_x,pos_y,act,value);
                break;
            case 'R':
                facing = dir[(find(dir.begin(), dir.end(), facing) - dir.begin()+1*(value/90))%4];
                break;
            case 'L':
                facing = dir[(find(dir.begin(), dir.end(), facing) - dir.begin() + 3*((value/90)))%4];
                break;
            case 'F':
                move(pos_x,pos_y,facing,value);
                break;
        }

        cout << pos_x << ' ' <<pos_y << endl;
    }
    ofs << abs(pos_x)+abs(pos_y);
    ifs.close();
    ofs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}