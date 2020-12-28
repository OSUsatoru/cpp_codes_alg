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
    vector<int> lists;
    int num, ans;
    while(keys.size() < 25){
        ifs >> num;
        keys.insert(num);
        controlKeys.push_back(num);
        lists.push_back(num);
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
            ans = num;
            //ofs << num;
        }
        keys.erase(controlKeys.front());
        controlKeys.pop_front();
        keys.insert(num);
        controlKeys.push_back(num);
        lists.push_back(num);
    }
    /* Part 2: lists has all values and ans holds the invalid number
    ******************************************************************/


    int len = 2;
    while(true){
        ll sum = 0;
        deque<ll> picks;
        for(int i = 0; i < len; ++i){
            sum+=lists[i];
            picks.push_back(lists[i]);
        }
        bool ok = false;
        for(int i = len; i < lists.size(); ++i){
            if(sum == ans){
                ok = true;
                break;
            }else{
                sum-= picks.front();
                picks.pop_front();
                sum+=lists[i];
                picks.push_back(lists[i]);
            }
        }
        if(ok){
            ll high = LONG_MIN, low = LONG_MAX;
            for(int i = 0; i < picks.size(); ++i){
                //cerr << picks[i] <<endl;
                high = max(high,picks[i]);
                low = min(low,picks[i]);
            }
            ofs << high + low;
            break;
        }else{
            ++len;
        }
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