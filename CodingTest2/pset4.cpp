#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define INF INT_MAX

using namespace std;
int N, M; //  (2 ≤ N ≤ 500) (1 ≤ M ≤ 104)
int S, D; // (S≠D; 0≤S, D<N) 

vector< pair<int,int> > graph[503];
int vertex[503];
long long DIST[503];

void backTrack_erase_Graph(int curr){ 
    // curr 뒤에 있는 놈이야. 
    // from : vertex[curr]
    // to : curr 
    if(curr == 0) return ;

    for(int i=0; i<graph[vertex[curr]].size();  i++ ){
        if( graph[vertex[curr]][i].first == curr )
            graph[vertex[curr]].erase(graph[vertex[curr]].begin() + i);
    }
    backTrack_erase_Graph(vertex[curr]);
}



void dijsktra(int start, int end){
    // 1. 모든 DIST 값에 inf 값을 넣자. 
    for(int i=0; i<N; i++){
        DIST[i] = INF; 
    }
    DIST[start] = 0 ;

    priority_queue< pair<int,int> > PQ; 
    PQ.push( {0, start} );

    while( !PQ.empty() ){
        int curr_weight = -PQ.top().first; 
        int curr_node = PQ.top().second;
        PQ.pop(); 
        
        for(int i=0; i< graph[curr_node].size(); i++){
            int next_node = graph[curr_node][i].first; // to . 
            int next_weight = graph[curr_node][i].second; // weight .
                         
           if( curr_weight + next_weight < DIST[next_node] ){
                DIST[next_node] = curr_weight + next_weight;
                vertex[next_node] = curr_node;  // [i : to] value : from
                PQ.push( { -DIST[next_node], next_node }); 
            }
        }
    }   
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout << "1111111111"<< endl; 
 
    while(1){
        cin >> N >> M; // 장소의 수. 도로의 수.

        if(N==0 && M==0) break;

        // memset(vertex, 0, sizeof(vertex)); 
        cin >> S >> D ; // 출발을 S에서 도착을 D로. 

        cout << "222222"<< endl; 
        //그래프 입력받기 


        for(int i=0,from,to,weight; i<M; i++){
            cin >> from >> to >> weight; 
            graph[from].push_back({to, weight});
        }

        dijsktra(S,D);

        for(int i=0; i<N; i++){
            cout << DIST[i] << ' ' ; 
        }
        cout << endl << "Vertex : " ;
        for(int i=0; i<N; i++){
            cout << vertex[i] << ' ' ; 
        }
        cout << endl;

        if(DIST[D] >= INF) cout << -1 << '\n';
        // D까지의 최단경로를 구했다면. 
        else backTrack_erase_Graph(D); 

        dijsktra(S,D);
        cout << endl << "Vertex : " ;
        for(int i=0; i<N; i++){
            cout << vertex[i] << ' ' ; 
        }

        cout << endl;

        cout << "------------------------"<< endl;
        if(DIST[D] >= INF) cout << -1 << '\n';
        else cout << DIST[D]<< '\n';
        cout << "------------------------"<< endl;
        
    }




    return 0; 
} 