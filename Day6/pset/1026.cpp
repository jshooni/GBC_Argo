#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

/*
길이가 N 인 정수 배열 A B .
함수 S = A[0]*B[0]  +  ... 
S의 값을 가장 작게 만들기 위해 A의 수를 재배열하자. 

S를 가장 작게 만들기 위해서
A를 재배열하자. B는 그대로.



*/



int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int N; 
    a
    cin >> N; 
    int A[N]; 
    int B[N]; 
    for(int i=0; i<N ; i++){
        cin >> A[i] ; 
    }
    for(int i=0; i<N ; i++){
        cin >> B[i] ; 
    }
    

// B를 재배열 하면안된다.. 
// B 현재 들어있는 것들 중에서 인덱스 별로 몇번째 크기인지 딱딱 해준다. 
// 
// * 서로 문자열 길이는 같다. 

// 
// 일단 최솟값을 구하는게 어떻게 구하는 것일까... 
// A 제일 작은 수 * B 제일 큰수 이렇게 나열하면 되지 않을까. 
// 그렇게 하면되겠노.. 그냥 둘다 sort해서 하면될 것 같은데 

    sort(A, A+N);
    sort(B, B+N);
    int sum=0; 
    for(int i=0; i<N; i++){
        sum += A[i]*B[N-i-1];
    }
    
    cout << sum << endl; 
    


    return 0; 
}