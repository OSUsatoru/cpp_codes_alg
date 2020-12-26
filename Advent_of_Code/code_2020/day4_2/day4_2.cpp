#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

typedef long long ll;

const int INF=2e9;
const int MOD=1e9+7;
// no need cid

deque<string> keys{"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}, cpyKeys=keys;
vector<string> eyes{"amb", "blu","brn","gry","grn","hzl","oth"};

bool Sisdigit(const string& str){
    for(char const&ch: str){
        if(!isdigit(ch)){
            return false;
        }
    }
    return true;
}

void Solve()
{
    ifstream ifs("input.txt");
    if (ifs.fail()) {
        cerr << "Failed to open file." << endl;
        exit(1);
    }
    int cnt = 0,num;
    string str;
    while(getline(ifs,str)){
        if(str.empty()){
            if(keys.empty()){
                ++cnt;
            }
            keys = cpyKeys;
        }else{
            string tmp,key,value,unit;
            stringstream ss;
            ss << str;
            while(getline(ss,tmp,' ')){
                key = tmp.substr(0,3);
                value = tmp.substr(4);
                for(int i = 0; i < keys.size(); ++i){
                    if(keys[i]==key){
                        bool ok = false;
                        if(key == "byr"){
                            if(Sisdigit(value)){
                                num = stoi(value);
                                if(num >= 1920 and num <= 2002){
                                    ok = true;
                                }
                            }
                        }else if(key == "iyr"){
                            if(Sisdigit(value)){
                                num = stoi(value);
                                if(num >= 2010 and num <= 2020){
                                    ok = true;
                                }
                            }
                        }else if(key == "eyr"){
                            if(Sisdigit(value)){
                                num = stoi(value);
                                if(num >= 2020 and num <= 2030){
                                    ok = true;
                                }
                            }
                        }else if(key == "hgt"){
                            unit = value.substr(value.length()-2);
                            value = value.substr(0,value.length()-2);

                            if(unit == "cm"){
                                if(Sisdigit(value)){
                                    num = stoi(value);
                                    if(num >= 150 and num <= 193){
                                        ok = true;
                                    }
                                }
                            }else if(unit == "in"){
                                if(Sisdigit(value)){
                                    num = stoi(value);
                                    if(num >= 59 and num <= 76){
                                        ok = true;
                                    }
                                }
                            }
                        }else if(key == "hcl"){
                            if(value[0]=='#' and value.length() == 7){
                                bool check = true;
                                for(int i = 1; i < 7; ++i){
                                    if(value[i] < '0' or value[i] >'9' and value[i] < 'a' or value[i] > 'f'){
                                        check = false;
                                    }
                                }
                                if(check){
                                    ok = true;
                                }
                            }
                        }else if(key == "ecl"){
                            if(find(eyes.begin(),eyes.end(),value)!=eyes.end()){
                                ok = true;
                            }
                        }else if(key == "pid"){
                            if(Sisdigit(value) and value.length()==9){

                                ok = true;
                            }
                        }
                        if(ok){
                            keys.erase(keys.begin()+i);
                        }
                        break;
                    }
                }
            }
        }

    }
    //last case
    if(keys.empty()){
        ++cnt;
    }


    ofstream ofs("output.txt");
    if (!ofs) {
        cerr << "error" << std::endl;
        exit(1);
    }

    ofs << cnt;
    ifs.close();


}
int main()
{
    fastio;
    Solve();

    return 0;
}