/*Two sum Problem */
#include<iostream>
#include<vector>
using namespace std ;

/*Brute Force :
checking the sum of each element with other 
Time complexity : O(n^2) -> 2 loops 
*/
void TwoSum_1(int* arr , int size , int traget ){
    int flag = 0 , firstI , secondI ;
    for (int i = 0 ; i<size ; i++){
            for (int j = i+1 ; j < size ; j++){
                if (arr[i]+arr[j] == traget){
                    flag = 1 ;
                    firstI = i ;
                    secondI = j ;
                    break;
                }
            }
    }
    if (flag){ 
        cout << "The sum of 2 element is found to be the traget value" << endl ;
        cout << "Element at index " << firstI << " and " << secondI << endl ;
    }
    else {
        cout << "Trageted element not found"  << endl ;
    }
}
/*Better : Using hashmap 
Ex. arr [] = [2,5,6,8,11] and k = 14 
x = k - arr[i] = 14 - 2 = 12 
is 12 present in the 
*/
vector<int> TwoSum_2(vector<int> &nums , int traget){
    
}
int main (){
    int size ;
    cout << "Enter the size of the array :" << endl ;
    cin >> size ;

    int* arr = new int [size] ;
    cout << "Enter the element of array : " << endl ;
    for (int i = 0 ; i < size ; i++){
        cin >> arr[i];
    }
    int traget ;
    cout << "Enter the traget value :" << endl;
    cin >> traget ;
    TwoSum_1(arr,size,traget);
    
}