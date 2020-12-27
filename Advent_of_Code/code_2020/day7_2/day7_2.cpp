#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;
typedef pair<string,int> psi;
const int INF=2e9;
const int MOD=1e9+7;


int related_bags(string pBag, unordered_map <string, vector<psi>> &bags){

    if(bags.find(pBag) == bags.end()){
        return 1;
    }else{
        int ans = 1;
        //each case, check their child bags
        for(auto itr = bags[pBag].begin(); itr != bags[pBag].end(); ++itr){
            //cerr << (*itr).first << ':' << (*itr).second <<endl;
            ans += ((*itr).second * related_bags((*itr).first,bags));
        }
        cout << ans << endl;
        return ans;
    }


}


void Solve()
{
    ifstream ifs("input.txt");
    if (ifs.fail()) {
        cerr << "Failed to open file." << endl;
        exit(1);
    }

    unordered_map <string, vector<psi>> bags;
    string str;
    while(getline(ifs, str)){
        string pBag,cBag,tmp;
        int value;
        pBag = str.substr(0,str.find("bag")-1);
        tmp = str.substr(str.find("contain") + 8);
        //cerr << cBag << ' ' << tmp << endl;
        while(tmp.find(',') != string::npos ){
            //This contains int and string
            cBag = tmp.substr(0,tmp.find("bag")-1);

            value = stoi(cBag.substr(0,cBag.find(' ')));
            cBag = cBag.substr(cBag.find(' ')+1);
            bags[pBag].push_back(psi(cBag,value));
            //cout << cBag << ' ' << pBag <<endl;
            tmp = tmp.substr(tmp.find(',')+2);
        }
        // this pBag may not contain any bags
        cBag = tmp.substr(0,tmp.find("bag")-1);
        if(cBag.substr(0,cBag.find(' ')) == "no"){

        }else{
            value = stoi(cBag.substr(0,cBag.find(' ')));
            cBag = cBag.substr(cBag.find(' ')+1);
            //cout << cBag << ' ' << pBag <<endl;

            bags[pBag].push_back(psi(cBag,value));

        }
    }





    ofstream ofs("output.txt");
    if (!ofs) {
        cerr << "error" << std::endl;
        exit(1);
    }
    //check includes "shiny gold"
    ofs << related_bags("shiny gold", bags)-1;
    ifs.close();
    ofs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}