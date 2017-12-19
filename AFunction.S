
 .global _RandomG
 .global _Add
 .global _Mul
 .global _Division
 .global _Sub



_RandomG:
        pushl   %ebp                     /* save old stack */
        movl    %esp, %ebp               /* new stack */
        subl	$16, %esp                 /* allocate 16 bytes */


        movl    $0, 12(%esp)            /* For loop starting from 0 */
        jmp     FK

LFSR:
        movl	8(%esp), %ebx       /* Seed value is stored in EBX */
        shrl	%ebx                /* Seed value is shifter right */
        movl	%ebx, %eax          /* moves shifted value to EAX */
        movl	8(%esp), %ebx       /* EBX gets again Seed value value */
        andl	$1, %ebx            /* Performs logical AND and stores in EBX  */
        negl	%ebx                /* Two’s complement inversion of EBX)  */
        andl	$0xA3000000, %ebx   /* Logical AND 0xA3000000 that is for taps 32, 30, 26, 25 */
        xorl	%eax, %ebx          /* Logical XOR EAX shifted value and EBX */
        movl	%ebx, 8(%esp)       /* Moves result value to +8 ESP and changes previous seed value */

        addl	$1, 12(%esp)        /* increases +12 starting value by one */

FK:
        cmpl	$19, 12(%esp)       /* compares +12 value to 19 for the FOR loop , it compares 19 because starts from 0 and iterates 20 times*/
        jbe 	LFSR                 /* Starts again for loop */
        movl	$0, %ebx            /* Sets EBX value to  */

        leave
        ret                         /* leave the function */



_Add:
        /*Setup stack*/
        pushl %ebp
        movl %esp, %ebp
        subl $16, %esp

        movl 8(%ebp), %eax /* Get value of a */
        movl 12(%ebp), %ebx /* Get value of b */
        addl %ebx, %eax /* adds %ebx to %eax and sum is returned by %eax */


        leave
        ret  /* leave the function */

_Mul:
        /*Setup stack*/
        pushl %ebp
        movl %esp, %ebp
        subl $16, %esp

        movl 8(%ebp), %eax /* Get value of a */
        movl 12(%ebp), %ebx /* Get value of b */
        imull %ebx, %eax /* perform multiplication */


        leave
        ret  /* leave the function */

_Division:
        /*Setup stack*/
        pushl %ebp
        movl %esp, %ebp
        subl $16, %esp

        xorl	%edx, %edx	/* Zero %edx */
        movl 8(%ebp), %eax /* Get value of a*/
        movl 12(%ebp), %ebx /* Get value of b*/

        divl	%ebx  /* divides %eax by %ebx and quotient is returned*/

        leave
        ret  /* leave the function */

_Sub:

        /*Setup stack*/
        pushl %ebp
        movl %esp, %ebp
        subl $16, %esp

        movl 8(%ebp), %eax /* Get value of a*/
        movl 12(%ebp), %ebx /* Get value of b*/
        subl %ebx, %eax /*  subtract b from a*/


        leave
        ret  /* leave the function */
