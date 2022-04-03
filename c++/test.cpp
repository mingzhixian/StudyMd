#include <stdio.h>
#include <math.h>

int a(int tmp){
    return -tmp;
}
char a(char tmp){
    return tmp+1;
}
int main(int argc, char const *argv[])
{
    printf("%d,%f\n", abs(-12), fabs(-1212.32324));
    printf("%d,,,%c\n",a(6),a('8'));
    return 0;
}