# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
}; //链表的节点

int K;

list_node * input_list(void) //读入链表
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
        }
        else {
            list_node * new_pnode = new list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

list_node * remove_last_kth_node(list_node * head, int K)
{
    //////在下面完成代码
    // 设置前后两个指针，前面的指针先走k步
    list_node * prehead = (list_node *)malloc(sizeof(list_node));
    prehead->next = head;
    list_node * ptr1 = prehead, *ptr2 = prehead;
    for(int i = 0; i < K; i++) ptr1 = ptr1->next;
    while(ptr1->next != nullptr){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // 把ptr2后面对应的那个节点删除
    list_node * temp = ptr2->next->next;
    ptr2->next = temp;
    return prehead->next;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main ()
{
    list_node * head = input_list(); // 链表的头节点
    list_node * rhead = remove_last_kth_node(head, K);
    print_list(rhead);
    return 0;
}