//Задача №99. Поиск подстроки / https://informatics.msk.ru/mod/statements/view3.php?id=241&chapterid=99#1
//Найти все вхождения строки T в строку S.
#include <iostream>
#include <vector>

using namespace std;

vector<int> prefix_function(string s){
    vector<int> pi(s.size());

    for(size_t i=1; i < s.size(); ++i){
        int j = pi[i-1];

        while(j > 0 && s[j] != s[i])
            j = pi[j-1];
        if(s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}
int main(){

    string s,t;
    cin >> s >> t;

    string temp = t + "#" + s;

    vector<int> pi = prefix_function(temp);

    for(size_t i=0; i < pi.size(); ++i){
        if(pi[i] == t.size()){
            printf("%lu ", i - 2*t.size());
        }
    }
    return 0;
}