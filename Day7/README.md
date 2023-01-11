# DP (Dynamic Programming)

## Top down / bottom up

## 배경
> 피보나치 수열. 
>> 이미 했던 연산이 반복되는 결점을 보완하기 위해서

## 원리
> 처음 진행되는 연산은 기록해 두고,<br> 
> 이미 진행했던 연산이라면 다시 연산하는 것이 아니라,<br>  기록되어 있는 값을 가져옴. 

## 개념
> 하나의 문제를 여러 하위 문제로 나누어 풀고, 그것들을 결합해서 최종 목적에 도달하는 방식의 알고리즘이에요.


<br> 


## 특징
> * DP is a technique for solving problems by breaking them down into smaller subproblems and storing the solutions to these subproblems in a table or array.<br> 
> * The key to DP is to find the right subproblems to solve and the order in which to solve them.<br> 
> * DP algorithms typically have a time complexity of O(n^2) or O(n^3), where n is the size of the input.
> * DP is useful for solving problems that have an optimal substructure, meaning that the optimal solution can be constructed from optimal solutions of its subproblems.<br> 
> * DP is often used to solve optimization problems, such as finding the shortest path or the longest increasing subsequence.<br> 
Some common DP problems include the Knapsack problem, the Longest Common Subsequence (LCS) problem, and the Edit Distance problem.
> * It is important to choose the right data structures and implementation techniques to ensure that the DP solution is as efficient as possible.<br> 

<br> <br> <br> 
* > 동적 계획법(DP, Dynamic Programming)은 작은 하위 문제로 문제를 나누고 그 해결책을 테이블이나 배열에 저장하는 기법입니다.<br> 
* > DP의 핵심은 적절한 하위 문제를 찾고 그것들을 해결하는 순서를 찾는 것입니다.<br> 
* > DP 알고리즘은 일반적으로 O(n^2) 또는 O(n^3)의 시간 복잡도를 가지며, 여기서 n은 입력의 크기입니다.<br> 
* > DP는 최적의 구조를 가진 문제를 해결할 때 유용합니다. 이는 최적의 해결책이 그 하위 문제의 최적 해결책으로부터 구성될 수 있다는 것을 의미합니다.<br> 
* > DP는 최단 경로를 찾거나 가장 긴 증가하는 서브시퀀스를 찾는 것과 같은 최적화 문제를 해결할 때 자주 사용됩니다.<br> 
일반적인 DP 문제로는 캐리어(Knapsack) 문제, 최장 공통 서브시퀀스(LCS, Longest Common Subsequence) 문제, 그리고 편집 거리(Edit Distance) 문제가 있습니다.<br> 

* > DP 솔루션이 가능한 최고의 효율을 유지하기 위해 적절한 데이터 구조와 구현 기법을 선택하는 것이 중요합니다.


## fibonacci (Top DOWN)
```c++ 
    int fiboData[100] = {0,};
    int fibo(int n)
    {
        if( n >= 2 ) return 1;
        
        if(fiboData[n] == 0)
            fiboData[n] = fibo(n-1) + fibo(n-2);
        
        return fiboData[n];
    }
```
<br><br><br>
## fibonacci (Bottom UP)

```c++ 
    int fiboData[100] = {0,};
    
    int fibo(int n){
        fiboData[0] = 0; 
        fiboData[1] = 1;

        for(int i=2;  i <= n  ; i++){
            fiboData[i] = fiboData[i-1] + fiboData[i-2];
        }

        return fiboData[n]; 
    }
```

# TopDown vs BottomUp

* TopDown 
    > 반복되는 부분을 지워줘야 함. 

* BottomUp
    > 넘어가야하는 부분이 없기 때문에, 쬐금더 일반적으로 할 수 잇음. 
