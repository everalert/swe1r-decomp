#include "address_constants.h"

void SetAngleFromTurnRate(float* tilt, float cur_turnrate, float max_turnrate, float max_angle) {
	float new_tilt = cur_turnrate / max_turnrate * max_angle;
	if (new_tilt > 80.0f) new_tilt = 80.0f;
	if (new_tilt < -80.0f) new_tilt = -80.0f;
	*tilt = *tilt - (new_tilt - *tilt) * dt_d * -5.0;
}


//	EXE+4AF50 - D9 44 24 08           - fld dword ptr [esp+08]
//	EXE+4AF54 - D8 74 24 10           - fdiv dword ptr [esp+10]
//	EXE+4AF58 - 8B 4C 24 04           - mov ecx,[esp+04]
//	EXE+4AF5C - D9E0                  - fchs 
//	EXE+4AF5E - D8 4C 24 14           - fmul dword ptr [esp+14]
//	EXE+4AF62 - D9 01                 - fld dword ptr [ecx]
//	EXE+4AF64 - D9C9                  - fxch st(1)
//	EXE+4AF66 - D8 15 24CC4A00        - fcom dword ptr [(EXE+ACC24)] { (80.00) }
//	EXE+4AF6C - DFE0                  - fnstsw ax
//	EXE+4AF6E - F6 C4 41              - test ah,41 { 65 }
//	EXE+4AF71 - 75 08                 - jne (EXE+4AF7B)
//	EXE+4AF73 - DDD8                  - fstp st(0)
//	EXE+4AF75 - D9 05 24CC4A00        - fld dword ptr [(EXE+ACC24)] { (80.00) }
//	EXE+4AF7B - D8 15 28CC4A00        - fcom dword ptr [(EXE+ACC28)] { (-80.00) }
//	EXE+4AF81 - DFE0                  - fnstsw ax
//	EXE+4AF83 - F6 C4 01              - test ah,01 { 1 }
//	EXE+4AF86 - 74 08                 - je (EXE+4AF90)
//	EXE+4AF88 - DDD8                  - fstp st(0)
//	EXE+4AF8A - D9 05 28CC4A00        - fld dword ptr [(EXE+ACC28)] { (-80.00) }
//	EXE+4AF90 - D8E1                  - fsub st(0),st(1)
//	EXE+4AF92 - DC 0D 402AE200        - fmul qword ptr [(EXE+A22A40)] { (0.04) }
//	EXE+4AF98 - DC 0D 30CC4A00        - fmul qword ptr [(EXE+ACC30)] { (-5.00) }
//	EXE+4AF9E - DEE9                  - fsubp st(1),st(0)
//	EXE+4AFA0 - D9 19                 - fstp dword ptr [ecx]
//	EXE+4AFA2 - C3                    - ret 
//	EXE+4AFA3 - 90                    - nop 
//	EXE+4AFA4 - 90                    - nop 
//	EXE+4AFA5 - 90                    - nop 
//	EXE+4AFA6 - 90                    - nop 
//	EXE+4AFA7 - 90                    - nop 
//	EXE+4AFA8 - 90                    - nop 
//	EXE+4AFA9 - 90                    - nop 
//	EXE+4AFAA - 90                    - nop 
//	EXE+4AFAB - 90                    - nop 
//	EXE+4AFAC - 90                    - nop 
//	EXE+4AFAD - 90                    - nop 
//	EXE+4AFAE - 90                    - nop 
//	EXE+4AFAF - 90                    - nop 

