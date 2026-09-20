#include <stdio.h>
#include <stdbool.h>

#define SIZE 11  // Size of the bit array

int bit_array[SIZE] = {0};  // Bloom filter bit array

// Hash function 1: h1(x) = (2 * x + 3) % 11
int hash1(int x) {
    return (2 * x + 3) % SIZE;
}

// Hash function 2: h2(x) = (3 * x + 1) % 11
int hash2(int x) {
    return (3 * x + 1) % SIZE;
}

// Insert a key into the Bloom filter
void insert(int key) {
    int index1 = hash1(key);
    int index2 = hash2(key);
    bit_array[index1] = 1;
    bit_array[index2] = 1;
    printf("Inserted key %d: set bits at %d and %d\n", key, index1, index2);
}

// Check if a key might be in the Bloom filter
bool query(int key) {
    int index1 = hash1(key);
    int index2 = hash2(key);
    return bit_array[index1] && bit_array[index2];
}

// Print the current state of the bit array
void print_bit_array() {
    printf("Bit array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", bit_array[i]);
    }
    printf("\n");
}

int main() {
    // Insert keys into the Bloom filter
    insert(5);
    insert(8);
    insert(13);

    // Print the final bit array
    print_bit_array();

    // Query some keys
    int keys_to_check[] = {5, 10, 8, 20};
    for (int i = 0; i < 4; i++) {
        int key = keys_to_check[i];
        if (query(key)) {
            printf("Key %d might be in the set.\n", key);
        } else {
            printf("Key %d is definitely not in the set.\n", key);
        }
    }

    return 0;
}
