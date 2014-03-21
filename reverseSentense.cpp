#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
char* reverseSentense( char* src){
  // char* src = con_src;
  const int wordlen = 15;
  const int wordcount =100;
  //char** twoArray = new char*[wordlen];
  char twoArray[wordcount][wordlen]={'\0'};
  int wordpos,letterpos,sentenselen;
  cout<<src<<endl;
  for(wordpos=0,letterpos=0;*src!='\0';src++){
    if((*src==' ')|(*(src-1)==' ')){
     
      // printf("%s",twoArray[wordpos]);
      wordpos++;
      letterpos=0;
      // *src='*';
    }
    //  if(twoArray[wordpos]==NULL){
    //twoArray[wordpos]=new char[wordlen];
    //}
    twoArray[wordpos][letterpos++]=*src;
    // cout<<twoArray[wordpos]<<endl;
    sentenselen++;
}
  char* reverse=(char*)calloc(sentenselen+1,sizeof(char));
  char* currpos = reverse;
 
  for(;wordpos>=0;wordpos--){
   cout<<wordpos<<endl;
   letterpos = 0;
    while(twoArray[wordpos][letterpos]!='\0'){
      *currpos++ = twoArray[wordpos][letterpos];
      // cout<<twoArray[wordpos]<<endl;
      letterpos++;

 }
}
  return reverse;
}
int main(int argc,char** argv){
  char* sentense = "I's am a stundent";
  cout<<"reverse sentense:"<<reverseSentense(sentense)<<std::endl;


}


