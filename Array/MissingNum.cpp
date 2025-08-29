#include <iostream>
using namespace std;
/*Find the number of missing number
ex. N = 5 so element should be 1 to 5 (1 toh N)
arr [] = [1 2 4 5 ]
size of arr n = N-1 (one element less)
*/

/*Brute force :
i=> 1 to N : This will be for comparing i(1,2,3,4,5)
ex. N = 5 , element should 1 to 5 and i will also be from 1 to 5
if i value in iteration is present in the array then no element is missing
*/
int Missing_1(int arr[], int N)
{
    int flag = 0;
    int elem, i;
    for (i = 1; i <= N; i++) // i = 1 , 2 , 3 , 4 , 5
    { 

        flag = 0; // for every i flag should be set to 0 again

        for (int j = 0; j < N - 1; j++) // used to access array element
        { 
            if (arr[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return i;
    }
    return 0;
}
/* Better : Using hasing 
Hash array with size N+1 (0-N) is created  
element which is present in the arr is hashed i.e 
In hash array , index of element in arr is marked with 1 and element not presentis marked with 0
hash loop starting from 1 to ignor index 0 with 0 as value (phele se 0 mil jayega nahi toh)
ex. arr [N-1] = [1 2 4 5] 

    Inintally   0 1 2 3 4 5   ----index      
    hash [N+1]=[0 0 0 0 0 0]

After hashing  0 1 2 3 4 5    ----index/element of arr
    hash[N+1]=[0 1 1 0 1 1] 

    
*/
int Missing_2(int arr[] , int N){
    int* hash = new int [N+1] ;
    for (int i = 0 ; i < N-1 ; i++){
        hash[arr[i]]++ ;
    }
    int i ;
    for (i = 1 ; i <= N ; i++){
        if (hash[i] == 0)
        return i ;
    }
    
    return 0 ;
}

/*Optimal : 
    Method 1 -> sum 
    Method 2 -> XOR 
*/
/*Method 1 : Sum 
sum of n natural number(S) = n (n+1)/2
and sum of arr = x
missing no. = S - x
*/
int Missing_3(int arr[] , int n){
    int sum = n*(n+1)/2 ;
    int sumarr= 0 ;
    for (int i = 0 ; i < n-1 ; i++){
        sumarr +=arr[i] ;
    }
    return sum - sumarr ;
}
int main()
{
    int size;
    cout << "Enter the size (N) an should have :" << endl;
    cin >> size;
    int *arr = new int[size];
    cout << "Enter the element of the array(one element less) :" << endl;
    for (int i = 0; i < size - 1; i++)
    {
        cin >> arr[i];
    }

    int miss_1 = Missing_1(arr, size);
    cout << "The missing number in the array is " << miss_1 << endl;

    int miss_2 = Missing_2(arr, size);
    cout << "The missing number in the array is " << miss_2 << endl;

    int miss_3 = Missing_3(arr, size);
    cout << "The missing number in the array is " << miss_3 << endl;
}