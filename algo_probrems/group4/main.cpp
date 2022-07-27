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


/*
    if v = 1, v = 2
    2nd and 3rd are undefine

    find MST by using Prim

    by using Used Edges, for-loop to find 2nd and 3rd MST
    erase one of Used Edges, check other possible Edges for new ST
    first_graph, second_graph dequeue
    push erased edge's parent into first_graph
    push erased edge's child into second_graph
    for-loop to check other Used Edges
    find connected vertices and push into first or second graph
    after inner loop, by using nested for-loop to check every path b/w
    first and second graph

    2nd MST: min( new Edge weight - Used Edge weight )
    3rd MST: if 2nd < (new Edge weight - Used Edge weight),
                if 3rd >= (new Edge weight - Used Edge weight), else
             else if 2nd >= (new Edge weight - Used Edge weight)
                if 3rd >= ( old 2nd ), else
*/

typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> pipii;

struct myComp {
    constexpr bool operator()( pair<int, pair<int, int>> const& a, pair<int, pair<int, int>> const& b)
        const noexcept
    {
        return a.first > b.first;
    }
};


void Solve()
{
    ifstream ifs("input.txt");
    char ch;
    int v;
    ifs >> v;
    vector<vector<int>> graph(v,vector<int> (v));   // user input of v*v elements
    for(int i = 0; i < v; ++i){
        for(int j = 0; j < v; ++j){
            ifs >> graph[i][j];
            if(j!=v-1)
                ifs >> ch;
        }
    }
    ifs.close();
    //for Prim
    priority_queue<pipii, vector<pipii>, myComp> que; // priority queue
    vector<bool> check(v,false);           // used vertex = true; else false;
    int cost, parent, child, result = 0;

    // This will be used for second and third MST
    deque<pii> Edges;   // used Edges (parent, child)

    // for 2nd and 3rd MST
    deque<pii> tempEdges;
    deque<int> first_graph, second_graph;
    int second_min = INF, third_min = INF;      // min of (new Edge weight - Used Edge weight)
    int new_cost;
    bool ok;
    /* First MST by using Prim
    **********************************/
    que.push(pipii(0,pii(0,0)));     // starting weight and position

    while(!que.empty()){
        cost = que.top().first;
        parent = que.top().second.first;
        child = que.top().second.second;
        que.pop();

        // if vertex is unchecked
        if(check[child] == false){
            check[child] = true;    //check it
            result+=cost;           // add cost

            Edges.push_back(pii(parent, child));    // push used edge

            // push connected vertex
            for(int i = 0; i < v; ++i){
                if(i!=child and check[i] == false)
                        que.push(pipii( graph[child][i], pii(child, i) ));          //graph[child][i] = cost
            }
        }

    }
    Edges.pop_front();     // delete first position (0,0)
    /*
    cout << "result "<<result << '\n';
    cout << "Used Edges" << '\n';
    for(auto itr = Edges.begin(); itr != Edges.end(); ++itr)
    {
        cout << (*itr).first << ' ' << (*itr).second << '\n';

    }
    */

    /* Second and Third MST
    *********************************/

    // loop first Used Edge to last Used Edge
    // delete (i)th edge
    for(int i = 0; i < Edges.size(); ++i){
        // clean up
        first_graph.clear();
        second_graph.clear();
        cost = graph[Edges[i].first][Edges[i].second];
        //since we delete one edge of MST, there will be 2 graphs.
        first_graph.push_back(Edges[i].first);
        second_graph.push_back(Edges[i].second);
        /*
        cout << "first E: " << first_graph[0] << endl;
        cout << "second E: " << second_graph[0] << endl;
        */
        tempEdges = Edges;          // copy Edges;
        tempEdges.erase(tempEdges.begin() + i);     // delete one Edge

        // if find connected edge to first or second graph, push_back into graph and pop it
        while(!tempEdges.empty()){

            for(int i = 0; i < tempEdges.size(); ++i){
                // if tempEdges[i].first or second is connected to first
                ok = false;
                for(int j = 0; j < first_graph.size(); ++j){
                    // if connected
                    if(tempEdges[i].first == first_graph[j]){

                        first_graph.push_back(tempEdges[i].second);
                        ok = true;
                        break;
                    }
                    else if(tempEdges[i].second == first_graph[j]){
                        first_graph.push_back(tempEdges[i].first);
                        ok = true;
                        break;
                    }
                }
                // if tempEdges[i].first or second is connected to second
                if(ok == false){
                    for(int j = 0; j < second_graph.size(); ++j){
                        // if connected
                    if(tempEdges[i].first == second_graph[j]){
                        second_graph.push_back(tempEdges[i].second);
                        ok = true;
                        break;
                    }
                    else if(tempEdges[i].second == second_graph[j]){
                        second_graph.push_back(tempEdges[i].first);
                        ok = true;
                        break;
                       }
                    }
                }
                //if ok is true; then we pushed vertex into graph, so we erase it from tempGraph and break for loop
                if(ok == true){
                    tempEdges.erase(tempEdges.begin() + i);
                    break;
                }

            }
        }
        /*
        cout << "first: ";
        for(int j = 0; j < first_graph.size(); ++j){
            cout << first_graph[j] << ' ';
        }
        cout << endl << "second: ";
        for(int j = 0; j < second_graph.size(); ++j){
            cout << second_graph[j] << ' ';
        }
        cout << endl << endl;
        */
        // what we have here, verteces of first and second graph
        // cost of deleted Used Edge
        // no need to check first[0] and second[0] cuz cost is b/w first[0] and second[0]
        // find second_min and third_min
        for(int i = 0; i < first_graph.size(); ++i){
            for(int j = 0; j < second_graph.size(); ++j){
                 // don't wanna check i==0 and j == 0
                if(i+j!= 0){
                    new_cost = graph[first_graph[i]][second_graph[j]];

                    // (new_cost - cost) is diff
                    // if second_min >= diff, third_min = second_min, second_min = diff
                    // if second_min < diff, if third_min >= diff, third_min = diff

                    if( second_min >= (new_cost - cost)){
                        third_min = second_min;
                        second_min = new_cost - cost;
                    }else{
                        if(third_min >= (new_cost - cost)){
                            third_min = new_cost - cost;
                        }
                    }
                }

            }
        }

    }
    //result
    //cout << result << endl;
    //cout << result + second_min << endl;
    //cout << result + third_min;
    std::ofstream ofs("output.txt");
    if (!ofs) {
        std::cerr << "error" << std::endl;
        std::exit(1);
    }

    ofs << result << std::endl;
    ofs << result + second_min << std::endl;
    ofs << result + third_min;
    /*
    for(auto itr = Edges.begin(); itr != Edges.end(); ++itr){
        tempEdges = Edges;
        // clean up
        first_graph.clear();
        second_graph.clear();

        cost = graph[(*itr).first][(*itr).second];


        //since we delete one edge of MST, there will be 2 graphs.
        first_graph.push_back((*itr).first);
        second_graph.push_back((*itr).second);

        // create graphs without itr's Edge, and check second_min and third_min;
        for(auto itr_2 = Edges.begin(); itr_2 != Edges.end(); ++itr_2){
            // without itr's Edge
            if(itr != itr_2){
                    cout << (*itr).first << (*itr).second << endl;
                    //push first or second graph, if *(itr_2).first or *(itr_2).first
            }
        }


    }*/



}
int main()
{
    fastio;
    Solve();

    return 0;
}
