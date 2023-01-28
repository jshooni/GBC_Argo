#include <iostream> 
#include <vector>
#include <queue>
#include <stack> 

using namespace std; 

stack<int> s;

int main(void){

    int N; 
    cin >> N; 
    queue<int> QQ;
    vector<char> vs; 
    for(int i=0,a; i<N; i++){
        cin >> a; 
        QQ.push(a);
    }
    
    int k=1; 
    while( k <= N ){
        s.push(k); 
        vs.push_back('+'); 
        while(1){
            if( !s.empty() && s.top()==QQ.front() ) {
                s.pop(); 
                QQ.pop();
                vs.push_back('-');
            }
            else break; 
        }
        if(k++ > N) break; 
    }

    if(!s.empty()) cout << "NO" ;   
    else {
        for(int i=0; i<vs.size(); i++){
            cout << vs[i] << '\n'; 
        }
    }

    return 0; 
}