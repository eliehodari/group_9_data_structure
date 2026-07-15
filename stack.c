#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *s) { s->top = -1; }
int isEmpty(Stack *s) { return s->top == -1; }
int isFull(Stack *s) { return s->top == MAX_SIZE - 1; }


void push(Stack *s, char value) {
    if (isFull(s)) { printf("Stack overflow!\n"); return; }
    s->top++;
    s->data[s->top] = value;
}


char pop(Stack *s) {
    char value;
    if (isEmpty(s)) { printf("Stack underflow!\n"); return '\0'; }
    value = s->data[s->top];
    s->top--;
    return value;
}


char peek(Stack *s) {
    if (isEmpty(s)) return '\0';
    return s->data[s->top];
}

int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

int isBalanced(const char *expr) {
    Stack s;
    int i;
    char ch, top;
    initStack(&s);

    for (i = 0; expr[i] != '\0'; i++) {
        ch = expr[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&s, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (isEmpty(&s)) return 0;
            top = pop(&s);
            if (!isMatchingPair(top, ch)) return 0;
        }
    }
    return isEmpty(&s);
}

int main(void) {
    Stack s;
    const char *expressions[] = {
        "{ (a + b) * [c - d] }",
        "([)]",
        "((a+b)",
        "func(x, y[i], {z})"
    };
    int numExpr = 4;
    int i;

    printf("Stack push/pop/peek demonstration\n");
    printf("---------------------------------\n");
    initStack(&s);
    push(&s, 'A');
    push(&s, 'B');
    push(&s, 'C');
    printf("Peek top: %c\n", peek(&s));
    printf("Pop: %c\n", pop(&s));
    printf("Pop: %c\n", pop(&s));
    printf("Peek top: %c\n", peek(&s));

    printf("\nBalanced Brackets Checker\n");
    printf("-------------------------\n");
    for (i = 0; i < numExpr; i++) {
        printf("Expression: %-25s -> %s\n",
               expressions[i],
               isBalanced(expressions[i]) ? "Balanced" : "Not Balanced");
    }

    return 0;
}
