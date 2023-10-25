void func_46BEC0(void* EngineData) {
	// TODO: confirm the parts like BYTEn() in IDA were converted correctly
	int v3; // ebp
	int v4; // ebx
	char v5; // cl
	int v6; // ecx
	double v7; // st7
	int v8; // edi
	int v9; // ebx
	void *v10_racedata; // eax
	unsigned int v11; // ecx
	double v12; // st7
	double v13; // st7
	double v14; // st6
	BOOL v15; // edx
	double v16; // st5
	char v18; // c0
	char v20; // c0
	char v22; // c0
	int v23; // ebx
	int v24; // edi
	char v25; // cl
	int v26; // ecx
	int v27; // eax
	double v28; // st7
	double v29; // st7
	int v30; // eax
	int v31; // eax
	int v32; // eax
	int v33; // eax
	int v34; // eax
	int v35; // eax
	unsigned int v36; // eax
	int v37; // eax
	int v38; // eax
	double v40; // st7
	char v41; // c0
	int v42; // eax
	int v43; // eax
	int v44; // eax
	int v45; // eax
	double v46; // st7
	int v47; // ecx
	unsigned __int8 v49; // c0
	unsigned __int8 v50; // c3
	int v51; // eax
	int v52; // eax
	int v53_airborne; // ecx
	int v54_eflags2cpy; // eax
	unsigned __int8 v56; // c0
	unsigned __int8 v57; // c3
	char v59; // c0
	int v60_eflags1cpy; // ecx
	int v61_eflags2cpy; // eax
	double v63; // st7
	char v64; // c0
	unsigned __int8 v66; // c0
	unsigned __int8 v67; // c3
	int v68; // eax
	int v69; // [esp-4h] [ebp-74h]
	float v70; // [esp+10h] [ebp-60h]
	float v71; // [esp+14h] [ebp-5Ch]
	int v72; // [esp+18h] [ebp-58h]
	int v73; // [esp+1Ch] [ebp-54h]
	int v74; // [esp+20h] [ebp-50h]
	int v75; // [esp+24h] [ebp-4Ch]
	float v76; // [esp+24h] [ebp-4Ch]
	int v77; // [esp+28h] [ebp-48h]
	int v78; // [esp+2Ch] [ebp-44h]
	float v79; // [esp+30h] [ebp-40h]
	int v80; // [esp+34h] [ebp-3Ch]
	int v81; // [esp+38h] [ebp-38h]
	int v82; // [esp+3Ch] [ebp-34h]
	int v83; // [esp+3Ch] [ebp-34h]
	int v84; // [esp+40h] [ebp-30h]
	int v85; // [esp+44h] [ebp-2Ch]
	int v86; // [esp+48h] [ebp-28h]
	int v88; // [esp+50h] [ebp-20h]
	float *v89; // [esp+54h] [ebp-1Ch]
	float EngineDataa; // [esp+74h] [ebp+4h]
	float EngineDatab; // [esp+74h] [ebp+4h]

	const double dt_d& = *(0xE22A40);		// frametime
	const double totalt_d& = *(0xE22A38);	// total effective application time
	const uint32_t GameSettingFlags& = *(0xE996DC);
	const uint32_t DebugLevel& = *(0x50C040);
	const uint32_t DebugFlags& = *(0x50C048);

	void* RaceData = *(EngineData + 0x1E70);
	uint32_t& RaceFlags = *(RaceData + 0x08);
	void* pRaceFile = *(RaceData + 0x0C);		// SAV data

	uint32_t& EngineFlags1 = *(EngineData + 0x60);
	uint32_t& EngineFlags2 = *(EngineData + 0x64);
	float& EnginePitchFactor = *(EngineData + 0x18C);
	float& EngineSpeed = *(EngineData + 0x1A0);
	float& EngineSlideMult = *(EngineData + 0x1E8);
	float& EngineTargetTurnRate = *(EngineData + 0x1F0);
	float& Engine_0x1F14 =  *(EngineData + 0x1F14); // could be double
	v77 = 0;
	v79 = 0.0;
	v71 = 0.0;
	v70 = 0.0;
	v75 = 0;
	v78 = 0;
	v74 = 0;
	v73 = 0;
	v72 = 0;
	v81 = 0;
	v82 = 0;
	v80 = 0;
	v3 = *(RaceData + 16);			// unknown "offset" 
	RaceFlags &= 0xFFFFFFFB;		// set 1<<02 off
	RaceFlags &= 0xFFFFFFF7;		// set 1<<03 off
	bool CanChargeBoost = EngineFlags1 & 0x200000;		// able to charge boost
	v86 = dword_E98E90[v3] & 0x400;     // 1<<10, same addr as mirrored stuff at bottom
	v85 = dword_E98E90[v3] & 0x800;		// 1<<11
	
	v4 = *(pRaceFile + 35);		// file data -> ???; one of the missing pieces
	switch ( v4 ) {
		case 0:
		case 9:
			if ( GameSettingFlags & 0x4000 ) {    // 1<<14 mirrored mode
				v71 = -*&dword_EC8838;
				v72 = flt_EC8858;
				v73 = flt_EC885C;
			} else {
				v71 = *&dword_EC8838;
				v73 = flt_EC8858;
				v72 = flt_EC885C;
			}
			v7 = *dword_EC883C;
			v8 = flt_EC884C;
			v77 = flt_EC884C;
			v9 = flt_EC8848;
			v74 = flt_EC8848;
			v82 = flt_EC8840[0];
			v81 = flt_EC8844;
			v80 = flt_EC8860;
			if ( flt_EC8864 == 0.0 || (v78 = 1, flt_EC88C4 <= 0.5) )
				v78 = 0;
			v75 = flt_EC8854;
			v79 = *&dword_EC8830;
			if ( !dword_EC8820 && v9 || v8 )
				RaceFlags &= 0xFFFFFFF7;	// set 1<<03 off
			else {
				if ( *&dword_EC8830 == 0.0 )
					goto LABEL_32;
				RaceFlags |= 0x00000008;	// set 1<<03 on
			}

LABEL_32:
			if ( v8 && dword_EC8820 && v9 )
				v74 = 0;
			v12 = v7 * 0.80000001;
			v70 = v12;
			if ( v12 > 0.80000001 )
				v70 = 0.80000001;
			if ( v70 < -0.80000001 )
				v70 = 0.80000001;

LABEL_40:
			v84 = UNK_BoostChargeHandler_46BD20(*&EngineData);
			if ( DebugFlags & 0x2000000 )           // 1<<25
			{
				v3 = *(RaceData + 16) != 0;
				v13 = flt_E98EA0[v3];
				v14 = flt_E98E80[v3];
				EngineDataa = flt_E98EA8[v3];
				v76 = flt_E98E88[v3];
				v15 = v14 > 0.30000001 || v76 > 0.30000001;
				v16 = v14 - v76;
				if ( GameSettingFlags & 0x4000 )            // 1<<14 mirrored mode
				{
					v71 = v16 * -0.5;
					if ( !v18 || (v72 = 1, EngineDataa >= -0.5) )
						v72 = 0;
					v73 = v13 > 0.5 && EngineDataa > 0.5;
				}
				else
				{
					v71 = v16 * 0.5;
					if ( !v20 || (v73 = 1, EngineDataa >= -0.5) )
						v73 = 0;
					if ( v13 <= 0.5 || (v72 = 1, EngineDataa <= 0.5) )
						v72 = 0;
				}
				v77 = v15;
				v70 = (flt_E98E88[v3] + flt_E98E80[v3]) * 0.5;
				if ( !v22 || (v74 = 1, v76 >= -0.60000002) )
					v74 = 0;
				v23 = dword_E98EB0[v3] & 4;             // 1<<02
				v24 = dword_E98E90[v3] & 8;             // 1<<03
				if ( (dword_E98EB0[v3] & 0x80u) != 0 )  // 1<<07
				{
					if ( totalt_d - EngineData[189] > 0.25 )// +0x2F4
						*(EngineData + 761) = 0;
					v25 = *(EngineData + 761) + 1;         // +0xBE4
					EngineData[189] = totalt_d;
					*(EngineData + 761) = v25;
					if ( v25 > 1 )
						v80 = 1;
				}
				if ( SLOBYTE(dword_E98EC0[v3]) < 0 )
					EngineData[189] = totalt_d;
				if ( SLOBYTE(dword_E98E90[v3]) < 0 && totalt_d - EngineData[189] > 0.5 )
					v78 = 1;
				v75 = v13 > 0.5 && EngineDataa < -0.5;
			}
			else
			{
				v24 = v81;
				v23 = v82;
			}
			EngineData[53] = 0.0;                      // +0xD4
			
			v26 = dword_4C7084;
			if ( dword_4C7084 > 0 )
			{
				if ( dword_4C7084 == 5 && EngineData[56] > 0.063000001 && EngineData[56] < 0.071999997 )// lap comp curr
				{
					*(EngineData + 53) = 1;
					v26 = dword_4C7084;
				}
				if ( v26 == 6 && EngineData[56] > 0.093000002 && EngineData[56] < 0.108 )// lap comp
					*(EngineData + 53) = 1;
			}
			v83 = sub_46A9C0(EngineData);
			if (v83) {
				v83 = 1;
				v73 = 0;
				v72 = 0;
				v84 = 0;
				EngineFlags1 &= 0xFF7FFFFF;        // set 1<<23 off; is boosting?
			}

			if (EngineFlags1 & 0x10 && !(EngineFlags1 & 0x200) && !(EngineFlags2 & 0x2000000)) {
			// flags1 1<<05 (unk), flags1 1<<09 (isbraking), flags2 1<<25 (racecomplete)
				v28 = sub_46A9F0(EngineData);
				if (v83 & 1)
					v28 += 0.2;
				else if (v83 & 2)
					v28 -= 0.2;
				v29 = v28 * 1.5;
				EngineDatab = v29;
				if ( v29 == 0.0 )
					sub_40A0B0(1);
				else {
					sub_409EE0(1, (60.0 - EngineDatab * -30.0), 180 * (EngineDatab >= 0.0) + 90, -1);
					dword_4D78A0 = 1;
				}
				*&dword_50CAE4 = v29;
				v71 = v71 - EngineDatab * -0.60000002;
			}
			if ( DebugFlags & 0x100 ) {               // 1<<08
				if ( DebugLevel && (v85 || v86) ) {
					v30 = -(v85 != 0);
					LOBYTE(v30) = v30 & 0xFE;             // 1111 1110
					v88 = 0x536E6170;
					v89 = (v30 + 1);
					sub_450C00(EngineData, &v88);
				}
				if ( DebugFlags & 0x100 && DebugLevel )// 1<<08
					sub_46A990(EngineData, v3); // sets flags1 1<<12 on conditionally
			}

			if ( v80 || dword_4D79E0 ) {
				dword_4D79E0 = 0;
				if ( (EngineFlags1 & 0xF) == 2 ) {		// 0010 specifically
					if ( !(EngineFlags1 & 0x5800) )	{	// 1<<11 (unk), 1<<12 (unk), 1<<14 (isdead) all off
						if (!(EngineFlags2 & 0x4000)) {   // 1<<14 isexploding
							if ( **(RaceData + 24) == 2 ) {// character/non-base stat vehicle data
								sub_46BA30(EngineData);
								sub_46BB30(*RaceData);
							}
							if ( RNG_4816B0() * 4.6566129e-10 >= 0.5 ) {
								v34 = sub_427590(1, **(RaceData + 24), 21, 22, 23, 24, 25, (EngineData + 20));
							} else {
								v33 = **(RaceData + 24);
								if ( v33 != 14 ) {
									v69 = sub_427590(1, v33, 3, 17, 18, 19, 20, (EngineData + 20));
									sub_41DF10(1, 0, 0x7461756E, 1, **(RaceData + 24), v69);
									goto LABEL_120;
								}
								v34 = sub_427590(1, 14, 3, 18, 18, 19, 20, (EngineData + 20));
							}
							sub_41DF10(-1, 0, 0x7461756E, 1, **(RaceData + 24), v34);
						}
					}
				}
			}

LABEL_120:
			if (v24)
				EngineFlags1 |= 0x00100000;	// set 1<<20 on (cam lookback)
			else
				EngineFlags1 &= 0xFFEFFFFF; // set 1<<20 off (cam lookback)

			if (v78)
				EngineFlags1 |= 0x00000004; // set 1<<02 on
			else
				EngineFlags1 &= 0xFFFFFFFB; // set 1<<02 off
			
			EngineFlags1 &= 0x7FFFFFFF;     // set 1<<31 off
			
			if (EngineFlags1 & 0x0F && !(EngineFlags1 & 0x4000)) {	// any flags 1-4, 1<<14(dead) off
				if (v23) {
					v88 = 0x43427574;
					v89 = EngineData;
					sub_450C50(0x634D616E, &v88);
				} else if (dword_EC83D0) {
					v88 = dword_EC83D0;
					v89 = EngineData;
					sub_450C50(0x634D616E, &v88);
					dword_EC83D0 = 0;
				}
			}
			sub_46AA30(EngineData);
			UNK_RepairHandler_46AB10(*&EngineData);
			
			if ( EngineFlags1 & 0x2000000 ) {          // 1<<25 (on zon terrain)
				if ( v70 >= 0.050000001 || -v70 >= 0.050000001 ) {
					v40 = v70 * 1.25 * (v70 * 1.25);
					if ( v41 )
						v40 = -v40;
					EngineData[137] = -(EngineData[29] * (v40 * 0.80000001)) * 0.5;// +0x224, maxturnrate
				} else
					EngineData[137] = 0.0;
				v70 = 0.0;
			}
			if ( flt_EC884C != 0.0 && flt_EC88AC < 0.2 && flt_EC88AC > 0.0
					|| *&dword_EC8830 > 0.6 && flt_EC8850 != 0.0 && flt_EC88B0 < 0.2 && flt_EC88B0 > 0.0 ) {
				if (!(EngineFlags2 & 0x1000)) { // 1<<12
					EngineFlags2 |= 0x10u;      // turn 1<<04 on
					if ( v42 & 0x800 )          // 1<<11
						EngineFlags2 |= 0x20u;  // turn 1<<05 on
				}
			}
			
			if ( EngineFlags2 & 0x2000 ) {                 // 1<<13
				if ( !sub_427670(0, 0x80000)) {  // 1<<19
					sub_427590(1, **(RaceData + 24), 2, 2, 2, 2, 2, (EngineData + 20));// nonstat vehicle/char data, posx
					sub_427690(0, 0x80000);
				}
				if (flt_EC884C == 0.0 && *&dword_EC8830 <= 0.6 || EngineSpeed > 290.0)
					EngineFlags2 &= 0xFFFFFFDFu;	// ..11011111
			}
			
			if ((EngineFlags1 & 0x0F == 2) && !(EngineFlags1 & 0x4000))	{ // 0010, 1<<14(dead)
				if ( v74 ) {
					EngineFlags1 |= 0x02;			// set 1<<02 on
					if ( EngineSpeed < 70.0 )
						EngineFlags1 &= 0xFFFFFFEF;	// set 1<<04 off
				} else
					EngineFlags1 &= 0xFFFFFFFD;		// set 1<<02 off
				
				if (RaceFlags & 0x08) {				// flags 1<<3
					EnginePitchFactor = (v79 - -1.0) * 0.5 * 1.1764705;// pitch factor?
					if ( !(v49 | v50) )
						EnginePitchFactor = 1.0;
					if ( EnginePitchFactor < -1.0 )
						EnginePitchFactor = -1.0;
				} else if ( v77 ) {
					EnginePitchFactor = 1.0;
					if ( v83 )
						EnginePitchFactor = 0.5;
				} else if ( v70 >= -0.5 || EngineSpeed >= 20.0 )
					EnginePitchFactor = 0.1;
				else
					EnginePitchFactor = v70 * 0.40000001;
				
				if ( EngineData[153] <= 0.0 && EnginePitchFactor > 0.30000001 )// +0x264 unk
					EngineFlags1 |= 0x10;             // 1<<04
				
				v53_airborne = EngineFlags2 & 0x200;	// 1<<09

				if (v53_airborne)
					EngineFlags2 |= 0x00000008;     // set 1<<03 (issliding?) on
				else
					EngineFlags2 &= 0xFFFFFFF7;     // set 1<<03 off
				
				if (v77 || v79 > 0.5)
					EngineFlags2 &= 0xFFFFFFFB;     // set 1<<02 off
				else
					EngineFlags2 |= 0x00000004;     // set 1<<02 on

				// if airborne and >100 speed, inc slide multiplier, else dec slide multiplier
				if (v53_airborne && EngineSpeed > 100.0) {
					EngineSlideMult = EngineSlideMult + dt_d * 0.5;
					if ( !(v56 | v57) )
						EngineSlideMult = 1.0;
				} else {
					EngineSlideMult = EngineSlideMult - dt_d * 0.5;
					if ( v59 )
						EngineSlideMult = 0.0;
				}

				if (v84 && CanChargeBoost) {
					RNG_4816B0();
					EngineFlags1 |= 0x800000; // 1<<23
				}
				if (EngineFlags1 & 0x800000 && !v77 && v79 <= 0.5)
					EngineFlags1 &= 0xFF7FFFFF; // set 1<<23 off (isboosting)
				
				Engine_0x1F14 = Engine_0x1F14 - dt_d;
				
				if ( v73 || v72 ) {
					if (EngineFlags2 & 0x400)                    // 1<<10 (isrolldisabled?)
						sub_426C80(75, 7, 0.5, 1.0, 1);
				}
				if ( v73 ) {
					if ( !v72 ) {
						UNK_ManualTiltHandler_46B5A0(EngineData, -1.0);
						goto LABEL_211;
					}
				} else if ( !v72 ) {
					goto LABEL_210;
				}
				if ( !v73 ) {
					UNK_ManualTiltHandler_46B5A0(EngineData, 1.0);
					goto LABEL_211;
				}
LABEL_210:
				UNK_ManualTiltHandler_46B5A0(EngineData, 0.0);

LABEL_211:
				if ( v71 >= 0.050000001 || -v71 >= 0.050000001 ) {
					v63 = v71 * 1.25 * (v71 * 1.25);
					if ( v64 )
						v63 = -v63;
					EngineTargetTurnRate = -(EngineData[29] * (v63 * 0.80000001));// target turn rate, maxturnrate
				} else
					EngineTargetTurnRate = 0.0;
				
				EngineData[191] = v70;                   // pitch input?
				if ( v70 > 0.1 ) {
					EngineTargetTurnRate = (1.0 - v70 * 0.40000001) * EngineTargetTurnRate;
					if ( !(v66 | v67) )
						EnginePitchFactor = EnginePitchFactor - v70 * -0.40000001;// pitch factor?
				}
				if ( v70 < -0.1 ) {
					v68 = EngineFlags2;
					EngineTargetTurnRate = (1.0 - v70 * 0.40000001) * EngineTargetTurnRate;
					if ( !(v68 & 0x200) && EnginePitchFactor > 0.5 )
						EnginePitchFactor = EnginePitchFactor - v70 * -0.40000001;
				}
				if ( EngineFlags1 & 0x400000 ) {         // 1<<22 unk, accel related
					if ( EnginePitchFactor < 1.2 )
						EnginePitchFactor = 1.2;
				}
				EngineData[139] = 1.0;                   // "stat multiplier"
			}
			return;

		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			if ( GameSettingFlags & 0x4000 ) {			// 1<<14 mirrored mode
				v72 = dword_E98E90[v3] & 0x10;          // 1<<4
				v71 = -flt_E98EA0[v3];
				v73 = dword_E98E90[v3] & 0x20;          // 1<<5
			} else {
				v71 = flt_E98EA0[v3];
				v73 = dword_E98E90[v3] & 0x10;          // 1<<4
				v72 = dword_E98E90[v3] & 0x20;          // 1<<5
			}
			v70 = flt_E98E80[v3];
			v77 = flt_EC884C;
			v74 = dword_E98E90[v3] & 2;					// 1<<1
			v81 = dword_E98E90[v3] & 8;					// 1<<3
			v82 = dword_E98EB0[v3] & 4;					// 1<<2
			if ( (dword_E98EB0[v3] & 0x80u) != 0 ) {	// 1<<7
				if ( totalt_d - *(EngineData + 189) > 0.25 )	// unk
					*(EngineData + 761) = 0;					// unk
				v5 = *(EngineData + 761) + 1;
				*(EngineData + 189) = totalt_d;
				*(EngineData + 761) = v5;
				if ( v5 > 1 )
					v80 = 1;
			}
			if ( SLOBYTE(dword_E98EC0[v3]) < 0 )
				*(EngineData + 189) = totalt_d;
			v6 = dword_E98E90[v3];
			if ( (v6 & 0x80u) != 0 && totalt_d - *(EngineData + 189) > 0.5 )// 1<<7, manual unfiltered deltatime?
				v78 = 1;
			if ( v6 & 0x100 )                         // 1<<8
				v75 = 1;
			if ( v4 == 1 )
				v75 = v77 == 0;
			goto LABEL_40;
		default:
			goto LABEL_40;
	}
}


//	EXE+6BEC0 - 83 EC 60              - sub esp,60 { 96 }
//	EXE+6BEC3 - 53                    - push ebx
//	EXE+6BEC4 - 55                    - push ebp
//	EXE+6BEC5 - 56                    - push esi
//	EXE+6BEC6 - 8B 74 24 70           - mov esi,[esp+70]
//	EXE+6BECA - 33 C0                 - xor eax,eax
//	EXE+6BECC - 57                    - push edi
//	EXE+6BECD - 89 44 24 28           - mov [esp+28],eax
//	EXE+6BED1 - 89 44 24 30           - mov [esp+30],eax
//	EXE+6BED5 - 89 44 24 14           - mov [esp+14],eax
//	EXE+6BED9 - 89 44 24 10           - mov [esp+10],eax
//	EXE+6BEDD - 89 44 24 24           - mov [esp+24],eax
//	EXE+6BEE1 - 89 44 24 2C           - mov [esp+2C],eax
//	EXE+6BEE5 - 89 44 24 20           - mov [esp+20],eax
//	EXE+6BEE9 - 89 44 24 1C           - mov [esp+1C],eax
//	EXE+6BEED - 89 44 24 18           - mov [esp+18],eax
//	EXE+6BEF1 - 89 44 24 38           - mov [esp+38],eax
//	EXE+6BEF5 - 89 44 24 3C           - mov [esp+3C],eax
//	EXE+6BEF9 - 89 44 24 34           - mov [esp+34],eax
//	EXE+6BEFD - 89 86 8C010000        - mov [esi+0000018C],eax
//	EXE+6BF03 - 89 86 F0010000        - mov [esi+000001F0],eax
//	EXE+6BF09 - 8B 86 701E0000        - mov eax,[esi+00001E70]
//	EXE+6BF0F - 8B 48 0C              - mov ecx,[eax+0C]
//	EXE+6BF12 - 8B 50 08              - mov edx,[eax+08]
//	EXE+6BF15 - 0FBE 68 10            - movsx ebp,byte ptr [eax+10]
//	EXE+6BF19 - 0FBE 59 23            - movsx ebx,byte ptr [ecx+23]
//	EXE+6BF1D - 83 E2 FB              - and edx,-05 { 251 }
//	EXE+6BF20 - 89 50 08              - mov [eax+08],edx
//	EXE+6BF23 - 8B 86 701E0000        - mov eax,[esi+00001E70]
//	EXE+6BF29 - 8B 48 08              - mov ecx,[eax+08]
//	EXE+6BF2C - 83 E1 F7              - and ecx,-09 { 247 }
//	EXE+6BF2F - 89 48 08              - mov [eax+08],ecx
//	EXE+6BF32 - 8B 46 60              - mov eax,[esi+60]
//	EXE+6BF35 - 8B 3C AD 908EE900     - mov edi,[ebp*4+(EXE+A98E90)]
//	EXE+6BF3C - 25 00002000           - and eax,00200000 { 2097152 }
//	EXE+6BF41 - 89 44 24 4C           - mov [esp+4C],eax
//	EXE+6BF45 - 8B C7                 - mov eax,edi
//	EXE+6BF47 - 25 00040000           - and eax,00000400 { 1024 }
//	EXE+6BF4C - 89 44 24 48           - mov [esp+48],eax
//	EXE+6BF50 - 8B C7                 - mov eax,edi
//	EXE+6BF52 - 25 00080000           - and eax,00000800 { 2048 }
//	EXE+6BF57 - 83 FB 09              - cmp ebx,09 { 9 }
//	EXE+6BF5A - 89 44 24 44           - mov [esp+44],eax
//	EXE+6BF5E - 0F87 D4020000         - ja (EXE+6C238)
//	EXE+6BF64 - 33 D2                 - xor edx,edx
//	EXE+6BF66 - 8A 93 20CE4600        - mov dl,[ebx+(EXE+6CE20)]
//	EXE+6BF6C - FF 24 95 10CE4600     - jmp dword ptr [edx*4+(EXE+6CE10)]
//	EXE+6BF73 - A1 DC96E900           - mov eax,[(EXE+A996DC)] { (9) }
//	EXE+6BF78 - D9 04 AD A08EE900     - fld dword ptr [ebp*4+(EXE+A98EA0)]
//	EXE+6BF7F - F6 C4 40              - test ah,40 { 64 }
//	EXE+6BF82 - 74 1A                 - je (EXE+6BF9E)
//	EXE+6BF84 - 8B C7                 - mov eax,edi
//	EXE+6BF86 - 83 E0 10              - and eax,10 { 16 }
//	EXE+6BF89 - 89 44 24 18           - mov [esp+18],eax
//	EXE+6BF8D - 8B C7                 - mov eax,edi
//	EXE+6BF8F - D9E0                  - fchs 
//	EXE+6BF91 - D9 5C 24 14           - fstp dword ptr [esp+14]
//	EXE+6BF95 - 83 E0 20              - and eax,20 { 32 }
//	EXE+6BF98 - 89 44 24 1C           - mov [esp+1C],eax
//	EXE+6BF9C - EB 16                 - jmp (EXE+6BFB4)
//	EXE+6BF9E - 8B C7                 - mov eax,edi
//	EXE+6BFA0 - D9 5C 24 14           - fstp dword ptr [esp+14]
//	EXE+6BFA4 - 83 E0 10              - and eax,10 { 16 }
//	EXE+6BFA7 - 89 44 24 1C           - mov [esp+1C],eax
//	EXE+6BFAB - 8B C7                 - mov eax,edi
//	EXE+6BFAD - 83 E0 20              - and eax,20 { 32 }
//	EXE+6BFB0 - 89 44 24 18           - mov [esp+18],eax
//	EXE+6BFB4 - D9 04 AD 808EE900     - fld dword ptr [ebp*4+(EXE+A98E80)]
//	EXE+6BFBB - D9 5C 24 10           - fstp dword ptr [esp+10]
//	EXE+6BFBF - D9 05 4C88EC00        - fld dword ptr [(EXE+AC884C)] { (0.00) }
//	EXE+6BFC5 - E8 562D0300           - call (EXE+9ED20)
//	EXE+6BFCA - 89 44 24 28           - mov [esp+28],eax
//	EXE+6BFCE - 8B C7                 - mov eax,edi
//	EXE+6BFD0 - 83 E0 02              - and eax,02 { 2 }
//	EXE+6BFD3 - 83 E7 08              - and edi,08 { 8 }
//	EXE+6BFD6 - 89 44 24 20           - mov [esp+20],eax
//	EXE+6BFDA - 8B 04 AD B08EE900     - mov eax,[ebp*4+(EXE+A98EB0)]
//	EXE+6BFE1 - 8B C8                 - mov ecx,eax
//	EXE+6BFE3 - 89 7C 24 38           - mov [esp+38],edi
//	EXE+6BFE7 - 83 E1 04              - and ecx,04 { 4 }
//	EXE+6BFEA - A8 80                 - test al,-80 { 128 }
//	EXE+6BFEC - 89 4C 24 3C           - mov [esp+3C],ecx
//	EXE+6BFF0 - 74 4B                 - je (EXE+6C03D)
//	EXE+6BFF2 - D9 86 F4020000        - fld dword ptr [esi+000002F4]
//	EXE+6BFF8 - DC 2D 382AE200        - fsubr qword ptr [(EXE+A22A38)] { (11.37) }
//	EXE+6BFFE - DC 1D D0D84A00        - fcomp qword ptr [(EXE+AD8D0)] { (0.25) }
//	EXE+6C004 - DFE0                  - fnstsw ax
//	EXE+6C006 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C009 - 75 07                 - jne (EXE+6C012)
//	EXE+6C00B - C6 86 F9020000 00     - mov byte ptr [esi+000002F9],00 { 0 }
//	EXE+6C012 - 8A 8E F9020000        - mov cl,[esi+000002F9]
//	EXE+6C018 - DD 05 382AE200        - fld qword ptr [(EXE+A22A38)] { (11.37) }
//	EXE+6C01E - FE C1                 - inc cl
//	EXE+6C020 - D9 9E F4020000        - fstp dword ptr [esi+000002F4]
//	EXE+6C026 - 8A C1                 - mov al,cl
//	EXE+6C028 - 88 8E F9020000        - mov [esi+000002F9],cl
//	EXE+6C02E - 3C 01                 - cmp al,01 { 1 }
//	EXE+6C030 - 7E 0B                 - jle (EXE+6C03D)
//	EXE+6C032 - BA 01000000           - mov edx,00000001 { 1 }
//	EXE+6C037 - 89 54 24 34           - mov [esp+34],edx
//	EXE+6C03B - EB 05                 - jmp (EXE+6C042)
//	EXE+6C03D - BA 01000000           - mov edx,00000001 { 1 }
//	EXE+6C042 - F6 04 AD C08EE900 80  - test byte ptr [ebp*4+(EXE+A98EC0)],-80 { 128 }
//	EXE+6C04A - 74 0C                 - je (EXE+6C058)
//	EXE+6C04C - DD 05 382AE200        - fld qword ptr [(EXE+A22A38)] { (11.37) }
//	EXE+6C052 - D9 9E F4020000        - fstp dword ptr [esi+000002F4]
//	EXE+6C058 - 8B 0C AD 908EE900     - mov ecx,[ebp*4+(EXE+A98E90)]
//	EXE+6C05F - F6 C1 80              - test cl,-80 { 128 }
//	EXE+6C062 - 74 1D                 - je (EXE+6C081)
//	EXE+6C064 - D9 86 F4020000        - fld dword ptr [esi+000002F4]
//	EXE+6C06A - DC 2D 382AE200        - fsubr qword ptr [(EXE+A22A38)] { (11.37) }
//	EXE+6C070 - DC 1D 78D74A00        - fcomp qword ptr [(EXE+AD778)] { (0.50) }
//	EXE+6C076 - DFE0                  - fnstsw ax
//	EXE+6C078 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C07B - 75 04                 - jne (EXE+6C081)
//	EXE+6C07D - 89 54 24 2C           - mov [esp+2C],edx
//	EXE+6C081 - F6 C5 01              - test ch,01 { 1 }
//	EXE+6C084 - 74 04                 - je (EXE+6C08A)
//	EXE+6C086 - 89 54 24 24           - mov [esp+24],edx
//	EXE+6C08A - 3B DA                 - cmp ebx,edx
//	EXE+6C08C - 0F85 A6010000         - jne (EXE+6C238)
//	EXE+6C092 - 8B 4C 24 28           - mov ecx,[esp+28]
//	EXE+6C096 - 33 C0                 - xor eax,eax
//	EXE+6C098 - 85 C9                 - test ecx,ecx
//	EXE+6C09A - 0F94 C0               - sete al
//	EXE+6C09D - 89 44 24 24           - mov [esp+24],eax
//	EXE+6C0A1 - E9 92010000           - jmp (EXE+6C238)
//	EXE+6C0A6 - A1 DC96E900           - mov eax,[(EXE+A996DC)] { (9) }
//	EXE+6C0AB - F6 C4 40              - test ah,40 { 64 }
//	EXE+6C0AE - 74 2C                 - je (EXE+6C0DC)
//	EXE+6C0B0 - D9 05 3888EC00        - fld dword ptr [(EXE+AC8838)] { (0.00) }
//	EXE+6C0B6 - D9E0                  - fchs 
//	EXE+6C0B8 - D9 5C 24 14           - fstp dword ptr [esp+14]
//	EXE+6C0BC - D9 05 5888EC00        - fld dword ptr [(EXE+AC8858)] { (0.00) }
//	EXE+6C0C2 - E8 592C0300           - call (EXE+9ED20)
//	EXE+6C0C7 - D9 05 5C88EC00        - fld dword ptr [(EXE+AC885C)] { (0.00) }
//	EXE+6C0CD - 89 44 24 18           - mov [esp+18],eax
//	EXE+6C0D1 - E8 4A2C0300           - call (EXE+9ED20)
//	EXE+6C0D6 - 89 44 24 1C           - mov [esp+1C],eax
//	EXE+6C0DA - EB 28                 - jmp (EXE+6C104)
//	EXE+6C0DC - 8B 0D 3888EC00        - mov ecx,[(EXE+AC8838)] { (0) }
//	EXE+6C0E2 - D9 05 5888EC00        - fld dword ptr [(EXE+AC8858)] { (0.00) }
//	EXE+6C0E8 - 89 4C 24 14           - mov [esp+14],ecx
//	EXE+6C0EC - E8 2F2C0300           - call (EXE+9ED20)
//	EXE+6C0F1 - D9 05 5C88EC00        - fld dword ptr [(EXE+AC885C)] { (0.00) }
//	EXE+6C0F7 - 89 44 24 1C           - mov [esp+1C],eax
//	EXE+6C0FB - E8 202C0300           - call (EXE+9ED20)
//	EXE+6C100 - 89 44 24 18           - mov [esp+18],eax
//	EXE+6C104 - D9 05 3C88EC00        - fld dword ptr [(EXE+AC883C)] { (0.00) }
//	EXE+6C10A - D9 05 4C88EC00        - fld dword ptr [(EXE+AC884C)] { (0.00) }
//	EXE+6C110 - E8 0B2C0300           - call (EXE+9ED20)
//	EXE+6C115 - D9 05 4888EC00        - fld dword ptr [(EXE+AC8848)] { (0.00) }
//	EXE+6C11B - 8B F8                 - mov edi,eax
//	EXE+6C11D - 89 7C 24 28           - mov [esp+28],edi
//	EXE+6C121 - E8 FA2B0300           - call (EXE+9ED20)
//	EXE+6C126 - D9 05 4088EC00        - fld dword ptr [(EXE+AC8840)] { (0.00) }
//	EXE+6C12C - 8B D8                 - mov ebx,eax
//	EXE+6C12E - 89 5C 24 20           - mov [esp+20],ebx
//	EXE+6C132 - E8 E92B0300           - call (EXE+9ED20)
//	EXE+6C137 - D9 05 4488EC00        - fld dword ptr [(EXE+AC8844)] { (0.00) }
//	EXE+6C13D - 89 44 24 3C           - mov [esp+3C],eax
//	EXE+6C141 - E8 DA2B0300           - call (EXE+9ED20)
//	EXE+6C146 - D9 05 6088EC00        - fld dword ptr [(EXE+AC8860)] { (0.00) }
//	EXE+6C14C - 89 44 24 38           - mov [esp+38],eax
//	EXE+6C150 - E8 CB2B0300           - call (EXE+9ED20)
//	EXE+6C155 - D9 05 6488EC00        - fld dword ptr [(EXE+AC8864)] { (0.00) }
//	EXE+6C15B - D8 1D 50D74A00        - fcomp dword ptr [(EXE+AD750)] { (0) }
//	EXE+6C161 - 89 44 24 34           - mov [esp+34],eax
//	EXE+6C165 - DFE0                  - fnstsw ax
//	EXE+6C167 - F6 C4 40              - test ah,40 { 64 }
//	EXE+6C16A - 75 1B                 - jne (EXE+6C187)
//	EXE+6C16C - D9 05 C488EC00        - fld dword ptr [(EXE+AC88C4)] { (0.00) }
//	EXE+6C172 - DC 1D 78D74A00        - fcomp qword ptr [(EXE+AD778)] { (0.50) }
//	EXE+6C178 - C7 44 24 2C 01000000  - mov [esp+2C],00000001 { 1 }
//	EXE+6C180 - DFE0                  - fnstsw ax
//	EXE+6C182 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C185 - 74 08                 - je (EXE+6C18F)
//	EXE+6C187 - C7 44 24 2C 00000000  - mov [esp+2C],00000000 { 0 }
//	EXE+6C18F - D9 05 5488EC00        - fld dword ptr [(EXE+AC8854)] { (0.00) }
//	EXE+6C195 - E8 862B0300           - call (EXE+9ED20)
//	EXE+6C19A - 8B 15 3088EC00        - mov edx,[(EXE+AC8830)] { (0) }
//	EXE+6C1A0 - 89 44 24 24           - mov [esp+24],eax
//	EXE+6C1A4 - A1 2088EC00           - mov eax,[(EXE+AC8820)] { (0) }
//	EXE+6C1A9 - 89 54 24 30           - mov [esp+30],edx
//	EXE+6C1AD - 85 C0                 - test eax,eax
//	EXE+6C1AF - 75 04                 - jne (EXE+6C1B5)
//	EXE+6C1B1 - 85 DB                 - test ebx,ebx
//	EXE+6C1B3 - 75 04                 - jne (EXE+6C1B9)
//	EXE+6C1B5 - 85 FF                 - test edi,edi
//	EXE+6C1B7 - 74 0E                 - je (EXE+6C1C7)
//	EXE+6C1B9 - 8B 86 701E0000        - mov eax,[esi+00001E70]
//	EXE+6C1BF - 8B 48 08              - mov ecx,[eax+08]
//	EXE+6C1C2 - 83 E1 F7              - and ecx,-09 { 247 }
//	EXE+6C1C5 - EB 1D                 - jmp (EXE+6C1E4)
//	EXE+6C1C7 - D9 44 24 30           - fld dword ptr [esp+30]
//	EXE+6C1CB - D8 1D 50D74A00        - fcomp dword ptr [(EXE+AD750)] { (0) }
//	EXE+6C1D1 - DFE0                  - fnstsw ax
//	EXE+6C1D3 - F6 C4 40              - test ah,40 { 64 }
//	EXE+6C1D6 - 75 0F                 - jne (EXE+6C1E7)
//	EXE+6C1D8 - 8B 86 701E0000        - mov eax,[esi+00001E70]
//	EXE+6C1DE - 8B 48 08              - mov ecx,[eax+08]
//	EXE+6C1E1 - 83 C9 08              - or ecx,08 { 8 }
//	EXE+6C1E4 - 89 48 08              - mov [eax+08],ecx
//	EXE+6C1E7 - 85 FF                 - test edi,edi
//	EXE+6C1E9 - 74 15                 - je (EXE+6C200)
//	EXE+6C1EB - A1 2088EC00           - mov eax,[(EXE+AC8820)] { (0) }
//	EXE+6C1F0 - 85 C0                 - test eax,eax
//	EXE+6C1F2 - 74 0C                 - je (EXE+6C200)
//	EXE+6C1F4 - 85 DB                 - test ebx,ebx
//	EXE+6C1F6 - 74 08                 - je (EXE+6C200)
//	EXE+6C1F8 - C7 44 24 20 00000000  - mov [esp+20],00000000 { 0 }
//	EXE+6C200 - D8 0D D8D84A00        - fmul dword ptr [(EXE+AD8D8)] { (0.80) }
//	EXE+6C206 - D9 54 24 10           - fst dword ptr [esp+10]
//	EXE+6C20A - D8 1D D8D84A00        - fcomp dword ptr [(EXE+AD8D8)] { (0.80) }
//	EXE+6C210 - DFE0                  - fnstsw ax
//	EXE+6C212 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C215 - 75 08                 - jne (EXE+6C21F)
//	EXE+6C217 - C7 44 24 10 CDCC4C3F  - mov [esp+10],3F4CCCCD { 0.80 }
//	EXE+6C21F - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6C223 - D8 1D DCD84A00        - fcomp dword ptr [(EXE+AD8DC)] { (-0.80) }
//	EXE+6C229 - DFE0                  - fnstsw ax
//	EXE+6C22B - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C22E - 74 08                 - je (EXE+6C238)
//	EXE+6C230 - C7 44 24 10 CDCC4C3F  - mov [esp+10],3F4CCCCD { 0.80 }
//	EXE+6C238 - 55                    - push ebp
//	EXE+6C239 - 56                    - push esi
//	EXE+6C23A - E8 E1FAFFFF           - call (EXE+6BD20)
//	EXE+6C23F - 89 44 24 48           - mov [esp+48],eax
//	EXE+6C243 - A1 48C05000           - mov eax,[(EXE+10C048)] { (0) }
//	EXE+6C248 - 83 C4 08              - add esp,08 { 8 }
//	EXE+6C24B - A9 00000002           - test eax,02000000 { 33554432 }
//	EXE+6C250 - 0F84 46020000         - je (EXE+6C49C)
//	EXE+6C256 - 8B 86 701E0000        - mov eax,[esi+00001E70]
//	EXE+6C25C - 33 C9                 - xor ecx,ecx
//	EXE+6C25E - 8A 50 10              - mov dl,[eax+10]
//	EXE+6C261 - 84 D2                 - test dl,dl
//	EXE+6C263 - 0F95 C1               - setne cl
//	EXE+6C266 - 8B E9                 - mov ebp,ecx
//	EXE+6C268 - D9 04 AD A08EE900     - fld dword ptr [ebp*4+(EXE+A98EA0)]
//	EXE+6C26F - D9 04 AD 808EE900     - fld dword ptr [ebp*4+(EXE+A98E80)]
//	EXE+6C276 - D9 04 AD A88EE900     - fld dword ptr [ebp*4+(EXE+A98EA8)]
//	EXE+6C27D - D9 5C 24 74           - fstp dword ptr [esp+74]
//	EXE+6C281 - D9 04 AD 888EE900     - fld dword ptr [ebp*4+(EXE+A98E88)]
//	EXE+6C288 - D9 5C 24 24           - fstp dword ptr [esp+24]
//	EXE+6C28C - D8 15 00D84A00        - fcom dword ptr [(EXE+AD800)] { (0.30) }
//	EXE+6C292 - DFE0                  - fnstsw ax
//	EXE+6C294 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C297 - 74 1C                 - je (EXE+6C2B5)
//	EXE+6C299 - D9 44 24 24           - fld dword ptr [esp+24]
//	EXE+6C29D - D8 1D 00D84A00        - fcomp dword ptr [(EXE+AD800)] { (0.30) }
//	EXE+6C2A3 - DFE0                  - fnstsw ax
//	EXE+6C2A5 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C2A8 - 74 0B                 - je (EXE+6C2B5)
//	EXE+6C2AA - 33 DB                 - xor ebx,ebx
//	EXE+6C2AC - 33 D2                 - xor edx,edx
//	EXE+6C2AE - BF 01000000           - mov edi,00000001 { 1 }
//	EXE+6C2B3 - EB 09                 - jmp (EXE+6C2BE)
//	EXE+6C2B5 - BF 01000000           - mov edi,00000001 { 1 }
//	EXE+6C2BA - 33 DB                 - xor ebx,ebx
//	EXE+6C2BC - 8B D7                 - mov edx,edi
//	EXE+6C2BE - D9C0                  - fld st(0)
//	EXE+6C2C0 - A1 DC96E900           - mov eax,[(EXE+A996DC)] { (9) }
//	EXE+6C2C5 - 8B 0C AD B08EE900     - mov ecx,[ebp*4+(EXE+A98EB0)]
//	EXE+6C2CC - D9C2                  - fld st(2)
//	EXE+6C2CE - D9C9                  - fxch st(1)
//	EXE+6C2D0 - D8 64 24 24           - fsub dword ptr [esp+24]
//	EXE+6C2D4 - D9C9                  - fxch st(1)
//	EXE+6C2D6 - D8 1D E0D84A00        - fcomp dword ptr [(EXE+AD8E0)] { (-0.50) }
//	EXE+6C2DC - F6 C4 40              - test ah,40 { 64 }
//	EXE+6C2DF - 74 56                 - je (EXE+6C337)
//	EXE+6C2E1 - D8 0D E0D84A00        - fmul dword ptr [(EXE+AD8E0)] { (-0.50) }
//	EXE+6C2E7 - DFE0                  - fnstsw ax
//	EXE+6C2E9 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C2EC - D9 5C 24 14           - fstp dword ptr [esp+14]
//	EXE+6C2F0 - 74 15                 - je (EXE+6C307)
//	EXE+6C2F2 - D9 44 24 74           - fld dword ptr [esp+74]
//	EXE+6C2F6 - D8 1D E0D84A00        - fcomp dword ptr [(EXE+AD8E0)] { (-0.50) }
//	EXE+6C2FC - 89 7C 24 18           - mov [esp+18],edi
//	EXE+6C300 - DFE0                  - fnstsw ax
//	EXE+6C302 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C305 - 75 04                 - jne (EXE+6C30B)
//	EXE+6C307 - 89 5C 24 18           - mov [esp+18],ebx
//	EXE+6C30B - D9C1                  - fld st(1)
//	EXE+6C30D - D8 1D 74D74A00        - fcomp dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6C313 - DFE0                  - fnstsw ax
//	EXE+6C315 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C318 - 75 17                 - jne (EXE+6C331)
//	EXE+6C31A - D9 44 24 74           - fld dword ptr [esp+74]
//	EXE+6C31E - D8 1D 74D74A00        - fcomp dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6C324 - DFE0                  - fnstsw ax
//	EXE+6C326 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C329 - 75 06                 - jne (EXE+6C331)
//	EXE+6C32B - 89 7C 24 1C           - mov [esp+1C],edi
//	EXE+6C32F - EB 58                 - jmp (EXE+6C389)
//	EXE+6C331 - 89 5C 24 1C           - mov [esp+1C],ebx
//	EXE+6C335 - EB 52                 - jmp (EXE+6C389)
//	EXE+6C337 - D8 0D 74D74A00        - fmul dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6C33D - DFE0                  - fnstsw ax
//	EXE+6C33F - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C342 - D9 5C 24 14           - fstp dword ptr [esp+14]
//	EXE+6C346 - 74 15                 - je (EXE+6C35D)
//	EXE+6C348 - D9 44 24 74           - fld dword ptr [esp+74]
//	EXE+6C34C - D8 1D E0D84A00        - fcomp dword ptr [(EXE+AD8E0)] { (-0.50) }
//	EXE+6C352 - 89 7C 24 1C           - mov [esp+1C],edi
//	EXE+6C356 - DFE0                  - fnstsw ax
//	EXE+6C358 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C35B - 75 04                 - jne (EXE+6C361)
//	EXE+6C35D - 89 5C 24 1C           - mov [esp+1C],ebx
//	EXE+6C361 - D9C1                  - fld st(1)
//	EXE+6C363 - D8 1D 74D74A00        - fcomp dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6C369 - DFE0                  - fnstsw ax
//	EXE+6C36B - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C36E - 75 15                 - jne (EXE+6C385)
//	EXE+6C370 - D9 44 24 74           - fld dword ptr [esp+74]
//	EXE+6C374 - D8 1D 74D74A00        - fcomp dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6C37A - 89 7C 24 18           - mov [esp+18],edi
//	EXE+6C37E - DFE0                  - fnstsw ax
//	EXE+6C380 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C383 - 74 04                 - je (EXE+6C389)
//	EXE+6C385 - 89 5C 24 18           - mov [esp+18],ebx
//	EXE+6C389 - D9 04 AD 888EE900     - fld dword ptr [ebp*4+(EXE+A98E88)]
//	EXE+6C390 - D9C9                  - fxch st(1)
//	EXE+6C392 - D8 1D E4D84A00        - fcomp dword ptr [(EXE+AD8E4)] { (-0.60) }
//	EXE+6C398 - D8 04 AD 808EE900     - fadd dword ptr [ebp*4+(EXE+A98E80)]
//	EXE+6C39F - 89 54 24 28           - mov [esp+28],edx
//	EXE+6C3A3 - D8 0D 74D74A00        - fmul dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6C3A9 - DFE0                  - fnstsw ax
//	EXE+6C3AB - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C3AE - D9 5C 24 10           - fstp dword ptr [esp+10]
//	EXE+6C3B2 - 74 15                 - je (EXE+6C3C9)
//	EXE+6C3B4 - D9 44 24 24           - fld dword ptr [esp+24]
//	EXE+6C3B8 - D8 1D E4D84A00        - fcomp dword ptr [(EXE+AD8E4)] { (-0.60) }
//	EXE+6C3BE - 89 7C 24 20           - mov [esp+20],edi
//	EXE+6C3C2 - DFE0                  - fnstsw ax
//	EXE+6C3C4 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C3C7 - 75 04                 - jne (EXE+6C3CD)
//	EXE+6C3C9 - 89 5C 24 20           - mov [esp+20],ebx
//	EXE+6C3CD - 8B 3C AD 908EE900     - mov edi,[ebp*4+(EXE+A98E90)]
//	EXE+6C3D4 - 8B D9                 - mov ebx,ecx
//	EXE+6C3D6 - 83 E3 04              - and ebx,04 { 4 }
//	EXE+6C3D9 - 83 E7 08              - and edi,08 { 8 }
//	EXE+6C3DC - F6 C1 80              - test cl,-80 { 128 }
//	EXE+6C3DF - 74 4B                 - je (EXE+6C42C)
//	EXE+6C3E1 - D9 86 F4020000        - fld dword ptr [esi+000002F4]
//	EXE+6C3E7 - DC 2D 382AE200        - fsubr qword ptr [(EXE+A22A38)] { (11.37) }
//	EXE+6C3ED - DC 1D D0D84A00        - fcomp qword ptr [(EXE+AD8D0)] { (0.25) }
//	EXE+6C3F3 - DFE0                  - fnstsw ax
//	EXE+6C3F5 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C3F8 - 75 07                 - jne (EXE+6C401)
//	EXE+6C3FA - C6 86 F9020000 00     - mov byte ptr [esi+000002F9],00 { 0 }
//	EXE+6C401 - 8A 8E F9020000        - mov cl,[esi+000002F9]
//	EXE+6C407 - DD 05 382AE200        - fld qword ptr [(EXE+A22A38)] { (11.37) }
//	EXE+6C40D - FE C1                 - inc cl
//	EXE+6C40F - D9 9E F4020000        - fstp dword ptr [esi+000002F4]
//	EXE+6C415 - 8A C1                 - mov al,cl
//	EXE+6C417 - 88 8E F9020000        - mov [esi+000002F9],cl
//	EXE+6C41D - 3C 01                 - cmp al,01 { 1 }
//	EXE+6C41F - 7E 0B                 - jle (EXE+6C42C)
//	EXE+6C421 - B9 01000000           - mov ecx,00000001 { 1 }
//	EXE+6C426 - 89 4C 24 34           - mov [esp+34],ecx
//	EXE+6C42A - EB 05                 - jmp (EXE+6C431)
//	EXE+6C42C - B9 01000000           - mov ecx,00000001 { 1 }
//	EXE+6C431 - F6 04 AD C08EE900 80  - test byte ptr [ebp*4+(EXE+A98EC0)],-80 { 128 }
//	EXE+6C439 - 74 0C                 - je (EXE+6C447)
//	EXE+6C43B - DD 05 382AE200        - fld qword ptr [(EXE+A22A38)] { (11.37) }
//	EXE+6C441 - D9 9E F4020000        - fstp dword ptr [esi+000002F4]
//	EXE+6C447 - F6 04 AD 908EE900 80  - test byte ptr [ebp*4+(EXE+A98E90)],-80 { 128 }
//	EXE+6C44F - 74 1D                 - je (EXE+6C46E)
//	EXE+6C451 - D9 86 F4020000        - fld dword ptr [esi+000002F4]
//	EXE+6C457 - DC 2D 382AE200        - fsubr qword ptr [(EXE+A22A38)] { (11.37) }
//	EXE+6C45D - DC 1D 78D74A00        - fcomp qword ptr [(EXE+AD778)] { (0.50) }
//	EXE+6C463 - DFE0                  - fnstsw ax
//	EXE+6C465 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C468 - 75 04                 - jne (EXE+6C46E)
//	EXE+6C46A - 89 4C 24 2C           - mov [esp+2C],ecx
//	EXE+6C46E - D8 1D 74D74A00        - fcomp dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6C474 - DFE0                  - fnstsw ax
//	EXE+6C476 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C479 - 75 17                 - jne (EXE+6C492)
//	EXE+6C47B - D9 44 24 74           - fld dword ptr [esp+74]
//	EXE+6C47F - D8 1D E0D84A00        - fcomp dword ptr [(EXE+AD8E0)] { (-0.50) }
//	EXE+6C485 - DFE0                  - fnstsw ax
//	EXE+6C487 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C48A - 74 06                 - je (EXE+6C492)
//	EXE+6C48C - 89 4C 24 24           - mov [esp+24],ecx
//	EXE+6C490 - EB 12                 - jmp (EXE+6C4A4)
//	EXE+6C492 - C7 44 24 24 00000000  - mov [esp+24],00000000 { 0 }
//	EXE+6C49A - EB 08                 - jmp (EXE+6C4A4)
//	EXE+6C49C - 8B 7C 24 38           - mov edi,[esp+38]
//	EXE+6C4A0 - 8B 5C 24 3C           - mov ebx,[esp+3C]
//	EXE+6C4A4 - C7 86 D4000000 00000000 - mov [esi+000000D4],00000000 { 0 }
//	EXE+6C4AE - 8B 0D 84704C00        - mov ecx,[(EXE+C7084)] { (-1) }
//	EXE+6C4B4 - 85 C9                 - test ecx,ecx
//	EXE+6C4B6 - 7E 70                 - jle (EXE+6C528)
//	EXE+6C4B8 - 83 F9 05              - cmp ecx,05 { 5 }
//	EXE+6C4BB - 75 36                 - jne (EXE+6C4F3)
//	EXE+6C4BD - D9 86 E0000000        - fld dword ptr [esi+000000E0]
//	EXE+6C4C3 - D8 1D DCD74A00        - fcomp dword ptr [(EXE+AD7DC)] { (3D810625) }
//	EXE+6C4C9 - DFE0                  - fnstsw ax
//	EXE+6C4CB - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C4CE - 75 23                 - jne (EXE+6C4F3)
//	EXE+6C4D0 - D9 86 E0000000        - fld dword ptr [esi+000000E0]
//	EXE+6C4D6 - D8 1D E0D74A00        - fcomp dword ptr [(EXE+AD7E0)] { (3D9374BC) }
//	EXE+6C4DC - DFE0                  - fnstsw ax
//	EXE+6C4DE - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C4E1 - 74 10                 - je (EXE+6C4F3)
//	EXE+6C4E3 - C7 86 D4000000 01000000 - mov [esi+000000D4],00000001 { 1 }
//	EXE+6C4ED - 8B 0D 84704C00        - mov ecx,[(EXE+C7084)] { (-1) }
//	EXE+6C4F3 - 83 F9 06              - cmp ecx,06 { 6 }
//	EXE+6C4F6 - 75 30                 - jne (EXE+6C528)
//	EXE+6C4F8 - D9 86 E0000000        - fld dword ptr [esi+000000E0]
//	EXE+6C4FE - D8 1D E4D74A00        - fcomp dword ptr [(EXE+AD7E4)] { (3DBE76C9) }
//	EXE+6C504 - DFE0                  - fnstsw ax
//	EXE+6C506 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C509 - 75 1D                 - jne (EXE+6C528)
//	EXE+6C50B - D9 86 E0000000        - fld dword ptr [esi+000000E0]
//	EXE+6C511 - D8 1D E8D74A00        - fcomp dword ptr [(EXE+AD7E8)] { (0.11) }
//	EXE+6C517 - DFE0                  - fnstsw ax
//	EXE+6C519 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C51C - 74 0A                 - je (EXE+6C528)
//	EXE+6C51E - C7 86 D4000000 01000000 - mov [esi+000000D4],00000001 { 1 }
//	EXE+6C528 - 56                    - push esi
//	EXE+6C529 - E8 92E4FFFF           - call (EXE+6A9C0)
//	EXE+6C52E - 83 C4 04              - add esp,04 { 4 }
//	EXE+6C531 - 89 44 24 3C           - mov [esp+3C],eax
//	EXE+6C535 - 85 C0                 - test eax,eax
//	EXE+6C537 - 74 21                 - je (EXE+6C55A)
//	EXE+6C539 - 33 C0                 - xor eax,eax
//	EXE+6C53B - C7 44 24 3C 01000000  - mov [esp+3C],00000001 { 1 }
//	EXE+6C543 - 89 44 24 1C           - mov [esp+1C],eax
//	EXE+6C547 - 89 44 24 18           - mov [esp+18],eax
//	EXE+6C54B - 89 44 24 40           - mov [esp+40],eax
//	EXE+6C54F - 8B 46 60              - mov eax,[esi+60]
//	EXE+6C552 - 25 FFFF7FFF           - and eax,FF7FFFFF { -8388609 }
//	EXE+6C557 - 89 46 60              - mov [esi+60],eax
//	EXE+6C55A - 8B 46 60              - mov eax,[esi+60]
//	EXE+6C55D - A8 10                 - test al,10 { 16 }
//	EXE+6C55F - 0F84 CE000000         - je (EXE+6C633)
//	EXE+6C565 - F6 C4 02              - test ah,02 { 2 }
//	EXE+6C568 - 0F85 C5000000         - jne (EXE+6C633)
//	EXE+6C56E - F7 46 64 00000002     - test [esi+64],02000000 { 33554432 }
//	EXE+6C575 - 0F85 B8000000         - jne (EXE+6C633)
//	EXE+6C57B - 56                    - push esi
//	EXE+6C57C - E8 6FE4FFFF           - call (EXE+6A9F0)
//	EXE+6C581 - 8A 44 24 40           - mov al,[esp+40]
//	EXE+6C585 - 83 C4 04              - add esp,04 { 4 }
//	EXE+6C588 - A8 01                 - test al,01 { 1 }
//	EXE+6C58A - 74 08                 - je (EXE+6C594)
//	EXE+6C58C - D8 25 E8D84A00        - fsub dword ptr [(EXE+AD8E8)] { (-0.20) }
//	EXE+6C592 - EB 0A                 - jmp (EXE+6C59E)
//	EXE+6C594 - A8 02                 - test al,02 { 2 }
//	EXE+6C596 - 74 06                 - je (EXE+6C59E)
//	EXE+6C598 - D8 25 ECD84A00        - fsub dword ptr [(EXE+AD8EC)] { (0.20) }
//	EXE+6C59E - D8 0D F0D84A00        - fmul dword ptr [(EXE+AD8F0)] { (1.50) }
//	EXE+6C5A4 - D9 54 24 74           - fst dword ptr [esp+74]
//	EXE+6C5A8 - D8 1D 50D74A00        - fcomp dword ptr [(EXE+AD750)] { (0) }
//	EXE+6C5AE - DFE0                  - fnstsw ax
//	EXE+6C5B0 - F6 C4 40              - test ah,40 { 64 }
//	EXE+6C5B3 - 75 58                 - jne (EXE+6C60D)
//	EXE+6C5B5 - D9 44 24 74           - fld dword ptr [esp+74]
//	EXE+6C5B9 - D8 1D 50D74A00        - fcomp dword ptr [(EXE+AD750)] { (0) }
//	EXE+6C5BF - DFE0                  - fnstsw ax
//	EXE+6C5C1 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C5C4 - 75 07                 - jne (EXE+6C5CD)
//	EXE+6C5C6 - B8 01000000           - mov eax,00000001 { 1 }
//	EXE+6C5CB - EB 02                 - jmp (EXE+6C5CF)
//	EXE+6C5CD - 33 C0                 - xor eax,eax
//	EXE+6C5CF - D9 44 24 74           - fld dword ptr [esp+74]
//	EXE+6C5D3 - D8 0D F4D84A00        - fmul dword ptr [(EXE+AD8F4)] { (-30.00) }
//	EXE+6C5D9 - 8D 04 80              - lea eax,[eax+eax*4]
//	EXE+6C5DC - 6A 00                 - push 00 { 0 }
//	EXE+6C5DE - 6A FF                 - push -01 { 255 }
//	EXE+6C5E0 - D8 2D F8D84A00        - fsubr dword ptr [(EXE+AD8F8)] { (60.00) }
//	EXE+6C5E6 - 8D 14 C0              - lea edx,[eax+eax*8]
//	EXE+6C5E9 - 8D 04 95 5A000000     - lea eax,[edx*4+0000005A]
//	EXE+6C5F0 - 50                    - push eax
//	EXE+6C5F1 - E8 2A270300           - call (EXE+9ED20)
//	EXE+6C5F6 - 50                    - push eax
//	EXE+6C5F7 - 6A 01                 - push 01 { 1 }
//	EXE+6C5F9 - E8 E2D8F9FF           - call SWEP1RCR.EXE+9EE0
//	EXE+6C5FE - 83 C4 14              - add esp,14 { 20 }
//	EXE+6C601 - C7 05 A0784D00 01000000 - mov [(EXE+D78A0)],00000001 { (0),1 }
//	EXE+6C60B - EB 0A                 - jmp (EXE+6C617)
//	EXE+6C60D - 6A 01                 - push 01 { 1 }
//	EXE+6C60F - E8 9CDAF9FF           - call SWEP1RCR.EXE+A0B0
//	EXE+6C614 - 83 C4 04              - add esp,04 { 4 }
//	EXE+6C617 - D9 44 24 74           - fld dword ptr [esp+74]
//	EXE+6C61B - D8 0D E4D84A00        - fmul dword ptr [(EXE+AD8E4)] { (-0.60) }
//	EXE+6C621 - 8B 4C 24 74           - mov ecx,[esp+74]
//	EXE+6C625 - 89 0D E4CA5000        - mov [(EXE+10CAE4)],ecx { (0) }
//	EXE+6C62B - D8 6C 24 14           - fsubr dword ptr [esp+14]
//	EXE+6C62F - D9 5C 24 14           - fstp dword ptr [esp+14]
//	EXE+6C633 - A1 48C05000           - mov eax,[(EXE+10C048)] { (0) }
//	EXE+6C638 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C63B - 74 57                 - je (EXE+6C694)
//	EXE+6C63D - A1 40C05000           - mov eax,[(EXE+10C040)] { (0) }
//	EXE+6C642 - 85 C0                 - test eax,eax
//	EXE+6C644 - 74 31                 - je (EXE+6C677)
//	EXE+6C646 - 8B 44 24 44           - mov eax,[esp+44]
//	EXE+6C64A - 85 C0                 - test eax,eax
//	EXE+6C64C - 75 08                 - jne (EXE+6C656)
//	EXE+6C64E - 8B 4C 24 48           - mov ecx,[esp+48]
//	EXE+6C652 - 85 C9                 - test ecx,ecx
//	EXE+6C654 - 74 21                 - je (EXE+6C677)
//	EXE+6C656 - F7 D8                 - neg eax
//	EXE+6C658 - 1B C0                 - sbb eax,eax
//	EXE+6C65A - 8D 54 24 50           - lea edx,[esp+50]
//	EXE+6C65E - 24 FE                 - and al,-02 { 254 }
//	EXE+6C660 - 52                    - push edx
//	EXE+6C661 - 40                    - inc eax
//	EXE+6C662 - 56                    - push esi
//	EXE+6C663 - C7 44 24 58 70616E53  - mov [esp+58],536E6170 { "panS" }
//	EXE+6C66B - 89 44 24 5C           - mov [esp+5C],eax
//	EXE+6C66F - E8 8C45FEFF           - call (EXE+50C00)
//	EXE+6C674 - 83 C4 08              - add esp,08 { 8 }
//	EXE+6C677 - A1 48C05000           - mov eax,[(EXE+10C048)] { (0) }
//	EXE+6C67C - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C67F - 74 13                 - je (EXE+6C694)
//	EXE+6C681 - A1 40C05000           - mov eax,[(EXE+10C040)] { (0) }
//	EXE+6C686 - 85 C0                 - test eax,eax
//	EXE+6C688 - 74 0A                 - je (EXE+6C694)
//	EXE+6C68A - 55                    - push ebp
//	EXE+6C68B - 56                    - push esi
//	EXE+6C68C - E8 FFE2FFFF           - call (EXE+6A990)
//	EXE+6C691 - 83 C4 08              - add esp,08 { 8 }
//	EXE+6C694 - 8B 44 24 34           - mov eax,[esp+34]
//	EXE+6C698 - 85 C0                 - test eax,eax
//	EXE+6C69A - 75 0D                 - jne (EXE+6C6A9)
//	EXE+6C69C - A1 E0794D00           - mov eax,[(EXE+D79E0)] { (0) }
//	EXE+6C6A1 - 85 C0                 - test eax,eax
//	EXE+6C6A3 - 0F84 10010000         - je (EXE+6C7B9)
//	EXE+6C6A9 - C7 05 E0794D00 00000000 - mov [(EXE+D79E0)],00000000 { (0),0 }
//	EXE+6C6B3 - 8B 46 60              - mov eax,[esi+60]
//	EXE+6C6B6 - 8B C8                 - mov ecx,eax
//	EXE+6C6B8 - 83 E1 0F              - and ecx,0F { 15 }
//	EXE+6C6BB - 80 F9 02              - cmp cl,02 { 2 }
//	EXE+6C6BE - 0F85 F5000000         - jne (EXE+6C7B9)
//	EXE+6C6C4 - F6 C4 58              - test ah,58 { 88 }
//	EXE+6C6C7 - 0F85 EC000000         - jne (EXE+6C7B9)
//	EXE+6C6CD - 8B 46 64              - mov eax,[esi+64]
//	EXE+6C6D0 - F6 C4 40              - test ah,40 { 64 }
//	EXE+6C6D3 - 0F85 E0000000         - jne (EXE+6C7B9)
//	EXE+6C6D9 - 8B 96 701E0000        - mov edx,[esi+00001E70]
//	EXE+6C6DF - 8B 42 18              - mov eax,[edx+18]
//	EXE+6C6E2 - 83 38 02              - cmp dword ptr [eax],02 { 2 }
//	EXE+6C6E5 - 75 1A                 - jne (EXE+6C701)
//	EXE+6C6E7 - 56                    - push esi
//	EXE+6C6E8 - E8 43F3FFFF           - call (EXE+6BA30)
//	EXE+6C6ED - 8B 8E 701E0000        - mov ecx,[esi+00001E70]
//	EXE+6C6F3 - 83 C4 04              - add esp,04 { 4 }
//	EXE+6C6F6 - 8B 11                 - mov edx,[ecx]
//	EXE+6C6F8 - 52                    - push edx
//	EXE+6C6F9 - E8 32F4FFFF           - call (EXE+6BB30)
//	EXE+6C6FE - 83 C4 04              - add esp,04 { 4 }
//	EXE+6C701 - E8 AA4F0100           - call (EXE+816B0)
//	EXE+6C706 - 89 44 24 74           - mov [esp+74],eax
//	EXE+6C70A - DB 44 24 74           - fild dword ptr [esp+74]
//	EXE+6C70E - D8 0D 68D74A00        - fmul dword ptr [(EXE+AD768)] { (805306368) }
//	EXE+6C714 - DC 1D 78D74A00        - fcomp qword ptr [(EXE+AD778)] { (0.50) }
//	EXE+6C71A - DFE0                  - fnstsw ax
//	EXE+6C71C - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C71F - 74 54                 - je (EXE+6C775)
//	EXE+6C721 - 8B 86 701E0000        - mov eax,[esi+00001E70]
//	EXE+6C727 - 8B 48 18              - mov ecx,[eax+18]
//	EXE+6C72A - 8B 01                 - mov eax,[ecx]
//	EXE+6C72C - 83 F8 0E              - cmp eax,0E { 14 }
//	EXE+6C72F - 75 11                 - jne (EXE+6C742)
//	EXE+6C731 - 8D 56 50              - lea edx,[esi+50]
//	EXE+6C734 - 52                    - push edx
//	EXE+6C735 - 6A 14                 - push 14 { 20 }
//	EXE+6C737 - 6A 13                 - push 13 { 19 }
//	EXE+6C739 - 6A 12                 - push 12 { 18 }
//	EXE+6C73B - 6A 12                 - push 12 { 18 }
//	EXE+6C73D - 6A 03                 - push 03 { 3 }
//	EXE+6C73F - 50                    - push eax
//	EXE+6C740 - EB 4D                 - jmp (EXE+6C78F)
//	EXE+6C742 - 8D 4E 50              - lea ecx,[esi+50]
//	EXE+6C745 - 51                    - push ecx
//	EXE+6C746 - 6A 14                 - push 14 { 20 }
//	EXE+6C748 - 6A 13                 - push 13 { 19 }
//	EXE+6C74A - 6A 12                 - push 12 { 18 }
//	EXE+6C74C - 6A 11                 - push 11 { 17 }
//	EXE+6C74E - 6A 03                 - push 03 { 3 }
//	EXE+6C750 - 50                    - push eax
//	EXE+6C751 - 6A 01                 - push 01 { 1 }
//	EXE+6C753 - E8 38AEFBFF           - call (EXE+27590)
//	EXE+6C758 - 8B 96 701E0000        - mov edx,[esi+00001E70]
//	EXE+6C75E - 83 C4 20              - add esp,20 { 32 }
//	EXE+6C761 - 50                    - push eax
//	EXE+6C762 - 8B 42 18              - mov eax,[edx+18]
//	EXE+6C765 - 8B 08                 - mov ecx,[eax]
//	EXE+6C767 - 51                    - push ecx
//	EXE+6C768 - 6A 01                 - push 01 { 1 }
//	EXE+6C76A - 68 6E756174           - push 7461756E { "nuat" }
//	EXE+6C76F - 6A 00                 - push 00 { 0 }
//	EXE+6C771 - 6A 01                 - push 01 { 1 }
//	EXE+6C773 - EB 3C                 - jmp (EXE+6C7B1)
//	EXE+6C775 - 8B 86 701E0000        - mov eax,[esi+00001E70]
//	EXE+6C77B - 8D 56 50              - lea edx,[esi+50]
//	EXE+6C77E - 52                    - push edx
//	EXE+6C77F - 6A 19                 - push 19 { 25 }
//	EXE+6C781 - 8B 48 18              - mov ecx,[eax+18]
//	EXE+6C784 - 6A 18                 - push 18 { 24 }
//	EXE+6C786 - 6A 17                 - push 17 { 23 }
//	EXE+6C788 - 6A 16                 - push 16 { 22 }
//	EXE+6C78A - 8B 11                 - mov edx,[ecx]
//	EXE+6C78C - 6A 15                 - push 15 { 21 }
//	EXE+6C78E - 52                    - push edx
//	EXE+6C78F - 6A 01                 - push 01 { 1 }
//	EXE+6C791 - E8 FAADFBFF           - call (EXE+27590)
//	EXE+6C796 - 83 C4 20              - add esp,20 { 32 }
//	EXE+6C799 - 50                    - push eax
//	EXE+6C79A - 8B 86 701E0000        - mov eax,[esi+00001E70]
//	EXE+6C7A0 - 8B 48 18              - mov ecx,[eax+18]
//	EXE+6C7A3 - 8B 11                 - mov edx,[ecx]
//	EXE+6C7A5 - 52                    - push edx
//	EXE+6C7A6 - 6A 01                 - push 01 { 1 }
//	EXE+6C7A8 - 68 6E756174           - push 7461756E { "nuat" }
//	EXE+6C7AD - 6A 00                 - push 00 { 0 }
//	EXE+6C7AF - 6A FF                 - push -01 { 255 }
//	EXE+6C7B1 - E8 5A17FBFF           - call (EXE+1DF10)
//	EXE+6C7B6 - 83 C4 18              - add esp,18 { 24 }
//	EXE+6C7B9 - 8B 46 60              - mov eax,[esi+60]
//	EXE+6C7BC - 85 FF                 - test edi,edi
//	EXE+6C7BE - 74 07                 - je (EXE+6C7C7)
//	EXE+6C7C0 - 0D 00001000           - or eax,00100000 { 1048576 }
//	EXE+6C7C5 - EB 05                 - jmp (EXE+6C7CC)
//	EXE+6C7C7 - 25 FFFFEFFF           - and eax,FFEFFFFF { -1048577 }
//	EXE+6C7CC - 89 46 60              - mov [esi+60],eax
//	EXE+6C7CF - 8B 44 24 2C           - mov eax,[esp+2C]
//	EXE+6C7D3 - 85 C0                 - test eax,eax
//	EXE+6C7D5 - 8B 46 60              - mov eax,[esi+60]
//	EXE+6C7D8 - 74 05                 - je (EXE+6C7DF)
//	EXE+6C7DA - 80 CC 04              - or ah,04 { 4 }
//	EXE+6C7DD - EB 03                 - jmp (EXE+6C7E2)
//	EXE+6C7DF - 80 E4 FB              - and ah,-05 { 251 }
//	EXE+6C7E2 - 8B D0                 - mov edx,eax
//	EXE+6C7E4 - 89 46 60              - mov [esi+60],eax
//	EXE+6C7E7 - 81 E2 FFFFFF7F        - and edx,7FFFFFFF { 2147483647 }
//	EXE+6C7ED - 8B C2                 - mov eax,edx
//	EXE+6C7EF - 89 56 60              - mov [esi+60],edx
//	EXE+6C7F2 - A8 0F                 - test al,0F { 15 }
//	EXE+6C7F4 - 74 56                 - je (EXE+6C84C)
//	EXE+6C7F6 - F6 C4 40              - test ah,40 { 64 }
//	EXE+6C7F9 - 75 51                 - jne (EXE+6C84C)
//	EXE+6C7FB - 85 DB                 - test ebx,ebx
//	EXE+6C7FD - 74 20                 - je (EXE+6C81F)
//	EXE+6C7FF - 8D 44 24 50           - lea eax,[esp+50]
//	EXE+6C803 - C7 44 24 50 74754243  - mov [esp+50],43427574 { "tuBC" }
//	EXE+6C80B - 50                    - push eax
//	EXE+6C80C - 68 6E614D63           - push aticfx32.dll+B616E { (131) }
//	EXE+6C811 - 89 74 24 5C           - mov [esp+5C],esi
//	EXE+6C815 - E8 3644FEFF           - call (EXE+50C50)
//	EXE+6C81A - 83 C4 08              - add esp,08 { 8 }
//	EXE+6C81D - EB 2D                 - jmp (EXE+6C84C)
//	EXE+6C81F - A1 D083EC00           - mov eax,[(EXE+AC83D0)] { (0) }
//	EXE+6C824 - 85 C0                 - test eax,eax
//	EXE+6C826 - 74 24                 - je (EXE+6C84C)
//	EXE+6C828 - 8D 4C 24 50           - lea ecx,[esp+50]
//	EXE+6C82C - 89 44 24 50           - mov [esp+50],eax
//	EXE+6C830 - 51                    - push ecx
//	EXE+6C831 - 68 6E614D63           - push aticfx32.dll+B616E { (131) }
//	EXE+6C836 - 89 74 24 5C           - mov [esp+5C],esi
//	EXE+6C83A - E8 1144FEFF           - call (EXE+50C50)
//	EXE+6C83F - 83 C4 08              - add esp,08 { 8 }
//	EXE+6C842 - C7 05 D083EC00 00000000 - mov [(EXE+AC83D0)],00000000 { (0),0 }
//	EXE+6C84C - 56                    - push esi
//	EXE+6C84D - E8 DEE1FFFF           - call (EXE+6AA30)
//	EXE+6C852 - 83 C4 04              - add esp,04 { 4 }
//	EXE+6C855 - 56                    - push esi
//	EXE+6C856 - E8 B5E2FFFF           - call (EXE+6AB10)
//	EXE+6C85B - 8B 46 60              - mov eax,[esi+60]
//	EXE+6C85E - 83 C4 04              - add esp,04 { 4 }
//	EXE+6C861 - A9 00000002           - test eax,02000000 { 33554432 }
//	EXE+6C866 - 74 74                 - je (EXE+6C8DC)
//	EXE+6C868 - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6C86C - D8 1D FCD84A00        - fcomp dword ptr [(EXE+AD8FC)] { (0.05) }
//	EXE+6C872 - DFE0                  - fnstsw ax
//	EXE+6C874 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C877 - 74 1F                 - je (EXE+6C898)
//	EXE+6C879 - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6C87D - D9E0                  - fchs 
//	EXE+6C87F - D8 1D FCD84A00        - fcomp dword ptr [(EXE+AD8FC)] { (0.05) }
//	EXE+6C885 - DFE0                  - fnstsw ax
//	EXE+6C887 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C88A - 74 0C                 - je (EXE+6C898)
//	EXE+6C88C - C7 86 24020000 00000000 - mov [esi+00000224],00000000 { 0 }
//	EXE+6C896 - EB 3C                 - jmp (EXE+6C8D4)
//	EXE+6C898 - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6C89C - D8 1D 50D74A00        - fcomp dword ptr [(EXE+AD750)] { (0) }
//	EXE+6C8A2 - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6C8A6 - D8 0D 00D94A00        - fmul dword ptr [(EXE+AD900)] { (1.25) }
//	EXE+6C8AC - DFE0                  - fnstsw ax
//	EXE+6C8AE - D9C0                  - fld st(0)
//	EXE+6C8B0 - DEC9                  - fmulp st(1),st(0)
//	EXE+6C8B2 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C8B5 - 74 02                 - je (EXE+6C8B9)
//	EXE+6C8B7 - D9E0                  - fchs 
//	EXE+6C8B9 - D8 0D D8D84A00        - fmul dword ptr [(EXE+AD8D8)] { (0.80) }
//	EXE+6C8BF - D9 46 74              - fld dword ptr [esi+74]
//	EXE+6C8C2 - D8C9                  - fmul st(0),st(1)
//	EXE+6C8C4 - D9E0                  - fchs 
//	EXE+6C8C6 - D8 0D 74D74A00        - fmul dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6C8CC - D9 9E 24020000        - fstp dword ptr [esi+00000224]
//	EXE+6C8D2 - DDD8                  - fstp st(0)
//	EXE+6C8D4 - C7 44 24 10 00000000  - mov [esp+10],00000000 { 0 }
//	EXE+6C8DC - D9 05 4C88EC00        - fld dword ptr [(EXE+AC884C)] { (0.00) }
//	EXE+6C8E2 - D8 1D 50D74A00        - fcomp dword ptr [(EXE+AD750)] { (0) }
//	EXE+6C8E8 - DFE0                  - fnstsw ax
//	EXE+6C8EA - F6 C4 40              - test ah,40 { 64 }
//	EXE+6C8ED - 75 26                 - jne (EXE+6C915)
//	EXE+6C8EF - D9 05 AC88EC00        - fld dword ptr [(EXE+AC88AC)] { (0.00) }
//	EXE+6C8F5 - DC 1D 08D94A00        - fcomp qword ptr [(EXE+AD908)] { (0.20) }
//	EXE+6C8FB - DFE0                  - fnstsw ax
//	EXE+6C8FD - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C900 - 74 13                 - je (EXE+6C915)
//	EXE+6C902 - D9 05 AC88EC00        - fld dword ptr [(EXE+AC88AC)] { (0.00) }
//	EXE+6C908 - DC 1D 30D84A00        - fcomp qword ptr [(EXE+AD830)] { (0.00) }
//	EXE+6C90E - DFE0                  - fnstsw ax
//	EXE+6C910 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C913 - 74 4C                 - je (EXE+6C961)
//	EXE+6C915 - D9 05 3088EC00        - fld dword ptr [(EXE+AC8830)] { (0.00) }
//	EXE+6C91B - DC 1D C8D84A00        - fcomp qword ptr [(EXE+AD8C8)] { (0.60) }
//	EXE+6C921 - DFE0                  - fnstsw ax
//	EXE+6C923 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C926 - 75 52                 - jne (EXE+6C97A)
//	EXE+6C928 - D9 05 5088EC00        - fld dword ptr [(EXE+AC8850)] { (0.00) }
//	EXE+6C92E - D8 1D 50D74A00        - fcomp dword ptr [(EXE+AD750)] { (0) }
//	EXE+6C934 - DFE0                  - fnstsw ax
//	EXE+6C936 - F6 C4 40              - test ah,40 { 64 }
//	EXE+6C939 - 75 3F                 - jne (EXE+6C97A)
//	EXE+6C93B - D9 05 B088EC00        - fld dword ptr [(EXE+AC88B0)] { (0.00) }
//	EXE+6C941 - DC 1D 08D94A00        - fcomp qword ptr [(EXE+AD908)] { (0.20) }
//	EXE+6C947 - DFE0                  - fnstsw ax
//	EXE+6C949 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6C94C - 74 2C                 - je (EXE+6C97A)
//	EXE+6C94E - D9 05 B088EC00        - fld dword ptr [(EXE+AC88B0)] { (0.00) }
//	EXE+6C954 - DC 1D 30D84A00        - fcomp qword ptr [(EXE+AD830)] { (0.00) }
//	EXE+6C95A - DFE0                  - fnstsw ax
//	EXE+6C95C - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C95F - 75 19                 - jne (EXE+6C97A)
//	EXE+6C961 - 8B 46 64              - mov eax,[esi+64]
//	EXE+6C964 - F6 C4 10              - test ah,10 { 16 }
//	EXE+6C967 - 75 11                 - jne (EXE+6C97A)
//	EXE+6C969 - 80 CC 10              - or ah,10 { 16 }
//	EXE+6C96C - F6 C4 08              - test ah,08 { 8 }
//	EXE+6C96F - 89 46 64              - mov [esi+64],eax
//	EXE+6C972 - 74 06                 - je (EXE+6C97A)
//	EXE+6C974 - 80 CC 20              - or ah,20 { 32 }
//	EXE+6C977 - 89 46 64              - mov [esi+64],eax
//	EXE+6C97A - 8B 46 64              - mov eax,[esi+64]
//	EXE+6C97D - F6 C4 20              - test ah,20 { 32 }
//	EXE+6C980 - 0F84 88000000         - je (EXE+6CA0E)
//	EXE+6C986 - 68 00000800           - push 00080000 { 524288 }
//	EXE+6C98B - 6A 00                 - push 00 { 0 }
//	EXE+6C98D - E8 DEACFBFF           - call (EXE+27670)
//	EXE+6C992 - 83 C4 08              - add esp,08 { 8 }
//	EXE+6C995 - 85 C0                 - test eax,eax
//	EXE+6C997 - 75 33                 - jne (EXE+6C9CC)
//	EXE+6C999 - 8B 86 701E0000        - mov eax,[esi+00001E70]
//	EXE+6C99F - 8D 56 50              - lea edx,[esi+50]
//	EXE+6C9A2 - 52                    - push edx
//	EXE+6C9A3 - 6A 02                 - push 02 { 2 }
//	EXE+6C9A5 - 8B 48 18              - mov ecx,[eax+18]
//	EXE+6C9A8 - 6A 02                 - push 02 { 2 }
//	EXE+6C9AA - 6A 02                 - push 02 { 2 }
//	EXE+6C9AC - 6A 02                 - push 02 { 2 }
//	EXE+6C9AE - 8B 11                 - mov edx,[ecx]
//	EXE+6C9B0 - 6A 02                 - push 02 { 2 }
//	EXE+6C9B2 - 52                    - push edx
//	EXE+6C9B3 - 6A 01                 - push 01 { 1 }
//	EXE+6C9B5 - E8 D6ABFBFF           - call (EXE+27590)
//	EXE+6C9BA - 83 C4 20              - add esp,20 { 32 }
//	EXE+6C9BD - 68 00000800           - push 00080000 { 524288 }
//	EXE+6C9C2 - 6A 00                 - push 00 { 0 }
//	EXE+6C9C4 - E8 C7ACFBFF           - call (EXE+27690)
//	EXE+6C9C9 - 83 C4 08              - add esp,08 { 8 }
//	EXE+6C9CC - D9 05 4C88EC00        - fld dword ptr [(EXE+AC884C)] { (0.00) }
//	EXE+6C9D2 - D8 1D 50D74A00        - fcomp dword ptr [(EXE+AD750)] { (0) }
//	EXE+6C9D8 - DFE0                  - fnstsw ax
//	EXE+6C9DA - F6 C4 40              - test ah,40 { 64 }
//	EXE+6C9DD - 74 13                 - je (EXE+6C9F2)
//	EXE+6C9DF - D9 05 3088EC00        - fld dword ptr [(EXE+AC8830)] { (0.00) }
//	EXE+6C9E5 - DC 1D C8D84A00        - fcomp qword ptr [(EXE+AD8C8)] { (0.60) }
//	EXE+6C9EB - DFE0                  - fnstsw ax
//	EXE+6C9ED - F6 C4 41              - test ah,41 { 65 }
//	EXE+6C9F0 - 75 13                 - jne (EXE+6CA05)
//	EXE+6C9F2 - D9 86 A0010000        - fld dword ptr [esi+000001A0]
//	EXE+6C9F8 - D8 1D 10D94A00        - fcomp dword ptr [(EXE+AD910)] { (290.00) }
//	EXE+6C9FE - DFE0                  - fnstsw ax
//	EXE+6CA00 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6CA03 - 75 09                 - jne (EXE+6CA0E)
//	EXE+6CA05 - 8B 46 64              - mov eax,[esi+64]
//	EXE+6CA08 - 80 E4 DF              - and ah,-21 { 223 }
//	EXE+6CA0B - 89 46 64              - mov [esi+64],eax
//	EXE+6CA0E - 8B 46 60              - mov eax,[esi+60]
//	EXE+6CA11 - 8B C8                 - mov ecx,eax
//	EXE+6CA13 - 83 E1 0F              - and ecx,0F { 15 }
//	EXE+6CA16 - 80 F9 02              - cmp cl,02 { 2 }
//	EXE+6CA19 - 0F85 E8030000         - jne (EXE+6CE07)
//	EXE+6CA1F - F6 C4 40              - test ah,40 { 64 }
//	EXE+6CA22 - 0F85 DF030000         - jne (EXE+6CE07)
//	EXE+6CA28 - 8B 4C 24 20           - mov ecx,[esp+20]
//	EXE+6CA2C - 85 C9                 - test ecx,ecx
//	EXE+6CA2E - 74 23                 - je (EXE+6CA53)
//	EXE+6CA30 - D9 86 A0010000        - fld dword ptr [esi+000001A0]
//	EXE+6CA36 - DC 1D 18D94A00        - fcomp qword ptr [(EXE+AD918)] { (70.00) }
//	EXE+6CA3C - 8B C8                 - mov ecx,eax
//	EXE+6CA3E - 80 CD 02              - or ch,02 { 2 }
//	EXE+6CA41 - 89 4E 60              - mov [esi+60],ecx
//	EXE+6CA44 - DFE0                  - fnstsw ax
//	EXE+6CA46 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6CA49 - 74 0E                 - je (EXE+6CA59)
//	EXE+6CA4B - 83 E1 EF              - and ecx,-11 { 239 }
//	EXE+6CA4E - 89 4E 60              - mov [esi+60],ecx
//	EXE+6CA51 - EB 06                 - jmp (EXE+6CA59)
//	EXE+6CA53 - 80 E4 FD              - and ah,-03 { 253 }
//	EXE+6CA56 - 89 46 60              - mov [esi+60],eax
//	EXE+6CA59 - 8B 96 701E0000        - mov edx,[esi+00001E70]
//	EXE+6CA5F - BF 0000803F           - mov edi,3F800000 { 1.00 }
//	EXE+6CA64 - F6 42 08 08           - test byte ptr [edx+08],08 { 8 }
//	EXE+6CA68 - 74 4E                 - je (EXE+6CAB8)
//	EXE+6CA6A - D9 44 24 30           - fld dword ptr [esp+30]
//	EXE+6CA6E - D8 25 0CD84A00        - fsub dword ptr [(EXE+AD80C)] { (-1.00) }
//	EXE+6CA74 - D8 0D 74D74A00        - fmul dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6CA7A - D8 0D 20D94A00        - fmul dword ptr [(EXE+AD920)] { (1.18) }
//	EXE+6CA80 - D8 15 F4D74A00        - fcom dword ptr [(EXE+AD7F4)] { (1.00) }
//	EXE+6CA86 - D9 9E 8C010000        - fstp dword ptr [esi+0000018C]
//	EXE+6CA8C - DFE0                  - fnstsw ax
//	EXE+6CA8E - F6 C4 41              - test ah,41 { 65 }
//	EXE+6CA91 - 75 06                 - jne (EXE+6CA99)
//	EXE+6CA93 - 89 BE 8C010000        - mov [esi+0000018C],edi
//	EXE+6CA99 - D9 86 8C010000        - fld dword ptr [esi+0000018C]
//	EXE+6CA9F - D8 1D 0CD84A00        - fcomp dword ptr [(EXE+AD80C)] { (-1.00) }
//	EXE+6CAA5 - DFE0                  - fnstsw ax
//	EXE+6CAA7 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6CAAA - 74 74                 - je (EXE+6CB20)
//	EXE+6CAAC - C7 86 8C010000 000080BF - mov [esi+0000018C],BF800000 { -1.00 }
//	EXE+6CAB6 - EB 68                 - jmp (EXE+6CB20)
//	EXE+6CAB8 - 8B 44 24 28           - mov eax,[esp+28]
//	EXE+6CABC - 85 C0                 - test eax,eax
//	EXE+6CABE - 74 1A                 - je (EXE+6CADA)
//	EXE+6CAC0 - 8B 44 24 3C           - mov eax,[esp+3C]
//	EXE+6CAC4 - 89 BE 8C010000        - mov [esi+0000018C],edi
//	EXE+6CACA - 85 C0                 - test eax,eax
//	EXE+6CACC - 74 52                 - je (EXE+6CB20)
//	EXE+6CACE - C7 86 8C010000 0000003F - mov [esi+0000018C],3F000000 { 0.50 }
//	EXE+6CAD8 - EB 46                 - jmp (EXE+6CB20)
//	EXE+6CADA - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6CADE - DC 1D 28D94A00        - fcomp qword ptr [(EXE+AD928)] { (-0.50) }
//	EXE+6CAE4 - DFE0                  - fnstsw ax
//	EXE+6CAE6 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6CAE9 - 74 25                 - je (EXE+6CB10)
//	EXE+6CAEB - D9 86 A0010000        - fld dword ptr [esi+000001A0]
//	EXE+6CAF1 - DC 1D 30D94A00        - fcomp qword ptr [(EXE+AD930)] { (20.00) }
//	EXE+6CAF7 - DFE0                  - fnstsw ax
//	EXE+6CAF9 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6CAFC - 74 12                 - je (EXE+6CB10)
//	EXE+6CAFE - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6CB02 - D8 0D 38D94A00        - fmul dword ptr [(EXE+AD938)] { (0.40) }
//	EXE+6CB08 - D9 9E 8C010000        - fstp dword ptr [esi+0000018C]
//	EXE+6CB0E - EB 10                 - jmp (EXE+6CB20)
//	EXE+6CB10 - 8B 46 60              - mov eax,[esi+60]
//	EXE+6CB13 - C7 86 8C010000 CDCCCC3D - mov [esi+0000018C],3DCCCCCD { (40) }
//	EXE+6CB1D - F6 C4 02              - test ah,02 { 2 }
//	EXE+6CB20 - D9 86 64020000        - fld dword ptr [esi+00000264]
//	EXE+6CB26 - D8 1D 50D74A00        - fcomp dword ptr [(EXE+AD750)] { (0) }
//	EXE+6CB2C - DFE0                  - fnstsw ax
//	EXE+6CB2E - F6 C4 41              - test ah,41 { 65 }
//	EXE+6CB31 - 74 1B                 - je (EXE+6CB4E)
//	EXE+6CB33 - D9 86 8C010000        - fld dword ptr [esi+0000018C]
//	EXE+6CB39 - D8 1D 00D84A00        - fcomp dword ptr [(EXE+AD800)] { (0.30) }
//	EXE+6CB3F - DFE0                  - fnstsw ax
//	EXE+6CB41 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6CB44 - 75 08                 - jne (EXE+6CB4E)
//	EXE+6CB46 - 8B 46 60              - mov eax,[esi+60]
//	EXE+6CB49 - 0C 10                 - or al,10 { 16 }
//	EXE+6CB4B - 89 46 60              - mov [esi+60],eax
//	EXE+6CB4E - 8B 46 64              - mov eax,[esi+64]
//	EXE+6CB51 - B9 01000000           - mov ecx,00000001 { 1 }
//	EXE+6CB56 - F6 C4 02              - test ah,02 { 2 }
//	EXE+6CB59 - 75 04                 - jne (EXE+6CB5F)
//	EXE+6CB5B - 8B 4C 24 24           - mov ecx,[esp+24]
//	EXE+6CB5F - 85 C9                 - test ecx,ecx
//	EXE+6CB61 - 74 04                 - je (EXE+6CB67)
//	EXE+6CB63 - 0C 08                 - or al,08 { 8 }
//	EXE+6CB65 - EB 02                 - jmp (EXE+6CB69)
//	EXE+6CB67 - 24 F7                 - and al,-09 { 247 }
//	EXE+6CB69 - 8B 5C 24 28           - mov ebx,[esp+28]
//	EXE+6CB6D - 89 46 64              - mov [esi+64],eax
//	EXE+6CB70 - 85 DB                 - test ebx,ebx
//	EXE+6CB72 - 75 18                 - jne (EXE+6CB8C)
//	EXE+6CB74 - D9 44 24 30           - fld dword ptr [esp+30]
//	EXE+6CB78 - D8 1D 74D74A00        - fcomp dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6CB7E - DFE0                  - fnstsw ax
//	EXE+6CB80 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6CB83 - 74 07                 - je (EXE+6CB8C)
//	EXE+6CB85 - 8B 46 64              - mov eax,[esi+64]
//	EXE+6CB88 - 0C 04                 - or al,04 { 4 }
//	EXE+6CB8A - EB 05                 - jmp (EXE+6CB91)
//	EXE+6CB8C - 8B 46 64              - mov eax,[esi+64]
//	EXE+6CB8F - 24 FB                 - and al,-05 { 251 }
//	EXE+6CB91 - 85 C9                 - test ecx,ecx
//	EXE+6CB93 - 89 46 64              - mov [esi+64],eax
//	EXE+6CB96 - 74 44                 - je (EXE+6CBDC)
//	EXE+6CB98 - D9 86 A0010000        - fld dword ptr [esi+000001A0]
//	EXE+6CB9E - D8 1D 3CD94A00        - fcomp dword ptr [(EXE+AD93C)] { (100.00) }
//	EXE+6CBA4 - DFE0                  - fnstsw ax
//	EXE+6CBA6 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6CBA9 - 75 31                 - jne (EXE+6CBDC)
//	EXE+6CBAB - DD 05 402AE200        - fld qword ptr [(EXE+A22A40)] { (0.01) }
//	EXE+6CBB1 - DC 0D 28D94A00        - fmul qword ptr [(EXE+AD928)] { (-0.50) }
//	EXE+6CBB7 - D9 86 E8010000        - fld dword ptr [esi+000001E8]
//	EXE+6CBBD - D9C9                  - fxch st(1)
//	EXE+6CBBF - DEE9                  - fsubp st(1),st(0)
//	EXE+6CBC1 - D8 15 F4D74A00        - fcom dword ptr [(EXE+AD7F4)] { (1.00) }
//	EXE+6CBC7 - D9 9E E8010000        - fstp dword ptr [esi+000001E8]
//	EXE+6CBCD - DFE0                  - fnstsw ax
//	EXE+6CBCF - F6 C4 41              - test ah,41 { 65 }
//	EXE+6CBD2 - 75 3B                 - jne (EXE+6CC0F)
//	EXE+6CBD4 - 89 BE E8010000        - mov [esi+000001E8],edi
//	EXE+6CBDA - EB 33                 - jmp (EXE+6CC0F)
//	EXE+6CBDC - DD 05 402AE200        - fld qword ptr [(EXE+A22A40)] { (0.01) }
//	EXE+6CBE2 - DC 0D 78D74A00        - fmul qword ptr [(EXE+AD778)] { (0.50) }
//	EXE+6CBE8 - D9 86 E8010000        - fld dword ptr [esi+000001E8]
//	EXE+6CBEE - D9C9                  - fxch st(1)
//	EXE+6CBF0 - DEE9                  - fsubp st(1),st(0)
//	EXE+6CBF2 - D8 15 50D74A00        - fcom dword ptr [(EXE+AD750)] { (0) }
//	EXE+6CBF8 - D9 9E E8010000        - fstp dword ptr [esi+000001E8]
//	EXE+6CBFE - DFE0                  - fnstsw ax
//	EXE+6CC00 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6CC03 - 74 0A                 - je (EXE+6CC0F)
//	EXE+6CC05 - C7 86 E8010000 00000000 - mov [esi+000001E8],00000000 { 0 }
//	EXE+6CC0F - 8B 44 24 40           - mov eax,[esp+40]
//	EXE+6CC13 - 85 C0                 - test eax,eax
//	EXE+6CC15 - 74 14                 - je (EXE+6CC2B)
//	EXE+6CC17 - 8B 44 24 4C           - mov eax,[esp+4C]
//	EXE+6CC1B - 85 C0                 - test eax,eax
//	EXE+6CC1D - 74 0C                 - je (EXE+6CC2B)
//	EXE+6CC1F - E8 8C4A0100           - call (EXE+816B0)
//	EXE+6CC24 - 81 4E 60 00008000     - or [esi+60],(EXE+400000) { (0) }
//	EXE+6CC2B - 8B 4E 60              - mov ecx,[esi+60]
//	EXE+6CC2E - F7 C1 00008000        - test ecx,(EXE+400000) { (0) }
//	EXE+6CC34 - 74 1E                 - je (EXE+6CC54)
//	EXE+6CC36 - 85 DB                 - test ebx,ebx
//	EXE+6CC38 - 75 1A                 - jne (EXE+6CC54)
//	EXE+6CC3A - D9 44 24 30           - fld dword ptr [esp+30]
//	EXE+6CC3E - D8 1D 74D74A00        - fcomp dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6CC44 - DFE0                  - fnstsw ax
//	EXE+6CC46 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6CC49 - 74 09                 - je (EXE+6CC54)
//	EXE+6CC4B - 81 E1 FFFF7FFF        - and ecx,FF7FFFFF { -8388609 }
//	EXE+6CC51 - 89 4E 60              - mov [esi+60],ecx
//	EXE+6CC54 - DD 05 402AE200        - fld qword ptr [(EXE+A22A40)] { (0.01) }
//	EXE+6CC5A - D8 AE 141F0000        - fsubr dword ptr [esi+00001F14]
//	EXE+6CC60 - 8B 6C 24 1C           - mov ebp,[esp+1C]
//	EXE+6CC64 - 8B 5C 24 18           - mov ebx,[esp+18]
//	EXE+6CC68 - 85 ED                 - test ebp,ebp
//	EXE+6CC6A - D9 9E 141F0000        - fstp dword ptr [esi+00001F14]
//	EXE+6CC70 - 75 04                 - jne (EXE+6CC76)
//	EXE+6CC72 - 85 DB                 - test ebx,ebx
//	EXE+6CC74 - 74 1C                 - je (EXE+6CC92)
//	EXE+6CC76 - 8B 46 64              - mov eax,[esi+64]
//	EXE+6CC79 - F6 C4 04              - test ah,04 { 4 }
//	EXE+6CC7C - 74 14                 - je (EXE+6CC92)
//	EXE+6CC7E - 6A 01                 - push 01 { 1 }
//	EXE+6CC80 - 57                    - push edi
//	EXE+6CC81 - 68 0000003F           - push 3F000000 { 0.50 }
//	EXE+6CC86 - 6A 07                 - push 07 { 7 }
//	EXE+6CC88 - 6A 4B                 - push 4B { 75 }
//	EXE+6CC8A - E8 F19FFBFF           - call (EXE+26C80)
//	EXE+6CC8F - 83 C4 14              - add esp,14 { 20 }
//	EXE+6CC92 - 85 ED                 - test ebp,ebp
//	EXE+6CC94 - 74 0B                 - je (EXE+6CCA1)
//	EXE+6CC96 - 85 DB                 - test ebx,ebx
//	EXE+6CC98 - 75 0B                 - jne (EXE+6CCA5)
//	EXE+6CC9A - 68 000080BF           - push BF800000 { -1.00 }
//	EXE+6CC9F - EB 0D                 - jmp (EXE+6CCAE)
//	EXE+6CCA1 - 85 DB                 - test ebx,ebx
//	EXE+6CCA3 - 74 07                 - je (EXE+6CCAC)
//	EXE+6CCA5 - 85 ED                 - test ebp,ebp
//	EXE+6CCA7 - 75 03                 - jne (EXE+6CCAC)
//	EXE+6CCA9 - 57                    - push edi
//	EXE+6CCAA - EB 02                 - jmp (EXE+6CCAE)
//	EXE+6CCAC - 6A 00                 - push 00 { 0 }
//	EXE+6CCAE - 56                    - push esi
//	EXE+6CCAF - E8 ECE8FFFF           - call (EXE+6B5A0)
//	EXE+6CCB4 - D9 44 24 1C           - fld dword ptr [esp+1C]
//	EXE+6CCB8 - D8 1D FCD84A00        - fcomp dword ptr [(EXE+AD8FC)] { (0.05) }
//	EXE+6CCBE - 83 C4 08              - add esp,08 { 8 }
//	EXE+6CCC1 - DFE0                  - fnstsw ax
//	EXE+6CCC3 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6CCC6 - 74 1F                 - je (EXE+6CCE7)
//	EXE+6CCC8 - D9 44 24 14           - fld dword ptr [esp+14]
//	EXE+6CCCC - D9E0                  - fchs 
//	EXE+6CCCE - D8 1D FCD84A00        - fcomp dword ptr [(EXE+AD8FC)] { (0.05) }
//	EXE+6CCD4 - DFE0                  - fnstsw ax
//	EXE+6CCD6 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6CCD9 - 74 0C                 - je (EXE+6CCE7)
//	EXE+6CCDB - C7 86 F0010000 00000000 - mov [esi+000001F0],00000000 { 0 }
//	EXE+6CCE5 - EB 36                 - jmp (EXE+6CD1D)
//	EXE+6CCE7 - D9 44 24 14           - fld dword ptr [esp+14]
//	EXE+6CCEB - D8 1D 50D74A00        - fcomp dword ptr [(EXE+AD750)] { (0) }
//	EXE+6CCF1 - D9 44 24 14           - fld dword ptr [esp+14]
//	EXE+6CCF5 - D8 0D 00D94A00        - fmul dword ptr [(EXE+AD900)] { (1.25) }
//	EXE+6CCFB - DFE0                  - fnstsw ax
//	EXE+6CCFD - D9C0                  - fld st(0)
//	EXE+6CCFF - DEC9                  - fmulp st(1),st(0)
//	EXE+6CD01 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6CD04 - 74 02                 - je (EXE+6CD08)
//	EXE+6CD06 - D9E0                  - fchs 
//	EXE+6CD08 - D8 0D D8D84A00        - fmul dword ptr [(EXE+AD8D8)] { (0.80) }
//	EXE+6CD0E - D9 46 74              - fld dword ptr [esi+74]
//	EXE+6CD11 - D8C9                  - fmul st(0),st(1)
//	EXE+6CD13 - D9E0                  - fchs 
//	EXE+6CD15 - D9 9E F0010000        - fstp dword ptr [esi+000001F0]
//	EXE+6CD1B - DDD8                  - fstp st(0)
//	EXE+6CD1D - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6CD21 - D8 1D 6CD74A00        - fcomp dword ptr [(EXE+AD76C)] { (3DCCCCCD) }
//	EXE+6CD27 - 8B 44 24 10           - mov eax,[esp+10]
//	EXE+6CD2B - 89 86 FC020000        - mov [esi+000002FC],eax
//	EXE+6CD31 - DFE0                  - fnstsw ax
//	EXE+6CD33 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6CD36 - 75 45                 - jne (EXE+6CD7D)
//	EXE+6CD38 - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6CD3C - D8 0D 38D94A00        - fmul dword ptr [(EXE+AD938)] { (0.40) }
//	EXE+6CD42 - D9 86 8C010000        - fld dword ptr [esi+0000018C]
//	EXE+6CD48 - D8 1D 74D74A00        - fcomp dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6CD4E - D8 2D F4D74A00        - fsubr dword ptr [(EXE+AD7F4)] { (1.00) }
//	EXE+6CD54 - DFE0                  - fnstsw ax
//	EXE+6CD56 - D8 8E F0010000        - fmul dword ptr [esi+000001F0]
//	EXE+6CD5C - F6 C4 41              - test ah,41 { 65 }
//	EXE+6CD5F - D9 9E F0010000        - fstp dword ptr [esi+000001F0]
//	EXE+6CD65 - 75 16                 - jne (EXE+6CD7D)
//	EXE+6CD67 - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6CD6B - D8 0D 40D94A00        - fmul dword ptr [(EXE+AD940)] { (-0.40) }
//	EXE+6CD71 - D8 AE 8C010000        - fsubr dword ptr [esi+0000018C]
//	EXE+6CD77 - D9 9E 8C010000        - fstp dword ptr [esi+0000018C]
//	EXE+6CD7D - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6CD81 - D8 1D 70D74A00        - fcomp dword ptr [(EXE+AD770)] { (-0.10) }
//	EXE+6CD87 - DFE0                  - fnstsw ax
//	EXE+6CD89 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6CD8C - 74 4D                 - je (EXE+6CDDB)
//	EXE+6CD8E - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6CD92 - D8 0D 38D94A00        - fmul dword ptr [(EXE+AD938)] { (0.40) }
//	EXE+6CD98 - 8B 46 64              - mov eax,[esi+64]
//	EXE+6CD9B - F6 C4 02              - test ah,02 { 2 }
//	EXE+6CD9E - D8 2D F4D74A00        - fsubr dword ptr [(EXE+AD7F4)] { (1.00) }
//	EXE+6CDA4 - D8 8E F0010000        - fmul dword ptr [esi+000001F0]
//	EXE+6CDAA - D9 9E F0010000        - fstp dword ptr [esi+000001F0]
//	EXE+6CDB0 - 75 29                 - jne (EXE+6CDDB)
//	EXE+6CDB2 - D9 86 8C010000        - fld dword ptr [esi+0000018C]
//	EXE+6CDB8 - D8 1D 74D74A00        - fcomp dword ptr [(EXE+AD774)] { (0.50) }
//	EXE+6CDBE - DFE0                  - fnstsw ax
//	EXE+6CDC0 - F6 C4 41              - test ah,41 { 65 }
//	EXE+6CDC3 - 75 16                 - jne (EXE+6CDDB)
//	EXE+6CDC5 - D9 44 24 10           - fld dword ptr [esp+10]
//	EXE+6CDC9 - D8 0D 40D94A00        - fmul dword ptr [(EXE+AD940)] { (-0.40) }
//	EXE+6CDCF - D8 AE 8C010000        - fsubr dword ptr [esi+0000018C]
//	EXE+6CDD5 - D9 9E 8C010000        - fstp dword ptr [esi+0000018C]
//	EXE+6CDDB - F7 46 60 00004000     - test [esi+60],(EXE { (00)905A4D) }
//	EXE+6CDE2 - 74 1D                 - je (EXE+6CE01)
//	EXE+6CDE4 - D9 86 8C010000        - fld dword ptr [esi+0000018C]
//	EXE+6CDEA - D8 1D 44D94A00        - fcomp dword ptr [(EXE+AD944)] { (1.20) }
//	EXE+6CDF0 - DFE0                  - fnstsw ax
//	EXE+6CDF2 - F6 C4 01              - test ah,01 { 1 }
//	EXE+6CDF5 - 74 0A                 - je (EXE+6CE01)
//	EXE+6CDF7 - C7 86 8C010000 9A99993F - mov [esi+0000018C],3F99999A { 1.20 }
//	EXE+6CE01 - 89 BE 2C020000        - mov [esi+0000022C],edi
//	EXE+6CE07 - 5F                    - pop edi
//	EXE+6CE08 - 5E                    - pop esi
//	EXE+6CE09 - 5D                    - pop ebp
//	EXE+6CE0A - 5B                    - pop ebx
//	EXE+6CE0B - 83 C4 60              - add esp,60 { 96 }
//	EXE+6CE0E - C3                    - ret 
//	EXE+6CE0F - 90                    - nop 

