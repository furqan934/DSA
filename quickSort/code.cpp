#include<iostream>
using namespace std;
int partition(int arr[],int pivot,int right){
    int x = arr[right];
    int i = pivot - 1;
    for (int j = pivot; j < right; j++){
        if(arr[j] <= x){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[right]);
    return i + 1;
}
void quickSort(int arr[],int pivot,int right){
    if(pivot < right){
        int pi = partition(arr,pivot,right);
        quickSort(arr,pivot,pi-1);
        quickSort(arr,pi+1,right);
    }
}
void traversing(int arr[],int n){
    for (int i =0 ; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int arr[]={3,6,2,8,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Original array: ";
    traversing(arr,n);
    quickSort(arr,0,n-1);
    cout << "Sorted array: ";
    traversing(arr,n);
    return 0;
}