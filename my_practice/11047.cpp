// 동전 0 


#include <iostream>
#include <queue>

using namespace std;
int N,K;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    priority_queue<int> PQ; 

    cin >> N >> K ;
    int cnt =0; 
    for(int a,i=0; i<N; i++ ){
        cin >> a;
        PQ.push(a);
    }
    
    while(K!=0){
        int j = K / PQ.top();
        if(j>=1){
            K -= PQ.top(); 
            cnt++; 
        }
        else PQ.pop();
    }
    cout << cnt; 
    return 0 ; 
}

/*
사실 priority_queue를 사용할 필요는 없었음. 
(문제에서부터 작은 수부터 차례대로 제시를 했기 때문에)
이건 초등학생도 풀만한 문제. 


*/