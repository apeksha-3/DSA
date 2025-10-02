#include<iostream> 
#include<string>
using namespace std ;

int fib (int i){
    if (i <= 1)
    return i ;

    return fib(i-1) + fib(i-2);
}
int main () {
    int n ;
    cout << "Enter number :" ;
    cin >>n ;
    cout << "Fib"
}