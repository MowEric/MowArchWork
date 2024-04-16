#include <stdio.h>

struct node {
    char letter;
    int pos;
    float value;
    struct node * next;
};


int main() {
    double c = sizeof(struct node);//sizeof(char) + sizeof(int) + sizeof(float);
    printf("%lf", c);
}
