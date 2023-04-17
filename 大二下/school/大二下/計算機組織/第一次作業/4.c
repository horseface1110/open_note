#include<stdio.h>
int main()
{
int i=0;
int h[9]={0}, x[3]={0}, y[3]={0},tmp=0,max = 3;
FILE *input = fopen("../input/4.txt","r");
for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
fclose(input);
int *p_x = &x[0] ;
int *p_h = &h[0] ;
int *p_y = &y[0] ;
asm volatile(
    "li x18, 0\n\t"               ////// x18 -> i
    "li x19, 0\n\t"               ////// x19 -> j, x20 -> tmp 
    "out_loop:\n\t"
    "beq x18, %[max], out_end_loop\n\t"
    "lw x22, 0(%[r_x])\n\t"         ////// x22 ->&x[0]
    "addi x18, x18, 1\n\t"        ////// i = i + 1
        "inner_loop:\n\t"
        "beq x19, %[max], inner_end_loop\n\t" ///////if j = 3
        "lw x21, 0(%[h])\n\t"         ////// x21 ->&h
        "lw x23, 0(%[y])\n\t"         ////// x23 ->&y
        "lw x22, 0(%[x])\n\t"         ////// x22 -> &x
        "mul %[tmp], x21, x22\n\t"////// tmp = h * x
        //"add x23, x23, %[tmp]\n\t"////// y = y + tmp
        "addi %[h], %[h], 4\n\t"    ////// h往下一格
        "addi %[x], %[x], 4\n\t"    ////// x往下一格
        "addi x19, x19, 1\n\t"    ////// j = j + 1
        "j inner_loop\n\t"
        "inner_end_loop:\n\t"
        "li x19, 0\n\t"           ////// j = 0
        "add x23, x23, %[tmp]\n\t"
        "li %[tmp], 0\n\t"        ////// tmp = 0
        "sw x23, 0(%[y])\n\t"
        "addi %[y], %[y], 4\n\t"  ////// y的index往下一格
        "j out_loop\n\t"
    "out_end_loop:\n\t"
    :[h] "+r" (p_h), [x] "+r" (p_x), [y] "+r" (p_y), [tmp] "+r" (tmp),[r_x] "+r" (&x[0])
    :[max] "r" (max)
    ://"x18", "x19", "x20", "x21", "x22", 

    );
p_y = &y[0];
for(i = 0; i<3; i++)
printf("%d \n", *p_y++);
return(0) ;
}