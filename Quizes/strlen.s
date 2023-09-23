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

strLen:
    xor %rax, %rax     
.loop:
    cmpb $0, (%rdi)    
    je .done           
    inc %rdi            
    inc %rax            
    jmp .loop          

.done:
    ret               