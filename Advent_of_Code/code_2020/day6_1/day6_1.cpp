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
    int index, key;
    string str;
    vector<bool> check(26,false);
    vector<int> cnts(1,0);
    while(getline(ifs,str)){
        if(str.empty()){
            fill(check.begin(),check.end(), false);
            cnts.push_back(0);
        }else{
            index = cnts.size()-1;
            for(int i = 0;i < str.size(); ++i){
                key = str[i] - 'a';
                if(check[key] == false){
                    check[key] = true;
                    ++cnts[index];
                }
            }
        }
    }

    ofstream ofs("output.txt");
    if (!ofs) {
        cerr << "error" << std::endl;
        exit(1);
    }
    ofs << accumulate(cnts.begin(),cnts.end(),0);
    ifs.close();
    ofs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}