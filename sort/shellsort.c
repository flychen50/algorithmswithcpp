#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef int Item;
#define less(A,B) ((A)<(B))
#define exch(A,B) {Item t = A;A=B;B=t;}
#define compexch(A,B) {if(less(B,A))  exch(A,B);}
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

void shell_sort(Item a[],int l,int r){
  int i,j,h;
  for(h=1;h<(r-l)/9;h=3*h+1);
  for(;h>0;h = h/3){
    for(i=l+h;i<=r;i++){
      int j=i;Item v= a[i];
      while(j>=l+h && less(v,a[j-h])){
        a[j] = a[j-h];j-=h;
      }
      a[j] = v;
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
  time_t start_time = time(NULL);
  insertion_sort_opt(a,0,list_range-1);
  shell_sort(a,0,list_range-1);
  for(int i=0;i<list_range;i++){
    printf("%4d ",a[i]);
  }
  time_t end_time = time(NULL);
  printf("\ntime %ld\n",end_time-start_time);
  return 0;
}
