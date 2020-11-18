#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(void){
    // 处理输入
    int n, num;
    cin >> n >> num;
    cin.get(); 	// 别忘了吃掉这个回车
    int * arr = new int [n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    // 求子数组的数量
    int ans = 0;
    for(int i = 0; i < n; i++){
        queue<int> window;
        int max = INT_MIN, min = INT_MAX;
        // 这里的i为前面窗口的开始位置
        for(int j = i; j < n; j++){
            
        }
    }

    return 0;
}

// 题目：
// 给定数组 arr 和整数 num，共返回有多少个子数组满足 max(arr[i...j]) - min(arr[i...j]) <= num

// 暴力求解的话，需要O(n^3)的时间复杂度，需要确定所有的数组段n^2的最值
// 如果模拟滑动窗口的话，能把时间复杂度降到O(n^2)