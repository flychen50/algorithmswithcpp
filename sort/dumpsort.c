#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define less(A,B) ((A)<(B))
#define exch(A,B) {Item t = A;A=B;B=t;}
#define min(A,B) ((A)<(B)?(A):(B))

void fixUp(Item a[],int k){
  while(k>1 && less(a[k/2],a[k])){
    exch(a[k/2],a[k]);
    k = k/2;
  }
}

void fixDown(Item a[],int k,int N){
  int j;
  while(2*k<=N){
    j = 2*k;
    if(j<N && less(a[j],a[j+1])) j++;
    if(!less(a[k],a[j])) break;
    exch(a[k],a[j]);k = j;
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

  for(int i=0;i<list_range;i++){
    printf("%d ",a[i]);
  }
  printf("mergesort\n");
  return 0;
}
