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
    string str,input;
    int ans=0, pos=0;

    while(getline(ifs,str)){
        if(str[pos%str.length()]=='#'){
            ++ans;
        }
        pos+=3;
    }

    ofstream ofs("output.txt");
    if (!ofs) {
        cerr << "error" << std::endl;
        exit(1);
    }

    ofs << ans;

    ifs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}