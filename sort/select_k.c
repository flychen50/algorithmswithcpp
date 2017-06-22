#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define less(A,B) ((A)<(B))
#define exch(A,B) {Item t = A;A=B;B=t;}
int partion(Item a[],int l,int r){
  int i=l-1,j = r;Item v = a[r];
  for(;;){
    while(less(a[++i],v));
    while(less(v,a[--j])) if(j==l) break;
    if(i>=j) break;
    exch(a[i],a[j]);
  }
  exch(a[i],a[r]);
  return i;
}
void select(Item a[],int l,int r,int k){
  int i;
  if(l>=r) return;
  i = partion(a,l,r);
  if(i>k) select(a,l,i-1,k);
  if(i<k) select(a,i+1,r,k);
  if(i==k) printf("select %d\n",a[i]);
}

void select_no_recursive(Item a[],int l,int r,int k){
  int i;
  do{
    i = partion(a,l,r);
    if(i>k) r = i-1;
    if(i<k) l = i+1;
    if(i==k){
      printf("select %d\n",a[i]);
      break;
    }
  }while(i!=k);
}
int main(int argc,char** argv){
  int list_range = atoi(argv[1]);
  int k = atoi(argv[2]);
  int *a = malloc(list_range*sizeof(int));
  for(int i=0;i<list_range;i++){
    a[i] = 10000*(1.0*rand()/RAND_MAX);
    printf("%d ",a[i]);
  }
  select_no_recursive(a,0,list_range-1,k);
  /* for(int i=0;i<100;i++){ */
  /*   printf("%d ",a[i]); */
  /* } */
  printf("select\n");
  return 0;
}
