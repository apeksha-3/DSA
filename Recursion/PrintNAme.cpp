
#include<iostream>
using namespace std ;

void print (int i , int n ){
    if (i > n){
        return ;
    }
    cout << "Apeksha" << endl;
    print(i+1 , n);
}
int main (){
    int n ;
    cout << "Entre the number of time to print the name :" << endl;
    cin >> n ;
    cout << "You entered: " << n << endl;

    print(1,n);
    return 0 ;
}