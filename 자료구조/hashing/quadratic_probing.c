#include <stdio.h>

#define TABLE_SIZE 13
#define EMPTY -1
#define DELETED -2

int hash_table[TABLE_SIZE];

// Hash function
int hash(int key) {
    return key % TABLE_SIZE;
}

// Insert using quadratic probing
void insert(int key) {
    int index = hash(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int new_index = (index + i * i) % TABLE_SIZE;

        if (hash_table[new_index] == EMPTY || hash_table[new_index] == DELETED) {
            hash_table[new_index] = key;
            printf("Inserted %d at index %d\n", key, new_index);
            return;
        }
        i++;
    }
    printf("Failed to insert %d: Hash table is full.\n", key);
}

// Search key in hash table
int search(int key) {
    int index = hash(key);
    int i = 0;

    while (i < TABLE_SIZE) {
        int new_index = (index + i * i) % TABLE_SIZE;

        if (hash_table[new_index] == EMPTY)
            return -1;  // Not found

        if (hash_table[new_index] == key)
            return new_index;

        i++;
    }
    return -1; // Not found after full loop
}

// Delete a key from the hash table
void delete(int key) {
    int pos = search(key);
    if (pos != -1) {
        hash_table[pos] = DELETED;
        printf("Deleted key %d from index %d\n", key, pos);
    } else {
        printf("Key %d not found for deletion.\n", key);
    }
}

// Display the hash table
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == EMPTY)
            printf("[%d] EMPTY\n", i);
        else if (hash_table[i] == DELETED)
            printf("[%d] DELETED\n", i);
        else
            printf("[%d] %d\n", i, hash_table[i]);
    }
    printf("\n");
}

int main() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = EMPTY;
    }

    // Insert keys
    int keys[] = {18, 41, 22, 44, 59, 32, 31};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(keys[i]);
    }

    display();

    // Delete a few keys
    delete(22);
    delete(59);

    display();

    // Search after deletion
    int search_keys[] = {22, 31, 59};
    for (int i = 0; i < 3; i++) {
        int result = search(search_keys[i]);
        if (result != -1)
            printf("Key %d found at index %d\n", search_keys[i], result);
        else
            printf("Key %d not found in the hash table.\n", search_keys[i]);
    }

    return 0;
}
