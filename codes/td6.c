#include <stdio.h>

int main() {
	int m,n,k;
	int *p1,*p2,*p3;

	m=22; n=33;
	p1=&m; p2=&n;
	printf("%d %d %d %d\n",*p1,*p2,m,n);

	p3=p1; p1=p2; p2=p3;
	printf("%d %d %d %d\n",*p1,*p2,m,n);

	k=*p1; *p1=*p2; *p2=k;
	printf("%d %d %d %d\n",*p1,*p2,m,n);

	printf("\nPointer addresses\n");
	printf("%p %p %p %p\n",p1,p2,&m,&n);
	printf("%p %p %p %p\n",&p1,&p2,m,n);

	return 0;
}
