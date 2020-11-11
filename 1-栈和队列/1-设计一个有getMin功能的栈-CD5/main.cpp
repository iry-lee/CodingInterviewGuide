#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class minStack{
private:
    stack<int> st;
    stack<int> helperSt;
    int gmin = INT_MAX;
public:
    // 构造函数
    minStack(){}

    void push(int n){
        st.push(n);
        if(n < gmin) gmin = n;
        helperSt.push(gmin);
    }

    void pop(){
        helperSt.pop();
        st.pop();
        if(helperSt.size() == 0) gmin = INT_MAX;
        else gmin = helperSt.top();
    }

    void getMin(){
        cout << helperSt.top() << endl;
    }
};

int main(void){
    int n;
    cin >> n;
    cin.get(); 	// 别忘了吃掉这个回车
    minStack ms;
    for(int i = 0; i < n; i++){
        string line;
        getline(cin,line);
        vector<int> temp;
        if(line[0] == 'p'){
            if(line[1] == 'u'){
                // line[5:]是对应的数字
                ms.push(stoi(line.substr(5)));
            }
            else ms.pop();
        }
        else ms.getMin();
    }
    return 0;
}
