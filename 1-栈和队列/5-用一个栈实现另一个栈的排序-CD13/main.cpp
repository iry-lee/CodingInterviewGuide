#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(void){
    int n;
    stack<int> st, st2;
    cin >> n;
    cin.get(); 	// 别忘了吃掉这个回车

    // 读取输入
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        st.push(temp);
    }

    // 排序部分
    // 思路是维护一个有序的栈st2，维护的方式就是借助st1，将插入位置前
    st2.push(st.top());
    st.pop();
    while (!st.empty()){
        if(st.top() >= st2.top()){
            st2.push(st.top());
            st.pop();
        }
        else {
            int temp = st.top();
            st.pop();
            while(!st2.empty() && st2.top() > temp){
                st.push(st2.top());
                st2.pop();
            }
            st2.push(temp);
        }
    }

    while(!st2.empty()){
        cout << st2.top() << " ";
        st2.pop();
    }

    return 0;
}
