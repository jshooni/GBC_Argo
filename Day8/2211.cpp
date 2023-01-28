// 네트워크 복구
/*
* 해커 공격 막는 법 : 모든 회선/ 컴퓨터 차단. 
관리자 -> 보안 시스템 설치하려함. 
이 보안 시스템은 1번 컴퓨터만 가능. 즉 start node는 언제나 1

. 한 컴퓨터가 공격을 받게 되면, 네트워크를 통해 슈퍼컴퓨터에 이 사실이 전달이 되고
. 그러면 슈퍼컴퓨터에서는 네트워크를 이용해서 보안 패킷을 전송하는 방식을 사용하기로 하였다
. 준비를 마친 뒤, 관리자는 다시 네트워크를 복구하기로 하였다

... 1. 해커가 다시 공격을 할 우려가 있기 때문에, 최소 개수의 회선만을 복구해야 한다.

    2. 슈퍼컴퓨터가 다른 컴퓨터들과 통신하는데 걸리는 최소 시간이,
         < 원래의 네트워크에서 통신하는데 걸리는 최소 시간          보다 커져서는 안 된다.


위의 조건을 만족하면서 네트워크를 복구하는 방법을 알아내는 프로그램을 작성해라. 

각 노드까지의 최소 거리를 일단 저장을 해볼까. 
그리고 그 노드들까지만 가는 경우만 살리면되는거 아닌가. 
나머지를 지우면되는거다. 
나머지를 지우는게 아니라 그 노드까지 가는 회선만 따로 저장을 해두자. 

ㅇㅇ 지우자. ㅋㅋ
지우는게 편할듯. 
*/
#include <iostream> 
#include <queue> 
#include <vector>
#include <algorithm>
#include <climits>

#define INF INT_MAX
using namespace std; 
vector< pair<int,int> > graph[1001];
vector< pair<int,int> > _fixed; // 복구할 회선 ab를 차례로 넣으면됨. 
// _fixed.push_back( {a, b} ); 
// cout << _fixed.first(top) << ' ' << _fixed.second
int DIST[1001];
int vertex[1001];
int M, N, start;
int cnt;


void dijsktra(void){
    // 1. 모든 DIST 값에 inf 값을 넣자. 
    for(int i=1; i<=N; i++){
        DIST[i] = INF; 
    }
    DIST[start] = 0 ;

    // 2. priority_queue 선언하자. 
    // { weight , currnode }
    priority_queue< pair<int,int> > PQ;    
    // 3. PQ에 일단 시작을 집어 넣자. 
    PQ.push( {0, start} );
    // 4. 이제 각 간선들로의 무게를 부여할거야. 
    while( !PQ.empty() ){
        int curr_weight = -PQ.top().first; 
        int curr_node = PQ.top().second;
        PQ.pop(); // 현재에다가 저장을 했으니까 pop을 해야겠지. 
        
        for(int i=0; i< graph[curr_node].size(); i++){
            int next_node = graph[curr_node][i].first; // to . 
            int next_weight = graph[curr_node][i].second; // weight .
            


            if( (curr_weight + next_weight) < DIST[next_node] ){

                DIST[next_node] = curr_weight + next_weight;
                vertex[next_node] = curr_node; 
                PQ.push( { -DIST[next_node], next_node }); 
            }
        }
    }
    return ;
}

int main(void){
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> N >> M; 
    start=1; 
    for(int i=0, a,b,c; i<M; i++){
        cin >> a >> b >> c; 
        graph[a].push_back( {b,c} );
        graph[b].push_back( {a,c} );
    }
    // for(int i=0; i< M; i++){
    //     cout << _fixed[i].first << ' ' << _fixed[i].second<< endl; 
    // }

    dijsktra();
 
    for(int i=1; i<=N; i++){
        if( vertex[i] != 0 ) cnt ++; 
    }
    
    cout << cnt << endl; 

    for(int i=1; i<=N; i++){
        if( vertex[i] != 0 ) 
          cout << i << ' ' << vertex[i] << '\n';  // to from  
    }


    // for(int i=1; i<=N; i++){

    //     for(int j=0; j<graph[i].size(); j++){
    //         if(graph[i][j].second > 0){
    //             count++;
    //             _fixed.push_back ( { graph[i][j].first, graph[i][j].second});
    //         }
    //     }
    // }
    
    // cout << "------------" << endl; 
    // cout << count << '\n';
    // sort(_fixed.begin(), _fixed.end());
    // for(int i=0; i<count ; i++)
    //     cout << _fixed[i].first << ' '<< _fixed[i].second << '\n';
    

    return 0; 
}