#include<bits/stdc++.h>
using namespace std;

void sayDigit(string arr[],int n) {
    if(n==0) return ;
    int rem = n % 10;
    n /= 10;
    sayDigit(arr,n);
    cout << arr[rem] << " ";
}

int main() {
    int n;
    cout << "Enter the number: " ;
    cin >> n;
    string arr[10] = {"zero","one","two","three","four","five",
                "six","seven","eight","nine"
    };
    sayDigit(arr,n);
}