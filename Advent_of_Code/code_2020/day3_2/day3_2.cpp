#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;

const int PATTERN = 5;

void Solve()
{
    ifstream ifs("input.txt");
    if (ifs.fail()) {
        cerr << "Failed to open file." << endl;
        exit(1);
    }
    string str,input;
    ll res=1;
    int y=0;
    vector<int> pos(PATTERN,0), mov{1,3,5,7,1}, ans(PATTERN,0);
    while(getline(ifs,str)){
        for(int i = 0; i < PATTERN; ++i){
            if(i==PATTERN-1){
                if(y%2==0){
                    if(str[pos[i]%str.length()]=='#'){
                        ++ans[i];
                    }
                    pos[i]+=mov[i];
                }
            }
            else{
                if(str[pos[i]%str.length()]=='#'){
                    ++ans[i];
                }
                pos[i]+=mov[i];
            }


        }
        ++y;

    }

    ofstream ofs("output.txt");
    if (!ofs) {
        cerr << "error" << std::endl;
        exit(1);
    }
    for(int num: ans) {res*=num; cerr << num << endl;}
    ofs << res;

    ifs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}