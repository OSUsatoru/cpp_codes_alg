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
    int high,low,ans=0,cnt;
    char key,tmp;
    while(getline(ifs,str)){
        stringstream ss;
        ss << str;
        ss >> low >> high >> key >> tmp >> input;
        high=abs(high);
        cnt = count(input.begin(),input.end(),key);
        if(low <= cnt and cnt <=high){
            ++ans;
        }
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