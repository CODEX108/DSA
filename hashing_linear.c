/*
Name: Manjiri Chavande
UID : 2023031003
Topic: Hashing with linear probing
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 23

typedef struct KeyValue {
    char *key;
    char *value;
} KeyValue;

typedef struct {
    KeyValue **array;
    int size;
    float load_factor;
    int num_keys;
    int num_occupied_indices;
    int num_ops;
} HashTable;


KeyValue *createKeyValue(char *key, char *value) {
    KeyValue* newKeyValue = (KeyValue*)malloc(sizeof(KeyValue));
    if (newKeyValue != NULL) {
        newKeyValue->key = key;
        newKeyValue->value = value;
    }
    return newKeyValue;
}


HashTable* createHashTable() {
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
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

// Function to convert a string key to an integer index
int key_to_int(char* key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {

        sum += key[i]; // Summing up the ASCII values of characters in the key
    }
    return sum % TABLE_SIZE; // Modulo operation to ensure the index is within the table size
}


int insert_key_value(HashTable *ht, char* key, char* value) {
    int index = key_to_int(key);
    while (ht->array[index] != NULL) {
        if (strcmp(ht->array[index]->key, key) == 0) {
            return -1; // Key already exists
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing to find the next available slot
    }
    ht->array[index] = createKeyValue(key, value);
    ht->num_keys++;
    ht->num_occupied_indices++;
    ht->num_ops++;
    ht->load_factor = (float)ht->num_keys / ht->size;
    return index;
}


char *search_key(HashTable *ht, char* key) {
    int index = key_to_int(key);
    int count = 0;
    while (ht->array[index] != NULL && count < TABLE_SIZE) {
        if (strcmp(ht->array[index]->key, key) == 0) {
            return ht->array[index]->value; // Return the value if the key is found
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing to find the next index
        count++;
    }
    return NULL;
}


int delete_key(HashTable *ht, char* key) {
    int index = key_to_int(key);
    int count = 0;
    while (ht->array[index] != NULL && count < TABLE_SIZE) {
        if (strcmp(ht->array[index]->key, key) == 0) {
            free(ht->array[index]);
            ht->array[index] = NULL;
            ht->num_keys--;
            ht->num_ops++;
            ht->load_factor = (float)ht->num_keys / ht->size;
            return index; // Return the index of the deleted key
        }
        index = (index + 1) % TABLE_SIZE; // Linear probing to find the next index
        count++;
    }
    return -1;
}

// Function to get the load factor of the hash table
float get_load_factor(HashTable *ht) {
    return ht->load_factor;
}


// Function to get the average probes of the hash table
float get_avg_probes(HashTable *ht) {
   return (ht->num_keys == 0) ? 0 : (float)ht->num_ops / ht->num_keys;
}

// Function to display the contents of the hash table
void display(HashTable *ht) {
    printf("Hash Table Content:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (ht->array[i] != NULL) {
            printf("Index: %d | Key: %s, Value: %s\n", i, ht->array[i]->key, ht->array[i]->value);
        }
        else{
            printf("Index: %d | NULL\n",i);
        }
    }
}

int main() {
    // Create a new hash table
    HashTable *ht = createHashTable();

    // Insert the specified key-value pairs
    insert_key_value(ht, "first_name", "Mrinalini");
    insert_key_value(ht, "last_name", "Thakur");
    insert_key_value(ht, "uid", "2023301003");
    insert_key_value(ht, "sport", "Badminton");
    insert_key_value(ht, "food", "Burger");
    insert_key_value(ht, "holiday", "Goa");
    insert_key_value(ht, "role_model", "Sudha Murthy");
    insert_key_value(ht, "subject", "Computer Science");
    insert_key_value(ht, "song", "Jai Ho");
    insert_key_value(ht, "movie", "Inception");
    insert_key_value(ht, "color", "White");
    insert_key_value(ht, "book", "Atomic habits");

    //Display the hash table contents
    display(ht);
    printf("Load Factor:  %f\n", get_load_factor(ht));

    //Test search and delete operations
    printf("Search 'Book': %s\n", search_key(ht, "book"));
    printf("Search 'Last name': %s\n", search_key(ht, "last name"));


    int deleted_index = delete_key(ht, "first_name");
    if (deleted_index != -1) {
        printf("Key 'first name' deleted from index: %d\n", deleted_index);
    } else {
        printf("Key 'first name' not found.\n");
    }
    // Display the updated hash table contents
    display(ht);
    printf("Load Factor:  %f\n", get_load_factor(ht));
    printf("Average probs: %f\n",get_avg_probes(ht));

    return 0;
}
