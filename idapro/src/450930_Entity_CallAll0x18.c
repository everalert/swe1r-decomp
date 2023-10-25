#include "address_constants.h"

void Entity_CallAll0x18() {
	void (*p_func)(void*);
	uint32_t p_ent_cur;
	uint32_t p_ent_man = *Entity_pManagerTable;
	uint32_t p_man_cur = Entity_pManagerTable;

	int16_t UnkConst = *(0x50C87C);	// always 0x00000000?? also asm loads first 2 bytes only

	while (p_ent_man) { 
		p_func = *(p_ent_man + 0x18);
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


//	(EXE+50930)  51                    - push ecx
//	(EXE+50931)  A1 C0FE4B00           - mov eax,[(EXE+BFEC0)] { (004BFE98) }
//	(EXE+50936)  56                    - push esi
//	(EXE+50937)  89 44 24 04           - mov [esp+04],eax
//	(EXE+5093B)  8B 30                 - mov esi,[eax]
//	(EXE+5093D)  85 F6                 - test esi,esi
//	(EXE+5093F)  74 5F                 - je (EXE+509A0)
//	(EXE+50941)  57                    - push edi
//	(EXE+50942)  55                    - push ebp
//	(EXE+50943)  53                    - push ebx
//	(EXE+50944)  8B 6E 18              - mov ebp,[esi+18]
//	(EXE+50947)  85 ED                 - test ebp,ebp
//	(EXE+50949)  74 44                 - je (EXE+5098F)
//	(EXE+5094B)  0FBF 0D 7CC85000      - movsx ecx,word ptr [(EXE+10C87C)] { (0) }
//	(EXE+50952)  85 4E 04              - test [esi+04],ecx
//	(EXE+50955)  75 38                 - jne (EXE+5098F)
//	(EXE+50957)  8B 4E 08              - mov ecx,[esi+08]
//	(EXE+5095A)  8B 7E 10              - mov edi,[esi+10]
//	(EXE+5095D)  33 DB                 - xor ebx,ebx
//	(EXE+5095F)  85 C9                 - test ecx,ecx
//	(EXE+50961)  7E 2C                 - jle (EXE+5098F)
//	(EXE+50963)  66 8B 57 06           - mov dx,[edi+06]
//	(EXE+50967)  81 E2 00110000        - and edx,00001100 { 4352 }
//	(EXE+5096D)  66 85 D2              - test dx,dx
//	(EXE+50970)  75 06                 - jne (EXE+50978)
//	(EXE+50972)  57                    - push edi
//	(EXE+50973)  FF D5                 - call ebp
//	(EXE+50975)  83 C4 04              - add esp,04 { 4 }
//	(EXE+50978)  03 7E 0C              - add edi,[esi+0C]
//	(EXE+5097B)  E8 4067FDFF           - call (EXE+270C0)
//	(EXE+50980)  8B 4E 08              - mov ecx,[esi+08]
//	(EXE+50983)  43                    - inc ebx
//	(EXE+50984)  0FBF C3               - movsx eax,bx
//	(EXE+50987)  3B C1                 - cmp eax,ecx
//	(EXE+50989)  7C D8                 - jl (EXE+50963)
//	(EXE+5098B)  8B 44 24 10           - mov eax,[esp+10]
//	(EXE+5098F)  8B 70 04              - mov esi,[eax+04]
//	(EXE+50992)  83 C0 04              - add eax,04 { 4 }
//	(EXE+50995)  85 F6                 - test esi,esi
//	(EXE+50997)  89 44 24 10           - mov [esp+10],eax
//	(EXE+5099B)  75 A7                 - jne (EXE+50944)
//	(EXE+5099D)  5B                    - pop ebx
//	(EXE+5099E)  5D                    - pop ebp
//	(EXE+5099F)  5F                    - pop edi
//	(EXE+509A0)  5E                    - pop esi
//	(EXE+509A1)  59                    - pop ecx
//	(EXE+509A2)  C3                    - ret 
//	(EXE+509A3)  90                    - nop 
//	(EXE+509A4)  90                    - nop 
//	(EXE+509A5)  90                    - nop 
//	(EXE+509A6)  90                    - nop 
//	(EXE+509A7)  90                    - nop 
//	(EXE+509A8)  90                    - nop 
//	(EXE+509A9)  90                    - nop 
//	(EXE+509AA)  90                    - nop 
//	(EXE+509AB)  90                    - nop 
//	(EXE+509AC)  90                    - nop 
//	(EXE+509AD)  90                    - nop 
//	(EXE+509AE)  90                    - nop 
//	(EXE+509AF)  90                    - nop 

