#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

int main(void){
    int n, aim;
    cin >> n >> aim;
    cin.get(); 	// 别忘了吃掉这个回车

    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++) cin >> arr[i];

    // 开始计算
    // 可以先使用table来存储所得到的结果
    vector<int> table (aim+1, -1);
    table[0] = 0;
    for(int i = 1; i <= aim; i++){
        for(int j = 0; j < n; j++){
            int delta = i - arr[j];
            if(delta >= 0 && delta <= aim && table[delta] >= 0){
                int num = table[delta] + 1;
                if(table[i] == -1) table[i] = num;
                else if(table[i] > num) table[i] = num;
            }
        }
    }
//    for(int t : table) cout << t << " ";
//    cout << endl;

    cout << table[aim];

    return 0;
}
/*
 * 给定数组arr，arr中所有的值都为正整数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，
 * 再给定一个aim，代表要找的钱数，求组成aim的最少货币数。
 * 输出一个整数，表示组成aim的最小货币数，无解时输出-1。
 * 要求：时间复杂度O(n*aim)，空间复杂度O(n)。
 *  这里的空间复杂度要求为O(n)应该是有问题的，空间复杂度应该为O(aim)
 */