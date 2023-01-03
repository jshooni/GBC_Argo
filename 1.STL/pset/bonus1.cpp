// #13277 <큰수 곱셈> 

/**
 * 두 정수 A와 B가 주어졌을 때, 두 수의 곱을 출력하는 프로그램을 작성하시오.
 * 첫째 줄에 정수 A와 B가 주어진다. 
 * 두 정수는 0보다 크거나 같은 정수이며, 0을 제외한 정수는 0으로 시작하지 않으며, 
 * 수의 앞에 불필요한 0이 있는 경우도 없다. 또한, 수의 길이는 300,000자리를 넘지 않는다.
 * 

음..... 

어떻게 해야할까. 
str1[0] * str2[0] 
*/

#include <iostream> 
#include <vector>
using namespace std; 

int main(void) {
    ios:: sync_with_stdio(false); cin.tie(0);

    string str1, str2; 
    cin >> str1 >> str2; 
    cout << "str1 : " << str1 << endl <<"str2 : " << str2 << endl; 
    
    int m_length=0;
    if(str1.size() <= str2.size()) m_length = str1.size(); 
    else m_length = str2.size(); 
    string str3;
    int a = str1[0]-'0';
    int b = str2[1]-'0'; 
    

    
    
    return 0; 
}