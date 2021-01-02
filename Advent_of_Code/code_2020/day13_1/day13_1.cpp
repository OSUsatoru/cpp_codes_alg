#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;
/*
    times of next buses are (current_time/bus_num)*bus_num
    or add bus_num to this result;
*/

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

    int ans_time = INT_MAX,bus_ID, current_time, next_bus_time, tmp;
    string bus_num;
    ifs >> current_time;
    while(getline(ifs, bus_num,',')){
        if(bus_num != "x"){
            tmp = stoi(bus_num);
            next_bus_time = (current_time/tmp)*tmp;
            if(next_bus_time == current_time){
                ans_time = current_time;
                bus_ID = tmp;
            }else{
                next_bus_time+=tmp;
                if(ans_time>next_bus_time){
                    ans_time=next_bus_time;
                    bus_ID = tmp;
                }
            }
        }
    }

    ofs << (ans_time - current_time) * bus_ID;
    ifs.close();
    ofs.close();

}
int main()
{
    fastio;
    Solve();

    return 0;
}