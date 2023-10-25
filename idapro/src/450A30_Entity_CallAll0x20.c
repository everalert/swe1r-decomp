#include "address_constants.h"

void Entity_CallAll0x20() {
	void (*p_func)(void*);
	uint32_t p_ent_cur;
	uint32_t p_ent_man = *Entity_pManagerTable;
	uint32_t p_man_cur = Entity_pManagerTable;

	while (p_ent_man) { 
		p_func = *(p_ent_man + 0x20);
		if (p_func) {
			p_ent_cur = *(p_ent_man + 0x10);				// ent array base addr
			for (int i = 0; i < *(p_ent_man + 0x08); ++i) {	// ent array size
				if (!(*(p_ent_cur + 4) & 0x11000000))		// if 1<<24 and 1<<28 off
					p_func(p_ent_cur);
				p_ent_cur += *(p_ent_man + 0x0C);			// ent size
			}
			sub_4270C0();									// does nothing, nulled debug stuff?
		}
		p_man_cur += 4;
		p_ent_man = *p_man_cur;
	}
}

//	(EXE+50A30)  51                    - push ecx
//	(EXE+50A31)  A1 C0FE4B00           - mov eax,[(EXE+BFEC0)]
//	(EXE+50A36)  56                    - push esi
//	(EXE+50A37)  89 44 24 04           - mov [esp+04],eax
//	(EXE+50A3B)  8B 30                 - mov esi,[eax]
//	(EXE+50A3D)  85 F6                 - test esi,esi
//	(EXE+50A3F)  74 54                 - je (EXE+50A95)
//	(EXE+50A41)  57                    - push edi
//	(EXE+50A42)  55                    - push ebp
//	(EXE+50A43)  53                    - push ebx
//	(EXE+50A44)  8B 6E 20              - mov ebp,[esi+20]
//	(EXE+50A47)  85 ED                 - test ebp,ebp
//	(EXE+50A49)  74 39                 - je (EXE+50A84)
//	(EXE+50A4B)  8B 46 08              - mov eax,[esi+08]
//	(EXE+50A4E)  8B 7E 10              - mov edi,[esi+10]
//	(EXE+50A51)  33 DB                 - xor ebx,ebx
//	(EXE+50A53)  85 C0                 - test eax,eax
//	(EXE+50A55)  7E 24                 - jle (EXE+50A7B)
//	(EXE+50A57)  66 8B 47 06           - mov ax,[edi+06]
//	(EXE+50A5B)  25 00110000           - and eax,00001100
//	(EXE+50A60)  66 85 C0              - test ax,ax
//	(EXE+50A63)  75 06                 - jne (EXE+50A6B)
//	(EXE+50A65)  57                    - push edi
//	(EXE+50A66)  FF D5                 - call ebp
//	(EXE+50A68)  83 C4 04              - add esp,04
//	(EXE+50A6B)  8B 56 0C              - mov edx,[esi+0C]
//	(EXE+50A6E)  8B 46 08              - mov eax,[esi+08]
//	(EXE+50A71)  03 FA                 - add edi,edx
//	(EXE+50A73)  43                    - inc ebx
//	(EXE+50A74)  0FBF CB               - movsx ecx,bx
//	(EXE+50A77)  3B C8                 - cmp ecx,eax
//	(EXE+50A79)  7C DC                 - jl (EXE+50A57)
//	(EXE+50A7B)  E8 4066FDFF           - call (EXE+270C0)
//	(EXE+50A80)  8B 44 24 10           - mov eax,[esp+10]
//	(EXE+50A84)  8B 70 04              - mov esi,[eax+04]
//	(EXE+50A87)  83 C0 04              - add eax,04
//	(EXE+50A8A)  85 F6                 - test esi,esi
//	(EXE+50A8C)  89 44 24 10           - mov [esp+10],eax
//	(EXE+50A90)  75 B2                 - jne (EXE+50A44)
//	(EXE+50A92)  5B                    - pop ebx
//	(EXE+50A93)  5D                    - pop ebp
//	(EXE+50A94)  5F                    - pop edi
//	(EXE+50A95)  5E                    - pop esi
//	(EXE+50A96)  59                    - pop ecx
//	(EXE+50A97)  C3                    - ret 
//	(EXE+50A98)  90                    - nop 
//	(EXE+50A99)  90                    - nop 
//	(EXE+50A9A)  90                    - nop 
//	(EXE+50A9B)  90                    - nop 
//	(EXE+50A9C)  90                    - nop 
//	(EXE+50A9D)  90                    - nop 
//	(EXE+50A9E)  90                    - nop 
//	(EXE+50A9F)  90                    - nop 

