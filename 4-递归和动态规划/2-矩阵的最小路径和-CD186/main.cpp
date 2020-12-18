#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    cin.get(); 	// 别忘了吃掉这个回车

    // 数据读入
    vector<vector<int>> matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> matrix[i][j];
    //开始计算
    // 这里dp只有两行的原因是，这里的结果只与上一行的值有关
    vector<int> dp (m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) dp[j] = matrix[i][j];
            else if(i == 0 && j != 0)
                dp[j] = dp[j-1] + matrix[i][j];
            else if(i != 0 && j == 0)
                dp[j] = dp[j] + matrix[i][j];
            else dp[j] = min(dp[j], dp[j-1]) + matrix[i][j];
        }
    }

    cout << dp[m-1];

    return 0;
}
/*
 * 给定一个 n * m 的矩阵 a，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，
 * 路径上所有的数字累加起来就是路径和，输出所有的路径中最小的路径和。
 */