bool WriteFileTGFD() {
    static int32_t magic = 0x00010003;
    static void* tgfd_addr = 0x00E364A0;
    const char* path = ".\\data\\player\\";             // 4B4F6C
    const char* filename = "tgfd.dat";                  // 4B6D00
    
    bool success = true;
    char buffer[256];
    FILE* file;

    if (AreTGFDPodUnlocksEmpty()) {                     // 421D80
        CopySAVtoTGFD(0, 0);                            // 44E530
        PrepareIntermediaryTGFD(0);                     // 421B20
    }
    
    CreateDirectoryA(path);                             // 484310
    sprintf(&buffer, "%s%s", path, filename);

    file = fopen(&buffer, "wb");
    if ( !file )
        return false;
    if ( !fwrite_locked(&magic, 1u, 4u, file) )         // 4A0160
        success = false;
    if ( !fwrite_locked(tgfd_addr, 1u, 0xFD4u, file) )  // 4A0160
        success = false;
    fclose(file);
    
    return success;
}


//	EXE+21C90 - 81 EC 04010000        - sub esp,00000104 { 260 }
//	EXE+21C96 - 56                    - push esi
//	EXE+21C97 - 57                    - push edi
//	EXE+21C98 - C7 44 24 08 03000100  - mov [esp+08],00010003 { (0) }
//	EXE+21CA0 - 33 FF                 - xor edi,edi
//	EXE+21CA2 - E8 D9000000           - call (EXE+21D80)
//	EXE+21CA7 - 85 C0                 - test eax,eax
//	EXE+21CA9 - 74 13                 - je (EXE+21CBE)
//	EXE+21CAB - 57                    - push edi
//	EXE+21CAC - 57                    - push edi
//	EXE+21CAD - E8 7EC80200           - call (EXE+4E530)
//	EXE+21CB2 - 83 C4 08              - add esp,08 { 8 }
//	EXE+21CB5 - 57                    - push edi
//	EXE+21CB6 - E8 65FEFFFF           - call (EXE+21B20)
//	EXE+21CBB - 83 C4 04              - add esp,04 { 4 }
//	EXE+21CBE - 68 6C4F4B00           - push (EXE+B4F6C) { (".\data\player\") }
//	EXE+21CC3 - E8 48260600           - call (EXE+84310)
//	EXE+21CC8 - 83 C4 04              - add esp,04 { 4 }
//	EXE+21CCB - 8D 44 24 0C           - lea eax,[esp+0C]
//	EXE+21CCF - 68 006D4B00           - push (EXE+B6D00) { ("tgfd.dat") }
//	EXE+21CD4 - 68 6C4F4B00           - push (EXE+B4F6C) { (".\data\player\") }
//	EXE+21CD9 - 68 24254B00           - push (EXE+B2524) { ("%s%s") }
//	EXE+21CDE - 50                    - push eax
//	EXE+21CDF - E8 9CCE0700           - call (EXE+9EB80)
//	EXE+21CE4 - 83 C4 10              - add esp,10 { 16 }
//	EXE+21CE7 - 8D 4C 24 0C           - lea ecx,[esp+0C]
//	EXE+21CEB - 90                    - nop 
//	EXE+21CEC - 90                    - nop 
//	EXE+21CED - 90                    - nop 
//	EXE+21CEE - 90                    - nop 
//	EXE+21CEF - 90                    - nop 
//	EXE+21CF0 - 90                    - nop 
//	EXE+21CF1 - 90                    - nop 
//	EXE+21CF2 - 90                    - nop 
//	EXE+21CF3 - 90                    - nop 
//	EXE+21CF4 - 8D 54 24 0C           - lea edx,[esp+0C]
//	EXE+21CF8 - 68 FC6C4B00           - push (EXE+B6CFC) { (25207) }
//	EXE+21CFD - 52                    - push edx
//	EXE+21CFE - E8 DDD40700           - call (EXE+9F1E0)
//	EXE+21D03 - 8B F0                 - mov esi,eax
//	EXE+21D05 - 83 C4 08              - add esp,08 { 8 }
//	EXE+21D08 - 85 F6                 - test esi,esi
//	EXE+21D0A - 74 52                 - je (EXE+21D5E)
//	EXE+21D0C - 56                    - push esi
//	EXE+21D0D - 6A 04                 - push 04 { 4 }
//	EXE+21D0F - 8D 44 24 10           - lea eax,[esp+10]
//	EXE+21D13 - 6A 01                 - push 01 { 1 }
//	EXE+21D15 - 50                    - push eax
//	EXE+21D16 - E8 45E40700           - call (EXE+A0160)
//	EXE+21D1B - 83 C4 10              - add esp,10 { 16 }
//	EXE+21D1E - 85 C0                 - test eax,eax
//	EXE+21D20 - 75 05                 - jne (EXE+21D27)
//	EXE+21D22 - BF 01000000           - mov edi,00000001 { 1 }
//	EXE+21D27 - 56                    - push esi
//	EXE+21D28 - 68 D40F0000           - push 00000FD4 { 4052 }
//	EXE+21D2D - 6A 01                 - push 01 { 1 }
//	EXE+21D2F - 68 A064E300           - push (EXE+A364A0) { (128195738) }
//	EXE+21D34 - E8 27E40700           - call (EXE+A0160)
//	EXE+21D39 - 83 C4 10              - add esp,10 { 16 }
//	EXE+21D3C - 85 C0                 - test eax,eax
//	EXE+21D3E - 75 05                 - jne (EXE+21D45)
//	EXE+21D40 - BF 01000000           - mov edi,00000001 { 1 }
//	EXE+21D45 - 56                    - push esi
//	EXE+21D46 - E8 A5D30700           - call (EXE+9F0F0)
//	EXE+21D4B - 83 C4 04              - add esp,04 { 4 }
//	EXE+21D4E - 33 C0                 - xor eax,eax
//	EXE+21D50 - 85 FF                 - test edi,edi
//	EXE+21D52 - 0F94 C0               - sete al
//	EXE+21D55 - 5F                    - pop edi
//	EXE+21D56 - 5E                    - pop esi
//	EXE+21D57 - 81 C4 04010000        - add esp,00000104 { 260 }
//	EXE+21D5D - C3                    - ret 
//	EXE+21D5E - BF 01000000           - mov edi,00000001 { 1 }
//	EXE+21D63 - 33 C0                 - xor eax,eax
//	EXE+21D65 - 85 FF                 - test edi,edi
//	EXE+21D67 - 5F                    - pop edi
//	EXE+21D68 - 5E                    - pop esi
//	EXE+21D69 - 0F94 C0               - sete al
//	EXE+21D6C - 81 C4 04010000        - add esp,00000104 { 260 }
//	EXE+21D72 - C3                    - ret 
//	EXE+21D73 - 90                    - nop 
//	EXE+21D74 - 90                    - nop 
//	EXE+21D75 - 90                    - nop 
//	EXE+21D76 - 90                    - nop 
//	EXE+21D77 - 90                    - nop 
//	EXE+21D78 - 90                    - nop 
//	EXE+21D79 - 90                    - nop 
//	EXE+21D7A - 90                    - nop 
//	EXE+21D7B - 90                    - nop 
//	EXE+21D7C - 90                    - nop 
//	EXE+21D7D - 90                    - nop 
//	EXE+21D7E - 90                    - nop 
//	EXE+21D7F - 90                    - nop 

