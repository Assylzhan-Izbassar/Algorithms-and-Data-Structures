#include <iostream>
#include <vector>

using namespace std;

bool isEqualPrefix(string s, string p){
    for(size_t i=0; i < p.size(); ++i){
        if(s[i] != p[i])
            return false;
    }
    return true;
}

bool isEqualSuffix(string s, string p){
    for(int i=0; i < p.size(); ++i){
        if(s[s.size()-p.size()+i] != p[i]){
            return false;
        }
    }
    return true;
}

int isEqual(string s){

    int count = 0;
    string temp;

    for(size_t i=0; i < s.size(); ++i){
        temp = ""; 
        for(size_t j=i; j < s.size(); ++j){
            temp += s[j];
            if(isEqualPrefix(s, temp) && !isEqualSuffix(s,temp)){
                count++;
            }
            if(isEqualSuffix(s,temp) && !isEqualPrefix(s,temp)){
                count++;
            }
        }
    }
    return count;
}

int main(){

    int t;
    cin >> t;

    vector<string> v(t);
    string s;

    for(size_t i=0; i < v.size(); ++i){
        cin >> s;
        v[i] = s;
    }   

    for(size_t i=0; i < v.size(); ++i){
        cout << isEqual(v[i]) << endl;
    }

    return 0;
}