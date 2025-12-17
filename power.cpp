#include<bits/stdc++.h>
using namespace std;

int power(int a , int b){
    if(b == 0) return 1;
    if(b == 1) return a;

    //recursion
    int ans = power(a,b/2);

    if(!(b&1)) return ans * ans;
    else return a * ans * ans;
}

int main() {
    int a,b;
    cin >> a >> b;
    int res = power(a,b);
    cout <<res << endl;
}