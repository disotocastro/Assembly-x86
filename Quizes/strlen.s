#  C++ interface with assembly
#
#  First parameter  -> DI
#  Second parameter -> SI
#  Third parameter  -> DX
#  Fourth parameter -> CX
#  Fifth parameter  -> r8
#  Sixth parameter  -> r9
#  Next parameters on stack
#
#  Return value in AX
#

.text
.global strLen

loop:
    mov %rdi, %rsi
    mov %rdx, %rcx
    mov, %r8, %r9
    mov %rdi, %r9

strLen:
    db str (%rdi)
    mov %rax, (equ $-strLen)  
    mov len, %rax	# Se devuelve el valor en el registro AX
    xor %rax, %rax
    jl loop 
    ret			# Retorna a C++