#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
char* reverseSentense( char* src){

  const int wordlen = 15;
  const int wordcount =100;

  char twoArray[wordcount][wordlen]={'\0'};
  int wordpos,letterpos,sentenselen;
  cout<<src<<endl;
  for(wordpos=0,letterpos=0;*src!='\0';src++){
    if((*src==' ')|(*(src-1)==' ')){
     
      wordpos++;
      letterpos=0;

    }
    twoArray[wordpos][letterpos++]=*src;
    sentenselen++;
}
  char* reverse=(char*)calloc(sentenselen+1,sizeof(char));
  char* currpos = reverse;
  for(;wordpos>=0;wordpos--){
   cout<<wordpos<<endl;
   letterpos = 0;
    while(twoArray[wordpos][letterpos]!='\0'){
      *currpos++ = twoArray[wordpos][letterpos];
      letterpos++;
 }
}
  return reverse;
}
int main(int argc,char** argv){
  char* sentense = "I's am a stundent";
  cout<<"reverse sentense:"<<reverseSentense(sentense)<<std::endl;
}


