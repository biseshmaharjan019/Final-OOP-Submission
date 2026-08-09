#include <stdio.h>

int main(){
int length , breadth;
printf("Enter length and breadth");
scanf("%d%d",&length,&breadth);
int peri=2*(length*breadth);
printf("The peri is %d\n",peri);
return 0;
}
