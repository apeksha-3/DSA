#include <iostream>
using namespace std;

// To find the largest element from the array
/*
1. Brute Method : 
-> Sort the array and then the last element will be the largest
=> Time complexity : depends upon the Sorting algo used
here because of bubble sort it is O(n^2)
*/

int Largest_1(int *arr, int size)
{

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
    return arr[size - 1];
}

/*
Optical Method : 
-> Take a variable(largest) and store the first elememt.
-> Now in loop start comparing that variable(largest) to every elment of the array
-> Element which is greater than the largest , change the value of largest to that element
=> Time Comlexity : O(n)
*/
int Largest_2(int *arr, int size)
{
    int largest = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (largest < arr[i])
            largest = arr[i];
    }
    return largest;
}

int main()
{
    int n;
    cout << "Enter the size of array :" << endl;
    cin >> n;

    int *arr = new int[n]; // dyanmic array
    cout << "Enter the element in the array : " << endl ;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The largest element using Brute method : " << Largest_1(arr, n) << endl;
    cout << "The largest element using Optimal mehtod : " << Largest_2(arr, n) << endl;

    delete []arr ;
    return 0;
}