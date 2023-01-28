#include <iostream> 
#include <vector> 
#include <climits>
#include <algorithm>
#define INF INT_MAX

using namespace std; 

vector< pair< pair<int, int>, int> > graph(502); 
long long DIST[502]; 
int V, E , start; 
bool infinite_; 



void Bellman_Ford(void){

    for(int i=1; i<=V; i++)
        DIST[i] = INF;
    
    DIST[1] = 0; 
    
    for(int i=1; i<=V-1; i++){ // V-1 만큼 반복. 
        for(int j=0; j<graph.size(); j++){ // 그래프 사이즈만큼. 총 엣지 개수만큼..? 
            int From = graph[j].first.first; 
            int To = graph[j].first.second; 
            int Weight  = graph[j].second; 
            
            if(DIST[From] == INF ) continue; 
            if( DIST[To] > DIST[From] + Weight ) 
                DIST[To] = DIST[From] + Weight;
        }
    }

    //무한 빠졌는지 한번더 돌려보는 것임. 
    for(int j=0; j<graph.size(); j++){ // 그래프 사이즈만큼. 총 엣지 개수만큼..? 
            int From = graph[j].first.first; 
            int To = graph[j].first.second; 
            int Weight  = graph[j].second; 
            
            if(DIST[From] == INF ) continue; 
            if( DIST[To] > DIST[From] + Weight ) { // 만약 바뀌었다면!!! 
                infinite_ = true; 
                return ;
            }
    }


}

int main(void) {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);

    cin >> V >> E ; 
    
    for(int i=0, from, to, weight ; i<E; i++){
        cin >> from >> to >> weight; 
        // cin >> graph[i].first.first >> graph[i].first.second >> graph[i].second ; 
        graph.push_back({{from, to}, weight});
        // graph.first.first.push_back(from);
        // graph.first.second.push_back(to);
        // graph.second.push_back(weight); 
    }

    // graph[i].second == 0  -> 순간이동
    // graph[i].second < 0  -> 타임머신. 
    // 1번도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간. 
    // 무한루프에 빠지면 -1을 출력. 
    // else -> 
    // 1번도시에서 -> 2번, 3번, 4번 쭉. 
    Bellman_Ford();

    if(infinite_ == false ){
        for(int i=2; i<= V; i++){
            if(DIST[i] >= INF)
                cout << -1 << '\n'; 
            else 
                cout << DIST[i] << '\n';
        }
    }
    else 
        cout << -1;
    

    return 0; 
}
 