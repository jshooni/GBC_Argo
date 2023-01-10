#include <iostream>
#include <vector>
#include <queue> 
#include <algorithm> 

using namespace std;

int N, M, V;
vector<int> graph_dfs[10001];
vector<int> graph_bfs[10001];
bool visited_dfs[10001];
bool visited_bfs[10001];
// vector<int> printout[10001];


void DFS(int start) { // DFS(1) -> DFS(2) -> DFS(4) -> DFS(3) 
    if ( visited_dfs[start] ) return ; 
    
    visited_dfs[start] = true ;

    // printout[0].push_back(start);
    cout << start << ' ' ; 

    sort(graph_dfs[start].begin(),graph_dfs[start].end());

    for (int i = 0 ; i < graph_dfs[start].size(); i++) { 
        int next_node = graph_dfs[start][i] ; // 4 -> 3
        if ( !visited_dfs[next_node] ) {
            DFS(next_node) ;  
        }
    } 
}

void BFS(int start){
    queue<int> Q; 
    Q.push(start);
    visited_bfs[start] = true; 

    while ( !Q.empty() ) {
        int curr = Q.front() ; 
        Q.pop() ; 

        cout << curr << ' ' ; 

        sort(graph_bfs[curr].begin(),graph_bfs[curr].end());

        for (int i = 0 ; i < graph_bfs[curr].size(); i++) {
            int next = graph_bfs[curr][i] ;

            if (!visited_bfs[next]) {
                visited_bfs[next] = true ;
                Q.push(next) ;
            }
        }
    }

}

int main(void){
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N >> M >> V; 
    // N : 노드 개수    M  : edge 개수  v : 시작 노드 

    for(int i=0, a, b; i< M ; i++){
        cin >> a >> b;
        // 연결되는 가가각의 노드  그래프 a -> 1 ? -> 1이라는 노드에서 연결되는.  양방향을 알려주기 위해서 b를 입력받아주는거임. 
        graph_dfs[a].push_back(b);
        graph_dfs[b].push_back(a);
        graph_bfs[a].push_back(b);
        graph_bfs[b].push_back(a);
    }

    DFS(V);
    cout << endl;
    BFS(V);

    return 0; 

}