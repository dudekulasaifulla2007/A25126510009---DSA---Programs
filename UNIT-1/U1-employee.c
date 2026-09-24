#include <stdio.h>

int main() {
    int n, i, key;
    int low, high, mid;
    int comparisons = 0;
    int position = -1;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    int id[n];

    printf("Enter employee IDs in ascending order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &id[i]);
    }

    printf("Enter employee ID to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        comparisons++;

        if (id[mid] == key) {
            position = mid;
            break;
        }
        else if (key < id[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (position != -1) {
        printf("Employee ID found at position: %d\n", position + 1);
    }
    else {
        printf("Employee ID not found\n");
    }

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}