#include <stdio.h>
#define N 10
main(){

  FILE *in;
  in = fopen("in.txt","r");
  int i,j,p,q,t,id[N],sz[N];
  for(i=0;i<N;i++) {id[i]=i;sz[i]=1;}
  while(fscanf(in,"%d %d\n",&p,&q)==2){
   
    for(i=p;i!=id[i];i=id[i]);

    for(j=q;j!=id[j];j=id[j]);

    if(i==j) continue;
    if(sz[i]<sz[j]){
      id[i]=j;sz[j]+=sz[i];    
}else{
      id[j]=i;sz[i]+=sz[j];
    }
    


    for(i=0;i<N;i++) printf(" %d ",id[i]);
    printf("\n");
    printf("disconnected pairs:%d %d\n",p,q);
}
  printf("hello world");


}
