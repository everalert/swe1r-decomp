#include "math.h"

void Vec4_MultiplyMat4(Vec4* out, Vec4* in_v, Mat4* in_m) {
  out->x = in_m->X.x * in_v->x + in_m->Y.x * in_v->y + in_m->Z.x * in_v->z + in_m->T.x * in_v->w;
  out->y = in_m->X.y * in_v->x + in_m->Y.y * in_v->y + in_m->Z.y * in_v->z + in_m->T.y * in_v->w;
  out->z = in_m->X.z * in_v->x + in_m->Y.z * in_v->y + in_m->Z.z * in_v->z + in_m->T.z * in_v->w;
  out->w = in_m->X.w * in_v->x + in_m->Y.w * in_v->y + in_m->Z.w * in_v->z + in_m->T.w * in_v->w;
}


//	(EXE+30AB0)  83 EC 10              - sub esp,10 { 16 }
//	(EXE+30AB3)  8B 44 24 1C           - mov eax,[esp+1C]
//	(EXE+30AB7)  8B 4C 24 18           - mov ecx,[esp+18]
//	(EXE+30ABB)  D9 40 24              - fld dword ptr [eax+24]
//	(EXE+30ABE)  D9 40 34              - fld dword ptr [eax+34]
//	(EXE+30AC1)  D9 40 28              - fld dword ptr [eax+28]
//	(EXE+30AC4)  D9 40 38              - fld dword ptr [eax+38]
//	(EXE+30AC7)  D9 40 2C              - fld dword ptr [eax+2C]
//	(EXE+30ACA)  D9 40 3C              - fld dword ptr [eax+3C]
//	(EXE+30ACD)  D9CD                  - fxch st(5)
//	(EXE+30ACF)  D8 49 08              - fmul dword ptr [ecx+08]
//	(EXE+30AD2)  D9 40 14              - fld dword ptr [eax+14]
//	(EXE+30AD5)  D9CD                  - fxch st(5)
//	(EXE+30AD7)  D8 49 0C              - fmul dword ptr [ecx+0C]
//	(EXE+30ADA)  DEC1                  - faddp 
//	(EXE+30ADC)  D9CC                  - fxch st(4)
//	(EXE+30ADE)  D8 49 04              - fmul dword ptr [ecx+04]
//	(EXE+30AE1)  DEC4                  - faddp st(4),st(0)
//	(EXE+30AE3)  D9CA                  - fxch st(2)
//	(EXE+30AE5)  D8 49 08              - fmul dword ptr [ecx+08]
//	(EXE+30AE8)  D9 40 18              - fld dword ptr [eax+18]
//	(EXE+30AEB)  D9 40 04              - fld dword ptr [eax+04]
//	(EXE+30AEE)  D8 09                 - fmul dword ptr [ecx]
//	(EXE+30AF0)  DEC5                  - faddp st(5),st(0)
//	(EXE+30AF2)  D9CA                  - fxch st(2)
//	(EXE+30AF4)  D8 49 0C              - fmul dword ptr [ecx+0C]
//	(EXE+30AF7)  DEC1                  - faddp 
//	(EXE+30AF9)  D9CA                  - fxch st(2)
//	(EXE+30AFB)  D8 49 08              - fmul dword ptr [ecx+08]
//	(EXE+30AFE)  D9 40 1C              - fld dword ptr [eax+1C]
//	(EXE+30B01)  D9CA                  - fxch st(2)
//	(EXE+30B03)  D8 49 04              - fmul dword ptr [ecx+04]
//	(EXE+30B06)  DEC3                  - faddp st(3),st(0)
//	(EXE+30B08)  D9CC                  - fxch st(4)
//	(EXE+30B0A)  D8 49 0C              - fmul dword ptr [ecx+0C]
//	(EXE+30B0D)  D9 40 20              - fld dword ptr [eax+20]
//	(EXE+30B10)  D9 40 08              - fld dword ptr [eax+08]
//	(EXE+30B13)  D8 09                 - fmul dword ptr [ecx]
//	(EXE+30B15)  DEC4                  - faddp st(4),st(0)
//	(EXE+30B17)  D9CB                  - fxch st(3)
//	(EXE+30B19)  D9 54 24 08           - fst dword ptr [esp+08]
//	(EXE+30B1D)  D9C9                  - fxch st(1)
//	(EXE+30B1F)  DEC5                  - faddp st(5),st(0)
//	(EXE+30B21)  D9 40 30              - fld dword ptr [eax+30]
//	(EXE+30B24)  D9CA                  - fxch st(2)
//	(EXE+30B26)  D8 49 04              - fmul dword ptr [ecx+04]
//	(EXE+30B29)  DEC5                  - faddp st(5),st(0)
//	(EXE+30B2B)  D9CA                  - fxch st(2)
//	(EXE+30B2D)  D8 49 08              - fmul dword ptr [ecx+08]
//	(EXE+30B30)  D9 40 0C              - fld dword ptr [eax+0C]
//	(EXE+30B33)  D8 09                 - fmul dword ptr [ecx]
//	(EXE+30B35)  DEC5                  - faddp st(5),st(0)
//	(EXE+30B37)  D9C9                  - fxch st(1)
//	(EXE+30B39)  D8 49 0C              - fmul dword ptr [ecx+0C]
//	(EXE+30B3C)  D9 40 10              - fld dword ptr [eax+10]
//	(EXE+30B3F)  D9CD                  - fxch st(5)
//	(EXE+30B41)  D9 54 24 0C           - fst dword ptr [esp+0C]
//	(EXE+30B45)  D9C9                  - fxch st(1)
//	(EXE+30B47)  DEC2                  - faddp st(2),st(0)
//	(EXE+30B49)  D9CC                  - fxch st(4)
//	(EXE+30B4B)  D8 49 04              - fmul dword ptr [ecx+04]
//	(EXE+30B4E)  D9 00                 - fld dword ptr [eax]
//	(EXE+30B50)  D9C9                  - fxch st(1)
//	(EXE+30B52)  DEC2                  - faddp st(2),st(0)
//	(EXE+30B54)  8B 44 24 14           - mov eax,[esp+14]
//	(EXE+30B58)  D8 09                 - fmul dword ptr [ecx]
//	(EXE+30B5A)  D9CB                  - fxch st(3)
//	(EXE+30B5C)  D9 58 04              - fstp dword ptr [eax+04]
//	(EXE+30B5F)  D9C9                  - fxch st(1)
//	(EXE+30B61)  D9 58 08              - fstp dword ptr [eax+08]
//	(EXE+30B64)  D9C9                  - fxch st(1)
//	(EXE+30B66)  DEC1                  - faddp 
//	(EXE+30B68)  D9C9                  - fxch st(1)
//	(EXE+30B6A)  D9 58 0C              - fstp dword ptr [eax+0C]
//	(EXE+30B6D)  D9 18                 - fstp dword ptr [eax]
//	(EXE+30B6F)  83 C4 10              - add esp,10 { 16 }
//	(EXE+30B72)  C3                    - ret 
//	(EXE+30B73)  90                    - nop 
//	(EXE+30B74)  90                    - nop 
//	(EXE+30B75)  90                    - nop 
//	(EXE+30B76)  90                    - nop 
//	(EXE+30B77)  90                    - nop 
//	(EXE+30B78)  90                    - nop 
//	(EXE+30B79)  90                    - nop 
//	(EXE+30B7A)  90                    - nop 
//	(EXE+30B7B)  90                    - nop 
//	(EXE+30B7C)  90                    - nop 
//	(EXE+30B7D)  90                    - nop 
//	(EXE+30B7E)  90                    - nop 
//	(EXE+30B7F)  90                    - nop 

