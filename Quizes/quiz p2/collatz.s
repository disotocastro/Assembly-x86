#
#  Collatz assembly routine
#
#    int Collatz( int numero )
#
#  Parameter is in DI register (int numero)
#  Return value in AX register (int)
#
#   Compilar: g++ -g collatz.cc collatz.s -o collatz.out
#   Correr: ./collatz.out 59

.text
.global collatz
collatz:
    push    %rbp           # Guardar el valor de RBP en la pila
    mov     %rsp, %rbp     
    mov     %rdi, %rax     # Mover el valor de entrada a RAX

    test    %rax, %rax     # Comprobar si es igual a cero
    jz      done           

loop:
    test    %rax, %rax     # Comprobar si es impar con el bit menos significativo
    jnz     odd            

even:
    shr     %rax           # Si par, div por 2
    jmp     loop

odd:
    mull    (%rax,%rax, 2)  # Si impar, multi por 2
    add     $1, %rax       
    jmp     loop

done:
    pop     %rbp           # Restaurar el valor de %rbp desde la pila
    ret