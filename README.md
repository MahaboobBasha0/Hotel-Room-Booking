# Hotel-Room-Booking![image](https://github.com/user-attachments/assets/e70caad9-2325-414d-bb0e-90a1a365befd)
 #include <stdio.h>
void hallosquare(int n);
int main() {
    int n;
    printf("Enter the size of the square: ");
    scanf("%d", &n);
    hallosquare(n);
    return 0;
}
void hallosquare(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("$");
            } else {
                printf(" ");
            }
        }
        printf("\n"); 
    }
}
