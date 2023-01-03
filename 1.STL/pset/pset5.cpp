/**
 * 
 * C 언어 프로그래밍에서 문자열(string)은 native한 자료형이 아니다. 
 * 사실, 문자열은 그저, 문자열의 끝을 표시하기 위한 말단의 NULL이 사용된, 문자들로 이루어진 문자열일 뿐이다. 
 * 하지만 프로그래밍 언어에서 문자열을 다루는 것은 매우 중요하기 때문에, C 표준 라이브러리는 문자열을 다루는 데에 매우 유용한 함수들을 제공하고 있다 
 *  : 그들 중에는 strcpy, strcmp, strtol, strtok, strlen, strcat 가 있다.
 * 
 * 하지만, 잘 알려져 있지 않으며, 잘 사용되지도 않는 함수가 하나 있다
 *  : strfry 함수다. strfry 함수는 입력된 문자열을 무작위로 재배열하여 새로운 문자열을 만들어낸다. 
 * (역자 주 : 여기에서 입력된 문자열과 새로 재배열된 문자열이 다를 필요는 없다.)

두 개의 문자열에 대해, 2번째 문자열이 1번째 문자열에 strfry 함수를 적용하여 얻어질 수 있는지 판단하라.

입력의 첫 번째 줄은 테스트 케이스의 수 0 < N < 1001 이다.

각각의 테스트 케이스는 하나의 줄에 영어 소문자들로만 이루어진 두 개의 문자열이 한 개의 공백으로 구분되어 주어진다. 
각각의 문자열의 길이는 최대 1000 이다.

각각의 테스트 케이스에 대해, 
2번째 문자열이 1번째 문자열에 strfry 함수를 적용하여 얻어질 수 있는지의 여부를 
"Impossible"(불가능) 또는 "Possible"(가능)으로 나타내시오. (따옴표는 제외하고 출력한다.)
*/

#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm>
using namespace std; 

int main(void) {
    ios:: sync_with_stdio(false); cin.tie(0);
    
    int N; 
    cin >> N; 

    vector<bool> V(N,true); 

    string str1; 
    string str2; 

    for(int i=0; i<N; i++){
        cin.ignore(); 
        cin >> str1 ; 
        cin >> str2 ; 
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        //cout << "str1 : " << str1 << endl; 
        //cout << "str2 : " << str2 << endl; 
        if(str1.compare(str2)!=0)
            V[i]=false; 
    }


    for(int i=0; i<N; i++){
        if(V[i] == true) cout << "Possible"<< endl; 
        else cout << "Impossible" << endl; 
    }
    

    return 0; 
}