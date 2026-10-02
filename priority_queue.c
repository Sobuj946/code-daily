#include <stdio.h>
#define MAX 5

int item[MAX], priority[MAX];
int front = -1, rear = -1;

void enqueue(int data, int p) {
    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    
    if (front == -1) { // First element
        front = rear = 0;
        item[rear] = data;
        priority[rear] = p;
        return;
    }
    
    // Insert according to priority (higher priority = larger p)
    int i;
    for (i = rear; i >= front; i--) {
        if (p > priority[i]) {
            item[i + 1] = item[i];
            priority[i + 1] = priority[i];
        } else {
            break;
        }
    }
    item[i + 1] = data;
    priority[i + 1] = p;
    rear++;
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }
    
    printf("Deleted item: %d with priority %d\n", item[front], priority[front]);
    
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements (item:priority):\n");
    for (int i = front; i <= rear; i++) {
        printf("%d:%d  ", item[i], priority[i]);
    }
    printf("\n");
}

int main() {
    enqueue(10, 2);
    enqueue(30, 3);
    enqueue(20, 1);
    enqueue(40, 5);
    
    display();
    
    dequeue();
    display();
    
    enqueue(50, 4);
    display();
    
    return 0;
}