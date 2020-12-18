#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

const int Module = 1000000007;

int main(void){
    // 读入数据
    int n, aim;
    cin >> n >> aim;
    cin.get();

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 开始计算
    // 用一个大小为 n x aim 的二维数组来存储
    vector<vector<int>> dp (aim+1, vector<int>(n, 0));

    for(int i = 0; i <= aim; i++){
        int sum = 0;
        for(int j = n-1; j >= 0; j--){
            int delta = i - arr[j];
            if(delta == 0) sum += 1;
            else if(delta > 0){
                sum += dp[delta][j];
                sum %= Module;
            }
            dp[i][j] = sum;
        }
    }

    cout << dp[aim][0];

    return 0;
}

// 现在写的程序有问题
// 比如从 1 3 5 中拿出总额为 4的硬币的数目
// 如歌使用上面的程序跑，就会得到三种拿法： 1+1+1+1, 1+3, 3+1，但是可以看到，有一种重复了
// 所以应该找到一种算法，能够避免出现重复的情况
//
// 想到一种 O(N*aim*aim)的方法：
// 可以依次换，比如，现在有面值为 a b c 的钱
// 然后先把能用a换到的数额都置为1
// 之后就不再关心面值为a的钱了，然后就可以求 b的倍数 nb，如果 dp[aim-nb] == 1，那么 dp[aim]++
// 对于面值为c的钱也是同样
// 这个方法是不对的，因为到使用完面值为 b的钱以后，只有dp[aim]是正确的，其他的dp[i]都不正确
// 这个方法实际用起来时间复杂度得是O(N*aim*aim)
//
// 如果使用动态规划，时间复杂度为 O(N*aim)
// 可以使用一张大小为 N*aim的表，来记录过程