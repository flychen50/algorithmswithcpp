#include <stdio.h>
#include <stdlib.h>
typedef int Item;
typedef struct node* link;
struct node {Item item;link next;};
#define less(A,B) ((A)<(B))
#define exch(A,B) {Item t = A;A=B;B=t;}
#define min(A,B) ((A)<(B)?(A):(B))

link merge(link a,link b){
  struct node head;link c = &head;
  while(a!=NULL  && b!=NULL){
    if(less(a->item,b->item)){
      c->next = a;c = a;a = a->next;
    }else{
      c->next = b;c = b;b = b->next;
    }
  }
  c->next = (a==NULL)?b:a;
  return head.next;
}

link linkmergesort(link c){
  link a,b;
  if(c==NULL || c->next == NULL) return c;
  a = c;b = c->next;
  while(b != NULL && b->next!=NULL) {
    c = c->next; b  = b->next->next;
  }
  b = c->next;c->next = NULL;
  return merge(linkmergesort(a),linkmergesort(b));
}


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


  /* b = &headb;b->next = NULL; */
  /* for(t = a->next;t!=NULL;t = u){ */
  /*   u = t->next; */
  /*   for(x = b;x->next !=NULL;x = x->next){ */
  /*     if(x->next->item > t->item) break; */
  /*   } */
  /*   t->next = x->next;x->next = t; */
  /* } */
  link c = a->next;
link d =linkmergesort(c);
  for(t = d;t!=NULL;t = t->next){
    printf("%d ",t->item);
  }
  /* for(t = b->next;t!=NULL;t = t->next){ */
  /*   printf("%d ",t->item); */
  /* } */
  printf("\nmergesort\n");
  return 0;
}
