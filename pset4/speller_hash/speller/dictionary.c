// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>
// Represents number of buckets in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int h;
struct node *nptr;
struct node *ptr;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
       h =  hash(word);
       ptr = hashtable[h];
       nptr = malloc(sizeof(node));
       strcpy(nptr -> word, word);
       nptr -> next = NULL;
       if (ptr == NULL)
       {
           hashtable[h] = nptr;
       }
       else
       {
           while (ptr -> next != NULL)
           {
               ptr = ptr -> next;
           }
            ptr -> next = nptr;
       }
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int c = 0;
    for (int i = 0; i < N; i++)
    {
        ptr = hashtable[i];
        while (ptr!= NULL)
        {
            ptr = ptr -> next;
            c++;
        }
    }
    return c;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    h = hash(word);
    ptr = hashtable[h];
    while (ptr != NULL)
    {
        if (!strcasecmp(ptr -> word, word))
        return true;
        ptr = ptr -> next;
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        ptr = hashtable [i];
        while (ptr != NULL)
        {
            nptr = ptr;
            ptr = ptr -> next;
            free (nptr);
        }
        hashtable [i] = NULL;
    }
    for (int i = 0; i < N; i++)
    {
        if (hashtable[i])
        return false;
    }
    return true;
}
