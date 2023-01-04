#include <iostream>
#include <string.h>
#include <string>
using namespace std;


int recursion(const char *s, int l, int r, int &num);
int isPalindrome(const char *s, int &num );

int main(void){
    int T; 
    cin >> T; 

    char str[T][1000]; 
    int num =0; 
    
    for(int i=0; i< T ; i++){
        cin >> str[i] ; 
    }
    for(int i=0; i<T ; i++){
        num =0;
        cout << isPalindrome(str[i], num) << " " << num << endl;
    }
   
    // printf("ABBA: %d\n", isPalindrome("ABBA")); // 1
    // printf("ABC: %d\n", isPalindrome("ABC"));   // 0
    return 0; 
}
int recursion(const char *s, int l, int r, int &num){
    num++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0; 

    else return recursion(s, l+1, r-1, num);
}
int isPalindrome(const char *s, int &num ){
    return recursion(s, 0, strlen(s)-1, num);
}