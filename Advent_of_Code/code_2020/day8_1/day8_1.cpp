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

    string str, key, value;
    vector<pair<string,int>> operation;

    while(getline(ifs, str)){
        key = str.substr(0, str.find(' '));
        value = str.substr(str.find(' ')+1);
        if(value[0]=='+'){
            operation.push_back(pair<string,int>(key,stoi(value.substr(1))));
        }else{
            operation.push_back(pair<string,int>(key,-(stoi(value.substr(1)))));
        }
    }
    int index = 0, ans = 0;
    vector<bool> check(operation.size(), false);
    while(true){
        if(check[index]){
            break;
        }else{
            check[index]=true;
        }
        if(operation[index].first == "nop"){
            ++index;
        }else if(operation[index].first == "acc"){
            ans+=operation[index].second;
            ++index;
        }else if(operation[index].first == "jmp"){
            index+=operation[index].second;
        }

    }
    ofs << ans;


    ifs.close();
    ofs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}