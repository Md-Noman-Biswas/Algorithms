#include<bits/stdc++.h>
using namespace std;
int upper_bound(vector<int> &v, int element){
    int l = 0;
    int h = v.size()-1;
    while(h-l > 1){
        int mid = (h+l)/2;
        if(v[mid] <= element){
            l = mid+1;
        }else{
            h = mid;
        }
    }
    if(v[l] > element){
        return l;
    }
    if(v[h] > element){
        return h;
    }else{
        return -1;
    }
}
int lower_bound(vector<int> &v, int element){
    int l = 0;
    int h = v.size()-1;
    while(h-l > 1){
        int mid = (h+l)/2;
        if(v[mid] < element){
            l = mid+1;
        }else{
            h = mid;
        }
    }
    if(v[l] >= element){
        return l;
    }
    if(v[h] >= element){
        return h;
    }else{
        return -1;
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int element;
    cin >> element;
    int lb = lower_bound(arr, element);
    cout << lb << " " << (lb != -1 ? arr[lb]: -1) << "\n";
    int ub = upper_bound(arr, element);
    cout << ub << " " << (ub != -1? arr[ub]: -1) << "\n";
}