//
// Created by Huang on 2022/4/3 0003.
//
#include "stdio.h"
#include "stdlib.h"
typedef struct Node{
    int data;
    struct Node* next;
}Node;

// 栈
Node* initStack(){
    Node* S = (Node*) malloc(sizeof (Node));
    S->data = 0;
    S->next = NULL;
    return S;
}
//判断栈空
int StackIsEmpty(Node* S){
    if(S->data == 0 || S->next == NULL) return 1;
    return 0;
}
// 进栈
void push(Node* S, int data){
    Node* node = (Node*) malloc(sizeof (Node));
    node->data = data;
    node->next = S->next;
    S->next = node;
    S->data++;
}
// 出栈
int pop(Node* S){
    if(StackIsEmpty(S)) return -1;
    else{
        Node* node = S->next;
        int data = node->data;
        S->next = node->next;
        free(node);
        S->data--;
        return data;
    }
}
// 获取栈顶元素
int getTop(Node* S){
    if(StackIsEmpty(S)) return -1;
    return S->next->data;
}
//遍历栈
void printStack(Node* S){
    Node* node = S->next;
    while(node){
        printf("%d -> ",node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// 队列
Node* initQueue(){
    Node* Q = (Node*) malloc(sizeof (Node));
    Q->data = 0;
    Q->next = NULL;
    return Q;
}
// 判断队空
int QueueIsEmpty(Node* Q){
    if(Q->next == NULL ||Q->data == 0) return 1;
    return 0;
}
//入队
void enQueue(Node* Q, int data){
    Node* node = Q;
    for (int i = 0; i < Q->data; ++i) {
        node = node->next;
    }
    Node* newNode = (Node*) malloc(sizeof (Node));
    newNode->data = data;
    newNode->next = NULL;
    node->next = newNode;
    Q->data++;
}
// 出队
int outQueue(Node* Q){
    if(QueueIsEmpty(Q)) return -1;
    else{
        Node* node = Q->next;
        int data = node->data;
        Q->next = node->next;
        free(node);
        Q->data--;
        return data;
    }
}
void printQueue(Node* Q){
    Node* node = Q->next;
    while(node){
        printf("%d -> ",node->data);
        node = node->next;
    }
    printf("NULL\n");
}
int main(){
//    Node* S = initStack();
//    push(S,10);
//    push(S,20);
//    push(S,30);
//    push(S,40);
//    pop(S);
//    printStack(S);
//    printf("%d\n",S->data);
    Node* Q = initQueue();
    enQueue(Q,1);
    enQueue(Q,10);
    enQueue(Q,100);
    enQueue(Q,1000);
    outQueue(Q);
    outQueue(Q);
    printQueue(Q);
    printf("%d\n",Q->data);
    return 0;
}

