#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

const int Module = 1000000007;
unordered_map <long long, int> myhash;

int fib(long long n){
    int arr [8] = {0, 1, 1, 2, 3, 5, 8, 13};
    if(n < 8) return arr[(int)n];
    if(myhash.find(n) != myhash.end()) return myhash[n];

    long long temp;
    if(n % 2 == 0) temp = fib(n/2)*(long long)(fib(n/2+1) + fib(n/2-1));
    else temp = (long long)fib(n/2+1)*fib(n/2+1) + (long long)fib(n/2)*fib(n/2);
    myhash[n] = (int)(temp % Module);
    return (int)(temp % Module);
}

int main(void){
    // 读入数据
    long long n;
    cin >> n;
    cout << fib(n);
    return 0;
}
/*
 * 这个题要找到时间复杂度为 O(logn)的方法
 * 看到 O(logn)，自然想到的就是如何在每次计算的时候，都能将后续计算的规模缩小1(n)倍。
 *
 * 斐波那契数列的递推关系式展开，有
 * fn = f(n-1) + f(n-2)
 *    = 2f(n-2) + f(n-3)
 *    = 3f(n-3) + 2f(n-4)
 * 观察到，后面两项的系数，也都符合斐波那契数列
 * 那是不是有这样的一个规律：
 * 如果n为偶数：
 * fn = f(4)f(n-3) + f(3)f(n-4)
 *    = ...
 *    = f(n/2)f(n/2+1) + f(n/2-1)f(n/2)
 * 如果n为奇数：
 * fn = f(4)f(n-3) + f(3)f(n-4)
 *    = ...
 *    = f(n/2+1)f(n/2+1) + f(n/2)f(n/2)
 */

// 问题输入：4593613583255041
// 正确答案：783154704