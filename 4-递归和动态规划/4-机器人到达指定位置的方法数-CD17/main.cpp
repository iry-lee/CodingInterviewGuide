#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

int main(void){
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    cin.get(); 	// 别忘了吃掉这个回车

    // 初始化
    const int Module = 1000000007;
    vector<int> dp (n, 0);
    vector<int> _dp (n ,0);
    _dp[m-1]  = 1;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            if(j == 0) dp[j] = _dp[j+1];
            else if(j == n-1) dp[j] = _dp[j-1];
            else dp[j] = (_dp[j+1] + _dp[j-1]) % Module;
        }
        for(int j = 0; j < n; j++){
            _dp[j] = dp[j];
        }
    }
    cout << dp[p-1];
    return 0;
}
/*
 */