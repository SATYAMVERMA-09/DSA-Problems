#include <bits/stdc++.h>
using namespace std;

int getSum (int *arr, int n){
  int sum = 0;
  for(int i = 0;i< n ;i++) {
    sum += arr[i];
  }
  return sum;
}
int main() {
/*
  int n ;
  cin >> n;
  int* arr = new int[n];
  for(int i = 0;i< n;i++) {
    cin >>  arr[i];
  }
  int ans  = getSum(arr,n);
  cout << "Answer is : " << ans <<endl;

  int a;
  cin >> a;
  int** arr1 = new int*[a];

  for(int i =0;i<a;i++) {
    arr1[i] = new int[a];
  }

// take input 

for(int i = 0;i<a;i++) {
  for(int j = 0;j<a;j++) {
    cin >> arr1[i][j];
  }
}
// print output 

for(int i = 0;i<a;i++) {
  for(int j = 0;j<a;j++) {
    cout << arr1[i][j] << " ";
  }
  cout << endl;
  }
  
// release the memory

for(int i = 0;i<a;i++) {
  delete [] arr1[i];
}

delete [] arr1;
*/
/*  
  int row ;
  cin >> row;
  int col ;
  cin >> col;
 
  int** arr = new int*[row];

  for(int i = 0;i<row;i++) {
    arr[i] = new int[col];
  }

  for(int i = 0;i< row;i++) {
    for(int j = 0;j< col;j++) {
      cin >> arr[i][j];
    }
  }

  for(int i = 0;i< row;i++) {
    for(int j = 0;j< col;j++) {
      cout << arr[i][j] << " ";
    }
    cout <<endl;
  }
*/
/*
int n = 5;
  while(true) {
    int* val = new int[n];
  }
*/

  int row;
  cin >> row;
  int** arr = new int*[row];

  vector<int> colume(row);

  for(int i = 0;i<row;i++){

    cout << "Enter colume size for row" << i << ":";
    cin >> colume[i];
    
    arr[i] = new int[colume[i]];
    
    }

    // input 
    for(int i = 0;i< row;i++) {
      cout << "Enter " << colume[i] << " elements for row " << i << ": ";
      for(int j = 0;j< colume[i];j++) {
        cin >>  arr[i][j];
      }
    }

    //output

    for(int i = 0;i< row;i++) {
      for(int j = 0;j<colume[i];j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }

    for(int i =0;i<row;i++){
      delete [] arr[i];
    }
    delete [] arr;

  return 0;
}