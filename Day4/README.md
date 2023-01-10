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
* 무조건 작은 숫자부터 들어가는게 아니라, 배열이 어떻게 정렬되었는지에 따라 그 순서에 따라 '큐'에 들어간다. 
* "큐에서 꺼냈을 때, 현재 위치가 결정이 되는거임 " 




### Code
```c++
    #include <iostream>
    #include <vector>
    #include <queue> 
    using namespace std;
    // queue 를 써야함. 
    // 많이 쓰이는 곳 --> 미로 탐색. 
    // 시작점부터 끝점까지 가는데 얼마나 걸리는가. 최단거리 구할 때 많이 씀. 
    // <-> DFS는 back tracking 할 때 많이 씀. 
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

```



# sort

* > **O(n²)** <br> Bubble Sort, Selection Sort, Insertion Sort, Shell Sort, Quick Sort
* > **O(n log n)** <br>  Heap Sort, Merge Sort
* > **O(kn)** <br> Radix Sort <br>(k는 자릿수, 자릿수가 적은 4바이트 정수에서나 제대로 된 성능을 낼 수 있다는 제약조건이 있다.)
* 
* > bubble sort : 인접한 두 개의 원소를 비교하여 자리를 교환하는 방식
* > Selection Sort : 전체 원소들 중에서 기준 위치에 맞는 원소를 선택하여 자리를 교환하는 방식
* > Insertion Sort : 정렬되어 있는 부분집합에 정렬할 새로운 원소의 위치를 삽입하는 방법<br>

* > Quick Sort : 정렬할 전체 원소에 대해서 정렬을 수행하지 않고,<br> 기준 값을 중심으로 왼쪽 부분 집합과 오른쪽 부분 집합으로 분할하여 정렬하는 방법
* 
* > Heap Sort : 최대 힙 트리나 최소 힙 트리를 구성해 정렬을 하는 방법으로 <br>내림차순 정렬을 위해서는 최대 힙을 구성하고,<br> 오름차순 정렬을 위해서는 최소 힙을 구성하면 된다.
* > Merge Sort : 2개 이상의 자료를 오름차순이나 내림차순으로 재 배열하는 것
# binary_search

