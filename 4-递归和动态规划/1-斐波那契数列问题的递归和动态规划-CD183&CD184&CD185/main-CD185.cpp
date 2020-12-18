#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

const int Module = 1000000007;

long long transMatrix [4][4] = {  1, 0, 0, 1,
                                  1, 0, 0, 1,
                                  0, 1, 0, 0,
                                  0, 0, 1, 0 };

long long beginState [4][4] =  {  1, 0, 0, 0,
                                  0, 0, 0, 0,
                                  0, 0, 0, 0,
                                  0, 0, 0, 0 };

// 矩阵乘法，矩阵m1乘上矩阵m2
long long** MatrixMulti(long long ** m1, long long ** m2, int len){
    long long** result = new long long* [len];
    for(int i = 0; i < len; i++){
        result[i] = new long long [len];
    }

    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            long long temp = 0;
            for(int k = 0; k < len; k++){
                temp += m1[i][k] * m2[k][j];
                temp %= Module;
            }
            // 这里求一个余数，保证最后得到的结果都是在int范围内
            result[i][j] = temp % Module;
        }
    }
    return result;
}

// 矩阵乘方
long long** MatrixPower(long long n, long long ** matrix, int len){
    // 先将result初始化为一个E矩阵
    long long** result = new long long* [len];
    for(int i = 0; i < len; i++){
        result[i] = new long long [len];
        for(int j = 0; j < len; j++){
            if(i == j) result[i][j] = 1;
            else result[i][j] = 0;
        }
    }
    // 然后把n转二进制
    vector<int> bN;
    // 二进制低位在数组头
    // 即 bN[0] 对应的是 2^0，bN[1]对应的是2^1
    while(n > 0){
        bN.push_back(n % 2);
        n = n / 2;
    }
    for(int i = 0; i < bN.size(); i++){
        if(bN[i] == 1) result = MatrixMulti(result, matrix, len);
        matrix = MatrixMulti(matrix, matrix, len);
    }
    return result;
}


int main(void){
    // 读入数据
    long long n;
    cin >> n;

    // 初始化变换矩阵
    int length = 4;
    long long ** transform = new long long* [length];
    for(int i = 0; i < length; i++){
        transform[i] = transMatrix[i];
    }
    // 初始化初始状态
    long long ** state = new long long* [length];
    for(int i = 0; i < length; i++){
        state[i] = beginState[i];
    }

    transform = MatrixPower(n-1, transform, length);
    state = MatrixMulti(state, transform, length);

    auto ans = (long long)(state[0][0] + state[0][1] + state[0][2] + state[0][3]);
    cout << (int)(ans % Module);

    return 0;
}

/*
 * 本题参考的是书上对斐波那契数列问题的解决方法
 * 即找到两种状态之间转换的转换矩阵，然后通过矩阵乘法来求解
 *          成熟母牛    三岁母牛    两岁母牛    一岁母牛
 * 初始 n0:    1           0          0          0
 *   ...
 *      ni:    a           b          c          d
 *    ni+1:   a+b          c          d         a+b
 *   ...
 * 从状态ni到状态ni+1的矩阵变换是：
 * (a, b, c, d)(  1  0  0  1 ) = (a+b, c, d, a+b)
 *             (  1  0  0  1 )
 *             (  0  1  0  0 )
 *             (  0  0  1  0 )
 * 只需要求这个n次方，然后乘上初始向量，就可以得到最终的向量\
 *
 * 本题需要自己写一个矩阵乘法
 */