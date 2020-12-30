#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;

// this takes O(2^n).
/*
void rec_cnt(ll &cnt, vector<int> &list,int index, int current, int last){
    if(index > list.size()){
        return;
    }
    if(current == last){
        ++cnt;
        return;
    }
    if((list[index] - current) <= 3){
        cerr << current <<endl;
        rec_cnt(cnt, list, index+1, list[index], last);
        rec_cnt(cnt, list, index+1, current, last);
    }else{
        return;
    }


}*/



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
    int num;
    vector<int> list;
    list.push_back(0);
    while(ifs >> num){
        list.push_back(num);
    }
    sort(list.begin(),list.end());
    list.push_back(list.back()+3);
    vector<ll> mem(list.size());
    mem[0]=1;

    //dp
    for(int i = 1; i < list.size(); ++i){
        for(int j = i-1; j >=0; --j){
            if(list[i]-list[j] <= 3){
                mem[i]+=mem[j];
            }else{
                break;
            }
        }
    }
    ofs << mem[list.size()-1];

    //ll cnt = 0;
    //int last = list[list.size()-1];
    //rec_cnt(cnt,list,0,0,last);

    ifs.close();
    ofs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}