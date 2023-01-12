# Dijsktra (다익스트라)
* 에츠허르 다익스트라가 고안한 알고리즘
* 하나의 시작 정점에서 다른 모든 정점까지의 최단거리를 구하는 알고리즘 (음의 가중치는 x)
### 사용처
* 도로 교통망에서의 최단거리 

## 구현 
* > vector< pair<int,int> > graph[N]; 
* * N개의 node, 각 edge와 그의 weight를 설정
* > DIST[N]; 
* * 시작노드로부터 해당 노드까지 최단거리로 가는 '거리' 
* > #define INF INT_MAX
* * 각 노드까지의 최단거리를 배열에 저장할 때, min 값을 저장하기 때문에, -> 초기 모든 노드 최단거리=무한대로 설정. 
* > priority_queue< pair< int,int>  > PQ; 
* * { weight , currnode }를 저장. 
* * 최단거리가 된 node를 저장. 

*> 루트노드부터 해서 특정 노드가지 최단시간으로 가는거임.
1번에서 4번노드까지의 최단경로를 구하고자 한다고 치면. 
3을 거쳐서 가면 9가 걸리고
2를 거쳐서 가면 7이 걸림. 

Result 

시작노드를 1로 했을 때. 

Distance 배열--> 시작노드는 0번째. 
0 2 3 7 INF (5는 도달할 수 없다는 의미로 그냥 무한이라고 표시 )

1. 다익스트라 맨 처음 세팅을 할 때 inf inf inf inf inf inf 로 초기화를 해줘야함. 



다익스트라 쓸 때,  vs 벨만포드 쓸 때 

다익스트라 -> weight 값이 양수일 때만 사용 가능. 

단방향인지 양방향인지 확인하는게 중요함 일단 ㅇㅇ . 


<br><br><br><br><br><br><br><br><br><br>

# 1753
#define INF 
vector<int> v_int(10 , INF); 
vector<double> v_double(10 , INF); 

v_int[1] --> int
v_double[1] --> double

v_int[1] / 3 --> xxx
v_double[1] / 3 --> xxx.lllllll 


```c++
#include <iostream> 
#include <vector>
#include <queue>
#include <climits>
#define INF INT_MAX

using namespace std; 

int V, E, start;
vector< pair<int, int> > graph[20001]; // 노드의 개수. 
int DIST[300001]; //간선의 개수

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
    while( !PQ.empty() ){
        int curr_weight = -PQ.top().first; 
        int curr_node = PQ.top().second;
        PQ.pop(); // 현재에다가 저장을 했으니까 pop을 해야겠지. 
        
        //인접노드 조사. 
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


int main(void) {
    cin >> V >> E >> start;
    for(int i=0, from, to, weight; i<E; i++){
        cin >> from >> to >> weight;
        graph[from].push_back( {to, weight} );
    }

    dijsktra(); 

    for(int i=1; i<=V; i++){
        if(DIST[i]==INF)
            cout << "INF" << endl; 
        else 
            cout << DIST[i] << endl; 
    }
    return 0; 
}
```



# 절대 endl;을 쓰지마라. '\n'을 써라. 
1753번 같은경우 endl을 썻을 때 900ms 정도 나왔는데 
\n로 두줄 바꿔주자마자 100ms가 나오는 것을 볼 수 있다.

추가로 반복문 안에서 int 선언하며 변수에 값을 집어 넣어주는 것은 시간초과에 영향이 거의 없다. 

++ 추가로. 
ios::sync_with_stdio(false); 
cin.tie(0); cout.tie(0); 
를 써주지 않았을 때는 약 328ms 가 나와서 3배정도 느려졌다. 

# 1503 최단경로 구하기 
* case 1) 1 -> v1 -> v2 -> N
* case 2) 1 -> v2 -> v1 -> N
* 추가 정보. v1==1 , v2==N  일때 나눠서 생각. 
다른 특별한거는 없음. 자신있게 케이스 분류. 
