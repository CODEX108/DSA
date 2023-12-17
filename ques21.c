#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 23

typedef struct KeyValue {
    char *key;
    char *value;
    bool isDeleted;
} KeyValue;

typedef struct {
    KeyValue **array;
    int size;
    float load_factor;
    // num of keys present
    int num_keys;
    // num of array indices of the table that are occupied
    int num_occupied_indices;
    // num of ops done so far
    int num_ops;
} HashTable;

KeyValue *createKeyValue(char *key, char *value) {
    KeyValue *newKeyValue = (KeyValue *)malloc(sizeof(KeyValue));
    if (newKeyValue != NULL) {
        newKeyValue->key = key;
        newKeyValue->value = value;
        newKeyValue->isDeleted = false;
    }
    return newKeyValue;
}

HashTable *createHashTable() {
    HashTable *newTable = (HashTable *)malloc(sizeof(HashTable));
    newTable->array = (KeyValue **)malloc(TABLE_SIZE * sizeof(KeyValue *));
    for (int i = 0; i < TABLE_SIZE; i++)
        newTable->array[i] = NULL;

    newTable->size = TABLE_SIZE;
    newTable->load_factor = 0;
    newTable->num_keys = 0;
    newTable->num_occupied_indices = 0;
    newTable->num_ops = 0;
    return newTable;
}

// Use sum of ASCII values to convert string to int
int key_to_int(char *key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum;
}

// Quadratic probing sequence
int probe_sequence(int attempt, int base) {
    return attempt * attempt * base;
}

// Return the index position in the table where the insertion happens
// Return -1 if insertion fails
int insert_key_value(HashTable *ht, char *key, char *value) {
    if (ht == NULL || key == NULL || value == NULL) {
        return -1; // Invalid input
    }

    int key_int = key_to_int(key);
    int index = key_int % ht->size;
    int original_index = index;
    int attempt = 0;

    while (ht->array[index] != NULL) {
        if (strcmp(ht->array[index]->key, key) == 0 && !ht->array[index]->isDeleted) {
            // Key already exists, update the value
            free(ht->array[index]->value);
            ht->array[index]->value = value;
            return index;
        }

        attempt++;
        index = (original_index + probe_sequence(attempt, 1)) % ht->size;
        ht->num_ops++;
    }

    // Key doesn't exist, insert a new key-value pair
    KeyValue *newKeyValue = createKeyValue(key, value);
    if (newKeyValue == NULL) {
        return -1; // Memory allocation failed
    }

    ht->array[index] = newKeyValue;
    ht->num_keys++;
    ht->num_occupied_indices++;
    ht->num_ops++;
    ht->load_factor = (float)ht->num_keys / ht->size;

    return index;
}

// Return the value of the key in the table
// Return NULL if key not found
char *search_key(HashTable *ht, char *key) {
    if (ht == NULL || key == NULL) {
        return NULL; // Invalid input
    }

    int key_int = key_to_int(key);
    int index = key_int % ht->size;
    int original_index = index;
    int attempt = 0;

    while (ht->array[index] != NULL) {
        if (strcmp(ht->array[index]->key, key) == 0 && !ht->array[index]->isDeleted) {
            // Key found
            return ht->array[index]->value;
        }

        attempt++;
        index = (original_index + probe_sequence(attempt, 1)) % ht->size;
        ht->num_ops++;
    }

    // Key not found
    return NULL;
}

// Return the index position in the table where the deletion happens
// Return -1 if deletion fails
int delete_key(HashTable *ht, char *key) {
    if (ht == NULL || key == NULL) {
        return -1; // Invalid input
    }

    int key_int = key_to_int(key);
    int index = key_int % ht->size;
    int original_index = index;
    int attempt = 0;

    while (ht->array[index] != NULL) {
        if (strcmp(ht->array[index]->key, key) == 0 && !ht->array[index]->isDeleted) {
            // Mark the key as deleted
            ht->array[index]->isDeleted = true;
            ht->num_keys--;
            return index;
        }

        attempt++;
        index = (original_index + probe_sequence(attempt, 1)) % ht->size;
        ht->num_ops++;
    }

    // Key not found
    return -1;
}

// This equals the number of keys in table/size of table
int get_load_factor(HashTable *ht) {
    if (ht == NULL) {
        return -1; // Invalid input
    }

    return ht->load_factor * 100; // Return load factor as a percentage
}

// This equals the number of operations done so far/num of elems in table
int get_avg_probes(HashTable *ht) {
    if (ht == NULL || ht->num_ops == 0) {
        return -1; // Invalid input or no operations performed
    }

    return ht->num_ops / ht->num_keys;
}

// Display hash table visually
void display(HashTable *ht) {
    printf("\nHash Table:\n");
    for (int i = 0; i < ht->size; i++) {
        if (ht->array[i] != NULL && !ht->array[i]->isDeleted) {
            printf("[%d] Key: %s, Value: %s\n", i, ht->array[i]->key, ht->array[i]->value);
        } else {
            printf("[%d] NULL or Deleted\n", i);
        }
    }
}

int main() {
    HashTable *ht = createHashTable();

    // Insert key-value pairs
    insert_key_value(ht, "first name", "John");
    insert_key_value(ht, "last name", "Doe");
    insert_key_value(ht, "uid", "12345");
    insert_key_value(ht, "sport", "Football");
    insert_key_value(ht, "food", "Pizza");
    insert_key_value(ht, "holiday", "Hawaii");
    insert_key_value(ht, "role_model", "Albert Einstein");
    insert_key_value(ht, "subject", "Computer Science");
    insert_key_value(ht, "song", "Bohemian Rhapsody");
    insert_key_value(ht, "movie", "The Shawshank Redemption");
    insert_key_value(ht, "colour", "Blue");
    insert_key_value(ht, "book", "To Kill a Mockingbird");

    // Display the hash table
    display(ht);

    // Test search operations
    char *search_result = search_key(ht, "sport");
    if (search_result != NULL) {
        printf("\nSearch Result: 'sport' -> %s\n", search_result);
    } else {
        printf("\nKey 'sport' not found.\n");
    }

    // Test delete operations
    int delete_result = delete_key(ht, "subject");
    if (delete_result != -1) {
        printf("\nDeleted 'subject' at index %d\n", delete_result);
    } else {
        printf("\nKey 'subject' not found or deletion failed.\n");
    }

    // Display the updated hash table
    display(ht);

    // Print load factor and average probes
    printf("\nLoad Factor: %d%%\n", get_load_factor(ht));
    printf("Average Probes: %d\n", get_avg_probes(ht));

    // Cleanup and free memory
    for (int i = 0; i < ht->size; i++) {
        free(ht->array[i]);
    }
    free(ht->array);
    free(ht);

    return 0;
}
