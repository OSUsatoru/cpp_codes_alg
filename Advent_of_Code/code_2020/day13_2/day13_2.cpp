#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;

/*
    Chinese Remainder Theorem:
    https://qiita.com/drken/items/ae02240cd1f8edfc86fd

    Euclidean division:
    https://qiita.com/drken/items/b97ff231e43bce50199a#1-%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95%E3%81%A8%E3%81%AF


    x % m = a
    x % n = b
    if m and n are relatively prime
    there exsits r (0 < r < mn) such that x % mn = r

    r = gcd(m,n);
    np + mq = d;

    x = a + m* ((b-a) / d)* p
*/

ll mod(ll a, ll b){
    return (a % b + b) % b;
}
ll extGcd(ll a, ll b, ll &p, ll &q){
    if(b == 0){ p = 1; q = 0; return a;}
    ll d = extGcd(b, a%b, q, p);
    q-=a/b * p;
    return d;
}

pair<ll,ll> ChineseRem(const vector<ll> &b, const vector<ll> &m){
    ll r = 0, M = 1;
    for(int i = 0; i < b.size(); ++i){
        ll p,q;
        ll d = extGcd(M, m[i],p,q);
        if((b[i]-r)%d!=0) return make_pair(0,1);
        ll tmp = (b[i]-r)/d*p%(m[i]/d);
        r+=M*tmp;
        M*=m[i]/d;
    }
    return make_pair(mod(r,M),M);
 }

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
    ll first_ID, current_time;
    vector<ll> bus_ID;
    vector<ll> mods;
    string str;
    ifs >> current_time;
    getline(ifs,str, ',');
    first_ID = stol(str);
    int cnt = 1;
    while(getline(ifs,str, ',')){
        if(str!="x"){
            bus_ID.push_back(stol(str));
            mods.push_back(stol(str)-cnt);
        }
        ++cnt;
    }
    pair<ll,ll> ans_pair;
    ans_pair = ChineseRem(mods,bus_ID);
    cerr << ans_pair.first << ' ' << ans_pair.second <<endl;
    ll ans = ans_pair.second + ans_pair.first;
    while(mod(ans,first_ID) != 0 or ans < current_time){
        ans+=ans_pair.second;
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