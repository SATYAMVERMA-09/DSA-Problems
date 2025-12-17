#include<bits/stdc++.h>
using namespace std;

void merge(int* arr, int s, int e){

    int mid = s + (e-s)/2;
    int right = mid + 1;
    int size = e-s+1;
    int left = s;
    int *fresh = new int[size];
    int index = 0;
    while(s<=mid && right<=e){
        if(arr[s] < arr[right]){
            fresh[index++] = arr[s++];
        }
        else{
            fresh[index++] = arr[right++];
        }
    }
    while(s <= mid){
        fresh[index++] = arr[s++];
    }

    while(right <= e){
        fresh[index++] = arr[right++];
    }

    for(int i =0;i<size;i++){
        arr[left + i] = fresh[i];
    }
    delete []fresh;
}

void mergeSort(int* arr,int s, int e){
    
    if(s>=e) return;

    int mid = s + (e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

int main() {
    int arr[5] = {6,3,8,7,9};
    int n = 5;
    mergeSort(arr,0,n-1);
    for(int i =0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}