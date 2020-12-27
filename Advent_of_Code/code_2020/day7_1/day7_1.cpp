#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;
/*
    store info: (child bag, parent bag) -> map<string,vector<string>>
    check shiny gold -> bags that constains child bag (vector<string>) -> check these bags parents if unchecked
*/

void related_bags(string cBag, unordered_map <string, vector<string>> &bags, unordered_set<string> &check){

    if(bags.find(cBag) != bags.end()){
        for(auto itr = bags[cBag].begin(); itr != bags[cBag].end(); ++itr){
            //if not chekced
            if(check.find(*itr) == check.end()){
                related_bags(*itr, bags, check);
            }
        }
    }
    check.insert(cBag);
}


void Solve()
{
    ifstream ifs("input.txt");
    if (ifs.fail()) {
        cerr << "Failed to open file." << endl;
        exit(1);
    }

    unordered_map <string, vector<string>> bags;
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
            bags[cBag].push_back(pBag);
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

            bags[cBag].push_back(pBag);

        }
    }


    unordered_set<string> check;
    related_bags("shiny gold", bags, check);

    ofstream ofs("output.txt");
    if (!ofs) {
        cerr << "error" << std::endl;
        exit(1);
    }
    //check includes "shiny gold"
    ofs << check.size()-1;

    ifs.close();
    ofs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}