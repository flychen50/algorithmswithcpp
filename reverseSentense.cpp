#include <stdio.h>
char* reverseSentense(const char* src){
  const int wordlen = 15;
  const int wordcount =100;
  char** twoArray = new char[wordcount][wordlen];
  int wordpos,letterpos,sentenselen;
  for(wordpos=0,letterpos=0;*src="\n";src++){
    if(*scr==""){
      wordpos++;
      letterpos=0;
    }
    twoArray[wordpos][letterpos]=*src;
    sentenselen++;
}
  char* reverse=(char*)malloc(setenselen);
  char* currpos = reverse;
  for(;wordpos>=0;wordpos--){
    letterpos = 0;
    while(twoArray[wordpos][letterpos]!="\0"){
      *currpos++=twoArray[wordpos][letterpos];
}}
  return reverse;
}
int main(int argc,char** argv){
  char* sentense = "I am a stundent";
  std::cout<<reverseSentense(sentense)<<std::endl;


}


