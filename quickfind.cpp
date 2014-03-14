#include <stdio.h>
#define N 10
main(){

  FILE *in;
  in = fopen("in.txt","r");
  int i,p,q,t,id[N];
  for(i=0;i<N;i++) id[i]=i;
  while(fscanf(in,"%d %d\n",&p,&q)==2){
   
   
    if(id[p]==id[q]) { printf("connected pairs:%d %d\n",p,q);continue;}
    for(t=id[p],i=0;i<N;i++)
      if(id[i]==t) id[i]=id[q];

    for(i=0;i<N;i++) printf(" %d ",id[i]);
    printf("\n");
    printf("disconnected pairs:%d %d\n",p,q);
}
  printf("hello world");


}
