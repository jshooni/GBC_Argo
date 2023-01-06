/**
 * 정휘는 후배들이 재귀 함수를 잘 다루는 재귀의 귀재인지 알아보기 위해 재귀 함수와 관련된 문제를 출제하기로 했다.

팰린드롬이란, 앞에서부터 읽었을 때와 뒤에서부터 읽었을 때가 같은 문자열을 말한다. 
팰린드롬의 예시로 AAA, ABBA, ABABA 등이 있고, 팰린드롬이 아닌 문자열의 예시로 ABCA, PALINDROME 등이 있다.

어떤 문자열이 팰린드롬인지 판별하는 문제는 재귀 함수를 이용해 쉽게 해결할 수 있다. 
아래 코드의 isPalindrome 함수는 주어진 문자열이 팰린드롬이면 1, 팰린드롬이 아니면 0을 반환하는 함수다.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int recursion(const char *s, int l, int r){ //( 문자열 포인터, 0"l" , 문자열 길이-1 "r")
    if(l >= r) return 1; // stop condition
    else if(s[l] != s[r]) return 0; // stop condition
    else return recursion(s, l+1, r-1); //  
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(void){
    int T; 
    cin >> T; 
    
    vector<string> V(T);
    string str; 
    for(int i=0; i<T; i++){
        cin >> str;
        V[i] = str;
    }
    for(int i=0; i<T; i++){
        cout << V[i] <<endl;
    }

    
    vector<string> ::iterator iter; // 주소값을 가리키는 .
    for(iter = V.begin() ; iter != V.end() ; iter++) {
        cout << *iter << ' ';
    }



    printf("ABBA: %d\n", isPalindrome("ABBA")); // 1
    printf("ABC: %d\n", isPalindrome("ABC"));   // 0

    return 0; 
}
