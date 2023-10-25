void DebugSetGameValue(int id, float value) {
	const uint32_t DebugFlags48);
	const uint32_t DebugLevel& =		*(0x50C040);
	const bool InvincibilityOn& =		*(0x50CA28);
	const float AILevel& =				*(0x4C707C);
	const float AISpread& =				*(0x4C7080);
	const float DeathSpeedMin& =		*(0x4C7BB8);
	const float DeathSpeedDrop& =		*(0x4C7BBC);
	const uint32_t SplineMarkersOn& =	*(0x50CA24);
	const uint32_t GameSettingFlags& =	*(0xE996DC);

	switch (id) {
		case 0:
			AddScaledValueAndClamp_i32(&DebugLevel_, value, 1.0, 0, 6);		// 0x429D90
			break;
		case 1:
			if (DebugFlags & 0x04)		// 1<<2
				InvincibilityOn_ = !InvincibilityOn;
			break;
		case 2:
			if (DebugFlags & 0x08)		// 1<<3
				AddScaledValueAndClamp_f(&AILevel, value, 0.001, 0.2, 2.0);	// 0x429D50
			break;
		case 3:
			if (DebugFlags & 0x08)
				AddScaledValueAndClamp_f(&AISpread, value, 0.5, 2.0, 200.0);
			break;
		case 4:
			if (DebugFlags & 0x08)
				AddScaledValueAndClamp_f(&DeathSpeedMin, value, 1.0, 20.0, 1000.0);
			break;
		case 5:
			if (DebugFlags & 0x08)
				AddScaledValueAndClamp_f(&DeathSpeedDrop, value, 1.0, 20.0, 500.0);
			break;
		case 6:
			if (DebugFlags & 0x10)		// 1<<04
				SplineMarkersOn = !SplineMarkersOn;
			break;
		case 7:
			if (DebugFlags & 0x20) {	// 1<<05
				if (GameSettingFlags & 0x4000)	// mirrored mode
					GameSettingFlags &= 0xFFFFBFFF;
				else
					GameSettingFlags |= 0x00004000;
			}
			break;
	}
}

//	EXE+2A9F0 - 8B 44 24 04           - mov eax,[esp+04]
//	EXE+2A9F4 - 83 F8 07              - cmp eax,07 { 7 }
//	EXE+2A9F7 - 0F87 40010000         - ja (EXE+2AB3D)
//	EXE+2A9FD - FF 24 85 40AB4200     - jmp dword ptr [eax*4+(EXE+2AB40)]
//	EXE+2AA04 - 8B 44 24 08           - mov eax,[esp+08]
//	EXE+2AA08 - 6A 06                 - push 06 { 6 }
//	EXE+2AA0A - 6A 00                 - push 00 { 0 }
//	EXE+2AA0C - 68 0000803F           - push RTSSHooks.dll+17A0000 { (0) }	// NOTE ???
//	EXE+2AA11 - 50                    - push eax
//	EXE+2AA12 - 68 40C05000           - push (EXE+10C040) { (6) }
//	EXE+2AA17 - E8 74F3FFFF           - call (EXE+29D90)
//	EXE+2AA1C - 83 C4 14              - add esp,14 { 20 }
//	EXE+2AA1F - C3                    - ret 
//	EXE+2AA20 - F6 05 48C05000 04     - test byte ptr [(EXE+10C048)],04 { (0),4 }
//	EXE+2AA27 - 0F84 10010000         - je (EXE+2AB3D)
//	EXE+2AA2D - A1 28CA5000           - mov eax,[(EXE+10CA28)] { (0) }
//	EXE+2AA32 - 33 C9                 - xor ecx,ecx
//	EXE+2AA34 - 85 C0                 - test eax,eax
//	EXE+2AA36 - 0F94 C1               - sete cl
//	EXE+2AA39 - 89 0D 28CA5000        - mov [(EXE+10CA28)],ecx { (0) }
//	EXE+2AA3F - C3                    - ret 
//	EXE+2AA40 - F6 05 48C05000 08     - test byte ptr [(EXE+10C048)],08 { (0),8 }
//	EXE+2AA47 - 0F84 F0000000         - je (EXE+2AB3D)
//	EXE+2AA4D - 8B 54 24 08           - mov edx,[esp+08]
//	EXE+2AA51 - 68 00000040           - push RTSSHooks.dll+1FA0000 { (0) }
//	EXE+2AA56 - 68 CDCC4C3E           - push RTSSHooks.dll+46CCCD { (0) }
//	EXE+2AA5B - 68 6F12833A           - push 3A83126F { 0.00 }
//	EXE+2AA60 - 52                    - push edx
//	EXE+2AA61 - 68 7C704C00           - push (EXE+C707C) { (27) }
//	EXE+2AA66 - E8 E5F2FFFF           - call (EXE+29D50)
//	EXE+2AA6B - 83 C4 14              - add esp,14 { 20 }
//	EXE+2AA6E - C3                    - ret 
//	EXE+2AA6F - F6 05 48C05000 08     - test byte ptr [(EXE+10C048)],08 { (0),8 }
//	EXE+2AA76 - 0F84 C1000000         - je (EXE+2AB3D)
//	EXE+2AA7C - 8B 44 24 08           - mov eax,[esp+08]
//	EXE+2AA80 - 68 00004843           - push 43480000 { (-16777216) }
//	EXE+2AA85 - 68 00000040           - push RTSSHooks.dll+1FA0000 { (0) }
//	EXE+2AA8A - 68 0000003F           - push RTSSHooks.dll+FA0000 { (0) }
//	EXE+2AA8F - 50                    - push eax
//	EXE+2AA90 - 68 80704C00           - push (EXE+C7080) { (20.00) }
//	EXE+2AA95 - E8 B6F2FFFF           - call (EXE+29D50)
//	EXE+2AA9A - 83 C4 14              - add esp,14 { 20 }
//	EXE+2AA9D - C3                    - ret 
//	EXE+2AA9E - F6 05 48C05000 08     - test byte ptr [(EXE+10C048)],08 { (0),8 }
//	EXE+2AAA5 - 0F84 92000000         - je (EXE+2AB3D)
//	EXE+2AAAB - 8B 4C 24 08           - mov ecx,[esp+08]
//	EXE+2AAAF - 68 00007A44           - push 447A0000 { (-16777216) }
//	EXE+2AAB4 - 68 0000A041           - push 41A00000 { (-16777216) }
//	EXE+2AAB9 - 68 0000803F           - push RTSSHooks.dll+17A0000 { (0) }
//	EXE+2AABE - 51                    - push ecx
//	EXE+2AABF - 68 B87B4C00           - push (EXE+C7BB8) { (326.00) }
//	EXE+2AAC4 - E8 87F2FFFF           - call (EXE+29D50)
//	EXE+2AAC9 - 83 C4 14              - add esp,14 { 20 }
//	EXE+2AACC - C3                    - ret 
//	EXE+2AACD - F6 05 48C05000 08     - test byte ptr [(EXE+10C048)],08 { (0),8 }
//	EXE+2AAD4 - 74 67                 - je (EXE+2AB3D)
//	EXE+2AAD6 - 8B 54 24 08           - mov edx,[esp+08]
//	EXE+2AADA - 68 0000FA43           - push 43FA0000 { (-16777216) }
//	EXE+2AADF - 68 0000A041           - push 41A00000 { (-16777216) }
//	EXE+2AAE4 - 68 0000803F           - push RTSSHooks.dll+17A0000 { (0) }
//	EXE+2AAE9 - 52                    - push edx
//	EXE+2AAEA - 68 BC7B4C00           - push (EXE+C7BBC) { (141.00) }
//	EXE+2AAEF - E8 5CF2FFFF           - call (EXE+29D50)
//	EXE+2AAF4 - 83 C4 14              - add esp,14 { 20 }
//	EXE+2AAF7 - C3                    - ret 
//	EXE+2AAF8 - F6 05 48C05000 10     - test byte ptr [(EXE+10C048)],10 { (0),16 }
//	EXE+2AAFF - 74 3C                 - je (EXE+2AB3D)
//	EXE+2AB01 - 8B 0D 24CA5000        - mov ecx,[(EXE+10CA24)] { (0) }
//	EXE+2AB07 - 33 C0                 - xor eax,eax
//	EXE+2AB09 - 85 C9                 - test ecx,ecx
//	EXE+2AB0B - 0F94 C0               - sete al
//	EXE+2AB0E - A3 24CA5000           - mov [(EXE+10CA24)],eax { (0) }
//	EXE+2AB13 - C3                    - ret 
//	EXE+2AB14 - F6 05 48C05000 20     - test byte ptr [(EXE+10C048)],20 { (0),32 }
//	EXE+2AB1B - 74 20                 - je (EXE+2AB3D)
//	EXE+2AB1D - 8B 0D DC96E900        - mov ecx,[(EXE+A996DC)] { (9) }
//	EXE+2AB23 - B8 00400000           - mov eax,00004000 { 16384 }
//	EXE+2AB28 - 85 C8                 - test eax,ecx
//	EXE+2AB2A - 74 0B                 - je (EXE+2AB37)
//	EXE+2AB2C - 8B C1                 - mov eax,ecx
//	EXE+2AB2E - 80 E4 BF              - and ah,-41 { 191 }
//	EXE+2AB31 - A3 DC96E900           - mov [(EXE+A996DC)],eax { (9) }
//	EXE+2AB36 - C3                    - ret 
//	EXE+2AB37 - 09 05 DC96E900        - or [(EXE+A996DC)],eax { (9) }
//	EXE+2AB3D - C3                    - ret 
