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
const int MOD=1e9+7; //prime number


typedef pair<int,int> position;


/*
next position is where:
A   right:  red + graph[blue]
A   left:   red - graph[blue]
A   up:     red - n * graph[blue]
A   down:   red + n * graph[blue]
B   right:  blue + graph[red]
B   left:   blue - graph[red]
B   up:     blue - n * graph[red]
B   down:   blue + n * graph[red]
*/
/*
0.  check position != goal
1.1 insert
1.2 check key
loop while empty or find goal
*/
void Solve()
{
    ifstream ifs("input.txt");

    int n;
    char ch;
    ifs >> n;
    int start = 0, last = n*n-1;
    vector<int> graph(n*n);
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            ifs >> graph[i*n+j];
            if(j!=n-1)
                ifs >> ch;
        }
    }

    ifs.close();
    vector<vector<int> > dist(last+1,vector<int> (last+1,-1));
    queue<position> que;
    //push start position and dist[s] = 0
    dist[start][last] = 0;
    que.push(position(start,last));

    int key;
    int red, blue;
    while(!que.empty())
    {
        red = que.front().first;
        blue = que.front().second;
        que.pop();
        //find correct path
        //the reason I can stop loop is because I am using BFS method
        if(red == last and blue == start)
            break;

        key = dist[red][blue];

        /*A possible move*/
        if( red%n + graph[blue] < n ) // right
        {
            // red and blue is not same position and
            // if dist == -1, unchecked. => check the next position and insert it
            if( (red + graph[blue] != blue) and dist[red + graph[blue]][blue] == -1 )
            {
                dist[red + graph[blue]][blue] = key + 1;
                que.push(position(red + graph[blue], blue));
            }

        }
        if( red%n - graph[blue] >= 0 ) //left
        {
            if( (red - graph[blue] != blue) and dist[red - graph[blue]][blue] == -1)
            {
                dist[red - graph[blue]][blue] = key + 1;
                que.push(position(red - graph[blue], blue));
            }
        }
        if( red-n*graph[blue]>= 0  ) //up
        {
            if( (red - n*graph[blue] != blue) and dist[red - n*graph[blue]][blue] == -1)
            {
                dist[red - n*graph[blue]][blue] = key + 1;
                que.push(position(red - n*graph[blue], blue));
            }
        }
        if(red + n*graph[blue] <= last) //down
        {
            if( (red + n*graph[blue] != blue) and dist[red + n*graph[blue]][blue] == -1)
            {
                dist[red + n*graph[blue]][blue] = key + 1;
                que.push(position(red + n*graph[blue], blue));
            }
        }

        /*B possible move*/

        if( blue%n + graph[red] < n ) // right
        {
            if( (blue + graph[red] != red) and dist[red][blue + graph[red]]== -1)
            {
                dist[red][blue + graph[red]] = key + 1;
                que.push(position(red, blue + graph[red]));
            }
        }
        if( blue%n - graph[red] >= 0 ) //left
        {
            if( (blue - graph[red] != red) and dist[red][blue - graph[red]] == -1)
            {
                dist[red][blue - graph[red]] = key + 1;
                que.push(position(red, blue - graph[red]));
            }
        }
        if(blue - n*graph[red] >= 0  ) //up
            if( (blue - n*graph[red] != red) and dist[red][blue - n*graph[red]] == -1)
            {
                dist[red][blue - n*graph[red]] = key + 1;
                que.push(position(red, blue - n*graph[red]));
            }
        if(blue + n*graph[red] <= last) //down
        {
            if( (blue + n*graph[red] != red) and dist[red][blue + n*graph[red]] == -1)
            {
                dist[red][blue + n*graph[red]]= key + 1;
                que.push(position(red, blue + n*graph[red]));
            }
        }
    }

    std::ofstream ofs("output.txt");
    if (!ofs) {
        std::cerr << "error" << std::endl;
        std::exit(1);
    }

    ofs << dist[last][start] << std::endl;
}
int main()
{
    fastio;
    Solve();

    return 0;
}
