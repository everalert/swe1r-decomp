#include "address_constants.h"

void Entity_CallAll0x14() {
	void (*p_func)(void*);
	uint32_t p_ent_cur;
	uint32_t p_ent_man = *Entity_pManagerTable;
	uint32_t p_man_cur = Entity_pManagerTable;

	int16_t UnkConst = *(0x50C87C);	// always 0x00000000?? also asm loads first 2 bytes only

	while (p_ent_man) { 
		p_func = *(p_ent_man + 0x14);
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


//	(EXE+508B0)  51                    - push ecx
//	(EXE+508B1)  A1 C0FE4B00           - mov eax,[(EXE+BFEC0)] { (004BFE98) }
//	(EXE+508B6)  56                    - push esi
//	(EXE+508B7)  89 44 24 04           - mov [esp+04],eax
//	(EXE+508BB)  8B 30                 - mov esi,[eax]
//	(EXE+508BD)  85 F6                 - test esi,esi
//	(EXE+508BF)  74 5F                 - je (EXE+50920)
//	(EXE+508C1)  57                    - push edi
//	(EXE+508C2)  55                    - push ebp
//	(EXE+508C3)  53                    - push ebx
//	(EXE+508C4)  8B 6E 14              - mov ebp,[esi+14]
//	(EXE+508C7)  85 ED                 - test ebp,ebp
//	(EXE+508C9)  74 44                 - je (EXE+5090F)
//	(EXE+508CB)  0FBF 0D 7CC85000      - movsx ecx,word ptr [(EXE+10C87C)] { (0) }
//	(EXE+508D2)  85 4E 04              - test [esi+04],ecx
//	(EXE+508D5)  75 38                 - jne (EXE+5090F)
//	(EXE+508D7)  8B 4E 08              - mov ecx,[esi+08]
//	(EXE+508DA)  8B 7E 10              - mov edi,[esi+10]
//	(EXE+508DD)  33 DB                 - xor ebx,ebx
//	(EXE+508DF)  85 C9                 - test ecx,ecx
//	(EXE+508E1)  7E 2C                 - jle (EXE+5090F)
//	(EXE+508E3)  66 8B 57 06           - mov dx,[edi+06]
//	(EXE+508E7)  81 E2 00110000        - and edx,00001100 { 4352 }
//	(EXE+508ED)  66 85 D2              - test dx,dx
//	(EXE+508F0)  75 06                 - jne (EXE+508F8)
//	(EXE+508F2)  57                    - push edi
//	(EXE+508F3)  FF D5                 - call ebp
//	(EXE+508F5)  83 C4 04              - add esp,04 { 4 }
//	(EXE+508F8)  03 7E 0C              - add edi,[esi+0C]
//	(EXE+508FB)  E8 C067FDFF           - call (EXE+270C0)
//	(EXE+50900)  8B 4E 08              - mov ecx,[esi+08]
//	(EXE+50903)  43                    - inc ebx
//	(EXE+50904)  0FBF C3               - movsx eax,bx
//	(EXE+50907)  3B C1                 - cmp eax,ecx
//	(EXE+50909)  7C D8                 - jl (EXE+508E3)
//	(EXE+5090B)  8B 44 24 10           - mov eax,[esp+10]
//	(EXE+5090F)  8B 70 04              - mov esi,[eax+04]
//	(EXE+50912)  83 C0 04              - add eax,04 { 4 }
//	(EXE+50915)  85 F6                 - test esi,esi
//	(EXE+50917)  89 44 24 10           - mov [esp+10],eax
//	(EXE+5091B)  75 A7                 - jne (EXE+508C4)
//	(EXE+5091D)  5B                    - pop ebx
//	(EXE+5091E)  5D                    - pop ebp
//	(EXE+5091F)  5F                    - pop edi
//	(EXE+50920)  5E                    - pop esi
//	(EXE+50921)  59                    - pop ecx
//	(EXE+50922)  C3                    - ret 
//	(EXE+50923)  90                    - nop 
//	(EXE+50924)  90                    - nop 
//	(EXE+50925)  90                    - nop 
//	(EXE+50926)  90                    - nop 
//	(EXE+50927)  90                    - nop 
//	(EXE+50928)  90                    - nop 
//	(EXE+50929)  90                    - nop 
//	(EXE+5092A)  90                    - nop 
//	(EXE+5092B)  90                    - nop 
//	(EXE+5092C)  90                    - nop 
//	(EXE+5092D)  90                    - nop 
//	(EXE+5092E)  90                    - nop 
//	(EXE+5092F)  90                    - nop 

