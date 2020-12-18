# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list()
{
    int val, n;
    scanf("%d", &n);
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
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

// 反转单向链表
list_node * reverse_list(list_node * head)
{
    //////在下面完成代码
    list_node * tail_node = nullptr;
    list_node * head_node = head;
    while(true){
        list_node * temp = head_node->next;
        head_node->next = tail_node;
        tail_node = head_node;
        if(temp == nullptr) break;
        else head_node = temp;
    }
    return head_node;
}

// 这里可以将链表切成K段，然后再拼接起来
list_node * reverse_knode(list_node * head1, int K)
{
    //////在下面完成代码
    list_node * prehead = (list_node*) malloc(sizeof(list_node));
    prehead->next = head1;
    list_node * ptr = prehead, *begin = nullptr, *_begin = prehead;
    int ct = 0;
    while(ptr != nullptr){
        if(ct == 1){
            begin = ptr;
            ptr = ptr->next;
        }
        else if(ct == K){
            list_node * temp = ptr->next;
            ptr->next = nullptr;
            _begin->next = reverse_list(begin);
            _begin = begin;
            ct = 0;
            ptr = temp;
        }
        else ptr = ptr->next;
        ct++;
    }
    if(_begin != begin) _begin->next = begin;
    return prehead->next;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

int main ()
{
    list_node * head = input_list();
    int K;
    scanf("%d", &K);
    list_node * new_head = reverse_knode(head, K);
    print_list(new_head);
    return 0;
}