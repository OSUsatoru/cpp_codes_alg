#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;

void move(int &x, int &y, int way_x, int way_y, int value){
    x+=way_x*value;
    y+=way_y*value;
}
void wayp_move(int &x, int &y, char forward, int value){
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
    int value, pos_x=0,pos_y=0, way_x = 10, way_y=1, cnt, tmp;
    vector<char> dir = {'N','E','S','W'};
    while(getline(ifs, str)){
        act = str[0];
        value = stoi(str.substr(1));
        switch(act){
            case 'N':
            case 'S':
            case 'E':
            case 'W':
                wayp_move(way_x,way_y,act,value);
                break;
            case 'R':
                cnt = value/90;
                while(cnt--){
                    tmp = way_x;
                    way_x = way_y;
                    way_y = -tmp;
                }
                break;
            case 'L':
                cnt = value/90;
                while(cnt--){
                    tmp = way_y;
                    way_y = way_x;
                    way_x = -tmp;
                }
                break;

            case 'F':
                move(pos_x,pos_y,way_x,way_y,value);
                break;
        }
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