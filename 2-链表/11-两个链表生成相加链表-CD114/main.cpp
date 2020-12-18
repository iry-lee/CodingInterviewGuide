# include <bits/stdc++.h>
using namespace std;

struct list_node{
    int val;
    struct list_node * next;
};

list_node * input_list(int n)
{
    int val;
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


list_node * add_list(list_node * head1, list_node * head2)
{
    //////在下面完成代码
    stack<int> st1, st2;
    queue<int> q;
    list_node * ptr1 = head1, * ptr2 = head2;
    while(ptr1 != nullptr){
        st1.push(ptr1->val);
        ptr1 = ptr1->next;
    }
    while(ptr2 != nullptr){
        st2.push(ptr2->val);
        ptr2 = ptr2->next;
    }

    // 然后进行加法运算
    int up = 0;
    while(!st1.empty() || !st2.empty()){
        int a = 0, b = 0;
        if(!st1.empty()){
            a = st1.top();
            st1.pop();
        }
        if(!st2.empty()){
            b = st2.top();
            st2.pop();
        }
        int temp = a + b + up;
        if(temp < 10) up = 0;
        else{
            up = 1;
            temp = temp % 10;
        }
        q.push(temp);
    }
    if(up == 1) q.push(1);

    // 重新构建一个新的链表
    list_node * head = nullptr;
    while(!q.empty()){
        list_node * node = (list_node *)malloc(sizeof(list_node));
        node->val = q.front();
        q.pop();
        node->next = head;
        head = node;
    }

    return head;
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
    int n, m;
    scanf("%d%d", &n, &m);
    list_node * head1 = input_list(n), * head2 = input_list(m);
    list_node * new_head = add_list(head1, head2);
    print_list(new_head);
    return 0;
}