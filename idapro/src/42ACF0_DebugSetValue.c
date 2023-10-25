void DebugSetValue(int id, float value) {
	const uint32_t DebugMenuState& = *(0x50C07C);

	switch (DebugMenuState) {
		case 0:
			DebugSetGameValue(id, val);		// 0x42A9F0
			break;
		case 1:
			DebugSetVehicleStat(id, val);	// 0x42A110
			break;
	}
}

//	EXE+2ACF0 - A1 7CC05000           - mov eax,[(EXE+10C07C)] { (0) }
//	EXE+2ACF5 - 85 C0                 - test eax,eax
//	EXE+2ACF7 - 75 13                 - jne (EXE+2AD0C)
//	EXE+2ACF9 - 8B 44 24 08           - mov eax,[esp+08]
//	EXE+2ACFD - 8B 4C 24 04           - mov ecx,[esp+04]
//	EXE+2AD01 - 50                    - push eax
//	EXE+2AD02 - 51                    - push ecx
//	EXE+2AD03 - E8 E8FCFFFF           - call (EXE+2A9F0)
//	EXE+2AD08 - 83 C4 08              - add esp,08 { 8 }
//	EXE+2AD0B - C3                    - ret 
//	EXE+2AD0C - 83 F8 01              - cmp eax,01 { 1 }
//	EXE+2AD0F - 75 12                 - jne (EXE+2AD23)
//	EXE+2AD11 - 8B 54 24 08           - mov edx,[esp+08]
//	EXE+2AD15 - 8B 44 24 04           - mov eax,[esp+04]
//	EXE+2AD19 - 52                    - push edx
//	EXE+2AD1A - 50                    - push eax
//	EXE+2AD1B - E8 F0F3FFFF           - call (EXE+2A110)
//	EXE+2AD20 - 83 C4 08              - add esp,08 { 8 }
//	EXE+2AD23 - C3                    - ret 
//	EXE+2AD24 - 90                    - nop 
//	EXE+2AD25 - 90                    - nop 
//	EXE+2AD26 - 90                    - nop 
//	EXE+2AD27 - 90                    - nop 
//	EXE+2AD28 - 90                    - nop 
//	EXE+2AD29 - 90                    - nop 
//	EXE+2AD2A - 90                    - nop 
//	EXE+2AD2B - 90                    - nop 
//	EXE+2AD2C - 90                    - nop 
//	EXE+2AD2D - 90                    - nop 
//	EXE+2AD2E - 90                    - nop 
//	EXE+2AD2F - 90                    - nop 
