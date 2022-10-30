#include <stdio.h>
#include <stdlib.h>

#define SIZE_BUFF  512 

int main(int argc, char ** argv){
  if(argc<3){
    printf("Pas assez d'arguments\n") ;
    exit(0) ;
  }

  FILE * fd = fopen(argv[1],"rb+") ;
  FILE * fw = fopen(argv[2],"ab+") ;
  if(fd==NULL|| fw==NULL){
    perror("Problème de fichier") ;
    exit(0);
  }

  int nb_read_ = 0 ;
  char * buffer = malloc(sizeof(char) * SIZE_BUFF + 1) ;
  while(nb_read_  = fread(buffer,sizeof(char), SIZE_BUFF , fd)){
 
    printf("%d\n",nb_read_) ;
    fwrite(buffer,sizeof(char),nb_read_,fw) ;
   
  }
  
  fclose(fd) ;
  fclose(fw) ;
  free(buffer) ;

  return 1 ;

}


