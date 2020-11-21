/*
Дана строка s[0..n-1]. Требуется вычислить для неё префикс-функцию, т.е. массив чисел π[0..n-1], 
где π[i] определяется следующим образом: это такая наибольшая длина наибольшего собственного суффикса 
подстроки s[0..i], совпадающего с её префиксом (собственный суффикс — значит не совпадающий со всей строкой).
Полное описание алгоритма: http://e-maxx.ru/algo/prefix_function
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> p;
//Итоговый алгоритм. Асимтотика алгоримта O(n) 
void prefix_f(string s){
    p[0] = -1;

    for(int i=1; i <= (int)s.size(); ++i){
        int k = p[i-1];
        while(k >= 0){
            if(s[k] == s[i-1]){
                p[i] = k + 1;
                break;
            }
            k = p[k];
        }
    }
}

int main(){
    string s;
    cin >> s;

    p = vector<int> (s.size());

    prefix_f(s);

    for(int i=0; i <= (int)p.size(); ++i){
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}