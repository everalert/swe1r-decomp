bool LapCompletion(void* EngineData, int a2) {
    int v2; // ebx
    int v3; // edi
    int v4; // eax
    _DWORD *v5; // eax
    double v7; // st7
    char v8; // c0
    int v9; // eax
    int v11; // ecx

    v2 = 0;
    v3 = 1;
    v4 = *(EngineData + 24);                       // flags1
    if ( !(v4 & 0x4000) )                         // 01000000 00000000; IsDead?
        v3 = a2;
    *(EngineData + 57) = *(EngineData + 56);        // lap comp last frame, lap comp this frame
    if ( dword_4D5E00 && v4 & 0x40 )              // 01000000; unk
    {
        v5 = *(EngineData + 1948);                   // ptr to race data
        *(EngineData + 58) = dword_EA0420[*v5];
        v5[30] = dword_EA0480[*v5];
    }
    if ( dword_4D5E00 && *(EngineData + 96) & 0x40 )// seems to be flags related to spawning/death of some kind
        *(EngineData + 56) = flt_EA0360[**(EngineData + 1948)];// lap completion this frame = ???
    else
        *(EngineData + 56) = UNK_LapProgress_47F810(EngineData + 172);// lap completion this frame = ???
    if ( *(EngineData + 69) <= 8 )                 // going forward counter?
        *(EngineData + 68) = FrameTime_d_E22A40 + *(EngineData + 68);// idle timer since last making neg progress?
    else
        *(EngineData + 68) = 0;
    if ( !v3 || *(EngineData + 56) > 0.80000001 && *(EngineData + 57) < 0.1 )
        return 0;
    v7 = *(EngineData + 58);                       // max lap completion
    if ( v8 )
    {
        if ( v7 > 0.80000001 )                      // the 80 in 80/10 rule?
            v7 = v7 - 1.0;
        if ( *(EngineData + 57) > 0.80000001 )
            *(EngineData + 57) = *(EngineData + 57) - 1.0;// lap completion last frame
    }
    if ( dword_4C7BE4 >= 0 )
    {
        if ( *(EngineData + 56) >= 1.0 )             // lap comp this frame
            v2 = 1;
        v9 = *(EngineData + 56);                     // lap comp this frame
        *(EngineData + 68) = 0;                      // no progress idle timer
        *(EngineData + 58) = v9;                     // max lap comp
        return v2;
    }
    if ( v7 >= *(EngineData + 56) || v7 < *(EngineData + 57) - 0.0099999998 )// lap comp this frame, lap comp last frame
        return 0;
    if ( v7 < 0.0 )
        v2 = 1;
    v11 = *(EngineData + 56);
    *(EngineData + 68) = 0;
    *(EngineData + 58) = v11;
    return v2;
}

//	EXE+7FDD0 - 53                    - push ebx
//	EXE+7FDD1 - 56                    - push esi
//	EXE+7FDD2 - 8B 74 24 0C           - mov esi,[esp+0C]
//	EXE+7FDD6 - 33 DB                 - xor ebx,ebx
//	EXE+7FDD8 - 57                    - push edi
//	EXE+7FDD9 - BF 01000000           - mov edi,00000001 { 1 }
//	EXE+7FDDE - 8B 46 60              - mov eax,[esi+60]
//	EXE+7FDE1 - F6 C4 40              - test ah,40 { 64 }
//	EXE+7FDE4 - 75 04                 - jne (EXE+7FDEA)
//	EXE+7FDE6 - 8B 7C 24 14           - mov edi,[esp+14]
//	EXE+7FDEA - 8B 8E E0000000        - mov ecx,[esi+000000E0]
//	EXE+7FDF0 - 89 8E E4000000        - mov [esi+000000E4],ecx
//	EXE+7FDF6 - 8B 0D 005E4D00        - mov ecx,[(EXE+D5E00)] { (0) }
//	EXE+7FDFC - 85 C9                 - test ecx,ecx
//	EXE+7FDFE - 74 25                 - je (EXE+7FE25)
//	EXE+7FE00 - A8 40                 - test al,40 { 64 }
//	EXE+7FE02 - 74 21                 - je (EXE+7FE25)
//	EXE+7FE04 - 8B 86 701E0000        - mov eax,[esi+00001E70]
//	EXE+7FE0A - 8B 10                 - mov edx,[eax]
//	EXE+7FE0C - 8B 0C 95 2004EA00     - mov ecx,[edx*4+(EXE+AA0420)]
//	EXE+7FE13 - 89 8E E8000000        - mov [esi+000000E8],ecx
//	EXE+7FE19 - 8B 10                 - mov edx,[eax]
//	EXE+7FE1B - 8B 0C 95 8004EA00     - mov ecx,[edx*4+(EXE+AA0480)]
//	EXE+7FE22 - 89 48 78              - mov [eax+78],ecx
//	EXE+7FE25 - A1 005E4D00           - mov eax,[(EXE+D5E00)] { (0) }
//	EXE+7FE2A - 85 C0                 - test eax,eax
//	EXE+7FE2C - 74 1D                 - je (EXE+7FE4B)
//	EXE+7FE2E - F6 46 60 40           - test byte ptr [esi+60],40 { 64 }
//	EXE+7FE32 - 74 17                 - je (EXE+7FE4B)
//	EXE+7FE34 - 8B 96 701E0000        - mov edx,[esi+00001E70]
//	EXE+7FE3A - 8B 02                 - mov eax,[edx]
//	EXE+7FE3C - 8B 0C 85 6003EA00     - mov ecx,[eax*4+(EXE+AA0360)]
//	EXE+7FE43 - 89 8E E0000000        - mov [esi+000000E0],ecx
//	EXE+7FE49 - EB 15                 - jmp (EXE+7FE60)
//	EXE+7FE4B - 8D 96 AC000000        - lea edx,[esi+000000AC]
//	EXE+7FE51 - 52                    - push edx
//	EXE+7FE52 - E8 B9F9FFFF           - call (EXE+7F810)
//	EXE+7FE57 - D9 9E E0000000        - fstp dword ptr [esi+000000E0]
//	EXE+7FE5D - 83 C4 04              - add esp,04 { 4 }
//	EXE+7FE60 - 83 BE 14010000 08     - cmp dword ptr [esi+00000114],08 { 8 }
//	EXE+7FE67 - 7E 0C                 - jle (EXE+7FE75)
//	EXE+7FE69 - C7 86 10010000 00000000 - mov [esi+00000110],00000000 { 0 }
//	EXE+7FE73 - EB 12                 - jmp (EXE+7FE87)
//	EXE+7FE75 - DD 05 402AE200        - fld qword ptr [(EXE+A22A40)] { (0.01) }
//	EXE+7FE7B - D8 86 10010000        - fadd dword ptr [esi+00000110]
//	EXE+7FE81 - D9 9E 10010000        - fstp dword ptr [esi+00000110]
//	EXE+7FE87 - 85 FF                 - test edi,edi
//	EXE+7FE89 - 0F84 0E010000         - je (EXE+7FF9D)
//	EXE+7FE8F - D9 86 E0000000        - fld dword ptr [esi+000000E0]
//	EXE+7FE95 - D8 1D 6CDF4A00        - fcomp dword ptr [(EXE+ADF6C)] { (3F4CCCCD) }
//	EXE+7FE9B - DFE0                  - fnstsw ax
//	EXE+7FE9D - F6 C4 41              - test ah,41 { 65 }
//	EXE+7FEA0 - 75 17                 - jne (EXE+7FEB9)
//	EXE+7FEA2 - D9 86 E4000000        - fld dword ptr [esi+000000E4]
//	EXE+7FEA8 - D8 1D 68DF4A00        - fcomp dword ptr [(EXE+ADF68)] { (0.00) }
//	EXE+7FEAE - DFE0                  - fnstsw ax
//	EXE+7FEB0 - F6 C4 01              - test ah,01 { 1 }
//	EXE+7FEB3 - 0F85 E4000000         - jne (EXE+7FF9D)
//	EXE+7FEB9 - D9 86 E0000000        - fld dword ptr [esi+000000E0]
//	EXE+7FEBF - D8 1D 68DF4A00        - fcomp dword ptr [(EXE+ADF68)] { (0.00) }
//	EXE+7FEC5 - D9 86 E8000000        - fld dword ptr [esi+000000E8]
//	EXE+7FECB - DFE0                  - fnstsw ax
//	EXE+7FECD - F6 C4 01              - test ah,01 { 1 }
//	EXE+7FED0 - 74 38                 - je (EXE+7FF0A)
//	EXE+7FED2 - D8 15 6CDF4A00        - fcom dword ptr [(EXE+ADF6C)] { (3F4CCCCD) }
//	EXE+7FED8 - DFE0                  - fnstsw ax
//	EXE+7FEDA - F6 C4 41              - test ah,41 { 65 }
//	EXE+7FEDD - 75 06                 - jne (EXE+7FEE5)
//	EXE+7FEDF - D8 25 4CDF4A00        - fsub dword ptr [(EXE+ADF4C)] { (1.00) }
//	EXE+7FEE5 - D9 86 E4000000        - fld dword ptr [esi+000000E4]
//	EXE+7FEEB - D8 1D 6CDF4A00        - fcomp dword ptr [(EXE+ADF6C)] { (3F4CCCCD) }
//	EXE+7FEF1 - DFE0                  - fnstsw ax
//	EXE+7FEF3 - F6 C4 41              - test ah,41 { 65 }
//	EXE+7FEF6 - 75 12                 - jne (EXE+7FF0A)
//	EXE+7FEF8 - D9 86 E4000000        - fld dword ptr [esi+000000E4]
//	EXE+7FEFE - D8 25 4CDF4A00        - fsub dword ptr [(EXE+ADF4C)] { (1.00) }
//	EXE+7FF04 - D9 9E E4000000        - fstp dword ptr [esi+000000E4]
//	EXE+7FF0A - A1 E47B4C00           - mov eax,[(EXE+C7BE4)] { (-1) }
//	EXE+7FF0F - 85 C0                 - test eax,eax
//	EXE+7FF11 - 7C 36                 - jl (EXE+7FF49)
//	EXE+7FF13 - DDD8                  - fstp st(0)
//	EXE+7FF15 - D9 86 E0000000        - fld dword ptr [esi+000000E0]
//	EXE+7FF1B - D8 1D 4CDF4A00        - fcomp dword ptr [(EXE+ADF4C)] { (1.00) }
//	EXE+7FF21 - DFE0                  - fnstsw ax
//	EXE+7FF23 - F6 C4 01              - test ah,01 { 1 }
//	EXE+7FF26 - 75 05                 - jne (EXE+7FF2D)
//	EXE+7FF28 - BB 01000000           - mov ebx,00000001 { 1 }
//	EXE+7FF2D - 8B 86 E0000000        - mov eax,[esi+000000E0]
//	EXE+7FF33 - C7 86 10010000 00000000 - mov [esi+00000110],00000000 { 0 }
//	EXE+7FF3D - 89 86 E8000000        - mov [esi+000000E8],eax
//	EXE+7FF43 - 8B C3                 - mov eax,ebx
//	EXE+7FF45 - 5F                    - pop edi
//	EXE+7FF46 - 5E                    - pop esi
//	EXE+7FF47 - 5B                    - pop ebx
//	EXE+7FF48 - C3                    - ret 
//	EXE+7FF49 - D8 96 E0000000        - fcom dword ptr [esi+000000E0]
//	EXE+7FF4F - DFE0                  - fnstsw ax
//	EXE+7FF51 - F6 C4 01              - test ah,01 { 1 }
//	EXE+7FF54 - 74 45                 - je (EXE+7FF9B)
//	EXE+7FF56 - D9 86 E4000000        - fld dword ptr [esi+000000E4]
//	EXE+7FF5C - D8 25 54DF4A00        - fsub dword ptr [(EXE+ADF54)] { (0.01) }
//	EXE+7FF62 - D9C1                  - fld st(1)
//	EXE+7FF64 - DED9                  - fcompp 
//	EXE+7FF66 - DFE0                  - fnstsw ax
//	EXE+7FF68 - F6 C4 01              - test ah,01 { 1 }
//	EXE+7FF6B - 75 2E                 - jne (EXE+7FF9B)
//	EXE+7FF6D - D8 1D 40DF4A00        - fcomp dword ptr [(EXE+ADF40)] { (-0.01) }
//	EXE+7FF73 - DFE0                  - fnstsw ax
//	EXE+7FF75 - F6 C4 01              - test ah,01 { 1 }
//	EXE+7FF78 - 74 05                 - je (EXE+7FF7F)
//	EXE+7FF7A - BB 01000000           - mov ebx,00000001 { 1 }
//	EXE+7FF7F - 8B 8E E0000000        - mov ecx,[esi+000000E0]
//	EXE+7FF85 - C7 86 10010000 00000000 - mov [esi+00000110],00000000 { 0 }
//	EXE+7FF8F - 89 8E E8000000        - mov [esi+000000E8],ecx
//	EXE+7FF95 - 8B C3                 - mov eax,ebx
//	EXE+7FF97 - 5F                    - pop edi
//	EXE+7FF98 - 5E                    - pop esi
//	EXE+7FF99 - 5B                    - pop ebx
//	EXE+7FF9A - C3                    - ret 
//	EXE+7FF9B - DDD8                  - fstp st(0)
//	EXE+7FF9D - 5F                    - pop edi
//	EXE+7FF9E - 8B C3                 - mov eax,ebx
//	EXE+7FFA0 - 5E                    - pop esi
//	EXE+7FFA1 - 5B                    - pop ebx
//	EXE+7FFA2 - C3                    - ret 
//	EXE+7FFA3 - 90                    - nop 
//	EXE+7FFA4 - 90                    - nop 
//	EXE+7FFA5 - 90                    - nop 
//	EXE+7FFA6 - 90                    - nop 
//	EXE+7FFA7 - 90                    - nop 
//	EXE+7FFA8 - 90                    - nop 
//	EXE+7FFA9 - 90                    - nop 
//	EXE+7FFAA - 90                    - nop 
//	EXE+7FFAB - 90                    - nop 
//	EXE+7FFAC - 90                    - nop 
//	EXE+7FFAD - 90                    - nop 
//	EXE+7FFAE - 90                    - nop 
//	EXE+7FFAF - 90                    - nop 
