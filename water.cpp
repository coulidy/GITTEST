#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int trap(int* h, int n) {
    if (n == 0) return 0;
    int *left = (int*)malloc(n * sizeof(int));
    int *right = (int*)malloc(n * sizeof(int));
    left[0] = h[0];
    right[n-1] = h[n-1];
    for (int i = 1; i < n; i++) {
        left[i] = (left[i-1] > h[i]) ? left[i-1] : h[i];
    }
  
    for (int i = n-2; i >= 0; i--) {
        right[i] = (right[i+1] > h[i]) ? right[i+1] : h[i];
    }
  
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (left[i] < right[i] ? left[i] : right[i]) - h[i];
    }
  
    free(left);
    free(right);
    return ans;
}

int main() {
    int capacity = 10;
    int size = 0;
    int* height = (int*)malloc(capacity * sizeof(int));
  
    printf("输入柱子的高度数组（空格分隔）:\n> ");
  
    char input[1024];
    fgets(input, sizeof(input), stdin);
  
    char* token = strtok(input, " ");
    while (token != NULL) {
        if (size >= capacity) { // 动态扩容
            capacity *= 2;
            height = realloc(height, capacity * sizeof(int));
        }
        height[size++] = atoi(token);
        token = strtok(NULL, " ");
    }
  
    int result = trap(height, size);
    printf("雨水总量为: %d\n", result);
  
    free(height);
    return 0;
}