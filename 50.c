#include <stdio.h>
//1
void um(){
    int max,a;
    scanf("%d",&a);
    max=a;
    while (a!=0){
        scanf("%d",&a);
        if (a>max) max=a;
    }
    printf("%d\n",max);
}
//2
void dois(){
    int somatorio,n,a=1;
    while (a!=0){
        scanf("%d",&a);
        somatorio+=a;
        n++;
    }
    n--;
    printf("%d\n",somatorio/n);
}
//3
void tres(){
    int max,a,max2;
    scanf("%d",&a);
    max=a;
    scanf("%d",&a);
    if (a>max){
            max2=max;
            max=a;
        }
    else max2=a;
    while (a!=0){
        scanf("%d",&a);
        if (a>max){
            max2=max;
            max=a;
        }
    }
    printf("%d\n",max2);
}
//4
int bitsUm (unsigned int n){
    int c=0;
    while (n!=0){
        if (n%2==1) c++;
        n/=2;
    }
    return c;
}
//5
int trailingZ (unsigned int n){
    if (n==0) return 32;
    else{
    int c=0;
    while (n%2!=1 && n!=0){
        c++;
        n/=2;
    }
    return c;
}}
//6
int qDig (unsigned int n){
    int c=0;
    while (n>9){
        n/=10;
        c++;
    }
    c++;
    return c; 
}
//7
char *mystrcat (char s1[], char s2[]){
    int i,j;
    for (i = 0;s1[i]!='\0';i++);
    for (j = 0;s2[j]!='\0';j++){
        s1[i+j] = s2[j];
    }
    s1[i+j]='\0';
    return s1;
}
//8
char *mystrcpy (char *dest, char source[]){
    int i=0;
    do{
        dest[i]=source[i];
        i++;
    }while (source[i]!='\0');
    return dest;
}
//9
int mystrcmp (char s1[], char s2[]){
    int i =0;
    while(s1[i]!='\0' && s2[i]!='\0'){
        if (s1[i]<s2[i]){
            return -1;
        }
        else if(s1[i]>s2[i]){
            return 1;
        }
        i++;
    }
    if (s1[i]=='\0' && s2[i]!='\0') return -1;
    else if (s2[i]=='\0' && s1[i]!='\0') return 1;
         else return 0;
}
//10
char *mystrstr (char s1[], char s2[]){
    int i,b=0; 
    for (i=0;s1[i]!='\0'&& s2[b]!='\0';i++){
        if (s1[i]==s2[b]) b++;
        else if (b!=0) b=0;
    }
    if (s2[b]=='\0') return s1+i-b;
    else return NULL;
}
//11
void strrev (char s[]){
    int i,b=0;
    for (i=0;s[i]!='\0';i++){
        b++;
    }
    b--;
    char c;
    for (i=0;i<b;i++){
        c=s[i];
        s[i]=s[b];
        s[b]=c;
        b--;
    }
}
//12
void strnoV (char s[]){
    int i,ondeguardar=0,naoEVogal,iv;
    char vogais[]="AEIOUaeiou";
    for (i=0;s[i]!='\0';i++){
        naoEVogal=1;
        for (iv=0;iv<10;iv++){ //verifica se é vogal
            if (vogais[iv]==s[i]) {naoEVogal=0;break;}
        }
        if (naoEVogal) {s[ondeguardar]=s[i];ondeguardar++;}
    }
    s[ondeguardar]='\0';
}
//13
void truncW (char t[], int n){
    int i,c=0,og=0;
    for (i=0;t[i]!='\0';i++){
        if (t[i]!=' ' && c<n) {
            c++;
            t[og]=t[i];
            og++;
        }
        else if (t[i]==' ') {
                c=0;
                t[og]=t[i];
                og++;
             }
    }
    t[og]='\0';
}
//14
char charMaisfreq (char s[]){
    int b=0,i,max=0,og=0,e;
    for (i=0;s[i]!='\0';i++){
        b++;
    } // b é o comprimento da string
    int r[b];
    char v[b],maxp=0;
    for (i=0;s[i]!='\0';i++){
        e=1;
        for (b=0;v[b]!='\0';b++){
            if (s[i]==v[b]) {r[b]++;e=0;break;} // esta repetido
        }
        if (e) {v[og]=s[i];r[og]=1;og++;} //nao esta repetido
    }
    v[og]='\0';
    for (i=0;v[i]!='\0';i++){
        if (r[i]>max) {max=r[i];maxp=v[i];}
    }
    return maxp;
}
//15
int iguaisConsecutivos (char s[]){
    char c;
    int i,co=0,max=0;
    c=s[0];
    for (i=0;s[i]!='\0';i++){
        if (s[i]==c) co++;
        else {co=1;c=s[i];}
        if (co>max) max=co;
    }
    return max;
}




int main(){
    char a[]="OlaO";
    char b = charMaisfreq(a);
    printf("%c\n",b);
    return 0;
}


