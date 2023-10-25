void GenerateDefaultDataSAV(bool use_tgfd, int8_t slot) {
    static int32_t starting_truguts =   0x190; // 400
    static uint32_t starting_vehicles = 0x22E01;
    static void* addr_tgfd = 0x00E364B4;
    static void* addr_sav =  0x00E35A60;

    // TODO: cast void* to Profile struct and ref children instead of doing manual offsets
    // TODO: final pass on the logic accuracy

    // NOTE: pretty sure all the redundant return value setting was just because the
    // compiler wanted to use eax register for output but then decided to use eax for
    // the upgrade loop halfway in, but still felt the need to have eax blank even
    // though it's a void function lol
    
    if (use_tgfd > 1)
        return;

    uint32_t offset = 80 * slot;
    void* addr = use_tgfd ? addr_tgfd : addr_sav;

    memset(addr_tgfd+offset, 0, 0x20u);        // filename not filling with As?
    *(addr+offset+0x20) = 0;       // unknown
    *(addr+offset+0x21) = 1;       // unknown
    *(addr+offset+0x22) = slot;    // file slot number
    *(addr+offset+0x23) = 0;       // unknown; used as switch expression in 46BEC0
    *(addr+offset+0x24) = 0;       // selected vehicle
    *(addr+offset+0x25) = 1;       // AMC track unlocks
    *(addr+offset+0x26) = 1;       // SPC track unlocks
    *(addr+offset+0x27) = 1;       // GAL track unlocks
    *(addr+offset+0x28) = 0;       // INV track unlocks
                                   // E364DD = nothing apparently; just for alignment?
    *(addr+offset+0x2A) = 0;       // AMC-SPC placements; 2x u16, prob just optimized to 1x u32
    *(addr+offset+0x2E) = 0;       // GAL-INV placements; 2x u16, prob just optimized to 1x u32
                                   // E364E6-7 = nothing apparently; just for alignment?
    *(addr+offset+0x34) = starting_vehicles;    // u32
    *(addr+offset+0x38) = starting_truguts;     // u32
    *(addr+offset+0x3C) = 0;       // unknown; u32
    *(addr+offset+0x40) = 1;       // pit droids
    for (int i = 0; i < 7; ++i) {
        *(addr+offset+0x41+i) = 0x00; // upgrade levels
        *(addr+offset+0x48+i) = 0xFF; // upgrade healths
    }
    *(addr+offset+0x4F) = 0;          // unknown; u8
}

//	EXE+3EA00 - 8B 44 24 04           - mov eax,[esp+04]
//	EXE+3EA04 - 53                    - push ebx
//	EXE+3EA05 - 33 DB                 - xor ebx,ebx
//	EXE+3EA07 - 57                    - push edi
//	EXE+3EA08 - 2B C3                 - sub eax,ebx
//	EXE+3EA0A - 0F84 A4000000         - je EXE+3EAB4
//	EXE+3EA10 - 48                    - dec eax
//	EXE+3EA11 - 0F85 33010000         - jne EXE+3EB4A
//	EXE+3EA17 - 8B 44 24 10           - mov eax,[esp+10]        // load slot no.
//	EXE+3EA1B - B1 01                 - mov cl,01 { 1 }         // used for setting bytes to 1
//	EXE+3EA1D - 8D 14 80              - lea edx,[eax+eax*4]     // 0, 5, 10, 15
//	EXE+3EA20 - C1 E2 04              - shl edx,04 { 4 }        // 5<<4=80, 10<<4=160, etc.
//	EXE+3EA23 - 88 9A D464E300        - mov [edx+EXE+A364D4],bl
//	EXE+3EA29 - 88 82 D664E300        - mov [edx+EXE+A364D6],al
//	EXE+3EA2F - C7 82 EC64E300 90010000 - mov [edx+EXE+A364EC],00000190 { 400 }
//	EXE+3EA39 - 88 8A F464E300        - mov [edx+EXE+A364F4],cl
//	EXE+3EA3F - 88 9A D764E300        - mov [edx+EXE+A364D7],bl
//	EXE+3EA45 - C7 82 E864E300 012E0200 - mov [edx+EXE+A364E8],00022E01 { 142849 }
//	EXE+3EA4F - 89 9A F064E300        - mov [edx+EXE+A364F0],ebx
//	EXE+3EA55 - 88 8A D564E300        - mov [edx+EXE+A364D5],cl
//	EXE+3EA5B - 33 C0                 - xor eax,eax
//	EXE+3EA5D - 88 9A D864E300        - mov [edx+EXE+A364D8],bl
//	EXE+3EA63 - 89 82 DE64E300        - mov [edx+EXE+A364DE],eax
//	EXE+3EA69 - 89 82 E264E300        - mov [edx+EXE+A364E2],eax
//	EXE+3EA6F - 88 8A D964E300        - mov [edx+EXE+A364D9],cl
//	EXE+3EA75 - 88 8A DA64E300        - mov [edx+EXE+A364DA],cl
//	EXE+3EA7B - 88 8A DB64E300        - mov [edx+EXE+A364DB],cl
//	EXE+3EA81 - 88 9A DC64E300        - mov [edx+EXE+A364DC],bl
//	EXE+3EA87 - 88 9C 10 F564E300     - mov [eax+edx+EXE+A364F5],bl
//	EXE+3EA8E - C6 84 10 FC64E300 FF  - mov byte ptr [eax+edx+EXE+A364FC],-01 { 255 }
//	EXE+3EA96 - 40                    - inc eax
//	EXE+3EA97 - 83 F8 07              - cmp eax,07 { 7 }
//	EXE+3EA9A - 7C EB                 - jl EXE+3EA87
//	EXE+3EA9C - 8D BA B464E300        - lea edi,[edx+EXE+A364B4]    // start at filename offset
//	EXE+3EAA2 - B9 08000000           - mov ecx,00000008 { 8 }
//	EXE+3EAA7 - 33 C0                 - xor eax,eax
//	EXE+3EAA9 - F3 AB                 - repe stosd  // write eax, ecx(8) times (=32B) = memset 
//	EXE+3EAAB - 88 9A 0365E300        - mov [edx+EXE+A36503],bl
//	EXE+3EAB1 - 5F                    - pop edi
//	EXE+3EAB2 - 5B                    - pop ebx
//	EXE+3EAB3 - C3                    - ret 
//	EXE+3EAB4 - 8B 54 24 10           - mov edx,[esp+10]
//	EXE+3EAB8 - B1 01                 - mov cl,01 { 1 }
//	EXE+3EABA - 8D 04 92              - lea eax,[edx+edx*4]
//	EXE+3EABD - C1 E0 04              - shl eax,04 { 4 }
//	EXE+3EAC0 - 88 98 805AE300        - mov [eax+EXE+A35A80],bl
//	EXE+3EAC6 - C7 80 985AE300 90010000 - mov [eax+EXE+A35A98],00000190 { 400 }
//	EXE+3EAD0 - 88 88 A05AE300        - mov [eax+EXE+A35AA0],cl
//	EXE+3EAD6 - 88 98 835AE300        - mov [eax+EXE+A35A83],bl
//	EXE+3EADC - C7 80 945AE300 012E0200 - mov [eax+EXE+A35A94],00022E01 { 142849 }
//	EXE+3EAE6 - 89 98 9C5AE300        - mov [eax+EXE+A35A9C],ebx
//	EXE+3EAEC - 88 88 815AE300        - mov [eax+EXE+A35A81],cl
//	EXE+3EAF2 - 88 98 845AE300        - mov [eax+EXE+A35A84],bl
//	EXE+3EAF8 - 88 90 825AE300        - mov [eax+EXE+A35A82],dl
//	EXE+3EAFE - 33 D2                 - xor edx,edx
//	EXE+3EB00 - 89 90 8A5AE300        - mov [eax+EXE+A35A8A],edx
//	EXE+3EB06 - 89 90 8E5AE300        - mov [eax+EXE+A35A8E],edx
//	EXE+3EB0C - 88 88 855AE300        - mov [eax+EXE+A35A85],cl
//	EXE+3EB12 - 88 88 865AE300        - mov [eax+EXE+A35A86],cl
//	EXE+3EB18 - 88 88 875AE300        - mov [eax+EXE+A35A87],cl
//	EXE+3EB1E - 88 98 885AE300        - mov [eax+EXE+A35A88],bl
//	EXE+3EB24 - 33 C9                 - xor ecx,ecx
//	EXE+3EB26 - 88 9C 01 A15AE300     - mov [ecx+eax+EXE+A35AA1],bl
//	EXE+3EB2D - C6 84 01 A85AE300 FF  - mov byte ptr [ecx+eax+EXE+A35AA8],-01 { 255 }
//	EXE+3EB35 - 41                    - inc ecx
//	EXE+3EB36 - 83 F9 07              - cmp ecx,07 { 7 }
//	EXE+3EB39 - 7C EB                 - jl EXE+3EB26
//	EXE+3EB3B - 8D B8 605AE300        - lea edi,[eax+EXE+A35A60]
//	EXE+3EB41 - B9 08000000           - mov ecx,00000008 { 8 }
//	EXE+3EB46 - 33 C0                 - xor eax,eax
//	EXE+3EB48 - F3 AB                 - repe stosd 
//	EXE+3EB4A - 5F                    - pop edi
//	EXE+3EB4B - 5B                    - pop ebx
//	EXE+3EB4C - C3                    - ret 

