#include "4783E0_ApplyAcceleration.hpp"

//[TODO] Make sense of this mess lol, pretty sure LP ver is wrong (no RaceData flag check, etc.)

float ApplyAcceleration(PodEngineData *PodEngine)
{
 	int v1; // esi
 	int v2; // eax
 	double v3; // st7
 	bool v4; // c0
 	bool v5; // c3
 	char v8; // c0
 	double v9; // st6
 	unsigned __int8 v12; // c0
 	unsigned __int8 v13; // c3
 	int v14; // eax
 	double v16; // st7
 	char v17; // c0
 	double v18; // st6
 	unsigned __int8 v21; // c0
 	unsigned __int8 v22; // c3
 	char v24; // c0
 	int v25; // eax
 	unsigned __int8 v29; // c0
 	unsigned __int8 v30; // c3
 	double v31; // st7
 	double v33; // st7
 	char v34; // c0
 	int v37; // ecx
 	double result; // st7
 	float v40; // [esp+0h] [ebp-8h]
 	float v42; // [esp+0h] [ebp-8h]
 	float v45; // [esp+0h] [ebp-8h]
 	
	v1 = a1;

	float SpeedFactor = (PodEngine->Flags0060 & PODENGINE_IS_BOOSTING || PodEngine->Flags0064 & PODENGINE_TERRAIN_SIDE) ? 4.0f : 1.5f;

 	if ( PodEngine->PodRaceData->Flags & 8 )
 	{
 	 	if ( PodEngine->Pitch <= 0.1f )
 	 	{
 	 	 	if ( PodEngine->Pitch >= -0.1f )
 	 	 	{
LABEL_15:
 	 	 	 	PodEngine->AccelerationFactor = GetDecelerationFactor(PodEngine->StatDecelInv, FrameTime) * PodEngine->AccelerationFactor;
 	 	 	 	goto LABEL_16;
 	 	 	}
 	 	 	PodEngine->AccelerationFactor = FrameTime * SpeedFactor * PodEngine->Pitch + PodEngine->AccelerationFactor;
 	 	 	if ( !(v12 | v13) && PodEngine->AccelerationFactor < PodEngine->Pitch * 0.5f )
 	 	 	{
 	 	 	 	PodEngine->AccelerationFactor = GetDecelerationFactor(20.0f, FrameTime) * PodEngine->AccelerationFactor;
 	 	 	}
 	 	}
 	 	else
 	 	{
 	 	 	PodEngine->AccelerationFactor = FrameTime * SpeedFactor * PodEngine->Pitch + PodEngine->AccelerationFactor;
 	 	 	if ( v8 )
 	 	 	 	v9 = PodEngine->Pitch / (1.0f - PodEngine->Pitch);
 	 	 	else
 	 	 	 	v9 = 10000.0f;
 	 	 	if ( PodEngine->AccelerationFactor > v9 )
 	 	 	 	goto LABEL_15;
 	 	}
LABEL_16:
 	 	if ( !(PodEngine->Flags0060 & PODENGINE_IS_BRAKING) )
 	 	 	goto LABEL_33;
 	 	goto LABEL_32;
 	}
 	if ( PodEngine->Pitch <= 0.1f )
 	{
 	 	if ( PodEngine->Pitch >= -0.1f )
 	 	{
 	 	 	if ( v24 )
 	 	 	 	PodEngine->AccelerationFactor = GetDecelerationFactor(10.0f, FrameTime) * PodEngine->AccelerationFactor;
 	 	 	else
 	 	 	 	PodEngine->AccelerationFactor = GetDecelerationFactor(PodEngine->StatDecelInv, FrameTime) * PodEngine->AccelerationFactor;
 	 	}
 	 	else
 	 	{
 	 	 	PodEngine->AccelerationFactor = FrameTime * SpeedFactor * PodEngine->Pitch + PodEngine->AccelerationFactor;
 	 	 	if ( !(v21 | v22) && PodEngine->AccelerationFactor < PodEngine->Pitch * 0.5 )
 	 	 	{
 	 	 	 	PodEngine->AccelerationFactor = GetDecelerationFactor(20.0f, FrameTime) * PodEngine->AccelerationFactor;
 	 	 	}
 	 	}
 	}
 	else
 	{
 	 	v16 = FrameTime * SpeedFactor * PodEngine->Pitch + PodEngine->AccelerationFactor;
 	 	PodEngine->AccelerationFactor = v16;
 	 	if ( v17 )
 	 	 	v18 = PodEngine->Pitch / (1.0f - PodEngine->Pitch);
 	 	else
 	 	 	v18 = 10000.0f;
 	 	if ( v16 > v18 )
 	 	{
 	 	 	PodEngine->AccelerationFactor = GetDecelerationFactor(PodEngine->StatDecelInv, FrameTime) * PodEngine->AccelerationFactor;
 	 	}
 	}
 	if ( PodEngine->Flags0060 & PODENGINE_IS_BRAKING )
 	{
LABEL_32:
 	 	PodEngine->AccelerationFactor = GetDecelerationFactor(PodEngine->StatAirBrakeInv, FrameTime) * PodEngine->AccelerationFactor;
 	}
LABEL_33:
	float PreBoostAccel;
 	if ( v29 | v30 )
 	 	PreBoostAccel = -(-PodEngine->AccelerationFactor * PodEngine->StatMaxSpeed / (PodEngine->StatAcceleration - PodEngine->AccelerationFactor));
 	else
 	 	PreBoostAccel = PodEngine->AccelerationFactor * PodEngine->StatMaxSpeed / (PodEngine->StatAcceleration + PodEngine->AccelerationFactor);
 	v33 = PreBoostAccel * PodEngine->BoostFactor;
 	if ( v34 )
 	{
 	 	if ( !(PodEngine->Flags0064 & 0x8000000) )
 	 	{
 	 	 	v37 = PodEngine->Flags0064 | 0x8000000;
 	 	 	PodEngine->Flags0064 = v37;
 	 	 	if ( PodEngine->TerrainSpeedFactor < 1.0f )
 	 	 	 	PodEngine->Flags0064 = v37 | 0x10000000;
 	 	}
 	 	v33 = v33 * PodEngine->TerrainSpeedFactor;
 	}
 	else
 	{
 	 	PodEngine->Flags0064 &= 0xF7FFFFFF;
 	}
 	PodEngine->Flags0060 = PodEngine->Flags0060;
 	result = v33 + PodEngine->TerrainSpeedOffset;
 	if ( PodEngine->Flags0060 & PODENGINE_TERRAIN_ZON_EXIT && result < 75.0f )
 	 	result = 75.0f;
 	if ( PodEngine->Flags0060 & PODENGINE_IN_AUTOPILOT && PodEngine->PitchInputMAYBE < -0.5 )
		result = PodEngine->Flags0064 & PODENGINE_RACE_COMPLETE ? 1.9f : 1.3f;
 	return result;
}