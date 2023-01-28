//1158
#include <iostream> 
#include <string> 
#include <queue> 
#include <stack>
using namespace std; 
queue<int> Q; 
/**

*/
void Yosapus(int N, int cnt){ // 죽일놈 앞으로 가져다가 주는거임. 
    for(int i=0; i<cnt; i++){
        int a = Q.front(); 
        Q.pop(); 
        Q.push(a);
    }
}
int main(void) {
    ios:: sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    
    int N, k ; 
    cin >> N >> k ; 
    
    for(int i=1 ; i<=N; i++){
        Q.push(i);
    }
    // setting queue; 
    while(1){
        if(Q.front() == k) break;
        int temp = Q.front(); 
        Q.pop();
        Q.push(temp);
    }
    cout << "<" <<  Q.front() ; 
    Q.pop(); 
    
    
    while(!Q.empty()){
        Yosapus(N, k-1);
        cout << ", " << Q.front();
        Q.pop(); 
    }

    cout << '>';
    



    return 0; 
}