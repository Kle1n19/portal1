#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

void mv(char *src, char *dst){
    unlink(dst);
    if (link(src, dst)< 0){
        printf(2,"mv:can't move %s to %s\n",src,dst);
        exit();
    }
    if (unlink(src)<0){
        printf(2,"mv:can'tremove %s\n",src);
        unlink(dst);
        exit();
    }
}


int main(int argc, char *argv[]){
    if (argc!=3){
        printf(2,"Usage: mv <from_file> <to_file>\n");
        exit();
    }
    mv(argv[1],argv[2]);
    exit();
}
