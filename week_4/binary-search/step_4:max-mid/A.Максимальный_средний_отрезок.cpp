#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &a){
    for(size_t i=0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout << endl;
}

struct f_data
{
    bool result;
    int index;

    f_data(bool result_, int index_){
        result = result_;
        index = index_;
    }
};

int g(vector<double> &m, vector<double> &p, int r, int d){
    return m[r-d] <= p[r];
}


f_data f(vector<int> &a, int d, double x){

    vector<double> p(a.size()+1);
    p[1] = a[0] - x;

    for(size_t i=2; i <= a.size(); ++i){
        p[i] = a[i-1] - x + p[i-1];
    }

    vector<double> m(a.size()+1);
    m[0] = p[0];

    for(size_t i=1; i <= a.size(); ++i){
        m[i] = min(p[i], m[i-1]);
    }
    int rx = -1;
    for(int r = 0; r <= a.size(); ++r){
        if(g(m,p,r,d)){
            rx = r;
            break;
        }
    }
    if(rx == -1){
        return f_data(false, rx);
    }

    return f_data(true, rx);
}

int main(){
    ios::sync_with_stdio(false);

    int n,d;
    cin >> n >> d;

    vector<int> a(n);

    for(size_t i=0; i < n; ++i) cin >> a[i];

    double l = -1;
    double r = 400;

    int rx = -1;

    while(r > l + 1){
        double x = l + (r-l)/2;
        f_data t = f(a,d,x);
        if(t.result){
            l = x;
            rx = t.index;
        }else{
            r = x;
        }
    }

    cout << rx << endl;

    return 0;
}