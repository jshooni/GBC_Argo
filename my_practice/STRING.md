# C++ 에서 String 사용하기 

```c++
    string first = "first";
    string second  = "Second" ; 
    first.append(second); 
```
* > 이렇게 하면 string first 자체가 바뀌게 된다. 
* > 단순 합치는게 아니라 위에 덮어 씌우는 개념임. 
* > return 값 : 그렇게 합쳐진 first를 리턴함. 

<br><br>
# Use '+'  instead of 'append' 
## 기존을 그래도 유지하고 합쳐진 거를 따로 다루고 싶을 때
```c++
    #include <iostream>
    #include <string>
    using namespace std;

    int main(void){
    
        string first = "first";
        string second = "second"; 
        string full = first + second ; 
        cout << "full name : " << full << endl; 
        cout << "Still first name is : " << first << endl; 
        return 0; 
    }
```
<br><br><br><br>
## string 안에 < " ' \ > 을 표현하고 싶다.
* > " &nbsp; -> &nbsp; \\"
* > ' &nbsp; -> &nbsp; \\'
* > \ &nbsp; -> &nbsp; \\\

### Example 
```c++ 
    string example = "I want to put \" or \' or \\ in this string"; 
    cout << "Result : " << example << endl;
```
