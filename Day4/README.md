# BFS (Breadth-First Search) 너비우선탐색
### <알아야하는 것>
* > 자료구조
* > 큐


## [ 자료구조 ]

###  그래프 자료구조의 구성 
![DFS_example](https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2F4KhlW%2Fbtq1AGGdauX%2FziMkE3TdIKSzvJ8HFUy27k%2Fimg.png)
* 노드 (Node) _ (Vertex)
* 간선 (Edge)

### 그래프탐색 
*  "하나의 노드에서 시작해서 다른 노드들을 방문하는 것"

### 용어정리
* > 루트 노드 (Root node) : 부모 노드가 없는 최상위 노드
* > 단말 노드(leaf node) : 자식 노드가 없는 노드
* > 크기(size) : 모든 노드의 개수
* > 깊이(depth) : 루트 노드로부터 거리
* > 높이(height) : 깊이의 최댓값
* > 차수(degree) : 노드별 간선 개수(트리에서는 자식 노드 방향 간선 개수)




## BFS
* BFS 알고리즘은 그래프에서 가까운 노드부터 우선적으로 탐색한다는 점에서, 선입선출 방식의 큐(Queue) 자료구조를 활용.
* (즉, BFS는 인접한 노드를 반복적으로 큐에 삽입하고  먼저 삽입된 노드부터 차례로 큐에서 꺼내도록 알고리즘을 작성)  

>1. 탐색 시작 노드 정보를 큐에 삽입하고 **방문 처리**
>2. 큐에서 노드를 꺼내 방문하지 않은 인접 노드 정보를 모두 큐에 삽입하고 방문 처리
>3. 2번의 과정을 더 이상 수행할 수 없을 때까지 반복합니다.
* **방문처리** : 탐색한 노드를 재방문하지 않도록 구분하는 것.
(큐에 한 번이라도 삽입된 노드를 다시 삽입하지 않도록 체크)



# sort
# binary_search

