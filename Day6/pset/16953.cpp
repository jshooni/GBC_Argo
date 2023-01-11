#include <iostream>
/*

정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.

2를 곱한다.
1을 수의 가장 오른쪽에 추가한다. 
A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.

*/

using namespace std; 

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    int A, B; 
    cin >> A >> B ; 
    int cnt=1; 

    while(1){
        if(B<A){
            cnt = -1; 
            break;
        }
        if(B == A) break; 

        else{
            if( B%2 == 0 ){  
                B /= 2; 
                cnt++; 
            }
            else if( B%10 == 1){ 
                B /= 10; 
                cnt++; 
            }
            else{
                cnt = -1; 
                break; 
            }
        }       
    }

    cout << cnt ; 
    return 0;     
}