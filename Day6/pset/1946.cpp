#include <iostream> 
#include <vector> 
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std; 
/*
다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 자만 선발한다
(즉, 어떤 지원자 A의 성적이 
다른 어떤 지원자 B의 성적에 비해 

"서류 심사 결과와 면접 성적이 모두 떨어진다면 "

A는 결코 선발되지 않는다.)



*/

// int bag[];
// priority_queue<int> qp; 

int main (void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    int N; 
    cin >> N;  // 총 몇번 할 것인지
    // vector<int> count(N,0);  

    for(int k=0; k< N ; k++){ //그룹이 몇그룹인지 
        int K =0; 
        cin >> K; // 신입사원 몇명인지 
        bool visited[K];
        memset(visited, true, sizeof(visited)) ;
        vector< pair<int,int> > items(K,{0,0}); // 점수1 점수2
        
        for(int i=0; i<K; i++ ) {
            cin >> items[i].first >>  items[i].second ; 
        }

        sort(items.begin(), items.end()); // 정렬을 했다. 
        
        int cnt = 1 ; 
        int second = items[0].second ; 
        for (int i = 1; i < K ; i++) { 
            if ( second >= items[i].second ) { 
                cnt++; 
                second = items[i].second ; 
            }            
        }
        // for(int i=0; i<K; i++){
        //     if(visited[i]==true){
        //         for(int j=i; j<K; j++){
        //                 if(items[i].second < items[j].second) { 
        //                     visited[j] = false; 
        //                 }    
        //         }
        //     }
        // }

        // for(int i=0; i<K; i++)
        //     if(visited[i]==true) count[k]++; 
        cout << cnt << endl;
    }

    return 0; 
} 

/*
여기서 first를 기준으로 정렬을 해준다. 
서류. 면접 ...2개가 있는데 
서류 1위부터 나열을 했잖아. 
그 상태에서.. 
차례대로 비교를 할건데 
1위는 무조건 뽑아 --> count ++ 하는거야. 
2위는 1위.second 비교해서 높으면 --> count ++; 
3위는 1위.second 2위.second 비교해서 높으면 --> count ++; 
4위는 1위.second 2위.second 3위.second 비교해서 높으면 --> count ++; 
. 
.
[n 위는]  1위.second 2위 3위 4위 ... 해서 (n-1)위.second 비교해서 높으면 -->count ++ 
    만약 그러지도 않는다면 그냥 continue 넘어가. 그거할 필요도 없고 그냥 계속반복 돌아가면됨. 


1등이면 그냥 집어너혹
[0] --> count ++ ; 
[1] --> if( [1]<[0]) count ++; 
[2] --> if( [2]<[0] || [2]<[1] ) count ++; 
[3] --> if( [3]<[0] || [3]<[1] || [3]<[2] ) count ++; 
2
5
3 2
1 4
4 1
2 3
5 5
7
3 6
7 3
4 2
1 4
5 7
2 5
6 1
*/ 

