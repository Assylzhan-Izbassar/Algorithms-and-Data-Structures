#include <iostream>
#include <vector>

using namespace std;

bool f(vector<double> &x, int k, long long D){

    long long cows = 1;
    long long min = 1e12;
    long long distance = 0;

    for(int i=x.size() - 1; i > 0; --i){    
        if(distance == 0){
            for(int j=i-1; j >= 0; --j){
                if((x[i]-x[j]) <= min){
                    if(x[i] - x[j] >= D){
                        min = x[i] - x[j];
                        cows++;
                        i = j + 1;
                        distance = 0;
                        cout << "When D is: "<< D <<  " index => " <<  j << endl;
                        break;
                    }else{
                        distance = x[i] - x[j];
                    }
                }
            }
        }
    }
    if(distance < min){
        min = distance;
        cows++;
    }
    cout << "When D is: "<< D <<  " min => " <<  min << " cows => " << cows << endl;
    return min >= D && cows <= k;
}

int main(){

    int n, k;
    cin >> n >> k;

    vector<double> v(n);

    for(size_t i=0; i < n; ++i) cin >> v[i];

    long long l = 0;
    long long r = 21;

    while(r > l + 1){
        long long D = l + (r-l)/2;

        if(f(v,k,D)){
            l = D;
        }else{
            r = D;
        }
    }
    cout << l << endl;

    return 0;
}