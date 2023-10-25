#include <cmath>
#include <algorithm>
#include "Vector3.hpp"
#include "4783E0_ApplyAcceleration.hpp"
#include "4787F0_ApplyBoost.hpp"
#include "480650_GetDecelerationFactor.hpp"
#include "478A70_CalculateTraction.hpp"

void CalculateSpeed(PodEngineData *PodEngine, int a2, int a3, vec3::Vector3 *ForwardVector)
{
 	float v4; // esi
 	int v5; // eax
 	float v6; // st6
 	float v7; // st6
 	float v8; // st7
 	double v9; // st7
 	int v10; // ecx
 	double v41; // st7
 	double v12; // st7
 	double v13; // st6
 	float v14; // st7
 	double v15; // st7
 	double v16; // st6
 	float v17; // eax
 	float v18; // ecx
 	int v19; // eax
 	int v20; // ebx
 	double v21; // st7
 	double v22; // st5
 	float v23; // [esp+0h] [ebp-40h]
 	float v24; // [esp+4h] [ebp-3Ch]
 	float v25; // [esp+4h] [ebp-3Ch]
 	float v26; // [esp+4h] [ebp-3Ch]
 	float v27; // [esp+4h] [ebp-3Ch]
 	float v28; // [esp+4h] [ebp-3Ch]
 	float v29; // [esp+4h] [ebp-3Ch]
 	float v30; // [esp+4h] [ebp-3Ch]
 	float v31; // [esp+18h] [ebp-28h]
 	int v33; // [esp+1Ch] [ebp-24h]
 	float v34; // [esp+20h] [ebp-20h]
 	float v35; // [esp+24h] [ebp-1Ch]
 	float v36; // [esp+28h] [ebp-18h]
 	float v37; // [esp+2Ch] [ebp-14h]
 	float v38; // [esp+30h] [ebp-10h]
 	char v39; // [esp+34h] [ebp-Ch]
 	float v40; // [esp+44h] [ebp+4h]
 	float v41; // [esp+44h] [ebp+4h]
 	float v42; // [esp+44h] [ebp+4h]

 	v4 = a1;

 	float TotalSpeed = ApplyBoost(PodEngine) + ApplyAcceleration(PodEngine);
 	CalculateTraction(PodEngine, TotalSpeed, ForwardVector);
 	if ( PodEngine->Flags0064 | ~0x400 && PodEngine->Flags0060 | ~0x2000000 && PodEngine->Velocity.z > 0.0f )
 	{
 	 	v6 = pow(PodEngine->Velocity.x,2.0f) + pow(PodEngine->Velocity.y,2.0f);
 	 	if ( pow(PodEngine->Velocity.z,2.0f) > v6 * 0.13690001f )
 	 	 	PodEngine->Velocity.z = sqrt(v6) * 0.2f;
 	}
	vec3::add(&PodEngine->Velocity, PodEngine->OpponentCollisionSpeed);

 	float DecelFactor = GetDecelerationFactor(4.0f, FrameTime);
 	vec3::mult(&PodEngine->CollisionSpeed, DecelFactor);
 	vec3::mult(&PodEngine->OpponentCollisionSpeed, DecelFactor);

 	v10 = PodEngine->Flags0060;
 	if ( !(v10 & 0x5000) && (PodEngine->Pitch > 0.1f || -PodEngine->Pitch > 0.1f || !(v10 & 0x2000)) )
 	{
 	 	v41 = v35 * PodEngine->SlopeSpeed.z + v34 * PodEngine->SlopeSpeed.y + v33 * PodEngine->SlopeSpeed.x;
		v12 = vec3::magnitude(PodEngine->SlopeSpeed);
 	 	if ( v41 < 0.0f || v12 <= 1.0f )
			vec3::add(&PodEngine->Velocity, PodEngine->SlopeSpeed);
 	 	else
 	 	{
 	 	 	if ( TotalSpeed > 1.0 )
 	 	 	{
 	 	 	 	v13 = v41 / (TotalSpeed * 60.0);
 	 	 	 	if ( v13 > 0.0 )
 	 	 	 	 	PodEngine->AccelerationFactor = FrameTime * v13 + FrameTime * v13 + PodEngine->AccelerationFactor;
 	 	 	}
 	 	 	v14 = v41 / v12 * 0.01f;
			v42 = std::max(1.0f, v14);
 	 	 	sub_42FA80(&v33, &v33, v42, PodEngine->SlopeSpeed.x);
 	 	}
 	}
 	sub_42FA80(a3, a2, FrameTime, &v33);
 	if ( (PodEngine->6552 - 400.0f) * 0.0016666667f < 1.0f
 	 	|| PodEngine->Flags0060 & 0x20
 	 	|| PodEngine->Flags0064 & 0x4000000 )
 	{
 	 	if ( &unk_800000 & PodEngine->Flags0064) )
 	 	{
 	 	 	PodEngine->340) = 0;
 	 	 	PodEngine->344) = 0;
 	 	 	PodEngine->348) = 0;
 	 	}
 	 	else
 	 	{
 	 	 	v17 = *(a3 + 4);
 	 	 	v18 = *(a3 + 8);
 	 	 	v36 = *a3;
 	 	 	v37 = v17;
 	 	 	v19 = PodEngine->316);
 	 	 	v38 = v18;
 	 	 	v20 = 0;
 	 	 	if ( sub_44ACB0(a3, a2, v19, &v39) )
 	 	 	{
 	 	 	 	do
 	 	 	 	{
 	 	 	 	 	if ( v20 >= 6 )
 	 	 	 	 	 	break;
 	 	 	 	 	++v20;
 	 	 	 	}
 	 	 	 	while ( sub_44ACB0(a3, a2, PodEngine->316), &v39) );
 	 	 	}
 	 	 	if ( v20 > 0 && PodEngine->Flags0060) < 0 )
 	 	 	{
 	 	 	 	PodEngine->AccelerationFactor = GetDecelerationFactor(5.0f, FrameTime) * PodEngine->AccelerationFactor;
 	 	 	}
 	 	 	v21 = *(a3 + 4) - v37;
 	 	 	v22 = *(a3 + 8) - v38;
 	 	 	PodEngine->340) = *a3 - v36;
 	 	 	PodEngine->344) = v21;
 	 	 	PodEngine->348) = v22;
 	 	}
 	}
 	else
 	{
 	 	PodEngine->340) = 0;
 	 	PodEngine->344) = 0;
 	 	PodEngine->348) = 0;
 	}
}