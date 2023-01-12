// 해킹

#include <iostream> 
#include <queue>
#include <vector>
#include <climits>
#define INF INT_MAX

using namespace std; 
vector< pair<int, int> > graph[10001];

int DIST[10001];
int T;

void dijsktra(int n, int start){
    // 1. 모든 DIST 값에 inf 값을 넣자. 
    for(int i=1; i<=n; i++){
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
                PQ.push( { -DIST[next_node], next_node }); 
            }
        }
    }

   
    return ;
}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> T; 
    vector< pair<int, int> > total(T, {0,0}); // 0 infected / 1time

    for(int k=0,n, d, c;  k<T ; k++){
        cin >> n >> d >> c ; 

        for(int j=1; j<=n; j++){
            if (graph[j].size() > 0) graph[j].clear(); 
        }
        
        for(int i=0, to, from, time;  i<d;  i++){
            cin >> to >> from >> time;
            graph[from].push_back({to, time});
        }

        dijsktra(n, c);
        
        for(int i=1; i<=n; i++){ // n은 노드의 개수만큼 도는거임. 
            if(DIST[i] < INF) {
                total[k].first ++; 
                total[k].second = max( DIST[i] , total[k].second );
            }
        }
        
    }


    for(int i=0; i<T; i++)
        cout << total[i].first << ' ' << total[i].second << '\n';
    


    return 0;
}


/*
while(T--){
    그리고 배열선언하는게 아니라, 
    pair<int, int> total; 
    
    for(int i=1; i<=n; i++){ 
            if(DIST[i] < INF) {
                total.first ++; 
                total.second = max( DIST[i] , total.second );
            }
    }
    
    cout << total.first  << ' ' << total.second << endl; 
    
}
*/