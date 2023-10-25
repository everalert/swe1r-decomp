// something to do with track loading
// common denominator function between loading from cantina and restarting from within race
// doesn't seem to execute the loading itself, maybe just calculates some kind of offset needed to load a track?

// a1 = pointer to whatever struct holds the track selection id;
// also holds other race settings including the selected racer,
// mirror mode toggle, AI racer count setting, etc.

int __cdecl sub_45BAB0(int a1)
{
	int result; // eax
	int v2; // edi
	int i; // ecx
	int v4; // edi
	int v5; // ecx
	_DWORD *v6; // esi
	int v7; // ecx
	_DWORD *v8; // edx

	result = -1;
	if ( *(a1 + 0x64) )
	{
		v2 = *(a1 + 0x72);
		for ( i = 0; i < v2; ++i )
		{
			if ( *(i + a1 + 0x73) == byte_4BFEF2[12 * *(a1 + 0x5D)] )// 0x5D = offset of selected track ID within some (apparently large) struct
				result = i;
		}
		if ( result == -1 )
			result = 0;
	}
	else
	{
		v4 = *(a1 + 0x72);
		v5 = 0;
		if ( v4 > 0 )
		{
			v6 = &unk_E29BC4;
			do
			{
				if ( *(v5 + a1 + 0x73) == byte_4BFEF2[12 * *(a1 + 0x5D)] && *v6 == 0x41414949 )
					result = v5;
				++v5;
				v6 += 0x22;
			}
			while ( v5 < v4 );
		}
		if ( result == -1 )
		{
			v7 = 0;
			v8 = &unk_E29BC4;
			do
			{
				if ( v7 >= v4 )
					break;
				if ( *v8 == 0x41414949 )
				{
					result = v7;
				}
				else
				{
					++v7;
					v8 += 0x22;
				}
			}
			while ( result == -1 );
		}
	}
	return result;
}