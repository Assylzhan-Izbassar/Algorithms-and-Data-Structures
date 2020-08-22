#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string p){
    for(size_t i=0; i < p.size(); ++i){
        if(p[i] != p[p.size() - 1 - i]){
            return false;
        }
    }
    return true;
}

int max_prefix_palindrome(string s){
    string prefix = "";
    string temp = "";
    for(size_t i=0; i < s.size(); ++i){
        temp += s[i];
        if(isPalindrome(temp)){
            prefix = temp;
        }
    }
    return prefix.size();
}

int main(){

    int t;
    cin >> t;
    
    string s;
    vector<string> v(t);

    for(size_t i=0; i < t; ++i){
        cin >> s;
        v[i] = s;
    }

    for(size_t i=0; i < v.size(); ++i){
        cout << max_prefix_palindrome(v[i]) << endl;
    }

    return 0;
}