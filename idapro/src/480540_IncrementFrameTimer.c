uint32_t IncrementFrameTimer() {
    static uint32_t frametotal = 0; // 0xE22A30
    static double timetotal = 0.0;  // 0xE22A38
    static double dt_d;             // 0xE22A40
    static double dt_raw_d;         // 0xE22A48
    static float dt_f;              // 0xE22A50
    static uint32_t timestamp;      // 0x50BC60
                                    // 0x50BC64 = is tabbed in flag?
                                    // 0x50BC68 = ?
                                    // 0x50BC70 = ?
    // can't change these with CE because the values are not stored as constants
    static double dt_max = (double)0x3FB99999A0000000; // 0.100000001490116120
    static double dt_min = (double)0x3F60624DE0000000; // 0.002000000094994903

    // TODO: restructure this to be more in line with assembly 
    if (dword_50CB68) { // what is this?
        dt_d = dbl_50CB70;
    } else {
        uint32_t time_current = GetCurrentTimestamp(); // EXE+8C490 
        uint32_t time_delta = time_current - timestamp;
        dt_d = time_delta * 0.001;
        dt_raw_d = dt_d;
        if (dt_d > dt_max) // 10fps
            dt_d = dt_max;
        timestamp = time_current;
    }

    if (dword_50CB64) // check if tabbed in?
        dt_d = 0.0;
    if (dt_d <= 0.0)
        dt_d = dt_min; // 500fps
    dt_f = dt_d;
    timetotal = timetotal + dt_d;
    ++frametotal;
    return frametotal;
}



//	EXE+80540 - A1 68CB5000           - mov eax,[EXE+10CB68] 
//	EXE+80545 - 83 EC 08              - sub esp,08 
//	EXE+80548 - 85 C0                 - test eax,eax
//	EXE+8054A - 75 70                 - jne EXE+805BC
//	EXE+8054C - E8 3FBF0000           - call EXE+8C490 
//	EXE+80551 - 8B 15 60CB5000        - mov edx,[EXE+10CB60]
//	EXE+80557 - 8B C8                 - mov ecx,eax
//	EXE+80559 - 2B C2                 - sub eax,edx
//	EXE+8055B - C7 44 24 04 00000000  - mov [esp+04],00000000
//	EXE+80563 - 89 44 24 00           - mov [esp+00],eax
//	EXE+80567 - DF 6C 24 00           - fild qword ptr [esp+00]
//	EXE+8056B - DC 0D 80DF4A00        - fmul qword ptr [EXE+ADF80]
//	EXE+80571 - DD 1D 402AE200        - fstp qword ptr [EXE+A22A40]
//	EXE+80577 - DD 05 402AE200        - fld qword ptr [EXE+A22A40]
//	EXE+8057D - DC 1D 88DF4A00        - fcomp qword ptr [EXE+ADF88]
//	EXE+80583 - A1 442AE200           - mov eax,[EXE+A22A44]
//	EXE+80588 - 8B 15 402AE200        - mov edx,[EXE+A22A40]
//	EXE+8058E - A3 4C2AE200           - mov [EXE+A22A4C],eax
//	EXE+80593 - 89 15 482AE200        - mov [EXE+A22A48],edx
//	EXE+80599 - DFE0                  - fnstsw ax
//	EXE+8059B - F6 C4 41              - test ah,41 
//	EXE+8059E - 75 14                 - jne EXE+805B4
//	EXE+805A0 - C7 05 402AE200 000000A0 - mov [EXE+A22A40],A0000000 
//	EXE+805AA - C7 05 442AE200 9999B93F - mov [EXE+A22A44],3FB99999 
//	EXE+805B4 - 89 0D 60CB5000        - mov [EXE+10CB60],ecx 
//	EXE+805BA - EB 18                 - jmp EXE+805D4
//	EXE+805BC - 8B 0D 70CB5000        - mov ecx,[EXE+10CB70] 
//	EXE+805C2 - 8B 15 74CB5000        - mov edx,[EXE+10CB74] 
//	EXE+805C8 - 89 0D 402AE200        - mov [EXE+A22A40],ecx 
//	EXE+805CE - 89 15 442AE200        - mov [EXE+A22A44],edx 
//	EXE+805D4 - A1 64CB5000           - mov eax,[EXE+10CB64] 
//	EXE+805D9 - 85 C0                 - test eax,eax
//	EXE+805DB - 74 14                 - je EXE+805F1
//	EXE+805DD - C7 05 402AE200 00000000 - mov [EXE+A22A40],00000000 
//	EXE+805E7 - C7 05 442AE200 00000000 - mov [EXE+A22A44],00000000 
//	EXE+805F1 - DD 05 402AE200        - fld qword ptr [EXE+A22A40] 
//	EXE+805F7 - DC 1D 70DF4A00        - fcomp qword ptr [EXE+ADF70] 
//	EXE+805FD - DFE0                  - fnstsw ax
//	EXE+805FF - F6 C4 41              - test ah,41 { 65 }
//	EXE+80602 - 74 14                 - je EXE+80618
//	EXE+80604 - C7 05 402AE200 000000E0 - mov [EXE+A22A40],E0000000 
//	EXE+8060E - C7 05 442AE200 4D62603F - mov [EXE+A22A44],3F60624D 
//	EXE+80618 - DD 05 382AE200        - fld qword ptr [EXE+A22A38] 
//	EXE+8061E - DC 05 402AE200        - fadd qword ptr [EXE+A22A40] 
//	EXE+80624 - DD 05 402AE200        - fld qword ptr [EXE+A22A40] 
//	EXE+8062A - A1 302AE200           - mov eax,[EXE+A22A30] 
//	EXE+8062F - D9 1D 502AE200        - fstp dword ptr [EXE+A22A50] 
//	EXE+80635 - 40                    - inc eax
//	EXE+80636 - DD 1D 382AE200        - fstp qword ptr [EXE+A22A38] 
//	EXE+8063C - A3 302AE200           - mov [EXE+A22A30],eax 
//	EXE+80641 - 83 C4 08              - add esp,08 
//	EXE+80644 - C3                    - ret 
