void CopyMat4(float* mat4_out, float* mat4_in) {
	// could just do this with one loop, but copying the asm structure for now
	// maybe the original code was iterating over vec4 objects, then iterating the values
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			mat4_out[i*4+j] = mat4_in[i*4+j];
		}
	}
}

//	EXE+4BB10 - 53                    - push ebx
//	EXE+4BB11 - 55                    - push ebp
//	EXE+4BB12 - 56                    - push esi
//	EXE+4BB13 - 8B 74 24 10           - mov esi,[esp+10]
//	EXE+4BB17 - 57                    - push edi
//	EXE+4BB18 - 8B 7C 24 18           - mov edi,[esp+18]
//	EXE+4BB1C - 8B C6                 - mov eax,esi
//	EXE+4BB1E - BB 04000000           - mov ebx,00000004 { 4 }
//	EXE+4BB23 - 8B CF                 - mov ecx,edi
//	EXE+4BB25 - BA 04000000           - mov edx,00000004 { 4 }
//	EXE+4BB2A - 2B CE                 - sub ecx,esi
//	EXE+4BB2C - 8B 2C 01              - mov ebp,[ecx+eax]
//	EXE+4BB2F - 89 28                 - mov [eax],ebp
//	EXE+4BB31 - 83 C0 04              - add eax,04 { 4 }
//	EXE+4BB34 - 4A                    - dec edx
//	EXE+4BB35 - 75 F5                 - jne (EXE+4BB2C)
//	EXE+4BB37 - 4B                    - dec ebx
//	EXE+4BB38 - 75 E9                 - jne (EXE+4BB23)
//	EXE+4BB3A - 5F                    - pop edi
//	EXE+4BB3B - 5E                    - pop esi
//	EXE+4BB3C - 5D                    - pop ebp
//	EXE+4BB3D - 5B                    - pop ebx
//	EXE+4BB3E - C3                    - ret 
//	EXE+4BB3F - 90                    - nop 
