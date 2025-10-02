#include<iostream> 
#include<string>
using namespace std ;

bool Palindrome (string str , int i , int n){
    if (i >= n/2)
    return true ;

    if (str[i] != str[n-i-1])
    return false ;

    Palindrome (str,i+1,n);

} 
int main (){
    string str ;
    cout << "Enter the string :" << endl ;
    cin >> str ;
    int n = str.length() ;
    if (Palindrome(str,0,n))
    cout << "The string is Palindrome"<< endl ;
    
    else
    cout << "The string is not Palindrome" << endl ;
    
   return 0 ; 
}