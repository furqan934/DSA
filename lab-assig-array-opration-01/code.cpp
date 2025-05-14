#include<iostream>
#include<cmath>
using namespace std ;
const int MAX = 100;
// Display all elements of the array
void display(int arr[],int n )
{
    cout << "array elaments are" ;
    for (int i=0; i < n ; i ++ )
    {
        cout << arr[i]<<" ";
    }
    cout << endl;
}
// insertion at end of the array.
void  insertAtEnd(int arr[] , int &n , int value )
{
    if(n >= MAX)
    {
        cout <<"array is full!";
    }
    arr[n]=value;
    n++;
    cout <<" element["<<value<<"] are  inserted at end succesfully\n";
}
// insertion at user specified location in the array.
void insertAtSpecificLocation(int arr[],int &n ,  int value,int pos)
{
    if(n >= MAX)
    {
        cout <<"array is full!";
    }
    if (pos < 0 || pos > n)
    {
        cout <<" invalid position! so insertion is invalid.";
    }
    for (int i=n; i>pos ; i --)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
    cout <<" element["<<value<<"] are  inserted uccesfully at position"<<pos<<"\n";
}
// Delete a user specified element:
void deleteOfUserSpecifidElement(int arr[] , int n, int value )
{
    int i;
    for (int i=0 ; i < n ; i ++)
    {
        if ( arr[i] == value);
        break;
    }
    if(i == n || i == -1)
    {
        cout << " element is not found!";
        return;
    }
    int j =i;
    for (j=i; j < n-1 ; j ++)
    {
        arr[j] = arr[j+1];
        // arr[j]= null;
    }
    n -- ;
    cout << "Deleted element " << value << ".\n";
}
//Search for the user specified element
int searchElemntLinear(int arr[],int n , int k)
{
    for (int i =0 ; i < n ; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}
//Report Statistics:
void reportStatistics(int arr[],int n)
{
    if(n == 0)
    {
        cout << "array is empty.no statistic to repport!";
        return;
    }
    int max,min = arr[0];
    int sum = 0;
    for (int i=0; i < n; i ++)
    {
        if(arr[i] > max)
        {
            max = arr[i] ;
        }
        if(arr[i] < min)
        {
            min = arr[i] ;
        }
        sum += arr[i];
    }
    // use statistic cast to ge value in double 
    double avg = static_cast<double> (sum) / n;

    double variance = 0;
    for (int i = 0; i < n; ++i)
    {
        variance += pow(arr[i] - avg, 2);
    }
    variance /= n;
    double stdDev = sqrt(variance);
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Average: " << avg << endl;
    cout << "Standard Deviation: " << stdDev << endl;
}
int main()
{
    int arr[MAX] = {1,2,3,4};
    int n= 4;
    int choice ;
    int invalidCount =0;
    do{
        cout << "\nMenu:\n";
        cout << "1. Display all elements\n";
        cout << "2. Insert an element at the end\n";
        cout << "3. Insert an element at a user-specified location\n";
        cout << "4. Delete a user-specified element\n";
        cout << "5. Search for a user-specified element\n";
        cout << "6. Report Statistics\n";
        cout << "7. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 1 || choice > 7)
        {
            cout << "invlid choice.Please enter choice between 1 and 7.\n";
            invalidCount ++;
            if (invalidCount >=2)
            {
                cout << "Too many invlid attempts.Exit!\n";
                break;
            }
            continue;
        }   
        invalidCount = 0;
        int value;
        int pos;
        switch(choice)
        {
            case 1: 
                display(arr,n);
                break;
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAtEnd(arr,n,value);
                break;
            case 3:
                cout << "Enter position (0 to " << n << "): ";
                cin >> pos;
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtSpecificLocation(arr, n,pos, value);
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteOfUserSpecifidElement(arr,n,value);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                searchElemntLinear(arr,n,value);
                break;
            case 6:
                reportStatistics(arr,n);
                break;
            case 7:
                cout << "Exiting program. Goodbye!\n";
                break; 
        }
    } while (choice != 7);
    }