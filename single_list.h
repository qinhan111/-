#include "stdio.h"
#include "stdlib.h"

#define NULL                         (0)
// #define inline                   static __inline

#define list_entry(ptr, type, member) \
((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

/**
 * @brief single list node
 */
struct slist_node
{
    struct slist_node *next;
};
typedef struct slist_node slist_t;

typedef void (*Init)(slist_t *sl);
typedef void (*Insert)(slist_t *sl,slist_t *node);
typedef void (*Append)(slist_t *sl,slist_t *node);
typedef slist_t* (*Remove)(slist_t *sl,slist_t *node);
typedef unsigned int (*Slist_len)(slist_t *sl);
typedef int (*Empty)(slist_t *sl);
typedef void (*First)(slist_t *sl);
typedef void (*Tail)(slist_t *sl);



struct SlistHandleStruct{
   Init init;
   Insert insert;
   Append append;
   Remove remove;
   Slist_len slist_len;
   Empty empty;
   First first;
   Tail tail;
};

/*
* test struct
*/

// struct People{
//     char* name;
//     unsigned int num;
//     slist_t slist;
// };

