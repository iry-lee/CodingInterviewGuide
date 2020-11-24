#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct ListNode{
    ListNode* next;
    int val;
};

int main(void){
    // 处理输入
    int n, m;
    cin >> n >> m;
    cin.get(); 	// 别忘了吃掉这个回车

    // 先构造环形链表
    auto* prehead = (ListNode*)malloc(sizeof(ListNode));
    ListNode* ptr = nullptr;
    for(int i = 0; i < n; i++){
        auto* temp = (ListNode*)malloc(sizeof(ListNode));
        temp->val = i + 1;
        if(i == 0) prehead->next = temp;
        else ptr->next = temp;
        ptr = temp;
        if(i == n-1) temp->next = prehead->next;
    }

//    ptr = prehead->next;
//    for(int i = 0; i < n; i++){
//        cout << ptr->val << " ";
//        ptr = ptr->next;
//    }
//    cout << endl;

    // 开始杀人
    ptr = prehead;
    while(ptr->next != ptr){
        // 每隔m-1个杀一个
        for(int j = 1; j < m; j++) ptr = ptr->next;
        ListNode* temp = ptr->next->next;
        free(ptr->next);
        ptr->next = temp;
    }

    cout << ptr->next->val;

    return 0;
}