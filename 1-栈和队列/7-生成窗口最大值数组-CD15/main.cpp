#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(void){
    int n, w;
    deque<int> dq;
    queue<int> ans;

    cin >> n >> w;
    cin.get(); 	// 别忘了吃掉这个回车
    int * arr = new int [n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    int be = 0;
    dq.push_back(be++);
    for(; be < n; be++){
        //  输出dq
        while(!dq.empty() && arr[be] > arr[dq.back()]) dq.pop_back();
        dq.push_back(be);
        if(be >= w-1) {
            while(dq.front() <= be - w) dq.pop_front();
            ans.push(arr[dq.front()]);
        }
    }
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
    return 0;
}

// 本题需要维护一个单调双端队列