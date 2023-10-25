#include "address_constants.h"

void Entity_CallAll0x1C() {
	void (*p_func)(void*);
	uint32_t p_ent_cur;
	uint32_t p_ent_man = *Entity_pManagerTable;
	uint32_t p_man_cur = Entity_pManagerTable;

	int16_t UnkConst = *(0x50C87C);	// always 0x00000000?? also asm loads first 2 bytes only

	while (p_ent_man) { 
		p_func = *(p_ent_man + 0x1C);
		if (p_func) {
			if (!(UnkConst & *(p_ent_man + 0x04))) {			// ???
				p_ent_cur = *(p_ent_man + 0x10);				// ent array base addr
				for (int i = 0; i < *(p_ent_man + 0x08); ++i) {	// ent array size
					if (!(*(p_ent_cur + 4) & 0x11000000))		// if 1<<24 and 1<<28 off
						p_func(p_ent_cur);
					p_ent_cur += *(p_ent_man + 0x0C);			// ent size
					sub_4270C0();								// does nothing, nulled debug stuff?
				}
			}
		}
		p_man_cur += 4;
		p_ent_man = *p_man_cur;
	}
}

//	(EXE+509B0)  51                    - push ecx
//	(EXE+509B1)  A1 C0FE4B00           - mov eax,[(EXE+BFEC0)]
//	(EXE+509B6)  56                    - push esi
//	(EXE+509B7)  89 44 24 04           - mov [esp+04],eax
//	(EXE+509BB)  8B 30                 - mov esi,[eax]
//	(EXE+509BD)  85 F6                 - test esi,esi
//	(EXE+509BF)  74 5F                 - je (EXE+50A20)
//	(EXE+509C1)  57                    - push edi
//	(EXE+509C2)  55                    - push ebp
//	(EXE+509C3)  53                    - push ebx
//	(EXE+509C4)  8B 6E 1C              - mov ebp,[esi+1C]
//	(EXE+509C7)  85 ED                 - test ebp,ebp
//	(EXE+509C9)  74 44                 - je (EXE+50A0F)
//	(EXE+509CB)  0FBF 0D 7CC85000      - movsx ecx,word ptr [(EXE+10C87C)]
//	(EXE+509D2)  85 4E 04              - test [esi+04],ecx
//	(EXE+509D5)  75 38                 - jne (EXE+50A0F)
//	(EXE+509D7)  8B 4E 08              - mov ecx,[esi+08]
//	(EXE+509DA)  8B 7E 10              - mov edi,[esi+10]
//	(EXE+509DD)  33 DB                 - xor ebx,ebx
//	(EXE+509DF)  85 C9                 - test ecx,ecx
//	(EXE+509E1)  7E 2C                 - jle (EXE+50A0F)
//	(EXE+509E3)  66 8B 57 06           - mov dx,[edi+06]
//	(EXE+509E7)  81 E2 00110000        - and edx,00001100
//	(EXE+509ED)  66 85 D2              - test dx,dx
//	(EXE+509F0)  75 06                 - jne (EXE+509F8)
//	(EXE+509F2)  57                    - push edi
//	(EXE+509F3)  FF D5                 - call ebp
//	(EXE+509F5)  83 C4 04              - add esp,04 { 4 }
//	(EXE+509F8)  03 7E 0C              - add edi,[esi+0C]
//	(EXE+509FB)  E8 C066FDFF           - call (EXE+270C0)
//	(EXE+50A00)  8B 4E 08              - mov ecx,[esi+08]
//	(EXE+50A03)  43                    - inc ebx
//	(EXE+50A04)  0FBF C3               - movsx eax,bx
//	(EXE+50A07)  3B C1                 - cmp eax,ecx
//	(EXE+50A09)  7C D8                 - jl (EXE+509E3)
//	(EXE+50A0B)  8B 44 24 10           - mov eax,[esp+10]
//	(EXE+50A0F)  8B 70 04              - mov esi,[eax+04]
//	(EXE+50A12)  83 C0 04              - add eax,04 { 4 }
//	(EXE+50A15)  85 F6                 - test esi,esi
//	(EXE+50A17)  89 44 24 10           - mov [esp+10],eax
//	(EXE+50A1B)  75 A7                 - jne (EXE+509C4)
//	(EXE+50A1D)  5B                    - pop ebx
//	(EXE+50A1E)  5D                    - pop ebp
//	(EXE+50A1F)  5F                    - pop edi
//	(EXE+50A20)  5E                    - pop esi
//	(EXE+50A21)  59                    - pop ecx
//	(EXE+50A22)  C3                    - ret 
//	(EXE+50A23)  90                    - nop 
//	(EXE+50A24)  90                    - nop 
//	(EXE+50A25)  90                    - nop 
//	(EXE+50A26)  90                    - nop 
//	(EXE+50A27)  90                    - nop 
//	(EXE+50A28)  90                    - nop 
//	(EXE+50A29)  90                    - nop 
//	(EXE+50A2A)  90                    - nop 
//	(EXE+50A2B)  90                    - nop 
//	(EXE+50A2C)  90                    - nop 
//	(EXE+50A2D)  90                    - nop 
//	(EXE+50A2E)  90                    - nop 
//	(EXE+50A2F)  90                    - nop 
