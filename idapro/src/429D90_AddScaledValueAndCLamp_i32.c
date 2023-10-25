void AddScaledValueAndClamp_i32(int32_t* n, float val, float mult, int32_t min, int32_t max) {
	&n += val * mult;
	if (&n < min) &n = min;
	if (&n > max) &n = max;
}

//	EXE+29D90 - D9 44 24 0C           - fld dword ptr [esp+0C]
//	EXE+29D94 - D8 4C 24 08           - fmul dword ptr [esp+08]
//	EXE+29D98 - 56                    - push esi
//	EXE+29D99 - 8B 74 24 08           - mov esi,[esp+08]
//	EXE+29D9D - DB 06                 - fild dword ptr [esi]
//	EXE+29D9F - DEC1                  - faddp 
//	EXE+29DA1 - E8 7A4F0700           - call (EXE+9ED20)
//	EXE+29DA6 - 8B 4C 24 14           - mov ecx,[esp+14]
//	EXE+29DAA - 89 06                 - mov [esi],eax
//	EXE+29DAC - 3B C1                 - cmp eax,ecx
//	EXE+29DAE - 7D 02                 - jnl (EXE+29DB2)
//	EXE+29DB0 - 89 0E                 - mov [esi],ecx
//	EXE+29DB2 - 8B 44 24 18           - mov eax,[esp+18]
//	EXE+29DB6 - 8B 0E                 - mov ecx,[esi]
//	EXE+29DB8 - 3B C8                 - cmp ecx,eax
//	EXE+29DBA - 7E 02                 - jle (EXE+29DBE)
//	EXE+29DBC - 89 06                 - mov [esi],eax
//	EXE+29DBE - 5E                    - pop esi
//	EXE+29DBF - C3                    - ret 
