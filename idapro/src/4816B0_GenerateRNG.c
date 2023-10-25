int32_t GenerateRNG() {
    static bool initialized = false;
    static int32_t rng;
    if (!initialized) {
        initialized = true;
        rng = 41222736;
    }
    rng = rng * 1103515245 + 12345;
    if (rng == 0x80000000)
        return 0;
    return rng < 0 ? -rng : rng;
}

//	EXE+816B0 - A0 80CB5000           - mov al,[EXE+10CB80] { (1) }
//	EXE+816B5 - 84 C0                 - test al,al
//	EXE+816B7 - 75 0E                 - jne EXE+816C7
//	EXE+816B9 - B8 50027502           - mov eax,02750250 { 41222736 }
//	EXE+816BE - C6 05 80CB5000 01     - mov byte ptr [EXE+10CB80],01 { (1),1 }
//	EXE+816C5 - EB 05                 - jmp EXE+816CC
//	EXE+816C7 - A1 7CCB5000           - mov eax,[EXE+10CB7C]
//	EXE+816CC - 69 C0 6D4EC641        - imul eax,eax,41C64E6D { 1103515245 }
//	EXE+816D2 - 05 39300000           - add eax,00003039 { 12345 }
//	EXE+816D7 - 3D 00000080           - cmp eax,80000000 { -2147483648 }
//	EXE+816DC - A3 7CCB5000           - mov [EXE+10CB7C],eax
//	EXE+816E1 - 75 03                 - jne EXE+816E6
//	EXE+816E3 - 33 C0                 - xor eax,eax
//	EXE+816E5 - C3                    - ret 
//	EXE+816E6 - 85 C0                 - test eax,eax
//	EXE+816E8 - 7D 02                 - jnl EXE+816EC
//	EXE+816EA - F7 D8                 - neg eax
//	EXE+816EC - C3                    - ret 

