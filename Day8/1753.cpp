#include <iostream> 
#include <vector>
#include <queue>
#include <climits>
#define INF INT_MAX

using namespace std; 

int V, E, start; 
vector< pair<int, int> > graph[20001]; // 노드의 개수. 
int DIST[20001]; //간선의 개수

void dijsktra(void){

    // 1. 모든 DIST 값에 inf 값을 넣자. 
    for(int i=1; i<=V; i++){
        DIST[i] = INF; 
    }
    DIST[start] = 0 ;

    
    // 2. priority_queue 선언하자. 
    // { weight , currnode }
    priority_queue< pair<int,int> > PQ; 
    
    // 3. PQ에 일단 시작을 집어 넣자. 
    PQ.push( {0, start} );

    // 4. 이제 각 간선들로의 무게를 부여할거야. 
    int next_node;
    int next_weight;
    int curr_weight;
    int curr_node;
    while( !PQ.empty() ){
        curr_weight = -PQ.top().first; 
        curr_node = PQ.top().second;
        PQ.pop(); // 현재에다가 저장을 했으니까 pop을 해야겠지. 
        
        for(int i=0; i< graph[curr_node].size(); i++){
            next_node = graph[curr_node][i].first; // to . 
            next_weight = graph[curr_node][i].second; // weight .             
            if( (curr_weight + next_weight) < DIST[next_node] ){
                DIST[next_node] = curr_weight + next_weight;
                PQ.push( { -DIST[next_node], next_node }); 
            }
        }
    }
    return ;
}


int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> V >> E >> start;

    for(int i=0, from, to, weight; i<E; i++){
        cin >> from >> to >> weight;
        graph[from].push_back( {to, weight} );
    }

    dijsktra(); 

    for(int i=1; i<=V; i++){
        if(DIST[i]==INF)
            cout << "INF" << '\n'; 
        else 
            cout << DIST[i] << '\n'; 
    }


    return 0; 
}