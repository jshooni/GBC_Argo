/*
4 5 1
1 2
1 3
1 4
2 4
3 4
*/
#include <iostream>
#include <vector> 
using namespace std ;

int N, M, V; 
vector<int> graph[10001] ;
bool visited[10001] ; 


void DFS(int start) { // DFS(1) -> DFS(2) -> DFS(4) -> DFS(3) 
    if ( visited[start] ) return ; 
    
    visited[start] = true ; 
    cout << start << ' '; 

    for (int i = 0 ; i < graph[start].size(); i++) { 
        int next_node = graph[start][i] ; // 4 -> 3
        if ( !visited[next_node] ) {
            DFS(next_node) ;  
        }
    } 
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0) ; 

    cin >> N >> M >> V ; 

    for (int i = 0, a, b; i < M ; i++) { 
        cin >> a >> b ; 
        graph[a].push_back(b) ; 
        graph[b].push_back(a) ;
    }

    DFS(V) ; 

    return 0 ;
}