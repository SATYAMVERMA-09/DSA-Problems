#include<bits/stdc++.h>
using namespace std;

void insertionSort(int* arr,int n, int position){
    //base case 
    if(position >= n) return;
    int key = 0;
    for(int i = 0;i<position;i++){
        if(arr[i] > arr[position]) key = i;

    }
    for(int i )
}

int main() {
    int arr[5] = {5,2,7,4,1};
    
    
    insertionSort(arr,5,1);

    for(int i = 0;i<5;i++){
        cout << arr[i] << " ";
    }
}