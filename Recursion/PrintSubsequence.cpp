/*Subsequences : A contiguous or non-contiguous sequence which follows the order
Ex. arr = [3,2,1] 
sub = { 3, 2, 1, {3,2}, {2,1}, {3,2,1}, {3,1}, {}} "This are correct subsequence"
{1,2} => Is wrong because order is not followed 
*/

// To Print all subsequence 
#include<iostream>
#include<vector>
using namespace std ;

void PrintS(int ind, int* arr, vector<int> &ds, int n){

    if (ind == n){
        for (auto it : ds){
            cout << it << " " ;
        }
        if (ds.size() == 0) cout << "{}" ;
        cout << endl ;
        return ; 
    }

    // Take a particular element and have all possible combination with it 
    ds.push_back(arr[ind]);

    /*after taking an element move to next element
    Ex: ds = {3} now take 2 and then 1 
    */
    PrintS(ind+1,arr,ds,n); 
    
    // Not take that element and have all possible combination with that 
    ds.pop_back();

    /*Ex: ds = {} 3 is not taken 
    take i+1 which 2 and then do combination with 2 
    ds = {2, {2,1}...}*/
    PrintS(ind+1,arr,ds,n) ;
}

int main () {
    int n ;
    cout << "Enter the number of element : " << endl;
    cin >> n ;
    int* arr = new int[n];
    cout << "Enter the element : " << endl ;
    for (int i = 0 ; i < n ; i++)
        cin >> arr[i] ;
    
    vector<int> ds ;
    PrintS(0,arr,ds,n) ;
    
    return 0 ;
}