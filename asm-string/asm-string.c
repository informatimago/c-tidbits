#include <stdio.h>

int main(void) {
    asm("   jmp do_print");
	asm("string: .string \"test-asm\"");
    asm("do_print:");
    asm("   lea     string, %rdi");
    asm("	movb	$0, %al");
    asm("   call    printf");
    printf(" test-c\n");
	return 0;
}
