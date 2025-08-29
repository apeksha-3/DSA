#include <iostream>
#include<climits>
using namespace std;

// Find the second largest element in an array 

/*
Brute Method : Sort the array 
-> last element is the largest (size -1 ) 
-> second last element will be found at n-2 
    but here is the catch 
    if largest = element at (n-2) then we cannot consider that to be second largest 
    so we need one more loop to check whether n-2 = largest 
    if yes check for n-3 and so on..
    if no second largest = n-2 element 

example : 1 2 3 5 7 7 
    largest = 7 and arr[n-2] = 7
    here we need the checking
Time complexity : depends on sorting algo.
*/
void BubbleSort (int*arr , int size){
 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int SLargest_1(int *arr, int size)
{
    int slargest = INT_MIN ;

    BubbleSort(arr,size);
    int largest = arr[size-1];
    for (int i = size-2 ; i >= 0; i--){
        if (arr[i]!= largest){
            slargest = arr[i] ;
            break;
        }
    }
    return slargest ;
}

/*
Better Method : 
-> First we will find largest element using optimal approach
-> largest(variable) have largest value and slargest = MIN_LIMIT
-> Again we have a loop over the array 
    if the current element is strictly smaller than(not equal to) the largest and greater than
    to slargest 
    slargest = current element 
Time Complexity : first loop O(n) second O(n) => O(2n)
   
*/

int Slargest_2 (int* arr , int size){
    int largest = arr[0];
    int slargest = INT_MIN ;
    // for largest 
    for (int i = 0; i < size; i++)
    {
        if (largest < arr[i])
            largest = arr[i];
    }
    // for slargest 
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > slargest && arr[i] != largest){
           slargest = arr[i] ; 
        }
    }
    return slargest ;
}

/*
Optimal Method : 
-> largest = arr[0] and slargest = MIN_LIMIT
-> we will have a loop in which largest will be compared with array element and if
largest change its value will be store in second largest 
Ex. 4 8 6 
largest = 8 
slargest = 4 
so to get slargest = 6 , we have this condition 
-> if arr[i] is smaller than largest 
then arr[i] should be strictly greater than slargest and should not be equal to largest 
*/

int Slargest_3 (int* arr , int size){
    int largest = arr[0] , slargest = INT_MIN ;
    for (int i = 0 ; i < size ; i++){
        if (arr[i] > largest){
            slargest = largest ;
            largest = arr[i];
        }
        else if (arr[i]>slargest && arr[i]!=largest){
            slargest = arr[i] ;
        }
    } 
    return slargest ;
}

int main (){
    int size ;
    cout << "Enter the size of array :" << endl ;
    cin >> size ;
    int* arr = new int[size] ;
    cout << "Enter the element of array : " << endl ;
    for (int i = 0 ; i < size ; i++){
        cin >> arr[i] ;
    }

    cout << "The second largest value from Brute method : " << SLargest_1(arr,size) << endl ;
    cout << "The second largest value from Better method : " << Slargest_2(arr,size) << endl ;
    cout << "The second largest value form optimal method : " << Slargest_3(arr,size) << endl ;

    delete[] arr ;
    return 0 ;
}