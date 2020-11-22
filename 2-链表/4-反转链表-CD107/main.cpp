# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};
struct double_list_node{
    int val;
    struct double_list_node * pre, * next;
};

list_node * input_list(void)
{
    int n, val;
    list_node * phead = new list_node();
    list_node * cur_pnode = phead;
    scanf("%d", &n);
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

double_list_node * input_double_list(void)
{
    int n, val;
    double_list_node * phead = new double_list_node();
    double_list_node * cur_pnode = phead;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &val);
        if (i == 1) {
            cur_pnode->val = val;
            cur_pnode->next = NULL;
            cur_pnode->pre = NULL;
        }
        else {
            double_list_node * new_pnode = new double_list_node();
            new_pnode->val = val;
            new_pnode->next = NULL;
            new_pnode->pre = cur_pnode;
            cur_pnode->next = new_pnode;
            cur_pnode = new_pnode;
        }
    }
    return phead;
}

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

double_list_node * reverse_double_list(double_list_node * head)
{
    //////在下面完成代码
    double_list_node * tail_node = nullptr;
    double_list_node * head_node = head;
    while(true){
        double_list_node * temp = head_node->next;
        head_node->next = tail_node;
        if(tail_node != nullptr) tail_node->pre = head_node;
        tail_node = head_node;
        if(temp == nullptr) break;
        else head_node = temp;
    }
    return head_node;
}

void print_list(list_node * head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    puts("");
}

void print_double_list(double_list_node * head)
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
    double_list_node * double_head = input_double_list();
    list_node * new_head = reverse_list(head);
    double_list_node * new_double_head = reverse_double_list(double_head);
    print_list(new_head);
    print_double_list(new_double_head);
    return 0;
}