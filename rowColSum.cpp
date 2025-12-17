#include<bits/stdc++.h>
using namespace std;

void printSum(int arr[][3], int r, int c){
    cout << "printing Sum: ";
    for(int i = 0;i<r;i++){
        int sum = 0;
        for(int j = 0;j<c;j++){
            sum += arr[i][j];
        }
        cout << "\n Row : "<< sum;
    }
}
void printSumcol(int arr[][3], int r, int c){
    cout << endl << "printing Sum: ";
    for(int i = 0;i<c;i++){
        int sum = 0;
        for(int j = 0;j<r;j++){
            sum += arr[j][i];
        }
        cout << "\n Col : "<< sum;
    }
}

int largestRowSum(int arr[][3], int r, int c){
    int maxi = INT_MIN;
    int rowIndex = 0;
    for(int i = 0;i<r;i++){
        int sum = 0;
        for(int j = 0;j<c;j++){
            sum += arr[i][j];
        }
        if(sum > maxi){
            maxi = sum;
            rowIndex = r;
        }
    }
    cout << endl << "the maximum Row sum is: " << maxi<<endl;
    return rowIndex;
}

int main() {
    int arr[3][3];
    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cin >> arr[i][j];
        }
    }


    for(int i = 0;i<3;i++){
        for(int j = 0;j<3;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    printSum(arr, 3, 3);
    printSumcol(arr, 3, 3);
    int ans= largestRowSum(arr, 3, 3);
    cout << "Largest sum at row index: " << ans;
    
    return 0;
}

