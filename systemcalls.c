
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(){
        FILE *rd;
        char b[200];
        int f;
        f=open("test.txt",O_RDWR);
        int f1;
        f1=lseek(f,10,SEEK_CUR);
        read(f,b,20);
        rd=popen("ls","w");
        write(1,b,20);
        pclose(rd);
}