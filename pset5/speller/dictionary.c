// Implements a dictionary's functionality
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
#define N 26

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    return tolower(word[0]) - 'a';
}

//INITIALIZE WORD COUNT
int wcount = 0;

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
    int hash_new;

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // TODO
        //hash the word
        hash_new = hash(word);

        //create node for new word and fill word in
        node *node_new = malloc(sizeof(node));
        if (node_new == NULL)
        {
            unload();
            return false;
        }
        strcpy(node_new->word, word);

        //set new node pointer
        node_new->next = hashtable[hash_new];

        //set the head to node_new
        hashtable[hash_new] = node_new;

        //increase word count by 1
        wcount++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (wcount > 0)
        return wcount;
    else
        return 0;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    //hash the word
    int hash_word = hash(word);

    //define head pointer and cursor pointer
    node *head = hashtable[hash_word];
    node *cursor = head;

    //traversing over linked list
    while (cursor != NULL)
    {
        int comp = strcasecmp(word, cursor->word);
        if (comp == 0)
            return true;
        else
            cursor = cursor->next;
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        // set pointer to head of list
        node *cursor = hashtable[i];

        // traverse list
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        free(cursor);
    }
    return true;
}
