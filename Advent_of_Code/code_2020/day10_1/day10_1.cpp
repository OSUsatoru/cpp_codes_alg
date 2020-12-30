#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;


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
    int num;
    vector<int> list, cnt(3,0);
    list.push_back(0);
    while(ifs >> num){
        list.push_back(num);
    }
    sort(list.begin(),list.end());
    list.push_back(list.back()+3);
    int current = 0;
    for(int i = 0; i < list.size(); ++i){
        ++cnt[list[i]-current-1];
        current = list[i];
    }
    ofs << cnt[0]*cnt[2];

    ifs.close();
    ofs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}