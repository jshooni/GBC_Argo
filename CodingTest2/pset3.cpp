#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define INF INT_MAX
using namespace std;
/*
일단 최단경로를 알아내
그리고 민준이를 거쳐서 가는 방법을 알아내

*/
vector<pair <int,int> > graph[5001];

long long IGNORE_GUNOO; // 1 -> V
long long SAVING_GUNOO; // 1 -> P -> V 
long long DIST[5001];
int V,E,P;


void dijsktra(int start, int end){
    // 1. 모든 DIST 값에 inf 값을 넣자. 
    for(int i=1; i<=V; i++){ // 아이 씨 팔 진짜. 여기였어 여기였어 여기를 초기화를 안해주는거였어 그냥 처음부터 다 초기화를 해줄거 ㄹ 시팔 시팔 내가 트릴ㄹ리가 없었는데 으암넝리ㅏ먼ㅇ;ㅣ라먼ㅇ;ㅣㅏ러이ㅏ; 여기엿어 
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
 
                PQ.push( { -DIST[next_node], next_node }); 
            }
        }
    }   
}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0);

    // 정점, edge, 건우 위치. 
    cin >> V >> E >> P; 


    for(int i=0,from,to,weight; i<E; i++){
        cin >> from >> to >> weight; 
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    

    dijsktra(1,P); 
    int one_p = DIST[P];
    // cout << " 1-p  : " << one_p << endl;
    dijsktra(P,V); 
    int p_v = DIST[V];
    // cout << " p-v  : " << p_v << endl;
    

    SAVING_GUNOO = one_p + p_v;
    // if(SAVING_GUNOO < INF)
    //     cout << " 건우 들리기  : " << SAVING_GUNOO << endl;
    // else cout << "건우 들리기는 INF " << endl; 

    dijsktra(1,V); 
    IGNORE_GUNOO = DIST[V];
    // cout << "마산 최적화 : " << IGNORE_GUNOO << endl;

    
    if(IGNORE_GUNOO == SAVING_GUNOO) cout << "SAVE HIM";
    else cout << "GOOD BYE";

    return 0; 
}