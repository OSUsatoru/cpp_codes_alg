#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define All(obj) (obj).begin(),(obj).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=0; i>=(n);--i)
#define FOR(i,b,n) for(int i=(b);i<(n);++i)

typedef long long ll;

const int M=2e5+5;
const int INF=2e9;
const int MOD=1e9+7;
void Solve()
{

    ifstream ifs("input.txt");
    int n,max_n = -101;
    ifs >> n;
    char ch;
    vector<vector<int>> arr(n,vector<int>(n));
    vector<vector<int>> mem(n,vector<int>(n));
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            ifs >> arr[i][j];
            cout << arr[i][j];
            if(j!=n-1)
                ifs >> ch;
        }
    }
    ifs.close();

     //case of i = 0
    for(int j = 0; j < n; ++j)
    {
        if(j==0)
            mem[0][j] = arr[0][j];
        else
            mem[0][j] = max(mem[0][j-1]+arr[0][j], arr[0][j]);
    }
    // go down, go left.
    for(int i = 1; i < n; ++i)
    {
        //move down
        for(int j = 0; j < n; ++j)
        {
            mem[i][j] = max(mem[i-1][j]+arr[i][j], arr[i][j]);
        }

        //move right
        for(int j = 1; j < n; ++j)
        {
            mem[i][j] = max(mem[i][j], max(mem[i][j-1]+arr[i][j], arr[i][j]));
        }
    }
    /*
    cerr << "this is memoization output" << endl;
    //display function
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            cerr << mem[i][j];
            if(j!= n-1)
                cerr << ',';
        }
        if(i!= n-1)
            cerr << '\n';
    }
    */
    for(int i = 0; i < n; ++i)
        max_n = max(max_n, max(mem[n-1][i],mem[i][n-1]));

    std::ofstream ofs("output.txt");
    if (!ofs) {
        std::cerr << "error" << std::endl;
        std::exit(1);
    }
    ofs << max_n;

}
int main()
{
    fastio;
    Solve();

    return 0;
}
