// 게임을 만든 동준이 

#include <iostream>
#include <vector>

using namespace std; 

int N; 

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    cin >> N; 
    vector<int> v(N,0); 

    for(int a,i=0; i<N; i++){
        cin >> a; 
        v.push(a); 
    }

    int cnt=0; 
    for(int i=0; i< N-1; i++){
        if((v[N-1]-v[i]) >= v.size()-1 ) 
    }


    while(1){
        int a;
        a = Q.front(); 
        Q.pop();
        if(Q.empty()) break; 
        while(a < Q.front()){
            a--; 
            cnt++;
        }
    }

    cout << cnt; 

    return 0; 
}