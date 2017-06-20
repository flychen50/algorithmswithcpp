#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define key(A) (A)
#define less(A,B) (key(A)<key(B))
#define exch(A,B) {Item t = A;A=B;B=t;}
int partion(Item a[],int l,int r){
  int i = l-1,j = r;Item v = a[r];
  for(;;){
    while(less(a[++i],v));
    while(less(v,a[--j])) if(j==l) break;
    if(i>=j) break;
    exch(a[i],a[j]);
  }
  exch(a[i],a[r]);
  return i;
}
void quicksort(Item a[],int l,int r){
  int i;
  if(r<=l) return;
  i = partion(a,l,r);
  quicksort(a,l,i-1);
  quicksort(a,i+1,r);
}
int main(int argc,char** argv){
  int *a = malloc(100*sizeof(int));
  for(int i=0;i<100;i++){
    a[i] = 10000*(1.0*rand()/RAND_MAX);
  }

  quicksort(a,0,100);
  for(int i=0;i<100;i++){
    printf("%d ",a[i]);
  }
  printf("quicksort\n");
  return 0;
}
