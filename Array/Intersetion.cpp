#include <iostream>
#include <vector>
#include <set>
using namespace std ;
/*Brute Force :
Two loop :- i on first array and j on second array 
maintaining visited array for seconnd array initialized with 0 
Time complexity : O(n*m)
Space complexity : O(m) space of visited array is of size of brr
*/
void Intersection_1 (int* arr , int* brr,int* visited , int n , int m ,vector<int> &result){
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < m ; j++){
            if (arr[i] == brr[j] && visited[j]==0){
                result.push_back(arr[i]);
                visited[j] = 1 ;
                break;
            }
            if (brr[j] > arr[i])
            break;
        }
    }
}

int main (){
    int n, m;
    cout << "Enter the size of array 1: ";
    cin >> n;
    cout << "Enter elements of array 1: ";
    int* arr = new int [n]; // it works
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter the size of array 2: ";
    cin >> m;
    int* brr = new int [m];  // it works 
    cout << "Enter elements of array 2: ";
    for (int i = 0; i < m; i++)
        cin >> brr[i];
    int* visited = new int[m] ;
    // visited = {0} ; not possible in cpp
    for (int i = 0 ; i < m ; i++){
        visited[i] = 0 ;
    }
    vector<int> result;

    Intersection_1(arr,brr,visited,n,m,result) ;
    for (int i = 0 ; i < result.size() ; i++){
        cout << result[i] ;
    }
}