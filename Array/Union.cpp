#include <iostream>
#include<climits>
#include <set>
#include <vector>

using namespace std;
//Union of two set is all the element present in both the set withput repeatetion  


/*Brute Force : Using a extra space to solve the problem result into brute force method 
Set data structure 
*/
int Union_1(int arr[], int brr[], int n1, int n2, vector<int> &result) {
    set<int> st;
    for (int i = 0; i < n1; i++)
        st.insert(arr[i]);
    for (int i = 0; i < n2; i++)
        st.insert(brr[i]);

    for (auto it : st)
        result.push_back(it);

    return result.size();
}

/* Optimal : Only when array is sorted 
using 2-pointer approach (i,j)
i will iterate on first array 
j will iterate on second array 
before inserting an element into union array check whether or not it is present 
*/
int Union_2(int arr[], int brr[], int n, int m, vector<int> &result) {
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr[i] <= brr[j]) {
            if (result.empty() || result.back() != arr[i])
                result.push_back(arr[i]);
            i++;
        }
        else {
            if (result.empty() || result.back() != brr[j])
                result.push_back(brr[j]);
            j++;
        }
    }

    while (i < n) {
        if (result.empty() || result.back() != arr[i])
            result.push_back(arr[i]);
        i++;
    }

    while (j < m) {
        if (result.empty() || result.back() != brr[j])
            result.push_back(brr[j]);
        j++;
    }

    return result.size();
}

int main() {
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

    vector<int> result;

    // Uncomment the method you want to use:
    // int k = Union_1(arr, brr, n, m, result);
    int k = Union_2(arr, brr, n, m, result);

    cout << "Union of the two arrays: ";
    for (int i = 0; i < k; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}