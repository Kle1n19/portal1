#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

void cp(char *src, char *dst){
    int src_fd;
    int dst_fd;
    int n;
    char buffer[256];

    if ((src_fd = open(src,O_RDONLY))<0){
        printf(2,"cp: can't open $s\n",src);
        exit();    
    }
    if((dst_fd = open(dst, O_CREATE|O_WRONLY))<0){
        printf(2,"cp: can't create %s\n", dst);
        close(src_fd);
        exit();
    }
    while((n = read(src_fd, buffer,sizeof(buffer)))>0){
        if(write(dst_fd,buffer,n)!=n){
            printf(2,"cp: write error to %s\n",dst);
            close(src_fd);
            close(dst_fd);
            exit();
        }    
    }
    if (n < 0){
        printf(2,"cp: read error from %s\n",src);
    }
    close(src_fd);
    close(dst_fd);
}


int main(int argc, char *argv[]){
    if(argc != 3){
        printf(2,"Usage: cp <from_file> <to_file>\n");
        exit();
    }
    cp(argv[1],argv[2]);
    exit();
}








