#include<bits/stdc++.h>
using namespace std;

bool check(int* arr, int size){
    if(size == 0 || size == 1) return true;
    if(arr[0] > arr[1]) return false ;
    else {
        return check(arr + 1,size -1);
    }
}

int main() {
    int arr[5] = {8,8,8,8,8};
    bool ans = check(arr,5);
    if(ans) cout << "Sorted array "<<endl;
    else cout << "Not a sorted array " << endl;
}