#include <stdio.h>
#include <time.h>
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
void insertion_sort_opt(Item a[],int l,int r){
  int i;
  for(i=r;i>l;i--) compexch(a[i],a[i-1]);
  for(i = l+2;i<=r;i++){
    int j = i; Item v = a[i];
    while(less(a[j],a[j-1])){
        exch(a[j],a[j-1]);
        j--;
      }
      exch(a[j],v);
  }
}




void select_sort(Item a[],int l,int r){
  int i,j;
  for(i=l;i<r;i++){
    int min = i;
    for(j=i+1;j<r;j++){
      if(less(a[j],a[min])){
        min = j;
      }
    }
    exch(a[i],a[min]);
  }
}

 void bubble(Item a[],int l,int r){
   int i,j;
   for(i=l;i<r;i++){
     for(j=r;j>i;j--){
       compexch(a[j-1],a[j])
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
  time_t start_time = time(NULL);
  // insertion_sort(a,0,list_range-1);
  //select_sort(a,0,list_range-1);
  //insertion_sort_opt(a,0,list_range-1);
  bubble(a,0,list_range-1);
  for(int i=0;i<list_range;i++){
    printf("%4d ",a[i]);
  }
  time_t end_time = time(NULL);
  printf("\ntime %ld\n",end_time-start_time);
  return 0;
}
