#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void func(stack<int> st){
    if(st.empty()) return;
    cout << st.top() << " ";
    st.pop();
    func(st);
}

int main(void){
    int n;
    stack<int> st;
    cin >> n;
    cin.get(); 	// 别忘了吃掉这个回车

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        st.push(temp);
    }

    func(st);
    return 0;
}
