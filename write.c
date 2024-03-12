#include <stdio.h>
#include <unistd.h>

int main(){
    int n;
    n=write(1,"hello",5);
    printf("the value of n is %d",n);
}