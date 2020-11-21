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
    // 看了一下书上的解法，应该是需要构造两个单调的双端队列
    int ans = 0;
    deque<int> qmax, qmin;
    // 依据是，有一个认识，如果arr[i, j]满足条件，那么arr[i, j]的子集一定满足条件;
    // 如果[i,j]不满足条件，则它的子数组都不满足这一条件
    // 所以每次只需要往后扩展 j，如果满足
    int i = 0, j = 0;
    while(i < n){
        // 更新qmax与qmin
        while (!qmax.empty() && arr[qmax.back()] <= arr[j])
            qmax.pop_back();
        qmax.push_back(j);
        while (!qmin.empty() && arr[qmin.back()] >= arr[j])
            qmin.pop_back();
        qmin.push_back(j);
        // 如果[i,j]满足条件，则它的子数组都满足这一条件
        if(arr[qmax.front()] - arr[qmin.front()] <= num)
            if(j < n-1) j++;
            else{
                // 剩余的n-i长度中，所有的子数组(n-i+1)*(n-i)/2个都满足
                ans += (n-i+1)*(n-i)/2;
                break;
            }
        // 如果[i,j]不满足条件，则它的子数组都不满足这一条件，i后移
        else{
            ans += j-i;
            if(qmin.front() <= i) qmin.pop_front();
            if(qmax.front() <= i) qmax.pop_front();
            i++;
            if(j < i) j = i;
        }
    }
    cout << ans;
    return 0;
}

// 题目：
// 给定数组 arr 和整数 num（这里不一定是正整数哦）共返回有多少个子数组满足 max(arr[i...j]) - min(arr[i...j]) <= num

// 暴力求解的话，需要 O(n^3)的时间复杂度，需要确定所有的数组段n^2的最值
// 如果模拟滑动窗口的话，能把时间复杂度降到 O(n^2)
// 所以使用队列是不是可以有时间复杂度为 O(n)的方法
// 如何化简这一问题，就是要看哪里有多余的计算，即明明知道某些情况不可以，仍旧计算了的
