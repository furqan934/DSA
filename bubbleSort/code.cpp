#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n){
    for ( int i = 0 ; i <n-1; i++)
    {   
        bool swaped = false;
        for (int j=0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swaped = true;
            }
        }
        if(!swaped){
            cout <<"already sorted is the array!\n";
            break;
        }
    }
}
void traversing(int arr[],int n){
    for (int i =0 ; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[]={5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original array: ";
    traversing(arr,n);
    bubbleSort(arr,n);
    cout << "Sorted array: ";
    traversing(arr,n);
    return 0;
}