#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>

using namespace std;

const int Module = 1000000007;

int main(void){
    // 读入数据
    int n;
    cin >> n;
    cin.get();

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 开始计算
    // 新构建的帮助数组，前后分别填充 1以方便计算
    vector<int> help;
    help.push_back(1);
    for(int a : arr) help.push_back(a);
    help.push_back(1);
    // 构建的一个dp矩阵，大小为 (n+2)x(n+2)，初始化为全 0
    // dp[l][r]表示，当 l-1 和 r+1 都没有被打爆的时候，打爆 [l,r]之间的所有的气球的得分
    vector<vector<int>> dp (n+2, vector<int>(n+2, 0));
    // 沿一列列对角线循环求解
    for(int i = 0; i < n; i++){
        for(int l = 1; l <= n-i; l++){
            int r = l + i;
            if(i == 0) dp[l][r] = help[l-1]*help[l]*help[l+1];
            else{
                vector<int> temp;   // 暂存可能解，用来找最优解
                // 假设第 k个球最后被打爆
                for(int k = l; k <= r; k++) {
                    int val = dp[l][k - 1] + help[l - 1] * help[k] * help[r + 1] + dp[k + 1][r];
                    temp.push_back(val);
                }
                dp[l][r] = *max_element(temp.begin(), temp.end());
            }
        }
    }

    cout << dp[1][n];

    return 0;
}

// 打气球的规则是这样的：
// 如果被打爆的气球，左右两边都没有气球，则本次得分为 X
// 如果被打爆的气球，左边还有气球，右边已没有气球，左边离该气球最近的气球得分为 L，则本次得分为 L*X
// 如果被打爆的气球，左边已没有气球，右边还有气球，右边离该气球最近的气球得分为 R，则本次得分为 X*R
// 如果被打爆的气球，左右两边都还有气球，离该气球最近的气球分数分别是 L和 R，则本次得分为 L*X*R

// 本题可以采用递归求解
// 每次打爆一个气球，剩下的气球又可以组成一个新的打气球的问题，故该解法的时间复杂度为 O(n!)
// 那么用动态规划如何求解？
// 打爆一个气球，得分多少，只取决于其左边和右边离它最近的那个球
// 逆着找回去，先是只有一个球，那么得分就是这个球的得分