//1158
#include <iostream> 
#include <string> 
#include <queue> 
#include <stack>
using namespace std; 
/**
 * 1 2 4 5 7
 * 
 * 제거되면 그다음부터 카운트 k 카운트 (그 다음 숫자 + k-1) -> 죽는 사람. 
 * 맨 마지막이 죽었을 경우 --> 맨 처음부터 스타트.
 * 중간에 죽었는데 맨 마지막 사람을 만났을 경우. 1로 가서 마저 count 
 * 
 * 죽은 사람은 큐에 넣어볼까. 
 *  
*/
int main(void) {
    ios:: sync_with_stdio(false); cin.tie(0);
    queue<int> Q; 
    queue<int> die; 
    int N; 
    cin >> N; 
    int k; 
    cin >> k; 
    
    
    
    





    int p = die.size(); 
    for(int i=0; i<p; i++){
        if(i==0) cout << "<";
        else if(i+1 == p-1) cout << die.front(); 
        else if(i+1 == p) cout << ">";
        else cout << die.front() << ", "; 
        die.pop(); 
    }       


    return 0; 
}