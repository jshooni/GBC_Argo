/**
 * 지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.

지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.

첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. (이 위치는 가장 처음 큐에서의 위치이다.) 
이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <deque> 
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;
int minimum[51] ;
int main(void){
    //queue 크기 N ( N은 50보다 작거나 같은 자연수)
    // 뽑아내려고 하는 횟수 M (M은 N보다 작거나 같은 자연수)
    // 둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다.  ( 1 <= 위치 <= N )

    deque<int> D ; 
    int N; 
    cin >> N;
    for(int i=0; i< N; i++){
        D.push_back(i+1);
    }

    
    int M;
    cin >> M;
    int num[M];
    for(int i=0; i<M; i++){
        cin >> num[i];
    }




    for(int i=0; i<M; i++){
        // deque<int> Q_f;
        int curr = num[i];
        int min=0 ;
        // while(!Q_f.empty()) Q_f.pop(); 

        while(curr !=D.front()){ 
            // Q_f.push_back(D.front());
            int k = D.front() ; 
            D.push_back(k);
            D.pop_front();
            min++ ; 
        }
        if(D.size()/2 >= min )  minimum[i] += min; 
        else minimum[i] += D.size()-min; 


        D.pop_front(); 
        
    }
    
    int result=0; 
    for(int i=0; i<M; i++) result+=minimum[i];
    cout << result << endl; 

    return 0 ; 
}