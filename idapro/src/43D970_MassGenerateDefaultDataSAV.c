void MassGenerateDefaultDataSAV() {
    for (int i = 0; i < 20; ++i)
        GenerateDefaultDataSAV(0, i);   // standard slots
    for (int i = 0; i < 4; ++i)
        GenerateDefaultDataSAV(1, i);   // tgfd slots
}

//	EXE+3D970 - 56                    - push esi
//	EXE+3D971 - 33 F6                 - xor esi,esi
//	EXE+3D973 - 56                    - push esi
//	EXE+3D974 - 6A 00                 - push 00 { 0 }
//	EXE+3D976 - E8 85100000           - call [EXE+3EA00]    // GenerateDefaultDataSAV
//	EXE+3D97B - 83 C4 08              - add esp,08 { 8 }
//	EXE+3D97E - 46                    - inc esi
//	EXE+3D97F - 83 FE 14              - cmp esi,14 { 20 }
//	EXE+3D982 - 7C EF                 - jl [EXE+3D973]
//	EXE+3D984 - 33 F6                 - xor esi,esi
//	EXE+3D986 - 56                    - push esi
//	EXE+3D987 - 6A 01                 - push 01 { 1 }
//	EXE+3D989 - E8 72100000           - call [EXE+3EA00]    // GenerateDefaultDataSAV
//	EXE+3D98E - 83 C4 08              - add esp,08 { 8 }
//	EXE+3D991 - 46                    - inc esi
//	EXE+3D992 - 83 FE 04              - cmp esi,04 { 4 }
//	EXE+3D995 - 7C EF                 - jl [EXE+3D986]
//	EXE+3D997 - 5E                    - pop esi
//	EXE+3D998 - C3                    - ret 
//	EXE+3D999 - 90                    - nop 
//	EXE+3D99A - 90                    - nop 
//	EXE+3D99B - 90                    - nop 
//	EXE+3D99C - 90                    - nop 
//	EXE+3D99D - 90                    - nop 
//	EXE+3D99E - 90                    - nop 
//	EXE+3D99F - 90                    - nop 
