#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef struct node* link;
struct node {Item item;link next;};
#define less(A,B) ((A)<(B))
#define exch(A,B) {Item t = A;A=B;B=t;}
#define min(A,B) ((A)<(B)?(A):(B))



int main(int argc,char** argv){

  if(argc<2){
    fprintf(stderr,"please input ragne_num");
    return -1;
  }
  int list_range = atoi(argv[1]);
  struct node heada ,headb;
  int i;
  link t,u,x,a = &heada,b;
  for(i=0,t=a;i<list_range;i++){
    t->next = malloc(sizeof *t);
    t = t->next;t->next = NULL;
    t->item = rand()%1000;
  }

  for(t = a->next;t!=NULL;t = t->next){
    printf("%d ",t->item);
  }
  printf("\n origin data\n");


  b = &headb;b->next = NULL;
  for(t = a->next;t!=NULL;t = u){
    u = t->next;
    for(x = b;x->next !=NULL;x = x->next){
      if(x->next->item > t->item) break;
    }
    t->next = x->next;x->next = t;
  }

  for(t = b->next;t!=NULL;t = t->next){
    printf("%d ",t->item);
  }
  printf("\nmergesort\n");
  return 0;
}
