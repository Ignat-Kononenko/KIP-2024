.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib ../Debug/StaticLibrary.lib
ExitProcess PROTO :DWORD

Atom PROTO : DWORD
Leng PROTO : DWORD
OutputInt PROTO : DWORD
OutputStr PROTO : DWORD
EXTRN Date: proc
EXTRN Time: proc

.stack 4096

.CONST
	overflownum BYTE "Выход за пределы значения", 0
	negativeValue BYTE "Отрицательное число", 0
	zerodel BYTE "Деление на ноль", 0
	L1 DWORD 2
	L2 DWORD 3
	L3 DWORD 5
	L4 DWORD -3
	L5 DWORD 1
	L6 BYTE "e", 0
	L7 BYTE "fe", 0
	L8 DWORD 6

.data
	count DWORD 0
	sum_c DWORD 0
	main_oper DWORD 0
	main_pp DWORD 0
	main_h DWORD 0
	main_g DWORD 0
	main_hh DWORD ?
	main_j DWORD ?
	main_k DWORD 0
	main_s DWORD 0

.code

sum PROC sum_a : DWORD, sum_b : DWORD
	push sum_a
	push sum_b
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop sum_c
	push sum_c
	jmp local0
local0:
	pop eax
	ret
OVERFLOW:
	push offset overflownum
	call OutputStr
	push 0
	call ExitProcess
NEGNUM:
	push offset negativeValue
	call OutputStr
DELZERO:
	push offset zerodel
	call OutputStr
	push 0
	call ExitProcess
sum ENDP

main PROC
	push L1
	push L2
	pop eax
	pop ebx
	add eax, ebx
	push eax
	push L2
	pop eax
	pop ebx
	mul ebx
	push eax
	pop main_oper
	push main_oper
	call OutputInt
	push main_oper
	push L3
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop main_pp
	push main_pp
	call OutputInt
	push L4
	push L1
	pop ebx
	pop eax
cmp ebx, 0
je DELZERO
	cdq
	idiv ebx
	push eax
	pop main_h
	push main_h
	call OutputInt
	push main_pp
	push L5
	pop ecx
CYCLE0:
	pop eax
	shl eax, 1
	cmp eax, 255
jg OVERFLOW
	cmp eax, 0
jl NEGNUM
	push eax
	loop CYCLE0
	pop main_g
	push main_g
	call OutputInt
	push offset L6
	pop main_hh
	push main_hh
	call OutputStr
	push offset L7
	pop main_j
	push main_j
	call OutputStr
	push L2
	push L1
	pop eax
	pop ebx
	add eax, ebx
	push eax
	push L1
	push L3
	pop eax
	pop ebx
	mul ebx
	push eax
	push L8
	push L1
	pop ebx
	pop eax
cmp ebx, 0
je DELZERO
	cdq
	idiv ebx
	push eax
	pop eax
	pop ebx
	add eax, ebx
	push eax
	pop ebx
	pop eax
	sub eax, ebx
	push eax
	pop main_k
	push main_k
	call OutputInt
	push L2
	push L8
	pop edx
	pop edx
	push L8
	push L2
	call sum
	push eax
	pop main_s
	push main_s
	call OutputInt
OutAsm:
	push 0
	call ExitProcess
OVERFLOW:
	push offset overflownum
	call OutputStr
	push 0
	call ExitProcess
NEGNUM:
	push offset negativeValue
	call OutputStr
	push 0
	call ExitProcess
DELZERO:
	push offset zerodel
	call OutputStr
	push 0
	call ExitProcess
main ENDP
end main