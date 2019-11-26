#include <stdio.h>
#include <string.h>

char get_check_code(int num[]) {
    int result = 0;
    int weights[] = {2, 7, 6, 5, 4, 3, 2};
    for (int i=0; i<7; i++) {
        result += num[i]*weights[i];
    }
    result = result % 11;
    result = 11 - result;
    char check[] = "-ABCDEFGHIZJ";
    return check[result];

}

int main(void) {
    int n;
    int num[7];
    printf("Enter your 7-digit NRIC number: ");
    scanf("%d", &n);

    for (int i=0; i <7; i++) {
        num[6-i] = n%10;
        n = n/10;
    }

    printf("Your check code is '%c'.", get_check_code(num));
    return 0;
}


