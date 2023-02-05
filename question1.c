#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    ABS,
    FIB,
    Val
} TypeTag;

typedef struct Node {
    TypeTag operation;
    int result;
    struct Node *left;
    struct Node *right;
} Node;



// function to create a new node
Node* makefunction(TypeTag operation) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->operation = operation;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* makeValue(int result) {
    Node *newvalue = makefunction(Val);
    newvalue->result = result;
    return newvalue;
}
//Fibunacci function using dynamic method
int fibonacci(int n) {
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

// function to calculate the value of a node
int calculate(Node* node) {
    if (node->operation == ADD) {
        return calculate(node->left) + calculate(node->right);
    }
    else if (node->operation == SUB) {
        return calculate(node->left) - calculate(node->right);
    }
    else if (node->operation == MUL) {
        return calculate(node->left) * calculate(node->right);
    }
    else if (node->operation == DIV) {
        return calculate(node->left) / calculate(node->right);
    }
    else if (node->operation == ABS) {
        return abs(calculate(node->left));
    }
    else if (node->operation == FIB) {
        return fibonacci(calculate(node->left));
    }
    else if (node->operation == Val) {
        return node->result;
    }
    
    
}


int main() {
    //for add operation
    Node *add = makefunction(ADD);
    add->left = makeValue(10);
    add->right = makeValue(6);
    //for Multiplication  operation
    Node *mul = makefunction(MUL);
    mul->left = makeValue(5);
    mul->right = makeValue(4);
    //for Division  operation
    Node *div = makefunction(DIV);
    div->left = makeValue(10);
    div->right = makeValue(2);
    //for Subtraction operation
    Node *sub = makefunction(SUB);
    sub->left = makeValue(calculate(add));
    sub->right = makeValue(calculate(mul));
    //for Fibunacci  operation
    Node *fibo = makefunction(FIB);
    fibo->left = makeValue(abs(calculate(sub))-1);
    fibo->result = fibonacci(calculate(fibo->left));
    //for operation results
    printf("add : %d\n", calculate(add));
    printf("mul : %d\n", calculate(mul));
    printf("sub : %d\n", calculate(sub));
    printf("div : %d\n", calculate(div));
    printf("fibo : %d\n", calculate(fibo));
    

    return 0;
}