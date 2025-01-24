//{ Driver Code Starts

// } Driver Code Ends
#include <stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main() {

    int a, b;
    scanf("%d %d", &a, &b);

    // write code to swap the values of a and b
    swap(&a,&b);

    printf("%d %d\n", a, b);

    return 0;
}

//{ Driver Code Starts.
// } Driver Code Ends