// ATM

/*
돈을 인출하는데 걸리는 시간.  -> P
3 1 4 3 2
->  1 2 3 3 4 
    1
    1+2
    1+2+3
    1+2+3+3
    1+2+3+3+4

    N=5 -> 5 4 3 2 1 

    1 3 6 9 13 ->

    내 앞에까지 오는데 걸리는 시간. 
    각 사람이 돈을 인출하는데 필요한 시간의 합. 
    
최솟값을 구하면된다. 

*/
#include <iostream>
#include <queue>
using namespace std;

int N; 
int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    
    cin >> N; 
    priority_queue<int> PQ;
    
    for(int a, i=0; i<N; i++){
        cin >> a; 
        PQ.push(-a);
    }
    int sum =0; 
    int k = N; 
    for(int i=0; i<N; i++){
        sum += -PQ.top()*(k--); 
        PQ.pop(); 
    }

    cout << sum; 
    return 0; 

}


/*
풀이 
3 1 4 3 2
->  1 2 3 3 4 
    1
    1+2
    1+2+3
    1+2+3+3
    1+2+3+3+4

이렇게 적어보면 어떻게 해야할 지 간단하게 답이 나옴. 
 
keypoint : "적어라. "

*/