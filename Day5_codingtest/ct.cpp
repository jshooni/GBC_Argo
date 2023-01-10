#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

/*

*/
int main(void){
    ios:: sync_with_stdio(false); cin.tie(0);

    int N; 
    cin >> N; 
    deque<int> Q;

    for(int i=1; i< N+1 ; i++){
        Q.push_back(i);
    }
    
    // for(int i=0; i< Q.size(); i++){
    //     cout << Q.front() << " " ;
    //     Q.pop_front(); 
    // }

    while(1){
        if(Q.size()==1) break;
        Q.pop_front(); 
        int a = Q.front(); 
        Q.push_back(a);
        Q.pop_front(); 
    }

    cout << Q.front(); 
    

    return 0 ;
}