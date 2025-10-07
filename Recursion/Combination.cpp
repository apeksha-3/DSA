/*Combination Sum: Given a traget element 
arr = [2,3,6,7] traget = 7 
sum = { {2,2,3} , {7} }
When we talk about combination , an element can be consider for n number of times to get traget element */

#include<iostream>
#include<vector>
using namespace std ;

void Combination_sum (int i, int target ,int* arr, vector<int> &ds , vector<vector<int>> &ans, int n ){
    if (i == n){
        if (target == 0) {
            ans.push_back(ds) ;
        }
        return ;
    }

    // Pick an element 
    if (arr[i] <= target){
        ds.push_back(arr[i]); // put the element 
        /*as you picked an element to get target, target is reduced by that pick element 
        Ex: target = 7  arr[i] = 2  ds = {2}  
        new target = 7-2
        */
        Combination_sum(i, target-arr[i] , arr, ds,ans,n);
        ds.pop_back() ;
    }

    Combination_sum(i+1, target,arr,ds,ans,n);
}

int main () {
    int n , target ;
    int* arr ;
    cout << "Enter the number of element : " << endl ;
    cin>> n ;

    cout << "Enter the value of target" << endl ;
    cin >> target ;

    cout << "Enter the element : " << endl ;
    for (int i = 0 ; i < n ; i++)
        cin >> arr[i] ;
    
    vector<int> ds ;
    vector<vector<int>> ans ;
    Combination_sum(0,target,arr,ds,ans,n) ;

    cout << "The possible combination sum for the target " << target << " are " << endl ;
    for (auto &i : ans){
        for (auto &j : i){
            cout << j << " " ;
        }
        cout << endl ;
    }
}
