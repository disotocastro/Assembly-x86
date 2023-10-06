.text
.global main

main:
	mov	$10, %rcx          ; este va a ser nuestro n
	call	function
    call exit

function:
	push %rcx		
    movl (%rdx), %eax               ; array[0]
    cmp $0, %eax                    ;comparo la arr.0
    jz zero                         ;si arry.0 == 0 -> zero 

    movl (%rdx,%rcx,1),%eax         ;arr.[1]
    cmp $0, %eax                    ;comparo la arr.0
    jne dif_zero                    ; 
    jmp	exit		                # Exit

dif_zero:
    add %1, %rdx                    ; le sumo 1 al contador
    call function                   ; llamada recursiva

zero:
    add %0, eax             ;se le suma 0 

exit:
    pop     %rcx   
    ret
    mov	$60, %eax
	xor	%edi, %edi
	syscall


; int Function(int t[], unsigned n){
;     int resultado;
;     if (t[n] = 0)
;     {
;         resultado = 0;
;     } 

;     if (t[n]!= 0)
;     {
;         resultado = 1 + Function(t, n+1);
;     }
;     return resultado;
; }