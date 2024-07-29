#include <stddef.h>
#include <string.h>
#include <stdio.h>

#define HASHMAP_SIZE 64
#define HASHMAP_SIZE_LIST 1


struct aiv_set_item
{
    const char *key;
    size_t key_len;
};

struct aiv_set
{
    struct aiv_set_item hashmap[HASHMAP_SIZE][HASHMAP_SIZE_LIST];
};

size_t djb33x_hash(const char *key, const size_t keylen)
{
    size_t hash = 5381;

    for (size_t i = 0; i < keylen; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }

    return hash;
}

//to insert a new set
void aiv_set_insert(struct aiv_set *set, const char *key)
{
    const size_t key_len = strlen(key);

    const size_t hash = djb33x_hash(key, key_len);

    const size_t index = hash % HASHMAP_SIZE;

    for (size_t i = 0; i < HASHMAP_SIZE_LIST; i++)
    {
        if (set->hashmap[index][i].key_len > 0)
        {
            if (set->hashmap[index][i].key_len == key_len && !memcmp(set->hashmap[index][i].key, key, key_len))
            {
                printf("Duplicate item found\n");
                return;
            }
        }
        else
        {
            set->hashmap[index][i].key = key;
            set->hashmap[index][i].key_len = key_len;
            printf("hash of %s = %llu (index: %llu)\n", key, hash, index);
            printf("added %s at index %llu slot %llu\n", key, index, i);
            return;
        }
    }
    printf("COLLISION! for %s (index %llu)\n", key, index);
}

//to find a specific set
void aiv_set_find(struct aiv_set *set, const char *key)
{
    const size_t key_len = strlen(key);

    const size_t hash = djb33x_hash(key, key_len);

    const size_t index = hash % HASHMAP_SIZE;

    for (size_t i = 0; i < HASHMAP_SIZE_LIST; i++)
    {
        if (set->hashmap[index][i].key_len > 0)
        {
            if (set->hashmap[index][i].key_len == key_len && !memcmp(set->hashmap[index][i].key, key, key_len))
            {
                printf("hash of %s = %llu (index: %llu)\n", key, hash, index);
                printf("FOUND %s at index %llu slot %llu\n", key, index, i);
                return;
            }
        }
    }
    printf("Data not found");
}

//to remove a set 
void aiv_set_remove(struct aiv_set *set, const char *key)
{
    const size_t key_len = strlen(key);

    const size_t hash = djb33x_hash(key, key_len);

    const size_t index = hash % HASHMAP_SIZE;

    printf("hash of %s = %llu (index: %llu)\n", key, hash, index);
    for (size_t i = 0; i < HASHMAP_SIZE_LIST; i++)
    {
        if (set->hashmap[index][i].key_len > 0)
        {
            if (set->hashmap[index][i].key_len == key_len && !memcmp(set->hashmap[index][i].key, key, key_len))
            {
                set->hashmap[index][i].key_len = 0;
                set->hashmap[index][i].key = NULL;
                return;
            }
        }
    }
    printf("Data not found");
}

//to print my sets
void aiv_set_print(struct aiv_set *set)
{
    for (size_t index = 0; index < HASHMAP_SIZE; index++)
    {
        if (set->hashmap[index][0].key_len > 0)
        {
            printf("\n");
        }
        for (size_t i = 0; i < HASHMAP_SIZE_LIST; i++)
        {
            if (set->hashmap[index][i].key_len > 0)
            {
                printf("%s ", set->hashmap[index][i].key);
            }
        }
    }
    
}

int main(int argc, char **argv)
{
    struct aiv_set myset;
    char item[10]; 
    memset(&myset, 0, sizeof(struct aiv_set));
    
    aiv_set_insert(&myset, "Rome");
    aiv_set_insert(&myset, "Milan");
    aiv_set_insert(&myset, "Florence");
    aiv_set_insert(&myset, "Florence");
    aiv_set_insert(&myset, "Naples");
    aiv_set_insert(&myset, "Palermo");
    aiv_set_insert(&myset, "Turin");
    aiv_set_insert(&myset, "Bologna");
    aiv_set_insert(&myset, "Venice");
    aiv_set_print(&myset);
    printf("\nInsert what you want to remove: ");
    scanf_s("%s", item);
    aiv_set_remove(&myset, item);
    aiv_set_print(&myset);

    return 0;
}