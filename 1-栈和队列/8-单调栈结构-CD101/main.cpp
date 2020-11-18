#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(void){
    // 处理输入
    int n;
    cin >> n;
    cin.get(); 	// 别忘了吃掉这个回车
    int * arr = new int [n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    // 单调栈结构
    vector<vector<int>> ans(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++) ans[i][j] = -1;
    }

    stack<int> increasingSt;
    for(int i = 0; i < n; i++){
        while (!increasingSt.empty() && arr[increasingSt.top()] > arr[i]){
            // 弹出，并且得到结果
            ans[increasingSt.top()][1] = i;
            increasingSt.pop();
        }
        increasingSt.push(i);
    }

    while (!increasingSt.empty()) increasingSt.pop();
    for(int i = n-1; i >= 0; i--){
        while (!increasingSt.empty() && arr[increasingSt.top()] > arr[i]){
            // 弹出，并得到结果
            ans[increasingSt.top()][0] = i;
            increasingSt.pop();
        }
        increasingSt.push(i);
    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}

// 题目：
// 给定一个不含有重复值的数组 arr，找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置。返回所有位置相应的信息。
// 题目的意思是说，分别返回某一位置i的左边和右边第一个比arr[i]小的数所在的位置