#include "address_constants.h"

void CalculateHeat(void* pEngine) {
	int v7; // [esp+8h] [ebp-Ch]
	int v8; // [esp+Ch] [ebp-8h]
	int v9; // [esp+10h] [ebp-4h]

	uint32_t* flags1 = (pEngine + 0x60);
	uint32_t* flags2 = (pEngine + 0x64);
	float* heat_rate = (pEngine + 0x8C);
	float* cool_rate = (pEngine + 0x90);
	float* manual_tilt = (pEngine + 0x208);
	float* temp = (pEngine + 0x218);
	float* segment_flags = (pEngine + 0x2A0);

	int32_t fire_tilt_priority = 0;

	if (*flags2 & 0x40000) {		// 1<<18 on lava terrain
		*temp -= dt_d * 20.0;
		if (*manual_tilt < -0.5)
			fire_tilt_priority = -1;
		else if (*manual_tilt > 0.5)
			fire_tilt_priority = 1;
	} else {
		if (*flags1 & 0x800000)		// 1<<23 is boosting
			*temp -= dt_d * *heat_rate;
		else
			*temp += dt_d * *cool_rate;
	}

	if ( *temp >= 100.0f )
		*temp = 100.0f;

	int32_t rng_segment;
	if ( *temp <= 0.0f ) {
		*temp = 0.0f;

		if (fire_tilt_priority == 0)
			rng_segment = RNG_4816B0() * 4.6566129e-10 * 6.0;
		else
			rng_segment = (fire_tilt_priority > 0 ? 3 : 0) + (RNG_4816B0() * 4.6566129e-10 * 3.0);

		if (!(*(segment_flags+rng_segment*4) & 0x08))	// 1<<03 on fire
		{
			v7 = 0, v8 = 0, v9 = 0;						// v7-v9 = vec3?
			sub_46E950(pEngine, 2 - rng_segment / 3, &v7, 0.1);
		}
		*(segment_flags + rng_segment * 4) |= 0x08;			// set 1<<03 (on fire) on
		*flags1 &= 0xFF7FFFFF;							// set 1<<23 (is boosting) off
		return;
	}
}

//	(EXE+788C0)  83 EC 0C              - sub esp,0C { 12 }
//	(EXE+788C3)  33 C9                 - xor ecx,ecx
//	(EXE+788C5)  56                    - push esi
//	(EXE+788C6)  8B 74 24 14           - mov esi,[esp+14]
//	(EXE+788CA)  57                    - push edi
//	(EXE+788CB)  F7 46 64 00000400     - test [esi+64],00040000 { (6) }
//	(EXE+788D2)  74 4A                 - je (EXE+7891E)
//	(EXE+788D4)  DD 05 402AE200        - fld qword ptr [(EXE+A22A40)] { (0.04) }
//	(EXE+788DA)  D9 86 08020000        - fld dword ptr [esi+00000208]
//	(EXE+788E0)  D8 1D 48DD4A00        - fcomp dword ptr [(EXE+ADD48)] { (-0.50) }
//	(EXE+788E6)  D8 0D 78DC4A00        - fmul dword ptr [(EXE+ADC78)] { (20.00) }
//	(EXE+788EC)  DFE0                  - fnstsw ax
//	(EXE+788EE)  D8 AE 18020000        - fsubr dword ptr [esi+00000218]
//	(EXE+788F4)  F6 C4 01              - test ah,01 { 1 }
//	(EXE+788F7)  D9 9E 18020000        - fstp dword ptr [esi+00000218]
//	(EXE+788FD)  74 05                 - je (EXE+78904)
//	(EXE+788FF)  83 C9 FF              - or ecx,-01 { 255 }
//	(EXE+78902)  EB 4A                 - jmp (EXE+7894E)
//	(EXE+78904)  D9 86 08020000        - fld dword ptr [esi+00000208]
//	(EXE+7890A)  D8 1D 60DC4A00        - fcomp dword ptr [(EXE+ADC60)] { (0.50) }
//	(EXE+78910)  DFE0                  - fnstsw ax
//	(EXE+78912)  F6 C4 41              - test ah,41 { 65 }
//	(EXE+78915)  75 37                 - jne (EXE+7894E)
//	(EXE+78917)  B9 01000000           - mov ecx,00000001 { 1 }
//	(EXE+7891C)  EB 30                 - jmp (EXE+7894E)
//	(EXE+7891E)  8B 46 60              - mov eax,[esi+60]
//	(EXE+78921)  DD 05 402AE200        - fld qword ptr [(EXE+A22A40)] { (0.04) }
//	(EXE+78927)  A9 00008000           - test eax,(EXE+400000) { (0) }
//	(EXE+7892C)  74 0E                 - je (EXE+7893C)
//	(EXE+7892E)  D8 8E 8C000000        - fmul dword ptr [esi+0000008C]
//	(EXE+78934)  D8 AE 18020000        - fsubr dword ptr [esi+00000218]
//	(EXE+7893A)  EB 0C                 - jmp (EXE+78948)
//	(EXE+7893C)  D8 8E 90000000        - fmul dword ptr [esi+00000090]
//	(EXE+78942)  D8 86 18020000        - fadd dword ptr [esi+00000218]
//	(EXE+78948)  D9 9E 18020000        - fstp dword ptr [esi+00000218]
//	(EXE+7894E)  D9 86 18020000        - fld dword ptr [esi+00000218]
//	(EXE+78954)  D8 1D 5CDD4A00        - fcomp dword ptr [(EXE+ADD5C)] { (100.00) }
//	(EXE+7895A)  DFE0                  - fnstsw ax
//	(EXE+7895C)  F6 C4 01              - test ah,01 { 1 }
//	(EXE+7895F)  75 0A                 - jne (EXE+7896B)
//	(EXE+78961)  C7 86 18020000 0000C842 - mov [esi+00000218],42C80000 { 100.00 }
//	(EXE+7896B)  D9 86 18020000        - fld dword ptr [esi+00000218]
//	(EXE+78971)  D8 1D 48DC4A00        - fcomp dword ptr [(EXE+ADC48)] { (0) }
//	(EXE+78977)  DFE0                  - fnstsw ax
//	(EXE+78979)  F6 C4 41              - test ah,41 { 65 }
//	(EXE+7897C)  0F84 D9000000         - je (EXE+78A5B)
//	(EXE+78982)  85 C9                 - test ecx,ecx
//	(EXE+78984)  C7 86 18020000 00000000 - mov [esi+00000218],00000000 { 0 }
//	(EXE+7898E)  7D 1B                 - jnl (EXE+789AB)
//	(EXE+78990)  E8 1B8D0000           - call (EXE+816B0)
//	(EXE+78995)  89 44 24 18           - mov [esp+18],eax
//	(EXE+78999)  DB 44 24 18           - fild dword ptr [esp+18]
//	(EXE+7899D)  D8 0D 18DD4A00        - fmul dword ptr [(EXE+ADD18)] { (30000000) }
//	(EXE+789A3)  D8 0D E8DC4A00        - fmul dword ptr [(EXE+ADCE8)] { (3.00) }
//	(EXE+789A9)  EB 42                 - jmp (EXE+789ED)
//	(EXE+789AB)  7E 27                 - jle (EXE+789D4)
//	(EXE+789AD)  E8 FE8C0000           - call (EXE+816B0)
//	(EXE+789B2)  89 44 24 18           - mov [esp+18],eax
//	(EXE+789B6)  DB 44 24 18           - fild dword ptr [esp+18]
//	(EXE+789BA)  D8 0D 18DD4A00        - fmul dword ptr [(EXE+ADD18)] { (30000000) }
//	(EXE+789C0)  D8 0D 60DD4A00        - fmul dword ptr [(EXE+ADD60)] { (-3.00) }
//	(EXE+789C6)  E8 55630200           - call (EXE+9ED20)
//	(EXE+789CB)  BF 03000000           - mov edi,00000003 { 3 }
//	(EXE+789D0)  2B F8                 - sub edi,eax
//	(EXE+789D2)  EB 20                 - jmp (EXE+789F4)
//	(EXE+789D4)  E8 D78C0000           - call (EXE+816B0)
//	(EXE+789D9)  89 44 24 18           - mov [esp+18],eax
//	(EXE+789DD)  DB 44 24 18           - fild dword ptr [esp+18]
//	(EXE+789E1)  D8 0D 18DD4A00        - fmul dword ptr [(EXE+ADD18)] { (30000000) }
//	(EXE+789E7)  D8 0D 64DD4A00        - fmul dword ptr [(EXE+ADD64)] { (6.00) }
//	(EXE+789ED)  E8 2E630200           - call (EXE+9ED20)
//	(EXE+789F2)  8B F8                 - mov edi,eax
//	(EXE+789F4)  F6 84 BE A0020000 08  - test byte ptr [esi+edi*4+000002A0],08 { 8 }
//	(EXE+789FC)  75 41                 - jne (EXE+78A3F)
//	(EXE+789FE)  8D 44 24 08           - lea eax,[esp+08]
//	(EXE+78A02)  68 CDCCCC3D           - push 3DCCCCCD { 0.10 }
//	(EXE+78A07)  50                    - push eax
//	(EXE+78A08)  B8 56555555           - mov eax,55555556 { "VUUU" }
//	(EXE+78A0D)  F7 EF                 - imul edi
//	(EXE+78A0F)  8B CA                 - mov ecx,edx
//	(EXE+78A11)  B8 02000000           - mov eax,00000002 { 2 }
//	(EXE+78A16)  C1 E9 1F              - shr ecx,1F { 31 }
//	(EXE+78A19)  03 D1                 - add edx,ecx
//	(EXE+78A1B)  C7 44 24 10 00000000  - mov [esp+10],00000000 { 0 }
//	(EXE+78A23)  2B C2                 - sub eax,edx
//	(EXE+78A25)  C7 44 24 14 00000000  - mov [esp+14],00000000 { 0 }
//	(EXE+78A2D)  50                    - push eax
//	(EXE+78A2E)  56                    - push esi
//	(EXE+78A2F)  C7 44 24 20 00000000  - mov [esp+20],00000000 { 0 }
//	(EXE+78A37)  E8 145FFFFF           - call (EXE+6E950)
//	(EXE+78A3C)  83 C4 10              - add esp,10 { 16 }
//	(EXE+78A3F)  8B 8C BE A0020000     - mov ecx,[esi+edi*4+000002A0]
//	(EXE+78A46)  83 C9 08              - or ecx,08 { 8 }
//	(EXE+78A49)  89 8C BE A0020000     - mov [esi+edi*4+000002A0],ecx
//	(EXE+78A50)  8B 46 60              - mov eax,[esi+60]
//	(EXE+78A53)  25 FFFF7FFF           - and eax,FF7FFFFF { -8388609 }
//	(EXE+78A58)  89 46 60              - mov [esi+60],eax
//	(EXE+78A5B)  5F                    - pop edi
//	(EXE+78A5C)  5E                    - pop esi
//	(EXE+78A5D)  83 C4 0C              - add esp,0C { 12 }
//	(EXE+78A60)  C3                    - ret 
//	(EXE+78A61)  90                    - nop 
//	(EXE+78A62)  90                    - nop 
//	(EXE+78A63)  90                    - nop 
//	(EXE+78A64)  90                    - nop 
//	(EXE+78A65)  90                    - nop 
//	(EXE+78A66)  90                    - nop 
//	(EXE+78A67)  90                    - nop 
//	(EXE+78A68)  90                    - nop 
//	(EXE+78A69)  90                    - nop 
//	(EXE+78A6A)  90                    - nop 
//	(EXE+78A6B)  90                    - nop 
//	(EXE+78A6C)  90                    - nop 
//	(EXE+78A6D)  90                    - nop 
//	(EXE+78A6E)  90                    - nop 
//	(EXE+78A6F)  90                    - nop 
