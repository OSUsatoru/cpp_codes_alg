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

    unordered_set<int> keys;
    deque<int> controlKeys;
    int num;
    while(keys.size() < 25){
        ifs >> num;
        keys.insert(num);
        controlKeys.push_back(num);
    }
    while(ifs >> num){
        bool ok = false;
        for(auto itr = keys.begin(); itr != keys.end(); ++itr){
            if(keys.find(num-*itr)!=keys.end()){
                ok=true;
                break;
            }
        }
        if(!ok){
            ofs << num;
        }
        keys.erase(controlKeys.front());
        controlKeys.pop_front();
        keys.insert(num);
        controlKeys.push_back(num);
    }


    ifs.close();
    ofs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}