#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string& name, int i, int j){
    
    if(i>j) return true;
    if(name[i] != name[j]) return false;
    else{
        return isPalindrome(name, i + 1 , j - 1);
    }

    
}

int main() {
    string name = "abcba";
    cout << endl;
    bool ans = isPalindrome(name, 0, name.size()-1);
    if(ans) cout << "It is a palindrome" <<endl;
    else cout << "Not a palindrome" <<endl;;
}