#include <stdio.h>
int hash (char s[]) {
  int r = 0;
  while (*s) {r += *s; s++;}
  return r;
}
int main(){
    char a[]="0tzzz";
    int b = hash(a);
    printf("%d \n",b);
    return 0;
}