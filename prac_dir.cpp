#include<stdio.h>
//#include <direct.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(void){
  int status;
  //status = mkdir("/home/cnd/mod1", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  status = mkdir("./data", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  if (status == 0){
    printf("Success to make a folder.\n");
  }else{
    printf("Failed to make a folder.\n");
  }
  /*if(_mkdir("folder")==0){
    printf("Success to make a folder.\n");
  }else{
    printf("Failed to make a folder.\n");
  }*/
}
