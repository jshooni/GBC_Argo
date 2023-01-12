#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std; 

int N, E, start; 
int v_1, v_2; 
vector< pair<int,int> > graph[801];
int DIST[801];
int SUM[2];
bool flag;
bool flag_;
/*
방향성이 없는 그래프. 
1 -> N 최단거리. 
BUT (임의로 주어진 두 정점은 반드시 통과해야한다.)

한번 이동했던 V (node) , E (간선) 다시 이동가능. 
but 반드시 최단 경로로 이동해야함. 





*/

void dijsktra(int sum_index, int l_start, int end){

    // 1. 모든 DIST 값에 inf 값을 넣자. 
    for(int i=1; i<=N; i++){
        DIST[i] = INF; 
    }
    DIST[l_start] = 0 ;
    // 2. priority_queue 선언하자. 
    // { weight , currnode }
    priority_queue< pair<int,int> > PQ; 
    // 3. PQ에 일단 시작을 집어 넣자. 
    PQ.push( {0, l_start} );

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
                PQ.push( { -DIST[next_node], next_node }); 
            }
        }
    }

    if(DIST[end] >= INF){
        flag=true;
        return ; 
    }
    SUM[sum_index] += DIST[end]; 
    return ;
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    // freopen("input.txt" , "r", stdin); 
    

    cin >> N >> E; 
    
    for(int i=0,from,to,weight; i<E; i++){
        cin >> from >> to >> weight; 
        graph[from].push_back( {to, weight} );
        graph[to].push_back( {from, weight} );
    }

    
    cin >> v_1 >> v_2; 
    
    if(v_1==1 && v_2==N){
        dijsktra(0, v_1, v_2);
        flag_=true;
    }
    else if(v_1==1 && v_2 !=N){
        dijsktra(0, v_1, v_2);
        dijsktra(0, v_2, N);
        flag_=true;
    }
    else if(v_1!=1 && v_2 ==N){
        dijsktra(0, 1, v_1);
        dijsktra(0, v_1, N);
        flag_=true;
    }
    else{
        dijsktra(0, 1, v_1); // SUM[0][1] 
        dijsktra(0, v_1, v_2);// SUM[0][2]
        dijsktra(0, v_2, N);// SUM[0][3]

        dijsktra(1, 1, v_2);
        dijsktra(1, v_2, v_1);
        dijsktra(1, v_1, N);
    }

    // 1 -> v1 -> v2 -> N    => SUM[0]
    // 1 -> v2 -> v1 -> N    => SUM[1]
    if( flag==true ) cout << -1 << endl; 
    else if( flag_ == true ) cout << SUM[0] << endl; 
    else cout << min( SUM[0],SUM[1] ) << endl; 
    
    return 0; 
}