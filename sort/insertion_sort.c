#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define less(A,B) ((A)<(B))
#define exch(A,B) {Item t = A;A=B;B=t;}
#define compexch(A,B) {if(less(B,A))  exch(A,B);}
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
void quicksort(Item a[],int l,int r){
  int i;
  if(r<=l) return;
  i = partion(a,l,r);
  quicksort(a,l,i-1);
  quicksort(a,i+1,r);
}

void insertion_sort(Item a[],int l,int r){
  int i,j;
  //白板面试时候，错误i<r,漏掉最后一个元素
  for(i=l+1;i<=r;i++){
    for(j=i;j>l;j--){
      compexch(a[j-1],a[j]);
    }
  }
}


int main(int argc,char** argv){
  if(argc<2){
    fprintf(stderr,"please input ragne_num");
    return -1;
  }
  int list_range = atoi(argv[1]);
  int *a = malloc(list_range*sizeof(int));
  for(int i=0;i<list_range;i++){
    a[i] = 10000*(1.0*rand()/RAND_MAX);
  }
  //quicksort(a,0,list_range-1);
  insertion_sort(a,0,list_range-1);
  for(int i=0;i<list_range;i++){
    printf("%4d ",a[i]);
  }
  printf("\n");
  return 0;
}
