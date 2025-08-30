#include <iostream>
#include <map>
using namespace std;
/*Find the number of that appear once and the other twice*/

/*Brute Force :
i loop -> 0 to n   ---- each element of i will 
j loop -> 0 to n   ---- check with every element j  
if they are found equal flag = 1 and break
if flag == 0 return that element 
*/
int AppearOnce_1(int arr[] , int n ){
    int flag ;
    for (int i = 0 ; i < n ; i++){
        flag = 0 ;
        for (int j = 0 ; j < n ; j++){
            if (arr[i] == arr[j]){
                flag = 1 ;
                break;
            }
        }
        if (flag == 0)
        return arr[i] ;
    }
    return -1 ;
}
/*
Better : Using hash or map
Disadvantage of using hashing :
1. Negative value (-ve value ke liye index kaise karenge)
2. The size of hash arr should be the ( max element of arr + 1 )
SO , 
map has key-value pair 
key is element and value will contain the occurence 
*/
int AppearOnce_2(int arr[] , int n){
    map<int,int> mpp ;

    for (int i = 0 ; i < n ; i++){
        mpp[arr[i]]++ ;
    }
    for (auto it : mpp){
        if (it.second == 1)
        return it.first ;
    }
    return -1 ;
}

/*Optimal : XOR 
Will work for even number of repetition of the number which are repetiting  (2 , 4 , 6)
2^2 = 0 , 2^2^2^2 = 0 ...
but 2^2^2 = 2 because 2 ^ 0 = 2 

arr[] = [1 1 2 2 3 4 4 ]
   xor = 1 ^ 1 ^ 2 ^ 2 ^ 3 ^ 4 ^ 4
   xor =    0  ^  0   ^ 3  ^  0 
   xor = 3
*/
int AppearOnce_3 (int arr[] , int n){
    int xor = 0 ;
    for (int i = 0 ; i < n ; i++){
        xor = xor ^ arr[i] ;
    }
    return xor ; 
}