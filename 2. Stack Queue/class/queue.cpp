#include <iostream>
#include <queue>

using namespace std; 

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);

    queue<int> Q;
    queue<pair<int, int>> QP; // xy 좌표를 저장을 할 때. 이런식으로 pair를 사용ㅎ암. 

    Q.push(3) ; 
    Q.push(4) ; 
    Q.push(5) ; 

    QP.push(make_pair(3,4)) ; 
    //QP.push({3,4}); 

    //s.empty : 비어 있으면 1을 반환. 
    while (!Q.empty()) { 
        int k = Q.front();  
        cout << k << '\n';
        Q.pop();
    }

    return 0; 
}