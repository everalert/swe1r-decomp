void GenerateDefaultDataTGFD(void* addr) {
    static void* tgfd_addr = 0x00E364A0;
    static uint32_t tgfd_len = 0xFD4; // 4052
    memset(addr, 0, tgfd_len);
    *(addr + 2) = 3;            // unknown
    *(addr + 4) = 1;            // unknown
    *(addr + 5) = 225u;         // sfx vol
    *(addr + 6) = 200u;         // music/cs vol
    *(addr + 7) = 0;            // unknown
                                //dword_50C75C = 0;         // related to the nullsub?
                                //nullsub_2();              // 0x426910
    *(addr + 0x0C) = 7;         // AMC freeplay unlocks
    *(addr + 0x0D) = 3;         // SPC freeplay unlocks
    *(addr + 0x0E) = 1;         // GAL freeplay unlocks
    *(addr + 0x0F) = 0;         // INV freeplay unlocks
    *(addr + 0x10) = 0x22E01;   // freeplay vehicle unlocks

    float* off_times = addr + 0x21C; // times
    char* off_fnames = addr + 0x924; // fnames
    void *off_trkfav = 0;
    for (int i = 0; i < 25; ++i) {
        for (int j; j < 2; ++j) {
            static float default_time = (float)0x4560FFD7; // 59:59.990 / 3599.99
            *(off_times-50) = default_time;
            *off_times = default_time; // mirrored
            ++off_times; 
            static uint32_t fname_length = 0x20; // 32
            memset(*off_fnames, 65u, fname_len);  // set default fname to As
            memset(*(off_fnames-1600), 65u, fname_len); // v4+0x640
            off_fnames += fname_len;
            int32_t base_trkfav = 2 * i + j;
            addr[base_trkfav + 0xF63] = byte_4BFEF2[off_trkfav]; // set track favourite from LUT?
            addr[base_trkfav + 0xF95] = byte_4BFEF2[off_trkfav]; // set track favourite from LUT?
        }
        off_trkfav = off_trkfav + 12;
    }

    for (int i = 0; i < 4; ++i)
        GenerateDefaultDataSAV(1, i); // 0x43EA00

    tgfd_addr = sub_44E440(tgfd_addr);  // 0x44E440, hashing function?
}

//  EXE+4E320 - 83 EC 08              - sub esp,08 { 8 }
//  EXE+4E323 - 53                    - push ebx
//  EXE+4E324 - 55                    - push ebp
//  EXE+4E325 - 8B 6C 24 14           - mov ebp,[esp+14]
//  EXE+4E329 - 56                    - push esi
//  EXE+4E32A - 57                    - push edi
//  EXE+4E32B - B9 F5030000           - mov ecx,000003F5 { 1013 }
//  EXE+4E330 - 33 C0                 - xor eax,eax
//  EXE+4E332 - 8B FD                 - mov edi,ebp
//  EXE+4E334 - F3 AB                 - repe stosd 
//  EXE+4E336 - BB 03000000           - mov ebx,00000003 { 3 }
//  EXE+4E33B - 33 FF                 - xor edi,edi
//  EXE+4E33D - C6 45 04 01           - mov byte ptr [ebp+04],01 { 1 }
//  EXE+4E341 - C6 45 05 E1           - mov byte ptr [ebp+05],-1F { 225 }
//  EXE+4E345 - C6 45 06 C8           - mov byte ptr [ebp+06],-38 { 200 }
//  EXE+4E349 - 88 45 07              - mov [ebp+07],al
//  EXE+4E34C - 89 5D 08              - mov [ebp+08],ebx
//  EXE+4E34F - 89 3D 5CC75000        - mov [EXE+10C75C],edi { (0) }
//  EXE+4E355 - E8 B685FDFF           - call EXE+26910
//  EXE+4E35A - C7 45 10 012E0200     - mov [ebp+10],00022E01 { 142849 }
//  EXE+4E361 - C6 45 0C 07           - mov byte ptr [ebp+0C],07 { 7 }
//  EXE+4E365 - 88 5D 0D              - mov [ebp+0D],bl
//  EXE+4E368 - C6 45 0E 01           - mov byte ptr [ebp+0E],01 { 1 }
//  EXE+4E36C - C6 45 0F 00           - mov byte ptr [ebp+0F],00 { 0 }
//  EXE+4E370 - 89 7C 24 1C           - mov [esp+1C],edi
//  EXE+4E374 - 8D 8D 1C020000        - lea ecx,[ebp+0000021C]
//  EXE+4E37A - 8D 85 24090000        - lea eax,[ebp+00000924]
//  EXE+4E380 - C7 44 24 14 19000000  - mov [esp+14],00000019 { 25 }
//  EXE+4E388 - B3 41                 - mov bl,41 { 65 }
//  EXE+4E38A - 33 F6                 - xor esi,esi
//  EXE+4E38C - C7 44 24 10 02000000  - mov [esp+10],00000002 { 2 }
//  EXE+4E394 - EB 02                 - jmp EXE+4E398
//  EXE+4E396 - B3 41                 - mov bl,41 { 65 }
//  EXE+4E398 - C7 81 38FFFFFF D7FF6045 - mov [ecx-000000C8],4560FFD7 { (0) }
//  EXE+4E3A2 - C7 01 D7FF6045        - mov [ecx],4560FFD7 { (0) }
//  EXE+4E3A8 - BA 20000000           - mov edx,00000020 { 32 }
//  EXE+4E3AD - 88 98 C0F9FFFF        - mov [eax-00000640],bl
//  EXE+4E3B3 - 88 18                 - mov [eax],bl
//  EXE+4E3B5 - 40                    - inc eax
//  EXE+4E3B6 - 4A                    - dec edx
//  EXE+4E3B7 - 75 F4                 - jne EXE+4E3AD
//  EXE+4E3B9 - 8B 5C 24 1C           - mov ebx,[esp+1C]
//  EXE+4E3BD - 8D 94 7D 640F0000     - lea edx,[ebp+edi*2+00000F64]
//  EXE+4E3C4 - 46                    - inc esi
//  EXE+4E3C5 - 83 C1 04              - add ecx,04 { 4 }
//  EXE+4E3C8 - 8A 9B F2FE4B00        - mov bl,[ebx+EXE+BFEF2]
//  EXE+4E3CE - 88 5C 32 FF           - mov [edx+esi-01],bl
//  EXE+4E3D2 - 8B 5C 24 1C           - mov ebx,[esp+1C]
//  EXE+4E3D6 - 8D 94 7D 960F0000     - lea edx,[ebp+edi*2+00000F96]
//  EXE+4E3DD - 8A 9B F2FE4B00        - mov bl,[ebx+EXE+BFEF2]
//  EXE+4E3E3 - 88 5C 32 FF           - mov [edx+esi-01],bl
//  EXE+4E3E7 - 8B 54 24 10           - mov edx,[esp+10]
//  EXE+4E3EB - 4A                    - dec edx
//  EXE+4E3EC - 89 54 24 10           - mov [esp+10],edx
//  EXE+4E3F0 - 75 A4                 - jne EXE+4E396
//  EXE+4E3F2 - 8B 74 24 1C           - mov esi,[esp+1C]
//  EXE+4E3F6 - 8B 54 24 14           - mov edx,[esp+14]
//  EXE+4E3FA - 47                    - inc edi
//  EXE+4E3FB - 83 C6 0C              - add esi,0C { 12 }
//  EXE+4E3FE - 4A                    - dec edx
//  EXE+4E3FF - 89 74 24 1C           - mov [esp+1C],esi
//  EXE+4E403 - 89 54 24 14           - mov [esp+14],edx
//  EXE+4E407 - 0F85 7BFFFFFF         - jne EXE+4E388
//  EXE+4E40D - 33 F6                 - xor esi,esi
//  EXE+4E40F - BF 04000000           - mov edi,00000004 { 4 }
//  EXE+4E414 - 56                    - push esi
//  EXE+4E415 - 6A 01                 - push 01 { 1 }
//  EXE+4E417 - E8 E405FFFF           - call EXE+3EA00
//  EXE+4E41C - 83 C4 08              - add esp,08 { 8 }
//  EXE+4E41F - 46                    - inc esi
//  EXE+4E420 - 4F                    - dec edi
//  EXE+4E421 - 75 F1                 - jne EXE+4E414
//  EXE+4E423 - 68 A064E300           - push EXE+A364A0 { (128195738) }
//  EXE+4E428 - E8 13000000           - call EXE+4E440
//  EXE+4E42D - 83 C4 04              - add esp,04 { 4 }
//  EXE+4E430 - A3 A064E300           - mov [EXE+A364A0],eax { (128195738) }
//  EXE+4E435 - 5F                    - pop edi
//  EXE+4E436 - 5E                    - pop esi
//  EXE+4E437 - 5D                    - pop ebp
//  EXE+4E438 - 5B                    - pop ebx
//  EXE+4E439 - 83 C4 08              - add esp,08 { 8 }
//  EXE+4E43C - C3                    - ret 

