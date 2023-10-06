.text

.global fact
; residuo queda en rdx
; el anio se encuentra en %rsi
main:
    call primerIf
    call exit
primerIf:
    div $4, %rsi         ; se divide el anio por 4
    cmp $0, %rdx         ; se compara con rdx pq el residuo queda ahi
    jz segundoIf
    $0, %rax             ; sino cumple las condiciones es 0
    ret

segundoIf:
    div $100, %rsi       ; se div 100 con el anio
    cmp $0, %rdx         ; se compara 0 con el modulo
    $0, %rax             ; se pone 0 en rax, pq es divisible por 100, se da por hecho que es falso a no ser que cumpla la siguiente condicion
    div $400, %rsi       ; se div entre 400
    cmp $0, %rdx         ; if (anio % 400 == 0)
    jz biciesto
    ret
biciesto:
    $1, %rax         ; se pone 1 en rax
    ret		

exit:	# exit(0)
	mov	$60, %eax
	xor	%edi, %edi
	syscall;
; bool biciesto(int anio){
;     bool esBiciesto = false;
;         if (anio % 4 == 0)
;         {
;             if (anio % 100 == 0)
;             {
;                 esBiciesto = false;
;                 if (anio % 400 == 0)
;                 {
;                     esBiciesto = true; 
;                 }                
;             } 
            
;           esBiciesto = true;
;         } 
;     return esBiciesto;
; }