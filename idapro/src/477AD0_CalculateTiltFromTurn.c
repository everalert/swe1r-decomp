#include "math.h"

// TODO: add constants from assembly to google sheet
// TODO: confirm consistency with marked up pseudocode in IDA

void CalculateTiltFromTurn(int pEngine, Vec4* pXformZ, float ZMotion, Vec3* pDRot) {
	// TODO: convert to Engine object references after object def figured out
	uint32_t* p_flags1 = (pEngine + 0x60);
	uint32_t* p_flags2 = (pEngine + 0x64);
	float* p_hover = (pEngine + 0x94);
	float* p_basehover = (pEngine + 0xA4);
	float* p_target_tilt = (pEngine + 0x200);
	float* p_current_tilt = (pEngine + 0x204);
	float* p_manual_tilt = (pEngine + 0x208);
	Vec4* p_xform_y = (pEngine + 0x30);
	Vec4* p_xform_x = (pEngine + 0x20);
	float* p_cur_turnrate = (pEngine + 0x1EC);
	float* p_target_turnrate = (pEngine + 0x1F0);
	float* p_max_turnrate = (pEngine + 0x74);
	void* p_0x194 = (pEngine + 0x194); // "gravity related"
	float scaled_hover = *hover * (float)0x3FC00000; // 1.5
	float new_hover = (*p_basehover + *p_basehover + *hover) * (float)0x3EAAAAAB; // 0.333..

	if (!(*p_flags2 & 0x400))           // if 1<<10 (roll disabled) off
		pDRot->z = DRot->z - *p_target_tilt;
	// TODO: figure out wtf this function is
	sub_4764E0(pEngine, pXformZ, p_xform_y, p_xform_x, p_0x194, ZMotion, scaled_hover, new_hover, pDRot);

	if (!(*p_flags2 & 0x400)) {
		pDRot->z = *p_target_tilt + DRot->z;

		if (!(*p_flags2 & 0x400)) {
			float old_target_tilt = *p_target_tilt;
			float max_tilt = *p_flags1 & 0x80000000 ? 300.0f : 70.0f; // 1<<31, 0x43960000, 0x428C0000
			SetAngleFromTurnRate(p_target_tilt, *p_current_turnrate, *p_target_turnrate, *p_max_turnrate, max_tilt); // 44AF50
			pDRot->z = DRot->z - (*p_target_tilt - old_target_tilt) * 0.2f;

			if (!(*p_flags2 & 0x400) && *p_manual_tilt != 0.0f) {
				float manual_tilt = *p_manual_tilt < 0.0f ? -*p_manual_tilt : *p_manual_tilt;
				pDRot->z = (*p_manual_tilt * 80.0f - DRot->z) * manual_tilt + DRot->z;
			}
		}
	}
	*p_current_tilt = pDRot->z;
}

//	(EXE+77AD0)  51                    - push ecx
//	(EXE+77AD1)  53                    - push ebx
//	(EXE+77AD2)  55                    - push ebp
//	(EXE+77AD3)  56                    - push esi
//	(EXE+77AD4)  8B 74 24 14           - mov esi,[esp+14]
//	(EXE+77AD8)  BD 00040000           - mov ebp,00000400 { 1024 }
//	(EXE+77ADD)  57                    - push edi
//	(EXE+77ADE)  D9 86 A4000000        - fld dword ptr [esi+000000A4]
//	(EXE+77AE4)  DCC0                  - fadd st(0),st(0)
//	(EXE+77AE6)  D9 86 94000000        - fld dword ptr [esi+00000094]
//	(EXE+77AEC)  D9C9                  - fxch st(1)
//	(EXE+77AEE)  D8 86 94000000        - fadd dword ptr [esi+00000094]
//	(EXE+77AF4)  D9C9                  - fxch st(1)
//	(EXE+77AF6)  D8 0D 20DD4A00        - fmul dword ptr [(EXE+ADD20)] { (3FC00000) }
//	(EXE+77AFC)  D9C9                  - fxch st(1)
//	(EXE+77AFE)  D8 0D 5CDC4A00        - fmul dword ptr [(EXE+ADC5C)] { (3EAAAAAB) }
//	(EXE+77B04)  D9C9                  - fxch st(1)
//	(EXE+77B06)  D9 5C 24 10           - fstp dword ptr [esp+10]
//	(EXE+77B0A)  8B 46 64              - mov eax,[esi+64]
//	(EXE+77B0D)  8B 7C 24 24           - mov edi,[esp+24]
//	(EXE+77B11)  D9 5C 24 18           - fstp dword ptr [esp+18]
//	(EXE+77B15)  85 C5                 - test ebp,eax
//	(EXE+77B17)  75 0C                 - jne (EXE+77B25)
//	(EXE+77B19)  D9 47 08              - fld dword ptr [edi+08]
//	(EXE+77B1C)  D8 A6 00020000        - fsub dword ptr [esi+00000200]
//	(EXE+77B22)  D9 5F 08              - fstp dword ptr [edi+08]
//	(EXE+77B25)  8B 44 24 18           - mov eax,[esp+18]
//	(EXE+77B29)  8B 4C 24 10           - mov ecx,[esp+10]
//	(EXE+77B2D)  8B 54 24 20           - mov edx,[esp+20]
//	(EXE+77B31)  57                    - push edi
//	(EXE+77B32)  50                    - push eax
//	(EXE+77B33)  51                    - push ecx
//	(EXE+77B34)  8D 86 94010000        - lea eax,[esi+00000194]
//	(EXE+77B3A)  52                    - push edx
//	(EXE+77B3B)  8D 4E 20              - lea ecx,[esi+20]
//	(EXE+77B3E)  50                    - push eax
//	(EXE+77B3F)  8B 44 24 30           - mov eax,[esp+30]
//	(EXE+77B43)  8D 56 30              - lea edx,[esi+30]
//	(EXE+77B46)  51                    - push ecx
//	(EXE+77B47)  52                    - push edx
//	(EXE+77B48)  50                    - push eax
//	(EXE+77B49)  56                    - push esi
//	(EXE+77B4A)  E8 91E9FFFF           - call (EXE+764E0)
//	(EXE+77B4F)  8B 46 64              - mov eax,[esi+64]
//	(EXE+77B52)  83 C4 24              - add esp,24 { 36 }
//	(EXE+77B55)  85 C5                 - test ebp,eax
//	(EXE+77B57)  0F85 BC000000         - jne (EXE+77C19)
//	(EXE+77B5D)  D9 86 00020000        - fld dword ptr [esi+00000200]
//	(EXE+77B63)  D8 47 08              - fadd dword ptr [edi+08]
//	(EXE+77B66)  D9 5F 08              - fstp dword ptr [edi+08]
//	(EXE+77B69)  85 6E 64              - test [esi+64],ebp
//	(EXE+77B6C)  0F85 A7000000         - jne (EXE+77C19)
//	(EXE+77B72)  8A 46 60              - mov al,[esi+60]
//	(EXE+77B75)  8B 8E 00020000        - mov ecx,[esi+00000200]
//	(EXE+77B7B)  8D 9E 00020000        - lea ebx,[esi+00000200]
//	(EXE+77B81)  89 4C 24 24           - mov [esp+24],ecx
//	(EXE+77B85)  A8 80                 - test al,-80 { 128 }
//	(EXE+77B87)  C7 44 24 18 00009643  - mov [esp+18],43960000 { (0) }
//	(EXE+77B8F)  75 08                 - jne (EXE+77B99)
//	(EXE+77B91)  C7 44 24 18 00008C42  - mov [esp+18],428C0000 { (0) }
//	(EXE+77B99)  8B 54 24 18           - mov edx,[esp+18]
//	(EXE+77B9D)  8B 46 74              - mov eax,[esi+74]
//	(EXE+77BA0)  8B 8E F0010000        - mov ecx,[esi+000001F0]
//	(EXE+77BA6)  52                    - push edx
//	(EXE+77BA7)  8B 96 EC010000        - mov edx,[esi+000001EC]
//	(EXE+77BAD)  50                    - push eax
//	(EXE+77BAE)  51                    - push ecx
//	(EXE+77BAF)  52                    - push edx
//	(EXE+77BB0)  53                    - push ebx
//	(EXE+77BB1)  E8 9A33FDFF           - call (EXE+4AF50)
//	(EXE+77BB6)  D9 03                 - fld dword ptr [ebx]
//	(EXE+77BB8)  D8 64 24 38           - fsub dword ptr [esp+38]
//	(EXE+77BBC)  83 C4 14              - add esp,14 { 20 }
//	(EXE+77BBF)  D8 0D C0DC4A00        - fmul dword ptr [(EXE+ADCC0)] { (3E4CCCCD) }
//	(EXE+77BC5)  D8 6F 08              - fsubr dword ptr [edi+08]
//	(EXE+77BC8)  D9 5F 08              - fstp dword ptr [edi+08]
//	(EXE+77BCB)  85 6E 64              - test [esi+64],ebp
//	(EXE+77BCE)  75 49                 - jne (EXE+77C19)
//	(EXE+77BD0)  D9 86 08020000        - fld dword ptr [esi+00000208]
//	(EXE+77BD6)  D8 1D 48DC4A00        - fcomp dword ptr [(EXE+ADC48)] { (0) }
//	(EXE+77BDC)  DFE0                  - fnstsw ax
//	(EXE+77BDE)  F6 C4 40              - test ah,40 { 64 }
//	(EXE+77BE1)  75 36                 - jne (EXE+77C19)
//	(EXE+77BE3)  D9 86 08020000        - fld dword ptr [esi+00000208]
//	(EXE+77BE9)  D8 1D 48DC4A00        - fcomp dword ptr [(EXE+ADC48)] { (0) }
//	(EXE+77BEF)  D9 86 08020000        - fld dword ptr [esi+00000208]
//	(EXE+77BF5)  D8 0D 34DD4A00        - fmul dword ptr [(EXE+ADD34)] { (80.00) }
//	(EXE+77BFB)  D9 86 08020000        - fld dword ptr [esi+00000208]
//	(EXE+77C01)  DFE0                  - fnstsw ax
//	(EXE+77C03)  F6 C4 01              - test ah,01 { 1 }
//	(EXE+77C06)  74 02                 - je (EXE+77C0A)
//	(EXE+77C08)  D9E0                  - fchs 
//	(EXE+77C0A)  D9C9                  - fxch st(1)
//	(EXE+77C0C)  D8 67 08              - fsub dword ptr [edi+08]
//	(EXE+77C0F)  D8C9                  - fmul st(0),st(1)
//	(EXE+77C11)  D8 47 08              - fadd dword ptr [edi+08]
//	(EXE+77C14)  D9 5F 08              - fstp dword ptr [edi+08]
//	(EXE+77C17)  DDD8                  - fstp st(0)
//	(EXE+77C19)  8B 47 08              - mov eax,[edi+08]
//	(EXE+77C1C)  5F                    - pop edi
//	(EXE+77C1D)  89 86 04020000        - mov [esi+00000204],eax
//	(EXE+77C23)  5E                    - pop esi
//	(EXE+77C24)  5D                    - pop ebp
//	(EXE+77C25)  5B                    - pop ebx
//	(EXE+77C26)  59                    - pop ecx
//	(EXE+77C27)  C3                    - ret 
//	(EXE+77C28)  90                    - nop 
//	(EXE+77C29)  90                    - nop 
//	(EXE+77C2A)  90                    - nop 
//	(EXE+77C2B)  90                    - nop 
//	(EXE+77C2C)  90                    - nop 
//	(EXE+77C2D)  90                    - nop 
//	(EXE+77C2E)  90                    - nop 
//	(EXE+77C2F)  90                    - nop 

