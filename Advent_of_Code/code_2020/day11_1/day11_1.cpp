#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;
/*
    (x,y): (1,-1)(1,0)(1,1)(0,-1)(0,1)(-1,-1)(-1,0)(-1,1)
    except: (0,0)
    check these and count occupied seat_1,
*/

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
    string str;
    vector<string> seat_1, seat_2;
    while(getline(ifs,str)){
        seat_1.push_back(str);
        seat_2.push_back(str);
    }
    bool changed;
    int cnt, h = seat_1.size(), w = seat_1[0].size();
    vector<pair<int,int>> checker = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};

    do{
        changed = false;
        seat_1 = seat_2;
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                cnt=0;
                for(int k = 0; k < checker.size(); ++k){
                    if( (i + checker[k].first) >= 0 and (i + checker[k].first) < h and (j+checker[k].second) >=0 and (j+checker[k].second) < w ){
                        if(seat_1[i+checker[k].first][j+checker[k].second] == '#'){
                            ++cnt;
                        }
                    }
                }
                if(seat_1[i][j]=='L' and cnt==0){
                    seat_2[i][j] ='#';
                    changed = true;
                }else if(seat_1[i][j] == '#' and cnt >= 4){
                    seat_2[i][j] = 'L';
                    changed = true;
                }
            }
        }

    }while(changed);
    int ans=0;
    cerr << endl;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cerr << seat_2[i][j];
            if(seat_2[i][j]=='#'){
                ++ans;
            }
        }
        cerr << endl;
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