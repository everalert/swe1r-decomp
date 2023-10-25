void CopySAVtoTGFD(int32_t slot) {
    static void* base_tgfd = 0xE364B4;
    static void* base_sav =  0xE35A60;
    int32_t offset = slot * 80;
    memcpy(base_tgfd+offset, base_sav+offset, 0x50u);
}

//	EXE+4E530 - 8B 44 24 08           - mov eax,[esp+08]
//	EXE+4E534 - 56                    - push esi
//	EXE+4E535 - 57                    - push edi
//	EXE+4E536 - B9 14000000           - mov ecx,00000014 { 20 }
//	EXE+4E53B - 8D 34 80              - lea esi,[eax+eax*4]
//	EXE+4E53E - 8B 44 24 0C           - mov eax,[esp+0C]
//	EXE+4E542 - C1 E6 04              - shl esi,04 { 4 }
//	EXE+4E545 - 8D 3C 80              - lea edi,[eax+eax*4]
//	EXE+4E548 - 81 C6 605AE300        - add esi,EXE+A35A60  // slot start
//	EXE+4E54E - C1 E7 04              - shl edi,04 { 4 }
//	EXE+4E551 - 81 C7 B464E300        - add edi,EXE+A364B4  // slot start
//	EXE+4E557 - F3 A5                 - repe movsd 
//	EXE+4E559 - 5F                    - pop edi
//	EXE+4E55A - 5E                    - pop esi
//	EXE+4E55B - C3                    - ret 
//	EXE+4E55C - 90                    - nop 
//	EXE+4E55D - 90                    - nop 
//	EXE+4E55E - 90                    - nop 
//	EXE+4E55F - 90                    - nop 
