#include <iostream>
using namespace std;

void pointer (int *p) {

    cout << p <<endl;
}
void update (int *p) {
    //p += 1;
    //cout << "inside: " << p<<endl;
    p += 1;
    *p += 1;
}
int getSum(int *arr,int n){
    cout << "Size is: " << sizeof(arr)<<endl;
    int sum =0 ;
    for(int i =0 ;i<n;i++) {
        sum += arr[i];  
    }
    return sum;
}



int main(){

   /* int a = 5;
    int *p = &a;
    cout << "Before update: "<<*p <<endl;
    update(p);
    cout << "After update: " << *p<<endl;
*/

    int arr[6] = {1,2,3,4,5,6};
    cout << endl << getSum(arr+3, 3) <<endl;

    return 0;
}