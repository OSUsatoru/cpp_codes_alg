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
    deque<int> indexes;
    int cnt = 0;
    while(getline(ifs, str)){
        key = str.substr(0, str.find(' '));
        if(key == "jmp" or key == "nop"){
            indexes.push_back(cnt);
        }
        value = str.substr(str.find(' ')+1);
        if(value[0]=='+'){
            operation.push_back(pair<string,int>(key,stoi(value.substr(1))));
        }else{
            operation.push_back(pair<string,int>(key,-(stoi(value.substr(1)))));
        }
        cnt++;
    }

    int index = 0, ans = 0, tmp;
    bool ok;
    vector<bool> check(operation.size(), false);
    operation[indexes[0]].first = (operation[indexes[0]].first == "nop" ? "jmp":"nop");
    while(true){

        if(check[index] or index >= operation.size()){
            ans = 0;
            index = 0;
            fill(check.begin(),check.end(),false);
            if(indexes.size() >=2){
                //fix previous one and and change next one
                operation[indexes[0]].first = (operation[indexes[0]].first == "nop" ? "jmp":"nop");
                operation[indexes[1]].first = (operation[indexes[1]].first == "nop" ? "jmp":"nop");
                indexes.pop_front();
            }else{
                ok = false;
                break;
            }
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
        if(index == operation.size() ){
            ok = true;
            break;
        }
    }

    if(ok)
        ofs << ans;
    else
        ofs << "no";

    ifs.close();
    ofs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}