#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
     
    priority_queue<int> pq;

    pq.push(40);
    pq.push(20);
    pq.push(70);
    pq.push(60);
    pq.push(50);
    
    while( !pq.empty() ){
        int k = pq.top();
        pq_small.push(k) ; 
        cout << k << ' ' ;
        pq.pop();
    }

    cout << endl; 


    return 0;
}