#include <iostream>
#include<climits>
using namespace std;
/*
Need to find the max number 1 appeared consecutively 
arr[] = [0 0 1 1 0 0 0 1 1 1 1 0 0]
max = 4 
*/

/*Optimal */
int MaxOne (int arr[] , int n){
    int count = 0 , maxi = 0 ;

    for (int i = 0 ; i < n ; i++){
        if (arr[i] == 1){
            count++ ;
            maxi = max(count,maxi);
        }
        else {
            count = 0 ;
        }
    }
    return maxi ;
}

int main (){
    int n ;
    cout << "Enter size of the array: " << endl;
    cin >> n ;

    int* arr = new int [n] ;
    cout << "Enter the element of the array :" << endl ;
    for (int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }
    int max = MaxOne(arr,n) ;
    cout << "The max consecutive one is : " << max ;
}