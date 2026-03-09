#include <stdio.h>
#include <math.h>
void th(int n, char src, char dest, char temp){
    if(n==1){
        printf("\nMoving disk 1 from peg %c to peg %c",src,dest);
        return;
    }
    th(n-1,src,temp,dest);
    printf("\nMove disk %d from peg %c to peg %c",n,src,dest);
    th(n-1,temp,dest,src);
}
int main(void){
    int n;
    printf("Enter number of disks: ");
    scanf("%d",&n);
    th(n,'a','c','b');
    printf("\nTotal moves required: %.0lf",pow(2,n)-1);
    return 0;
}
