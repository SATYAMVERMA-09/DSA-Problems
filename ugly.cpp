#include<bits/stdc++.h>
using namespace std;
bool uglynumber(int n) {
    if(n == 1) return true;
    if(n%2 == 0) return uglynumber(n/2);
    else if(n%3 == 0) return uglynumber(n/3);
    else if(n%5 == 0) return uglynumber(n/5);
    else return false;
}

int main() {
    int number;
    cout << "Enter the number: ";
    cin >> number;
    if(uglynumber(number)) cout << endl<< "Ugly number" <<endl;
    else cout << " not ugly number ";
    return 0;
}