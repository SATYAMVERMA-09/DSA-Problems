#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int s, int e) {
    int cnt = 0;

    int pivot = arr[s];
    for(int i =s+1;i<=e;i++){
        if(arr[i] <= pivot){
            cnt++;
        }
    }
    int pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);
    int i = s, j = e;
   // cout << pivot << "-" << arr[pivotIndex] <<endl;
    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex) {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}


void sorting(int arr[],int s, int e){
    if(s>=e) return;

    int p = partition(arr,s,e);
    sorting(arr,s,p-1);
    sorting(arr,p+1,e);
}

int main() {
    int arr[10] = {2,3,5,6,7,8,8,6,1,2};
    sorting(arr,0,9);
    for(int i = 0;i<10;i++){
        cout << arr[i] << " ";
    }
    return 0;
    }