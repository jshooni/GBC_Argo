/*
정수 X에 사용할 수 있는 연산은 다음과 같이 3 가지 이다.

    X가 3으로 나누어 떨어지면, 3으로 나눈다.
    X가 2로 나누어 떨어지면, 2로 나눈다.
    1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

*/
#include <iostream>
using namespace std; 

int _data[1000001];

int func(int n){
    _data[1]= 0; 
    _data[2]= 1; 
    _data[3]= 1;
    if(n <= 3) return _data[n]; 

    for(int i=4; i<=n; i++){
        _data[i] = _data[i-1] + 1; 
        if( i%2 == 0 ) _data[i] = min(_data[i], _data[i/2]+1);
        if( i%3 == 0 ) _data[i] = min(_data[i], _data[i/3]+1);
    }

    return _data[n];
}
int main(void){
    // ios::sync_with_stdio(false); 
    // cin.tie(0); cout.tie(0);
    
    int n; 
    cin >> n; 
    cout << func(n);
    
 
    return 0 ; 
}
