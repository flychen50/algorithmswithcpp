#include <stdio.h>
#define N 10
main(){

  FILE *in;
  in = fopen("in.txt","r");
  int i,j,p,q,t,id[N];
  for(i=0;i<N;i++) id[i]=i;
  while(fscanf(in,"%d %d\n",&p,&q)==2){
   
    for(i=p;i!=id[i];i=id[i]);

    for(j=q;j!=id[j];j=id[j]);

    if(i==j) continue;

    id[i]=j;


    for(i=0;i<N;i++) printf(" %d ",id[i]);
    printf("\n");
    printf("disconnected pairs:%d %d\n",p,q);
}
  printf("hello world");


}
