void Deg2SinCos(float deg, float* out_sin, float* out_cos) {
    // NOTE: not sure if argument order is correct
    const double pi = (double)0x400921FB54442D18;               // AC650; 3.14..
    const double pi2rad_factor = (double)0x3F76C16C16C16C17;    // AC658; 0.005..
    float rad = deg * pi * pi2rad_factor;
    *out_sin = sin(rad);
    *out_cos = cos(rad);
}

//	EXE+2F380 - D9 44 24 04           - fld dword ptr [esp+04]
//	EXE+2F384 - DC 0D 50C64A00        - fmul qword ptr [(EXE+AC650)] { (3.14) }
//	EXE+2F38A - 8B 44 24 0C           - mov eax,[esp+0C]
//	EXE+2F38E - 8B 4C 24 08           - mov ecx,[esp+08]
//	EXE+2F392 - DC 0D 58C64A00        - fmul qword ptr [(EXE+AC658)] { (0.01) }
//	EXE+2F398 - D9C0                  - fld st(0)
//	EXE+2F39A - D9FF                  - fcos 
//	EXE+2F39C - D9C9                  - fxch st(1)
//	EXE+2F39E - D9FE                  - fsin 
//	EXE+2F3A0 - D9 54 24 04           - fst dword ptr [esp+04]
//	EXE+2F3A4 - D9C9                  - fxch st(1)
//	EXE+2F3A6 - D9 18                 - fstp dword ptr [eax]
//	EXE+2F3A8 - D9 19                 - fstp dword ptr [ecx]
//	EXE+2F3AA - C3                    - ret 
//	EXE+2F3AB - 90                    - nop 
//	EXE+2F3AC - 90                    - nop 
//	EXE+2F3AD - 90                    - nop 
//	EXE+2F3AE - 90                    - nop 
//	EXE+2F3AF - 90                    - nop 

