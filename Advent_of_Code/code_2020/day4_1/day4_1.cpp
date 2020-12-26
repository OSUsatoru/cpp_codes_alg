#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;
// no need cid
deque<string> keys{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}, cpyKeys=keys;

void Solve()
{
    ifstream ifs("input.txt");
    if (ifs.fail()) {
        cerr << "Failed to open file." << endl;
        exit(1);
    }
    int cnt = 0;
    string str;
    while(getline(ifs,str)){
        if(str.empty()){
            if(keys.empty()){
                ++cnt;
            }
            keys = cpyKeys;
        }else{
            string tmp,key,value;
            stringstream ss;
            ss << str;
            while(getline(ss,tmp,' ')){

                key = tmp.substr(0,3);
                value = tmp.substr(4);
                //cerr << key  << ' ' << value << endl;
                for(int i = 0; i < keys.size(); ++i){
                    if(keys[i]==key){
                        keys.erase(keys.begin()+i);
                        break;
                    }
                }
            }
        }

    }
    //last case
    if(keys.empty()){
        ++cnt;
    }


    ofstream ofs("output.txt");
    if (!ofs) {
        cerr << "error" << std::endl;
        exit(1);
    }

    ofs << cnt;
    ifs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}