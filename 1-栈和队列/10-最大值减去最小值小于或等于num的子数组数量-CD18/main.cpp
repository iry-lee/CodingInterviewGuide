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




    return 0;
}

// 题目：
// 给定数组 arr 和整数 num，共返回有多少个子数组满足 max(arr[i...j]) - min(arr[i...j]) <= num