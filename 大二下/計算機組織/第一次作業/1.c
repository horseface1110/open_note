#include <stdio.h>

int main(){

	int a = 0 , b = 0;
	scanf("%d,%d",&a,&b);
	asm(
		"div %[A] %[A] %[B]\n\t"
		:[A] "+r"(a)
		:[B] "r"(b)
	);
	printf("%d\n",a);
	return 0;

}
