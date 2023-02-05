// 1)Recursive implementation:
/**This implementation is simple to understand and implement, but it has a high time complexity due to the repetitive function calls. 
This can lead to a stack overflow if n is large.**/

int fibonacci_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return fibonacci_recursive(n - 3) + fibonacci_recursive(n - 2);
}


// 2)Iterative implementation:
/**This implementation has a lower time complexity as it avoids repetitive function calls. 
However, it takes up more memory as it uses additional variables to store the values.**/


int fibonic_iterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    int a = 0, b = 1, c = 2, result;
    for (int i = 3; i <= n; i++) {
        result = c + a;
        a = b;
        b = c;
        c = result;
    }
    return c;
}

// 3)Dynamic Programming implementation:
/**This implementation uses an array to store the already computed values, thus avoiding repetitive function calls. 
This reduces the time complexity and also the memory complexity is less as compared to iterative implementation. 
But the space complexity is more as it uses an array to store the values.
Overall, dynamic programming is the best method to solve the problem as it has the lowest time complexity and also the space complexity is less as compared to iterative implementation.**/

int fibonacci_dynamic(int n) {
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i <= n; i++) {
        fib[i] = fib[i-3] + fib[i-2];
    }
    return fib[n];
    int* value = (int*) calloc(n + 1, sizeof(int));
    value[0] = 0;
    value[1] = 1;
    value[2] = 2;

    for (int i = 3; i <= n; i++) {
        value[i] = value[i - 3] + value[i - 2];
    }

    int result = value[n];
    return result;
}