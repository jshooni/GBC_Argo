/**
 * 세 개의 자연수 A, B, C가 주어질 때 
 * A × B × C를 계산한 결과에 
 * 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.
 * 
    
    (예를 들어 A = 150, B = 266, C = 427 이라면 
    A × B × C = 150 × 266 × 427 = 17037300 이 되고, 
    계산한 결과 17,037,300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.)

*/

#include <iostream>
#include <vector>
using namespace std; 


int main(void) {
    ios:: sync_with_stdio(false);
    cin.tie(0);

    int A; int B; int C; 
    cin >> A ; cin >> B; cin >> C;
    int sum = A*B*C; 

    // 100 <= A < 1000
    int n=0; 
    int sum_n = sum; 
    while(sum_n!=0){
        sum_n/=10;
        n++; 
    }


    vector<int> V(10, 0);

    //cout << "n : " << n << endl; 
    //cout << "sum : " << sum << endl; 

    for(int i=0; i < n ; i++){
        int index = sum%10; 
        V[index]++;
        sum = sum/10; 
        //cout << i << "번째 : " << V[i]<< "   "  << "sum : " << sum << endl; 
    }


    for(int i=0; i < 10 ; i++){
        //cout << i << "번째 : " << V[i]<< endl; 
        cout << V[i]<< endl; 
    }


    

    return 0; 
}