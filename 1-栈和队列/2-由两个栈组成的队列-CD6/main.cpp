#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class QueueStack{
private:
    stack<int> st1; // 先进这个栈
    stack<int> st2;
public:
    // 构造函数
    QueueStack(){}

    void add(int n){
        st1.push(n);
    }

    void poll(){
        if(st2.empty()){
            while (!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        st2.pop();
    }

    void peek(){
        if(st2.empty()){
            while (!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        cout << st2.top() << endl;
    }
};

int main(void){
    int n;
    cin >> n;
    cin.get(); 	// 别忘了吃掉这个回车
    QueueStack qs;
    for(int i = 0; i < n; i++){
        string line;
        getline(cin,line);
        vector<int> temp;
        if(line[0] == 'p'){
            if(line[1] == 'o'){
                qs.poll();
            }
            else qs.peek();
        }
        else qs.add(stoi(line.substr(4)));
    }
    return 0;
}
