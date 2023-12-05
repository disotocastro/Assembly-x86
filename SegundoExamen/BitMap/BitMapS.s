/**
  *  Bitmap assembly implementation
  *
  *  Author: CI0118 g2
  *  Date:	2022-ii
  *
  *
  *   Estudiante: Juan Diego Soto Castro	
  *       Carnet: C07722
  *
 **/
 
 .text
.global BitMapC			# BitMapC( BitMap * bitmap, int nitems, int BitsInWord )
						# DI bitmap, SI nitems, DX BitsInWord
						# numBits, numWords, map
						# int numBits, int numWords, unsigned long * map
.global BitMapD			# BitMapD()
.global BitMapMark			# BitMap Mark  method
.global BitMapClear			# BitMap Clear method
.global BitMapFind			# BtiMap Find  method


BitMapC:				# Assembly routine to create a bitmap

# Desctructor
BitMapD:				# Assembly routine to destroy the bitmap
	mov 8(%rdi), %rdi
	call free
	ret

# extern "C" void BitMapMark( BitMap *, int which, int );		// Mark method
BitMapMark:
    #if ( which < 0 || which >= this->numBits ) {		// check range
     #  return;
    #}
    #map[ which / BitsInLong ] |= 1 << ( which % BitsInLong );

    # if ( which < 0 || which >= this->numBits )
    cmp $0, %rsi
    jl retornador
    cmp 8(%rdi), %rsi
    jge retornador

    # division
    push %rdx
    mov %rdx, %rcx
    mov %rsi, %rax
    mov $0, %rdx
    div %rcx

    # configurar el bit a marcar
    mov $1, %r10
    mov %rdx, %rcx       # Mueve el valor del resto a rcx
    sal %cl, %r10        # Desplaza %r10 a la izquierda por el número de bits en %cl

    # operacion or
    push %rdx
    mov 8(%rdi,%rax,4), %r11
    or %r11, %r10
    mov %r10, 8(%rdi,%rax,4)

retornador:
    ret


BitMapClear:	
	# BitMapClear( BitMap *, int which, int )
    #if ( which < 0 || which >= this->numBits ) {		// check range
    #   return;
    #}
    #map[ which / BitsInLong ] |= 1 << ( which % BitsInLong );

	# which es menor que 0
	cmp $0, %rsi
	jl return

	# which es mayor o igual al número de bits en el mapa
	cmp 8(%rdi), %rsi
	jge return

	push %rdx

	# registros para la hacer la div
	mov %rdx, %rcx
	mov %rsi, %rax
	mov $0, %rdx
	div %rcx  # Divide %rax por %rcx, resultado en %rax, resto en %rdx

	# parte de limpiar en el mapa de bits
	mov $1, %r10
	mov %rdx, %rcx   
	sal %cl, %r10    # desplazamiento a la izquierda en %r10 por el número de bits en %cl (resto de la división)

	# guardar el valor en rdx para hacer operaciones
	push %rdx

	# Accede al bit correcto en el mapa de bits y lo almacena en %r11
	mov 8(%rdi, %rax, 4), %r11

	# Invierte el bit a limpiar y lo aplica al mapa de bits
	not %r10
	and %r11, %r10

	# Actualiza el bit en el mapa de bits
	mov %r10, 8(%rdi, %rax, 4)

return:
	ret





BitMapFind:
	xor	%rax, %rax
	ret


#
# Support routines
#
display:					# display the integer in CX
	push	%rbp
	mov	%rsp, %rbp
	push	%rcx
	lea	message(%rip), %rdi
	mov	%ecx, %esi
	xor	%eax, %eax	# is a variable argument function, so AL needs to be set
	call	printf
	pop	%rcx
	pop	%rbp
	ret

.data
message:	.asciz  "%d "



