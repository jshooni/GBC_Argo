#include <iostream>
#include <vector>
#include <queue> 
using namespace std;
// queue 를 써야함. 
// 많이 쓰이는 곳 --> 미로 탐색. 
// 시작점부터 끝점까지 가는데 얼마나 걸리는가. 최단거리 구할 때 많이 씀. 
// <-> DFS는 back tracking 할 때 많이 씀. 
// 
int N, M, V; 
vector<int> graph[10001];
bool visited[10001]; 

//안보고 짤 줄 알아야해 
// 이거는 그래플 할 때 쓰는거고. ㅇㅇ w
void BFS(int start){
    queue<int> Q; 
    Q.push(start);
    visited[start] = true; 

    while( !Q.empty() ){
        int curr = Q.front();
        Q.pop();

        cout << curr << ' '; 

        for( int i=0; i<graph[curr].size(); i++){
            int next = graph[curr][i];
            if(!visited[next]){
                visited[next] = true; 
                Q.push(next);
            }
        }
    }
    cout << '\n';
}


int main(void){
    
    cin >> N >> M >> V;
    for(int i=0, a, b; i< M ; i++){
        cin >> a >> b; 
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    BFS(V);

    return 0; 

}
