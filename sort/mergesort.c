#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define less(A,B) ((A)<(B))
#define exch(A,B) {Item t = A;A=B;B=t;}
#define min(A,B) ((A)<(B)?(A):(B))
void merge(Item a[],int l,int m ,int r){
  Item aux[r-l];
  int i,j,k;
  for(i = m+1;i>l;i--) aux[i-1] = a[i-1];
  for(j=m;j<r;j++) aux[r+m-j] = a[j+1];
  for(k=l;k<=r;k++){
    if(less(aux[j],aux[i])){
      a[k] = aux[j--];
    }else{
      a[k]= aux[i++];
    }
  }
}
void mymergesort(Item a[],int l,int r){
  int m = (l+r)/2;
  if(r<=l) return;
  mymergesort(a,l,m);
  mymergesort(a,m+1,r);
  merge(a,l,m,r);
}

void mergeBU(Item a[],int l ,int r){
  int i,m;
  for(m=1;m<r-l;m = m+m){
    for(i= l;i<=r-m;i +=m+m){
      merge(a,i,i+m-1,min(i+m+m-1,r));
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

  //  mymergesort(a,0,list_range-1);
  mergeBU(a,0,list_range-1);
  for(int i=0;i<100;i++){
    printf("%d ",a[i]);
  }
  printf("mergesort\n");
  return 0;
}
