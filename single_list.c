#include "single_list.h"

struct SlistHandleStruct slistHandle;
// static slist_t *people;
// struct People *people;

static void slist_init(slist_t *sl){

    sl->next = NULL;
}

static void slist_insert(slist_t *sl,slist_t *node){

    node->next = sl->next;
    sl->next = node;
}

static void slist_append(slist_t *sl,slist_t *node){
    struct slist_node *last_node;
    last_node = sl;
    while(last_node->next){
        last_node = last_node->next;
    }
    node->next = NULL;
    last_node->next = node;
}

static slist_t *slist_remove(slist_t *sl,slist_t *node){

    struct slist_node *n;
    n = sl;
    while(n->next && n->next!=node){//n is not tail and n's next is node
        n = n->next;
    }
    if(n->next != (slist_t*)0){
        n->next = n->next->next;
    }
    
    return sl;
}


static unsigned int slist_len(slist_t *sl){

    unsigned int len = 0;
    while(sl->next){

        sl = sl->next;
        len++;
    }

    return len;
}

static int slist_is_empty(slist_t *sl){
    return (sl->next == NULL) ? 1:0;
}

static slist_t* slist_first(slist_t *sl){

    return sl->next;
}

static slist_t* slist_tail(slist_t *sl){
    while(sl->next){
        sl = sl->next;
    }
    return sl;
}

void slist_function_init(){
    slistHandle.init = slist_init;
    slistHandle.insert = slist_insert;
    slistHandle.append = slist_append;
    slistHandle.remove = slist_remove;
    slistHandle.slist_len = slist_len;
    slistHandle.empty = slist_is_empty;
    slistHandle.first = slist_first;
    slistHandle.tail = slist_tail;
}

// void test(){
//     struct slist_node *head;
//     struct People *p;
//     slist_function_init();

//     struct People *qinhan = (struct People*)malloc(sizeof(struct People));
//     qinhan->name = "qinhan";
//     qinhan->num = 1;
//     slistHandle.init(&qinhan->slist);

//     struct People *baobao = (struct People*)malloc(sizeof(struct People));
//     baobao->name = "baobao";
//     baobao->num = 2;
//     slistHandle.init(&baobao->slist);

//     struct People *lili = (struct People*)malloc(sizeof(struct People));
//     lili->name = "lili";
//     lili->num = 3;
//     slistHandle.init(&lili->slist);

//     people = (struct People*)malloc(sizeof(struct People));
//     slistHandle.init(&people->slist);


//     slistHandle.append(&people->slist,&qinhan->slist);
//     slistHandle.append(&people->slist,&baobao->slist);
//     slistHandle.append(&people->slist,&lili->slist);
//     printf("%d\n",slistHandle.slist_len(&people->slist));

//     head = &people->slist;
//     while(head->next){

//         p = list_entry(head->next,struct People,slist);
//         if(p!=NULL)
//             printf("people's name:%s\n",p->name);
//         head = head->next;
//     }

//     slistHandle.remove(&people->slist,&qinhan->slist);
//     printf("%d\n",slistHandle.slist_len(&people->slist));
// }

void main(){
    test();
}


