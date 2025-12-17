#include<bits/stdc++.h>
using namespace std;

int getSum(int* arr, int size) {
    if(size == 0) return 0;
    if(size == 1 )return arr[0];
    
    int rem = getSum(arr +1 ,size -1);
    int sum = arr[0] + rem;
    return sum;            
}
 
int main() {
    int arr[5] = {0,2,6,8,9};
    int ans = getSum(arr,5);
    cout << "Sum is : " << ans << endl;
}