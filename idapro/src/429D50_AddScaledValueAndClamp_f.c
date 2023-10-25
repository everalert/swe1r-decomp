void AddScaledValueAndClamp_f(float* n, float val, float mult, float min, float max) {
	&n += val*mult;
	if (&n < min) &n = min;
	if (&n > max) &n = max;
}

//	EXE+29D50 - D9 44 24 0C           - fld dword ptr [esp+0C]
//	EXE+29D54 - D8 4C 24 08           - fmul dword ptr [esp+08]
//	EXE+29D58 - 8B 4C 24 04           - mov ecx,[esp+04]
//	EXE+29D5C - D8 01                 - fadd dword ptr [ecx]
//	EXE+29D5E - D8 54 24 10           - fcom dword ptr [esp+10]
//	EXE+29D62 - D9 19                 - fstp dword ptr [ecx]
//	EXE+29D64 - DFE0                  - fnstsw ax
//	EXE+29D66 - F6 C4 01              - test ah,01 { 1 }
//	EXE+29D69 - 74 06                 - je (EXE+29D71)
//	EXE+29D6B - 8B 44 24 10           - mov eax,[esp+10]
//	EXE+29D6F - 89 01                 - mov [ecx],eax
//	EXE+29D71 - D9 01                 - fld dword ptr [ecx]
//	EXE+29D73 - D8 5C 24 14           - fcomp dword ptr [esp+14]
//	EXE+29D77 - DFE0                  - fnstsw ax
//	EXE+29D79 - F6 C4 41              - test ah,41 { 65 }
//	EXE+29D7C - 75 06                 - jne (EXE+29D84)
//	EXE+29D7E - 8B 54 24 14           - mov edx,[esp+14]
//	EXE+29D82 - 89 11                 - mov [ecx],edx
//	EXE+29D84 - C3                    - ret 
//	EXE+29D85 - 90                    - nop 
//	EXE+29D86 - 90                    - nop 
//	EXE+29D87 - 90                    - nop 
//	EXE+29D88 - 90                    - nop 
//	EXE+29D89 - 90                    - nop 
//	EXE+29D8A - 90                    - nop 
//	EXE+29D8B - 90                    - nop 
//	EXE+29D8C - 90                    - nop 
//	EXE+29D8D - 90                    - nop 
//	EXE+29D8E - 90                    - nop 
//	EXE+29D8F - 90                    - nop 
