float SinCos2Deg(float sin, float cos) {
    // actually not sure the function does this anymore, putting off for now
}


//	EXE+2F560 - D9 44 24 08           - fld dword ptr [esp+08]
//	EXE+2F564 - D8 1D A8C64A00        - fcomp dword ptr [(EXE+AC6A8)] { (0.00) }
//	EXE+2F56A - 83 EC 08              - sub esp,08 { 8 }
//	EXE+2F56D - DFE0                  - fnstsw ax
//	EXE+2F56F - F6 C4 01              - test ah,01 { 1 }
//	EXE+2F572 - 74 1C                 - je (EXE+2F590)
//	EXE+2F574 - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+2F578 - D8 1D ACC64A00        - fcomp dword ptr [(EXE+AC6AC)] { (0.00) }
//	EXE+2F57E - DFE0                  - fnstsw ax
//	EXE+2F580 - F6 C4 01              - test ah,01 { 1 }
//	EXE+2F583 - 75 0B                 - jne (EXE+2F590)
//	EXE+2F585 - D9 05 64C64A00        - fld dword ptr [(EXE+AC664)] { (90.00) }
//	EXE+2F58B - E9 13010000           - jmp (EXE+2F6A3)
//	EXE+2F590 - D9 44 24 0C           - fld dword ptr [esp+0C]
//	EXE+2F594 - D8 1D A8C64A00        - fcomp dword ptr [(EXE+AC6A8)] { (0.00) }
//	EXE+2F59A - DFE0                  - fnstsw ax
//	EXE+2F59C - F6 C4 01              - test ah,01 { 1 }
//	EXE+2F59F - 74 1C                 - je (EXE+2F5BD)
//	EXE+2F5A1 - D9 44 24 0C           - fld dword ptr [esp+0C]
//	EXE+2F5A5 - D8 1D ACC64A00        - fcomp dword ptr [(EXE+AC6AC)] { (0.00) }
//	EXE+2F5AB - DFE0                  - fnstsw ax
//	EXE+2F5AD - F6 C4 01              - test ah,01 { 1 }
//	EXE+2F5B0 - 75 0B                 - jne (EXE+2F5BD)
//	EXE+2F5B2 - D9 05 78C64A00        - fld dword ptr [(EXE+AC678)] { (0.00) }
//	EXE+2F5B8 - E9 E6000000           - jmp (EXE+2F6A3)
//	EXE+2F5BD - D9 44 24 0C           - fld dword ptr [esp+0C]
//	EXE+2F5C1 - D8 1D 78C64A00        - fcomp dword ptr [(EXE+AC678)] { (0.01) }
//	EXE+2F5C7 - D9 44 24 0C           - fld dword ptr [esp+0C]
//	EXE+2F5CB - DFE0                  - fnstsw ax
//	EXE+2F5CD - F6 C4 01              - test ah,01 { 1 }
//	EXE+2F5D0 - 74 02                 - je (EXE+2F5D4)
//	EXE+2F5D2 - D9E0                  - fchs 
//	EXE+2F5D4 - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+2F5D8 - D8 1D 78C64A00        - fcomp dword ptr [(EXE+AC678)] { (0.01) }
//	EXE+2F5DE - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+2F5E2 - DFE0                  - fnstsw ax
//	EXE+2F5E4 - F6 C4 01              - test ah,01 { 1 }
//	EXE+2F5E7 - 74 02                 - je (EXE+2F5EB)
//	EXE+2F5E9 - D9E0                  - fchs 
//	EXE+2F5EB - D9C1                  - fld st(1)
//	EXE+2F5ED - D8D9                  - fcomp st(0),st(1)
//	EXE+2F5EF - DFE0                  - fnstsw ax
//	EXE+2F5F1 - F6 C4 41              - test ah,41 { 65 }
//	EXE+2F5F4 - 75 07                 - jne (EXE+2F5FD)
//	EXE+2F5F6 - B9 01000000           - mov ecx,00000001 { 1 }
//	EXE+2F5FB - EB 04                 - jmp (EXE+2F601)
//	EXE+2F5FD - 33 C9                 - xor ecx,ecx
//	EXE+2F5FF - D9C9                  - fxch st(1)
//	EXE+2F601 - D8F1                  - fdiv st(0),st(1)
//	EXE+2F603 - D9 5C 24 00           - fstp dword ptr [esp+00]
//	EXE+2F607 - DDD8                  - fstp st(0)
//	EXE+2F609 - D9 44 24 00           - fld dword ptr [esp+00]
//	EXE+2F60D - D8 1D A8C64A00        - fcomp dword ptr [(EXE+AC6A8)] { (0.00) }
//	EXE+2F613 - DFE0                  - fnstsw ax
//	EXE+2F615 - F6 C4 01              - test ah,01 { 1 }
//	EXE+2F618 - 74 19                 - je (EXE+2F633)
//	EXE+2F61A - D9 44 24 00           - fld dword ptr [esp+00]
//	EXE+2F61E - D8 1D ACC64A00        - fcomp dword ptr [(EXE+AC6AC)] { (0.00) }
//	EXE+2F624 - DFE0                  - fnstsw ax
//	EXE+2F626 - F6 C4 01              - test ah,01 { 1 }
//	EXE+2F629 - 75 08                 - jne (EXE+2F633)
//	EXE+2F62B - D9 05 78C64A00        - fld dword ptr [(EXE+AC678)] { (0.00) }
//	EXE+2F631 - EB 66                 - jmp (EXE+2F699)
//	EXE+2F633 - D9 44 24 00           - fld dword ptr [esp+00]
//	EXE+2F637 - D8 4C 24 00           - fmul dword ptr [esp+00]
//	EXE+2F63B - D9 54 24 04           - fst dword ptr [esp+04]
//	EXE+2F63F - D8 4C 24 00           - fmul dword ptr [esp+00]
//	EXE+2F643 - D9C0                  - fld st(0)
//	EXE+2F645 - D8 4C 24 04           - fmul dword ptr [esp+04]
//	EXE+2F649 - D9C9                  - fxch st(1)
//	EXE+2F64B - D8 0D B0C64A00        - fmul dword ptr [(EXE+AC6B0)] { (3EAAAAAB) }
//	EXE+2F651 - D9C1                  - fld st(1)
//	EXE+2F653 - D8 4C 24 04           - fmul dword ptr [esp+04]
//	EXE+2F657 - D9C9                  - fxch st(1)
//	EXE+2F659 - D8 6C 24 00           - fsubr dword ptr [esp+00]
//	EXE+2F65D - D9CA                  - fxch st(2)
//	EXE+2F65F - D8 0D B4C64A00        - fmul dword ptr [(EXE+AC6B4)] { (-0.20) }
//	EXE+2F665 - D9C9                  - fxch st(1)
//	EXE+2F667 - D9 54 24 00           - fst dword ptr [esp+00]
//	EXE+2F66B - D9 44 24 00           - fld dword ptr [esp+00]
//	EXE+2F66F - D9C9                  - fxch st(1)
//	EXE+2F671 - D8 4C 24 04           - fmul dword ptr [esp+04]
//	EXE+2F675 - D9CA                  - fxch st(2)
//	EXE+2F677 - DEEB                  - fsubp st(3),st(0)
//	EXE+2F679 - D8 0D B8C64A00        - fmul dword ptr [(EXE+AC6B8)] { (3E124925) }
//	EXE+2F67F - D9C9                  - fxch st(1)
//	EXE+2F681 - D8 0D BCC64A00        - fmul dword ptr [(EXE+AC6BC)] { (-0.06) }
//	EXE+2F687 - D9C9                  - fxch st(1)
//	EXE+2F689 - DEEA                  - fsubp st(2),st(0)
//	EXE+2F68B - DEE9                  - fsubp st(1),st(0)
//	EXE+2F68D - D8 0D 98C64A00        - fmul dword ptr [(EXE+AC698)] { (180.00) }
//	EXE+2F693 - DC 0D A0C64A00        - fmul qword ptr [(EXE+AC6A0)] { (0.32) }
//	EXE+2F699 - 85 C9                 - test ecx,ecx
//	EXE+2F69B - 74 06                 - je (EXE+2F6A3)
//	EXE+2F69D - D8 2D 64C64A00        - fsubr dword ptr [(EXE+AC664)] { (90.00) }
//	EXE+2F6A3 - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+2F6A7 - D8 1D ACC64A00        - fcomp dword ptr [(EXE+AC6AC)] { (0.00) }
//	EXE+2F6AD - DFE0                  - fnstsw ax
//	EXE+2F6AF - F6 C4 01              - test ah,01 { 1 }
//	EXE+2F6B2 - 74 06                 - je (EXE+2F6BA)
//	EXE+2F6B4 - D8 2D 98C64A00        - fsubr dword ptr [(EXE+AC698)] { (180.00) }
//	EXE+2F6BA - D9 44 24 0C           - fld dword ptr [esp+0C]
//	EXE+2F6BE - D8 1D ACC64A00        - fcomp dword ptr [(EXE+AC6AC)] { (0.00) }
//	EXE+2F6C4 - DFE0                  - fnstsw ax
//	EXE+2F6C6 - F6 C4 01              - test ah,01 { 1 }
//	EXE+2F6C9 - 74 02                 - je (EXE+2F6CD)
//	EXE+2F6CB - D9E0                  - fchs 
//	EXE+2F6CD - 83 C4 08              - add esp,08 { 8 }
//	EXE+2F6D0 - C3                    - ret 
//	EXE+2F6D1 - 90                    - nop 
//	EXE+2F6D2 - 90                    - nop 
//	EXE+2F6D3 - 90                    - nop 
//	EXE+2F6D4 - 90                    - nop 
//	EXE+2F6D5 - 90                    - nop 
//	EXE+2F6D6 - 90                    - nop 
//	EXE+2F6D7 - 90                    - nop 
//	EXE+2F6D8 - 90                    - nop 
//	EXE+2F6D9 - 90                    - nop 
//	EXE+2F6DA - 90                    - nop 
//	EXE+2F6DB - 90                    - nop 
//	EXE+2F6DC - 90                    - nop 
//	EXE+2F6DD - 90                    - nop 
//	EXE+2F6DE - 90                    - nop 
//	EXE+2F6DF - 90                    - nop 

