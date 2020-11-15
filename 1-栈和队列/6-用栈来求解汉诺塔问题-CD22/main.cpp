#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int ct = 0;

// n: 需要移动的圆盘的个数
// s1: 圆盘移出的塔
// s2: 圆盘移入的塔
// help: 中间的过渡塔
// flag: flag = 1 表示s1是lst，flag = 2 表示s1是rst
void movingDisk(int n, stack<int>& s1, stack<int>& s2, stack<int>& help, int flag){
    string outTower, inTower, helpTower = "mid";
    if(flag == 1) {
        outTower = "left";
        inTower = "right";
    }
    else if(flag == 2){
        outTower = "right";
        inTower = "left";
    }
    if(n == 0) return;
    else if(n == 1){
        int temp = s1.top();
        s1.pop();
        // 这里省略了help栈的一轮进出操作，但是输出依旧是做了输出
        cout << "Move " << temp << " from " << outTower << " to " << helpTower << endl;
        cout << "Move " << temp << " from " << helpTower << " to " << inTower << endl;
        ct+=2;
        s2.push(temp);
    }
    else{
        // 这一部分可能有问题
        movingDisk(n-1, s1, s2, help, flag);
        int temp = s1.top();
        s1.pop();
        cout << "Move " << temp << " from " << outTower << " to " << helpTower << endl;
        movingDisk(n-1, s2, s1, help, 3 - flag);
        s2.push(temp);
        cout << "Move " << temp << " from " << helpTower << " to " << inTower << endl;
        movingDisk(n-1, s1, s2, help, flag);
        ct+=2;
    }
}

int main(void){
    int n;
    stack<int> lst, mst, rst;
    cin >> n;
    cin.get(); 	// 别忘了吃掉这个回车
    // init lst
    for(int i = n; i > 0; i--) lst.push(i);
    movingDisk(n, lst, rst, mst, 1);
    cout << "It will move " << ct << " steps.\n";
    return 0;
}

// 汉诺塔是一个非常经典的题目
// 一共有三个柱子，分成左，中，右三支
// 需要将带孔圆盘从最左边的柱子移动到最右边的柱子
// 遵循的规则是，大的圆环不能放在小的圆环上面，
// 而且不能从最左侧的塔直接移动到最右侧，也不能从最右侧的塔直接移动到最左侧
// 初始状态圆盘从小到大依次放在最左边的栈中

// 题目要求是说使用栈模拟，但是我这个确实更像是递归的方法