#include <iostream>
using namespace std ;

int main () {
    int size ;
    cout << "Enter the size of the array :" << endl ;
    cin >> size ;
    bool flag = true ;
    int* arr = new int[size];
    cout << "Enter the element of the array :" << endl ;
    for (int i = 0 ; i < size ; i++){
        cin >> arr[i] ;
    }
    for (int i = 0 ; i < size-1 ; i++){
        if (arr[i] > arr[i+1]){
            flag  = false;
            break ; // instead of break i = size to terminate
        }
    }
    if (flag)
    cout << "Array is sorted" << endl;
    else 
    cout << "Array is not sorted " ;

    delete[] arr ;
    return 0;
}