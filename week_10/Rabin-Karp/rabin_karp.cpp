#include <iostream>
#include <vector>
#define mod 2305843009213693952;//2^61

using namespace std;

vector<int> ans;

void rabinKarp(string s, string w)//given string and pattern
{
    int n = s.size();
    int m = w.size();

    long long powerP[max(n,m)];//power of prime constant
    const int p = 31;

    powerP[0] = 1;

    for(size_t i=1; i < n; ++i)
        powerP[i] = p * powerP[i-1];

    long long prefHashOfS[n];//hash array for given string 

    for(size_t i=0; i < n; ++i){
        prefHashOfS[i] = powerP[i] * (s[i] - 'a' + 1);
        if(i) prefHashOfS[i] += prefHashOfS[i-1];
    }

    long long hashOfPattern = 0;

    for(size_t i=0; i < m; ++i)
        hashOfPattern += (powerP[i] * (w[i] - 'a' + 1));

    for(size_t i=0; i <= max(n,m) - min(n,m); ++i){
        long long temp = prefHashOfS[i+m-1];
        if(i != 0) temp -= prefHashOfS[i-1];
        if(hashOfPattern * powerP[i] == temp)
            ans.push_back(i);
    }
}

int main(){

    string s,w;
    cin >> s >> w;

    rabinKarp(s,w);

    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}