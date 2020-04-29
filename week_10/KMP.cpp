/*
Дана строка s[0..n-1]. Требуется вычислить для неё префикс-функцию, т.е. массив чисел π[0..n-1], 
где π[i] определяется следующим образом: это такая наибольшая длина наибольшего собственного суффикса 
подстроки s[0..i], совпадающего с её префиксом (собственный суффикс — значит не совпадающий со всей строкой).
Полное описание алгоритма: http://e-maxx.ru/algo/prefix_function
*/

#include <iostream>
#include <vector>

using namespace std;

//Итоговый алгоритм. Асимтотика алгоримта O(n) 
vector<int> prefix_function(string s){

    vector<int> pi(s.size());

    for(size_t i=1; i < s.size(); ++i){//Значение π[i] будем считать по очериди
        int j = pi[i-1];// j длина текущего рассматриваемого образца
        while(j > 0 && s[j] != s[i])
            j--;
        if(s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

int main(){

    string s;
    getline(cin, s);

    vector<int> temp = prefix_function(s);

    for(size_t i=0; i < temp.size(); ++i){
        printf("%d ", temp[i]);
    }

    cout << endl;

    return 0;
}