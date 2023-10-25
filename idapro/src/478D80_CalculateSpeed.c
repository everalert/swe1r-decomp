void CalculateSpeed() {
    // stuff
}

//	EXE+78D80 - 83 EC 28              - sub esp,28 { 40 }
//	EXE+78D83 - 53                    - push ebx
//	EXE+78D84 - 55                    - push ebp
//	EXE+78D85 - 56                    - push esi
//	EXE+78D86 - 8B 74 24 38           - mov esi,[esp+38]
//	EXE+78D8A - 57                    - push edi
//	EXE+78D8B - 56                    - push esi
//	EXE+78D8C - E8 4FF6FFFF           - call EXE+783E0
//	EXE+78D91 - D9 5C 24 14           - fstp dword ptr [esp+14]
//	EXE+78D95 - 83 C4 04              - add esp,04 { 4 }
//	EXE+78D98 - 56                    - push esi
//	EXE+78D99 - E8 52FAFFFF           - call EXE+787F0
//	EXE+78D9E - D8 44 24 14           - fadd dword ptr [esp+14]
//	EXE+78DA2 - 8B 4C 24 4C           - mov ecx,[esp+4C]
//	EXE+78DA6 - 83 C4 04              - add esp,04 { 4 }
//	EXE+78DA9 - 8D 44 24 14           - lea eax,[esp+14]
//	EXE+78DAD - 50                    - push eax
//	EXE+78DAE - 51                    - push ecx
//	EXE+78DAF - D9 5C 24 18           - fstp dword ptr [esp+18]
//	EXE+78DB3 - 8B 54 24 18           - mov edx,[esp+18]
//	EXE+78DB7 - 52                    - push edx
//	EXE+78DB8 - 56                    - push esi
//	EXE+78DB9 - E8 B2FCFFFF           - call EXE+78A70
//	EXE+78DBE - 8B 46 64              - mov eax,[esi+64]
//	EXE+78DC1 - 83 C4 10              - add esp,10 { 16 }
//	EXE+78DC4 - F6 C4 04              - test ah,04 { 4 }
//	EXE+78DC7 - 75 66                 - jne EXE+78E2F
//	EXE+78DC9 - F7 46 60 00000002     - test [esi+60],02000000 { 33554432 }
//	EXE+78DD0 - 75 5D                 - jne EXE+78E2F
//	EXE+78DD2 - D9 44 24 1C           - fld dword ptr [esp+1C]
//	EXE+78DD6 - D8 1D 48DC4A00        - fcomp dword ptr [EXE+ADC48] { (0) }
//	EXE+78DDC - DFE0                  - fnstsw ax
//	EXE+78DDE - F6 C4 41              - test ah,41 { 65 }
//	EXE+78DE1 - 75 4C                 - jne EXE+78E2F
//	EXE+78DE3 - D9 44 24 18           - fld dword ptr [esp+18]
//	EXE+78DE7 - D9 44 24 14           - fld dword ptr [esp+14]
//	EXE+78DEB - D8 4C 24 14           - fmul dword ptr [esp+14]
//	EXE+78DEF - D9 44 24 1C           - fld dword ptr [esp+1C]
//	EXE+78DF3 - D9CA                  - fxch st(2)
//	EXE+78DF5 - D8 4C 24 18           - fmul dword ptr [esp+18]
//	EXE+78DF9 - D9CA                  - fxch st(2)
//	EXE+78DFB - D8 4C 24 1C           - fmul dword ptr [esp+1C]
//	EXE+78DFF - D9CA                  - fxch st(2)
//	EXE+78E01 - DEC1                  - faddp 
//	EXE+78E03 - D9 54 24 3C           - fst dword ptr [esp+3C]
//	EXE+78E07 - D8 0D 78DD4A00        - fmul dword ptr [EXE+ADD78] { (0.14) }
//	EXE+78E0D - D9C9                  - fxch st(1)
//	EXE+78E0F - DED9                  - fcompp 
//	EXE+78E11 - DFE0                  - fnstsw ax
//	EXE+78E13 - F6 C4 41              - test ah,41 { 65 }
//	EXE+78E16 - 75 17                 - jne EXE+78E2F
//	EXE+78E18 - 8B 44 24 3C           - mov eax,[esp+3C]
//	EXE+78E1C - 50                    - push eax
//	EXE+78E1D - E8 4E780000           - call EXE+80670
//	EXE+78E22 - D8 0D 08DD4A00        - fmul dword ptr [EXE+ADD08] { (0.20) }
//	EXE+78E28 - 83 C4 04              - add esp,04 { 4 }
//	EXE+78E2B - D9 5C 24 1C           - fstp dword ptr [esp+1C]
//	EXE+78E2F - DD 05 402AE200        - fld qword ptr [EXE+A22A40] { (0.04) }
//	EXE+78E35 - D9 44 24 14           - fld dword ptr [esp+14]
//	EXE+78E39 - D9 44 24 18           - fld dword ptr [esp+18]
//	EXE+78E3D - D9 44 24 1C           - fld dword ptr [esp+1C]
//	EXE+78E41 - D9CA                  - fxch st(2)
//	EXE+78E43 - D8 86 DC010000        - fadd dword ptr [esi+000001DC]
//	EXE+78E49 - D9C9                  - fxch st(1)
//	EXE+78E4B - D8 86 E0010000        - fadd dword ptr [esi+000001E0]
//	EXE+78E51 - D9CA                  - fxch st(2)
//	EXE+78E53 - D8 86 E4010000        - fadd dword ptr [esi+000001E4]
//	EXE+78E59 - D9CB                  - fxch st(3)
//	EXE+78E5B - 51                    - push ecx
//	EXE+78E5C - D9 1C 24              - fstp dword ptr [esp]
//	EXE+78E5F - 68 00008040           - push 40800000 { 4.00 }
//	EXE+78E64 - D9 5C 24 1C           - fstp dword ptr [esp+1C]
//	EXE+78E68 - D9 5C 24 20           - fstp dword ptr [esp+20]
//	EXE+78E6C - D9 5C 24 24           - fstp dword ptr [esp+24]
//	EXE+78E70 - E8 DB770000           - call EXE+80650
//	EXE+78E75 - D8 8E D0010000        - fmul dword ptr [esi+000001D0]
//	EXE+78E7B - 83 C4 04              - add esp,04 { 4 }
//	EXE+78E7E - D9 9E D0010000        - fstp dword ptr [esi+000001D0]
//	EXE+78E84 - DD 05 402AE200        - fld qword ptr [EXE+A22A40] { (0.04) }
//	EXE+78E8A - D9 1C 24              - fstp dword ptr [esp]
//	EXE+78E8D - 68 00008040           - push 40800000 { 4.00 }
//	EXE+78E92 - E8 B9770000           - call EXE+80650
//	EXE+78E97 - D8 8E D4010000        - fmul dword ptr [esi+000001D4]
//	EXE+78E9D - 83 C4 04              - add esp,04 { 4 }
//	EXE+78EA0 - D9 9E D4010000        - fstp dword ptr [esi+000001D4]
//	EXE+78EA6 - DD 05 402AE200        - fld qword ptr [EXE+A22A40] { (0.04) }
//	EXE+78EAC - D9 1C 24              - fstp dword ptr [esp]
//	EXE+78EAF - 68 00008040           - push 40800000 { 4.00 }
//	EXE+78EB4 - E8 97770000           - call EXE+80650
//	EXE+78EB9 - D8 8E D8010000        - fmul dword ptr [esi+000001D8]
//	EXE+78EBF - 83 C4 04              - add esp,04 { 4 }
//	EXE+78EC2 - D9 9E D8010000        - fstp dword ptr [esi+000001D8]
//	EXE+78EC8 - DD 05 402AE200        - fld qword ptr [EXE+A22A40] { (0.04) }
//	EXE+78ECE - D9 1C 24              - fstp dword ptr [esp]
//	EXE+78ED1 - 68 00008040           - push 40800000 { 4.00 }
//	EXE+78ED6 - E8 75770000           - call EXE+80650
//	EXE+78EDB - D8 8E DC010000        - fmul dword ptr [esi+000001DC]
//	EXE+78EE1 - 83 C4 04              - add esp,04 { 4 }
//	EXE+78EE4 - D9 9E DC010000        - fstp dword ptr [esi+000001DC]
//	EXE+78EEA - DD 05 402AE200        - fld qword ptr [EXE+A22A40] { (0.04) }
//	EXE+78EF0 - D9 1C 24              - fstp dword ptr [esp]
//	EXE+78EF3 - 68 00008040           - push 40800000 { 4.00 }
//	EXE+78EF8 - E8 53770000           - call EXE+80650
//	EXE+78EFD - D8 8E E0010000        - fmul dword ptr [esi+000001E0]
//	EXE+78F03 - 83 C4 04              - add esp,04 { 4 }
//	EXE+78F06 - D9 9E E0010000        - fstp dword ptr [esi+000001E0]
//	EXE+78F0C - DD 05 402AE200        - fld qword ptr [EXE+A22A40] { (0.04) }
//	EXE+78F12 - D9 1C 24              - fstp dword ptr [esp]
//	EXE+78F15 - 68 00008040           - push 40800000 { 4.00 }
//	EXE+78F1A - E8 31770000           - call EXE+80650
//	EXE+78F1F - 8B 4E 60              - mov ecx,[esi+60]
//	EXE+78F22 - 83 C4 08              - add esp,08 { 8 }
//	EXE+78F25 - D8 8E E4010000        - fmul dword ptr [esi+000001E4]
//	EXE+78F2B - F6 C5 50              - test ch,50 { 80 }
//	EXE+78F2E - D9 9E E4010000        - fstp dword ptr [esi+000001E4]
//	EXE+78F34 - 0F85 43010000         - jne EXE+7907D
//	EXE+78F3A - D9 86 8C010000        - fld dword ptr [esi+0000018C]
//	EXE+78F40 - D8 1D BCDC4A00        - fcomp dword ptr [EXE+ADCBC] { (0.10) }
//	EXE+78F46 - DFE0                  - fnstsw ax
//	EXE+78F48 - F6 C4 41              - test ah,41 { 65 }
//	EXE+78F4B - 74 1E                 - je EXE+78F6B
//	EXE+78F4D - D9 86 8C010000        - fld dword ptr [esi+0000018C]
//	EXE+78F53 - D9E0                  - fchs 
//	EXE+78F55 - D8 1D BCDC4A00        - fcomp dword ptr [EXE+ADCBC] { (0.10) }
//	EXE+78F5B - DFE0                  - fnstsw ax
//	EXE+78F5D - F6 C4 41              - test ah,41 { 65 }
//	EXE+78F60 - 74 09                 - je EXE+78F6B
//	EXE+78F62 - F6 C5 20              - test ch,20 { 32 }
//	EXE+78F65 - 0F85 12010000         - jne EXE+7907D
//	EXE+78F6B - D9 44 24 18           - fld dword ptr [esp+18]
//	EXE+78F6F - D9 44 24 1C           - fld dword ptr [esp+1C]
//	EXE+78F73 - D8 8E CC010000        - fmul dword ptr [esi+000001CC]
//	EXE+78F79 - D9 44 24 14           - fld dword ptr [esp+14]
//	EXE+78F7D - D9CA                  - fxch st(2)
//	EXE+78F7F - D8 8E C8010000        - fmul dword ptr [esi+000001C8]
//	EXE+78F85 - D9CA                  - fxch st(2)
//	EXE+78F87 - D8 8E C4010000        - fmul dword ptr [esi+000001C4]
//	EXE+78F8D - D9CA                  - fxch st(2)
//	EXE+78F8F - DEC1                  - faddp 
//	EXE+78F91 - D9C9                  - fxch st(1)
//	EXE+78F93 - 8D BE C4010000        - lea edi,[esi+000001C4]
//	EXE+78F99 - DEC1                  - faddp 
//	EXE+78F9B - D9 54 24 3C           - fst dword ptr [esp+3C]
//	EXE+78F9F - D8 1D 48DC4A00        - fcomp dword ptr [EXE+ADC48] { (0) }
//	EXE+78FA5 - DFE0                  - fnstsw ax
//	EXE+78FA7 - F6 C4 01              - test ah,01 { 1 }
//	EXE+78FAA - 0F85 9D000000         - jne EXE+7904D
//	EXE+78FB0 - 57                    - push edi
//	EXE+78FB1 - E8 0A69FBFF           - call EXE+2F8C0
//	EXE+78FB6 - D8 15 50DC4A00        - fcom dword ptr [EXE+ADC50] { (1.00) }
//	EXE+78FBC - 83 C4 04              - add esp,04 { 4 }
//	EXE+78FBF - DFE0                  - fnstsw ax
//	EXE+78FC1 - F6 C4 41              - test ah,41 { 65 }
//	EXE+78FC4 - 0F85 81000000         - jne EXE+7904B
//	EXE+78FCA - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+78FCE - D8 1D 50DC4A00        - fcomp dword ptr [EXE+ADC50] { (1.00) }
//	EXE+78FD4 - DFE0                  - fnstsw ax
//	EXE+78FD6 - F6 C4 41              - test ah,41 { 65 }
//	EXE+78FD9 - 75 33                 - jne EXE+7900E
//	EXE+78FDB - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+78FDF - D8 0D 7CDD4A00        - fmul dword ptr [EXE+ADD7C] { (60.00) }
//	EXE+78FE5 - D8 7C 24 3C           - fdivr dword ptr [esp+3C]
//	EXE+78FE9 - D8 15 48DC4A00        - fcom dword ptr [EXE+ADC48] { (0) }
//	EXE+78FEF - DFE0                  - fnstsw ax
//	EXE+78FF1 - F6 C4 41              - test ah,41 { 65 }
//	EXE+78FF4 - 75 16                 - jne EXE+7900C
//	EXE+78FF6 - DD 05 402AE200        - fld qword ptr [EXE+A22A40] { (0.04) }
//	EXE+78FFC - D8C9                  - fmul st(0),st(1)
//	EXE+78FFE - DCC0                  - fadd st(0),st(0)
//	EXE+79000 - D8 86 A4010000        - fadd dword ptr [esi+000001A4]
//	EXE+79006 - D9 9E A4010000        - fstp dword ptr [esi+000001A4]
//	EXE+7900C - DDD8                  - fstp st(0)
//	EXE+7900E - D8 7C 24 3C           - fdivr dword ptr [esp+3C]
//	EXE+79012 - D8 0D 80DD4A00        - fmul dword ptr [EXE+ADD80] { (0.01) }
//	EXE+79018 - D9 54 24 3C           - fst dword ptr [esp+3C]
//	EXE+7901C - D8 1D 50DC4A00        - fcomp dword ptr [EXE+ADC50] { (1.00) }
//	EXE+79022 - DFE0                  - fnstsw ax
//	EXE+79024 - F6 C4 01              - test ah,01 { 1 }
//	EXE+79027 - 74 08                 - je EXE+79031
//	EXE+79029 - C7 44 24 3C 0000803F  - mov [esp+3C],3F800000 { 1.00 }
//	EXE+79031 - 8B 4C 24 3C           - mov ecx,[esp+3C]
//	EXE+79035 - 57                    - push edi
//	EXE+79036 - 8D 54 24 18           - lea edx,[esp+18]
//	EXE+7903A - 51                    - push ecx
//	EXE+7903B - 8D 44 24 1C           - lea eax,[esp+1C]
//	EXE+7903F - 52                    - push edx
//	EXE+79040 - 50                    - push eax
//	EXE+79041 - E8 3A6AFBFF           - call EXE+2FA80
//	EXE+79046 - 83 C4 10              - add esp,10 { 16 }
//	EXE+79049 - EB 32                 - jmp EXE+7907D
//	EXE+7904B - DDD8                  - fstp st(0)
//	EXE+7904D - D9 44 24 14           - fld dword ptr [esp+14]
//	EXE+79051 - D9 44 24 18           - fld dword ptr [esp+18]
//	EXE+79055 - D9 44 24 1C           - fld dword ptr [esp+1C]
//	EXE+79059 - D9CA                  - fxch st(2)
//	EXE+7905B - D8 07                 - fadd dword ptr [edi]
//	EXE+7905D - D9C9                  - fxch st(1)
//	EXE+7905F - D8 86 C8010000        - fadd dword ptr [esi+000001C8]
//	EXE+79065 - D9CA                  - fxch st(2)
//	EXE+79067 - D8 86 CC010000        - fadd dword ptr [esi+000001CC]
//	EXE+7906D - D9C9                  - fxch st(1)
//	EXE+7906F - D9 5C 24 14           - fstp dword ptr [esp+14]
//	EXE+79073 - D9C9                  - fxch st(1)
//	EXE+79075 - D9 5C 24 18           - fstp dword ptr [esp+18]
//	EXE+79079 - D9 5C 24 1C           - fstp dword ptr [esp+1C]
//	EXE+7907D - DD 05 402AE200        - fld qword ptr [EXE+A22A40] { (0.04) }
//	EXE+79083 - 8B 6C 24 40           - mov ebp,[esp+40]
//	EXE+79087 - 8B 7C 24 44           - mov edi,[esp+44]
//	EXE+7908B - 8D 4C 24 14           - lea ecx,[esp+14]
//	EXE+7908F - 51                    - push ecx
//	EXE+79090 - 51                    - push ecx
//	EXE+79091 - D9 1C 24              - fstp dword ptr [esp]
//	EXE+79094 - 55                    - push ebp
//	EXE+79095 - 57                    - push edi
//	EXE+79096 - E8 E569FBFF           - call EXE+2FA80
//	EXE+7909B - DB 86 98190000        - fild dword ptr [esi+00001998]
//	EXE+790A1 - 83 C4 10              - add esp,10 { 16 }
//	EXE+790A4 - D8 25 D8DC4A00        - fsub dword ptr [EXE+ADCD8] { (400.00) }
//	EXE+790AA - D8 0D DCDC4A00        - fmul dword ptr [EXE+ADCDC] { (0.00) }
//	EXE+790B0 - DC 1D 90DC4A00        - fcomp qword ptr [EXE+ADC90] { (1.00) }
//	EXE+790B6 - DFE0                  - fnstsw ax
//	EXE+790B8 - F6 C4 01              - test ah,01 { 1 }
//	EXE+790BB - 75 2B                 - jne EXE+790E8
//	EXE+790BD - F6 46 60 20           - test byte ptr [esi+60],20 { 32 }
//	EXE+790C1 - 75 25                 - jne EXE+790E8
//	EXE+790C3 - F7 46 64 00000004     - test [esi+64],RTSSHooks.dll+3D0000 { (0) }
//	EXE+790CA - 75 1C                 - jne EXE+790E8
//	EXE+790CC - 33 C0                 - xor eax,eax
//	EXE+790CE - 89 86 54010000        - mov [esi+00000154],eax
//	EXE+790D4 - 89 86 58010000        - mov [esi+00000158],eax
//	EXE+790DA - 89 86 5C010000        - mov [esi+0000015C],eax
//	EXE+790E0 - 5F                    - pop edi
//	EXE+790E1 - 5E                    - pop esi
//	EXE+790E2 - 5D                    - pop ebp
//	EXE+790E3 - 5B                    - pop ebx
//	EXE+790E4 - 83 C4 28              - add esp,28 { 40 }
//	EXE+790E7 - C3                    - ret 
//	EXE+790E8 - F7 46 64 00008000     - test [esi+64],EXE+400000 { (0) }
//	EXE+790EF - 74 1C                 - je EXE+7910D
//	EXE+790F1 - 33 C0                 - xor eax,eax
//	EXE+790F3 - 89 86 54010000        - mov [esi+00000154],eax
//	EXE+790F9 - 89 86 58010000        - mov [esi+00000158],eax
//	EXE+790FF - 89 86 5C010000        - mov [esi+0000015C],eax
//	EXE+79105 - 5F                    - pop edi
//	EXE+79106 - 5E                    - pop esi
//	EXE+79107 - 5D                    - pop ebp
//	EXE+79108 - 5B                    - pop ebx
//	EXE+79109 - 83 C4 28              - add esp,28 { 40 }
//	EXE+7910C - C3                    - ret 
//	EXE+7910D - 8B 17                 - mov edx,[edi]
//	EXE+7910F - 8B 47 04              - mov eax,[edi+04]
//	EXE+79112 - 8B 4F 08              - mov ecx,[edi+08]
//	EXE+79115 - 89 54 24 20           - mov [esp+20],edx
//	EXE+79119 - 89 44 24 24           - mov [esp+24],eax
//	EXE+7911D - 8B 86 3C010000        - mov eax,[esi+0000013C]
//	EXE+79123 - 8D 54 24 2C           - lea edx,[esp+2C]
//	EXE+79127 - 89 4C 24 28           - mov [esp+28],ecx
//	EXE+7912B - 52                    - push edx
//	EXE+7912C - 50                    - push eax
//	EXE+7912D - 55                    - push ebp
//	EXE+7912E - 57                    - push edi
//	EXE+7912F - 33 DB                 - xor ebx,ebx
//	EXE+79131 - E8 7A1BFDFF           - call EXE+4ACB0
//	EXE+79136 - 83 C4 10              - add esp,10 { 16 }
//	EXE+79139 - 85 C0                 - test eax,eax
//	EXE+7913B - 74 20                 - je EXE+7915D
//	EXE+7913D - 83 FB 06              - cmp ebx,06 { 6 }
//	EXE+79140 - 7D 1B                 - jnl EXE+7915D
//	EXE+79142 - 8B 96 3C010000        - mov edx,[esi+0000013C]
//	EXE+79148 - 8D 4C 24 2C           - lea ecx,[esp+2C]
//	EXE+7914C - 51                    - push ecx
//	EXE+7914D - 52                    - push edx
//	EXE+7914E - 55                    - push ebp
//	EXE+7914F - 57                    - push edi
//	EXE+79150 - 43                    - inc ebx
//	EXE+79151 - E8 5A1BFDFF           - call EXE+4ACB0
//	EXE+79156 - 83 C4 10              - add esp,10 { 16 }
//	EXE+79159 - 85 C0                 - test eax,eax
//	EXE+7915B - 75 E0                 - jne EXE+7913D
//	EXE+7915D - 85 DB                 - test ebx,ebx
//	EXE+7915F - 7E 29                 - jle EXE+7918A
//	EXE+79161 - F6 46 60 80           - test byte ptr [esi+60],-80 { 128 }
//	EXE+79165 - 74 23                 - je EXE+7918A
//	EXE+79167 - DD 05 402AE200        - fld qword ptr [EXE+A22A40] { (0.04) }
//	EXE+7916D - 51                    - push ecx
//	EXE+7916E - D9 1C 24              - fstp dword ptr [esp]
//	EXE+79171 - 68 0000A040           - push 40A00000 { 5.00 }
//	EXE+79176 - E8 D5740000           - call EXE+80650
//	EXE+7917B - D8 8E A4010000        - fmul dword ptr [esi+000001A4]
//	EXE+79181 - 83 C4 08              - add esp,08 { 8 }
//	EXE+79184 - D9 9E A4010000        - fstp dword ptr [esi+000001A4]
//	EXE+7918A - D9 47 08              - fld dword ptr [edi+08]
//	EXE+7918D - D9 47 04              - fld dword ptr [edi+04]
//	EXE+79190 - D8 64 24 24           - fsub dword ptr [esp+24]
//	EXE+79194 - D9C9                  - fxch st(1)
//	EXE+79196 - D8 64 24 28           - fsub dword ptr [esp+28]
//	EXE+7919A - D9 07                 - fld dword ptr [edi]
//	EXE+7919C - D8 64 24 20           - fsub dword ptr [esp+20]
//	EXE+791A0 - D9C9                  - fxch st(1)
//	EXE+791A2 - D9 54 24 28           - fst dword ptr [esp+28]
//	EXE+791A6 - D9C9                  - fxch st(1)
//	EXE+791A8 - D9 9E 54010000        - fstp dword ptr [esi+00000154]
//	EXE+791AE - D9C9                  - fxch st(1)
//	EXE+791B0 - D9 9E 58010000        - fstp dword ptr [esi+00000158]
//	EXE+791B6 - 5F                    - pop edi
//	EXE+791B7 - D9 9E 5C010000        - fstp dword ptr [esi+0000015C]
//	EXE+791BD - 5E                    - pop esi
//	EXE+791BE - 5D                    - pop ebp
//	EXE+791BF - 5B                    - pop ebx
//	EXE+791C0 - 83 C4 28              - add esp,28 { 40 }
//	EXE+791C3 - C3                    - ret 
//	EXE+791C4 - 90                    - nop 
//	EXE+791C5 - 90                    - nop 
//	EXE+791C6 - 90                    - nop 
//	EXE+791C7 - 90                    - nop 
//	EXE+791C8 - 90                    - nop 
//	EXE+791C9 - 90                    - nop 
//	EXE+791CA - 90                    - nop 
//	EXE+791CB - 90                    - nop 
//	EXE+791CC - 90                    - nop 
//	EXE+791CD - 90                    - nop 
//	EXE+791CE - 90                    - nop 
//	EXE+791CF - 90                    - nop 
