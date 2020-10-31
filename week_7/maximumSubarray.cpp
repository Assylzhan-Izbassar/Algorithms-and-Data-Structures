#include <iostream>
#include <vector>

using namespace std;

struct indices{

    private:
        int low, high;
        int sum;

    public:
        indices(int _low, int _high, int _sum){
            low = _low;
            high = _high;
            sum = _sum;
        }
        void setLow(int _low){
            low = _low;
        }
        void setHigh(int _high){
            high = _high;
        }
        void setSum(int _sum){
            sum = _sum;
        }
        int getLow(){
            return low;
        }
        int getHigh(){
            return high;
        }
        int getSum(){
            return sum;
        }
};

indices find_max_crossing_subarray(vector<int>& arr, int low, int mid, int high){

    int left_sum = -INT_MAX;
    int sum = 0;
    int max_left;

    for(int i = mid; i >= low; --i){
        sum = sum + arr[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = -INT_MAX;
    int max_right;
    sum = 0;

    for(int j = mid+1; j <= high; ++j){
        sum = sum + arr[j];
        if(sum > right_sum){
            right_sum = sum;
            max_right = j;
        }
    }
    return indices(max_left, max_right, left_sum+right_sum);
}

indices find_maximum_subarray(vector<int>& arr, int low, int high){
    if(low == high){
        return indices(low, high, arr[low]);
    }
    int mid = low + (high - low)/2;

    indices left = find_maximum_subarray(arr, low, mid);
    indices right = find_maximum_subarray(arr, mid+1, high);

    indices cross = find_max_crossing_subarray(arr,low, mid, high);

    if(left.getSum() >= right.getSum() && left.getSum() >= cross.getSum())
        return left;
    else if(right.getSum() >= left.getSum() && right.getSum() >= cross.getSum())
        return right;
    return cross;
}

int main(){

    vector<int> arr;

    int n;
    scanf("%d", &n);

    int x;

    for(int i=0; i < n; ++i){
        cin >> x;
        arr.push_back(x);
    }
    
    indices result = find_maximum_subarray(arr, 0, arr.size()-1);

    cout << result.getLow() << " " << result.getHigh()+1 << " " << result.getSum() << endl;

    return 0;
}
