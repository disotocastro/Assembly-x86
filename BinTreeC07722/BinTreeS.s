/**
  *  Binary tree assembly implementation
  *
  *  Author: CI0118 g3
  *  Date:	2023-ii
  *
  *  BinNode:
  *     BinNode * left;
  *     double key;
  *     char stuff[ x ];
  *     BinNode * right;
  *
 **/
 
 .text
.global spreOrder			# spreOrder( BinNode * )
.global sinOrder			# sinOrder( BinNode * )
.global spostOrder			# spostOrder( BinNode * )
.global sInsert			# sInsert( BinNode **, BinNode *, int )
.global sdestroyTree		# sdestroyTree( BinNode * )

spreOrder:				# Assembly routine to traverse binary tree in preorderr
	xor %rax, %rax
	ret


sinOrder:					# Assembly routine to traverse binary tree in order
	xor %rax, %rax
	ret








# CARNET: C07722, 2%3 = 2, toca hacer post orden
# 
# 
# BinNode* left; -> 8 bytes (ptr) ................ 0
# double key; -> 8 bytes.......................... +8
# char stuff[STUFF_SIZE]; -> 22 bytes............ +30
# BinNode* right; -> 8 bytes (ptr).............. +38 + 2 padding
# 
# 
# 8 + 8 + 22 (carnet) = 38, ese mov debera de ser mov 38(%rdi), %rdi, pero tira error
# con 40 funciona de manera correcta ???
# padding de 2. 


spostOrder:
    # parámetro: %rdi = BinNode* node

    # verificar si el nodo es NULL
    test %rdi, %rdi            # comprobar si node es NULL
    jz final                   # saltar al final si node es NULL

    # guardar %rdi en la pila
    push %rdi

    # recorrer el arbol izquierdo
    mov (%rdi), %rdi           # cargar la dirección de node->left en %rdi
    call spostOrder            # llamar a spostOrder recursivamente, en nodo izq

    pop %rdi
    push %rdi

    # recorrer arbol derecho
    mov 40(%rdi), %rdi         # cargar la dirección de node->right en %rdi, 
    call spostOrder            # llamar a spostOrder recursivamente, en nodo der

    # restaurar %rdi
    pop %rdi

    # nodo actual
    movsd 8(%rdi), %xmm0       # cargar el valor de node->key en %xmm0
    call display               

final:
    ret


sInsert:
    push %rbp                  
    mov %rsp, %rbp             # stack pointer

    mov (%rdi), %rcx           # nodo actual (puntero a BinNode) en %rcx
    test %rcx, %rcx            # ver si el nodo actual es NULL
    je crearNodo               # si es NULL, crear un nuevo nodo

    # Se compara la clave del nuevo nodo con la clave del nodo actual
    movsd 8(%rcx), %xmm1       # clave del nodo actual en %xmm1
    ucomisd %xmm1, %xmm0       # clave del nuevo nodo (%xmm0) con la del nodo actual (%xmm1)
    ja ir_der                  # Si la clave del nuevo nodo es mayor, ir a la derecha
    jb ir_izq                  # Si la clave del nuevo nodo es menor, ir a la izquierda

    # En caso de claves iguales, decidir ir a la izquierda o a la derecha
    jmp ir_der

ir_izq:
    lea (%rcx), %rdi           # dirección del hijo izquierdo en %rdi
    call sInsert               # llamada recursiva para insertar en el subárbol izquierdo
    jmp endInsert

ir_der:
    lea 40(%rcx), %rdi         # dirección del hijo derecho en %rdi (considerando padding)
    call sInsert               # llamada recursiva para insertar en el subárbol derecho
    jmp endInsert

crearNodo:
    mov $40, %rdi              # tamaño del nodo (con padding) +2
    call malloc                # llamar a malloc para crear un nuevo nodo
    test %rax, %rax            # verificar si malloc fue exitoso

    # Inicializar el nuevo nodo
    mov %rax, %rcx             # mover la dirección del nuevo nodo a %rcx
    movq $0, (%rcx)            # establecer hijo izquierdo a NULL
    movsd %xmm0, 8(%rcx)       # establecer la clave del nuevo nodo

    # Establecer hijo derecho a NULL (considerando padding)
    movq $0, 40(%rcx)          
    mov %rcx, (%rdi)           

    jmp endInsert

endInsert:
    mov %rbp, %rsp            
    pop %rbp                  
    ret                        



#######################################

sdestroyTree:               
    cmp     $0, %rdi        # comparr el nodo actual en rdi con 0 (NULL)
    je      final_nulo      # si el nodo es NULL (es decir, %rdi es 0), salta a la etiqueta final_nulo

    push    %rdi            # guardar el valor actual de %rdi (dirección del nodo actual) en la pila

    mov     16(%rdi), %rdi  # dirección del hijo izquierdo del nodo actual en %rdi
    call    sdestroyTree    # llamar recursivamente a sdestroyTree

    pop     %rdi            # recupera la dirección del nodo actual de la pila
    push    %rdi            # guardar nuevamente la dirección del nodo actual en la pila

    mov     40(%rdi), %rdi  # Carga la dirección del hijo derecho del nodo actual en %rdi
    call    sdestroyTree    # Llama recursivamente a sdestroyTree para eliminar el subárbol derecho

    pop     %rdi            # recuperar la dirección del nodo actual de la pila nuevamente
    call    free            # Libera la memoria del nodo actual

final_nulo:
    ret                     # Retorna de la función


# Support routines
#
display:				# display the number on XMM0
	push	%rbp
	mov	%rsp, %rbp
	push	%rcx
	add	$8, %rdi		# Adjust offset
	movsd	(%rdi), %xmm0		# put number in register xmm0
	mulsd	%xmm0, %xmm0
	lea	message(%rip), %rdi
	mov	$1, %eax		# is a variable argument function, so AL needs to be set to 1
	call	printf
	pop	%rcx
	pop	%rbp
	ret

.data
message:	.asciz  "%15.10f "















