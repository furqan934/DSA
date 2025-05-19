#include<iostream>
using namespace std ;
int recursion(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    else{
        return n * recursion(n - 1);
    }
}
int main(){
    int num;
    cout <<"Enter a number you  Want to Recurse: ";
    cin >> num;
    int num;
    cout <<"Enter a Number: ";
    cin >> num;
    if (num < 0){
        cout <<"Factorial for negative no doesn't Exist!" << endl;
    }
    else{
        cout << "Recursive Factoroial of the Number ("<< num <<") is: "<< (num) << endl;
    }
}