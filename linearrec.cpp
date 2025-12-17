#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int* arr, int size, int key) {
    if(size == 0) return false;
    if(arr[0] == key) return true;
    else {
        return linearSearch(arr + 1, size -1,key);
    }
}


int main() {
    int arr[5] = {4,6,7,8,9};
    int key = 9;
    bool ans = linearSearch(arr, 5, key);
    if(ans) cout << "Present " << endl;
    else cout << "Absent" << endl;
    return 0;
}