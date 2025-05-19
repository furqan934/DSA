#include<iostream>
using namespace std;

int factorial(int n){
    int fact = 1;
    for (int i = 1; i <= n ; i++){
        fact *= i;
    }
    return fact;
}
int main(){
    int num;
    cout <<"Enter a Number: ";
    cin >> num;
    if (num < 0){
        cout <<"Factorial for negative no doesn't Exist!" << endl;
    }
    else{
        cout << "Itrative Factoroial of the Number ("<< num <<") is: "<< factorial(num) << endl;
    }
}