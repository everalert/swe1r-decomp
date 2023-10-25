
void __cdecl FUN_004493f0(float *param_1,undefined4 param_2,int param_3,float param_4)

{
  float fVar1;
  
  switch(param_2) {
  case 0:
    if (param_3 == 1) {
      fVar1 = param_4 * 0.05 + *param_1;
      *param_1 = fVar1;
      if ((ushort)((ushort)(fVar1 < 1.0) << 8 | (ushort)(fVar1 == 1.0) << 0xe) == 0) {
        *param_1 = 1.0;
      }
      if (*param_1 < 0.01) {
        *param_1 = 0.01;
      }
    }
    if (param_3 == 2) {
      fVar1 = param_4 * 0.1 + *param_1;
      *param_1 = fVar1;
      if ((ushort)((ushort)(fVar1 < 1.0) << 8 | (ushort)(fVar1 == 1.0) << 0xe) == 0) {
        *param_1 = 1.0;
      }
      if (*param_1 < 0.01) {
        *param_1 = 0.01;
      }
    }
    if (param_3 == 3) {
      fVar1 = param_4 * 0.15 + *param_1;
      *param_1 = fVar1;
      if ((ushort)((ushort)(fVar1 < 1.0) << 8 | (ushort)(fVar1 == 1.0) << 0xe) == 0) {
        *param_1 = 1.0;
      }
      if (*param_1 < 0.01) {
        *param_1 = 0.01;
      }
    }
    if (param_3 == 4) {
      fVar1 = param_4 * 0.2 + *param_1;
      *param_1 = fVar1;
      if ((ushort)((ushort)(fVar1 < 1.0) << 8 | (ushort)(fVar1 == 1.0) << 0xe) == 0) {
        *param_1 = 1.0;
      }
      if (*param_1 < 0.01) {
        *param_1 = 0.01;
      }
    }
    if (param_3 == 5) {
      fVar1 = param_4 * 0.25 + *param_1;
      *param_1 = fVar1;
      if ((ushort)((ushort)(fVar1 < 1.0) << 8 | (ushort)(fVar1 == 1.0) << 0xe) == 0) {
        *param_1 = 1.0;
      }
      if (*param_1 < 0.01) {
        *param_1 = 0.01;
        return;
      }
    }
    break;
  case 1:
    if (param_3 == 1) {
      fVar1 = param_4 * 116.0 + param_1[1];
      param_1[1] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1000.0) << 8 | (ushort)(fVar1 == 1000.0) << 0xe) == 0) {
        param_1[1] = 1000.0;
      }
      if (param_1[1] < 50.0) {
        param_1[1] = 50.0;
      }
    }
    if (param_3 == 2) {
      fVar1 = param_4 * 232.0 + param_1[1];
      param_1[1] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1000.0) << 8 | (ushort)(fVar1 == 1000.0) << 0xe) == 0) {
        param_1[1] = 1000.0;
      }
      if (param_1[1] < 50.0) {
        param_1[1] = 50.0;
      }
    }
    if (param_3 == 3) {
      fVar1 = param_4 * 348.0 + param_1[1];
      param_1[1] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1000.0) << 8 | (ushort)(fVar1 == 1000.0) << 0xe) == 0) {
        param_1[1] = 1000.0;
      }
      if (param_1[1] < 50.0) {
        param_1[1] = 50.0;
      }
    }
    if (param_3 == 4) {
      fVar1 = param_4 * 464.0 + param_1[1];
      param_1[1] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1000.0) << 8 | (ushort)(fVar1 == 1000.0) << 0xe) == 0) {
        param_1[1] = 1000.0;
      }
      if (param_1[1] < 50.0) {
        param_1[1] = 50.0;
      }
    }
    if (param_3 == 5) {
      fVar1 = param_4 * 578.0 + param_1[1];
      param_1[1] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1000.0) << 8 | (ushort)(fVar1 == 1000.0) << 0xe) == 0) {
        param_1[1] = 1000.0;
      }
      if (param_1[1] < 50.0) {
        param_1[1] = 50.0;
        return;
      }
    }
    break;
  case 2:
    if (param_3 == 1) {
      fVar1 = ((1.0 - param_4) * 0.14 - -0.86) * param_1[3];
      param_1[3] = fVar1;
      if ((ushort)((ushort)(fVar1 < 5.0) << 8 | (ushort)(fVar1 == 5.0) << 0xe) == 0) {
        param_1[3] = 5.0;
      }
      if (param_1[3] < 0.1) {
        param_1[3] = 0.1;
      }
    }
    if (param_3 == 2) {
      fVar1 = ((1.0 - param_4) * 0.28 - -0.72) * param_1[3];
      param_1[3] = fVar1;
      if ((ushort)((ushort)(fVar1 < 5.0) << 8 | (ushort)(fVar1 == 5.0) << 0xe) == 0) {
        param_1[3] = 5.0;
      }
      if (param_1[3] < 0.1) {
        param_1[3] = 0.1;
      }
    }
    if (param_3 == 3) {
      fVar1 = ((1.0 - param_4) * 0.42 - -0.58) * param_1[3];
      param_1[3] = fVar1;
      if ((ushort)((ushort)(fVar1 < 5.0) << 8 | (ushort)(fVar1 == 5.0) << 0xe) == 0) {
        param_1[3] = 5.0;
      }
      if (param_1[3] < 0.1) {
        param_1[3] = 0.1;
      }
    }
    if (param_3 == 4) {
      fVar1 = ((1.0 - param_4) * 0.56 - -0.44) * param_1[3];
      param_1[3] = fVar1;
      if ((ushort)((ushort)(fVar1 < 5.0) << 8 | (ushort)(fVar1 == 5.0) << 0xe) == 0) {
        param_1[3] = 5.0;
      }
      if (param_1[3] < 0.1) {
        param_1[3] = 0.1;
      }
    }
    if (param_3 == 5) {
      fVar1 = ((1.0 - param_4) * 0.7 - -0.3) * param_1[3];
      param_1[3] = fVar1;
      if ((ushort)((ushort)(fVar1 < 5.0) << 8 | (ushort)(fVar1 == 5.0) << 0xe) == 0) {
        param_1[3] = 5.0;
      }
      if (param_1[3] < 0.1) {
        param_1[3] = 0.1;
        return;
      }
    }
    break;
  case 3:
    if (param_3 == 1) {
      fVar1 = param_4 * 40.0 + param_1[4];
      param_1[4] = fVar1;
      if ((ushort)((ushort)(fVar1 < 650.0) << 8 | (ushort)(fVar1 == 650.0) << 0xe) == 0) {
        param_1[4] = 650.0;
      }
      if (param_1[4] < 450.0) {
        param_1[4] = 450.0;
      }
    }
    if (param_3 == 2) {
      fVar1 = param_4 * 80.0 + param_1[4];
      param_1[4] = fVar1;
      if ((ushort)((ushort)(fVar1 < 650.0) << 8 | (ushort)(fVar1 == 650.0) << 0xe) == 0) {
        param_1[4] = 650.0;
      }
      if (param_1[4] < 450.0) {
        param_1[4] = 450.0;
      }
    }
    if (param_3 == 3) {
      fVar1 = param_4 * 120.0 + param_1[4];
      param_1[4] = fVar1;
      if ((ushort)((ushort)(fVar1 < 650.0) << 8 | (ushort)(fVar1 == 650.0) << 0xe) == 0) {
        param_1[4] = 650.0;
      }
      if (param_1[4] < 450.0) {
        param_1[4] = 450.0;
      }
    }
    if (param_3 == 4) {
      fVar1 = param_4 * 160.0 + param_1[4];
      param_1[4] = fVar1;
      if ((ushort)((ushort)(fVar1 < 650.0) << 8 | (ushort)(fVar1 == 650.0) << 0xe) == 0) {
        param_1[4] = 650.0;
      }
      if (param_1[4] < 450.0) {
        param_1[4] = 450.0;
      }
    }
    if (param_3 == 5) {
      fVar1 = param_4 * 200.0 + param_1[4];
      param_1[4] = fVar1;
      if ((ushort)((ushort)(fVar1 < 650.0) << 8 | (ushort)(fVar1 == 650.0) << 0xe) == 0) {
        param_1[4] = 650.0;
      }
      if (param_1[4] < 450.0) {
        param_1[4] = 450.0;
        return;
      }
    }
    break;
  case 4:
    if (param_3 == 1) {
      fVar1 = ((1.0 - param_4) * 0.07999998 - -0.92) * param_1[5];
      param_1[5] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1000.0) << 8 | (ushort)(fVar1 == 1000.0) << 0xe) == 0) {
        param_1[5] = 1000.0;
      }
      if (param_1[5] < 1.0) {
        param_1[5] = 1.0;
      }
    }
    if (param_3 == 2) {
      fVar1 = ((1.0 - param_4) * 0.17 - -0.83) * param_1[5];
      param_1[5] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1000.0) << 8 | (ushort)(fVar1 == 1000.0) << 0xe) == 0) {
        param_1[5] = 1000.0;
      }
      if (param_1[5] < 1.0) {
        param_1[5] = 1.0;
      }
    }
    if (param_3 == 3) {
      fVar1 = ((1.0 - param_4) * 0.26 - -0.74) * param_1[5];
      param_1[5] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1000.0) << 8 | (ushort)(fVar1 == 1000.0) << 0xe) == 0) {
        param_1[5] = 1000.0;
      }
      if (param_1[5] < 1.0) {
        param_1[5] = 1.0;
      }
    }
    if (param_3 == 4) {
      fVar1 = ((1.0 - param_4) * 0.35 - -0.65) * param_1[5];
      param_1[5] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1000.0) << 8 | (ushort)(fVar1 == 1000.0) << 0xe) == 0) {
        param_1[5] = 1000.0;
      }
      if (param_1[5] < 1.0) {
        param_1[5] = 1.0;
      }
    }
    if (param_3 == 5) {
      fVar1 = ((1.0 - param_4) * 0.44 - -0.56) * param_1[5];
      param_1[5] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1000.0) << 8 | (ushort)(fVar1 == 1000.0) << 0xe) == 0) {
        param_1[5] = 1000.0;
      }
      if (param_1[5] < 1.0) {
        param_1[5] = 1.0;
        return;
      }
    }
    break;
  case 5:
    if (param_3 == 1) {
      fVar1 = param_4 * 1.6 + param_1[9];
      param_1[9] = fVar1;
      if ((ushort)((ushort)(fVar1 < 20.0) << 8 | (ushort)(fVar1 == 20.0) << 0xe) == 0) {
        param_1[9] = 20.0;
      }
      if (param_1[9] < 1.0) {
        param_1[9] = 1.0;
      }
    }
    if (param_3 == 2) {
      fVar1 = param_4 * 3.2 + param_1[9];
      param_1[9] = fVar1;
      if ((ushort)((ushort)(fVar1 < 20.0) << 8 | (ushort)(fVar1 == 20.0) << 0xe) == 0) {
        param_1[9] = 20.0;
      }
      if (param_1[9] < 1.0) {
        param_1[9] = 1.0;
      }
    }
    if (param_3 == 3) {
      fVar1 = param_4 * 4.8 + param_1[9];
      param_1[9] = fVar1;
      if ((ushort)((ushort)(fVar1 < 20.0) << 8 | (ushort)(fVar1 == 20.0) << 0xe) == 0) {
        param_1[9] = 20.0;
      }
      if (param_1[9] < 1.0) {
        param_1[9] = 1.0;
      }
    }
    if (param_3 == 4) {
      fVar1 = param_4 * 6.4 + param_1[9];
      param_1[9] = fVar1;
      if ((ushort)((ushort)(fVar1 < 20.0) << 8 | (ushort)(fVar1 == 20.0) << 0xe) == 0) {
        param_1[9] = 20.0;
      }
      if (param_1[9] < 1.0) {
        param_1[9] = 1.0;
      }
    }
    if (param_3 == 5) {
      fVar1 = param_4 * 8.0 + param_1[9];
      param_1[9] = fVar1;
      if ((ushort)((ushort)(fVar1 < 20.0) << 8 | (ushort)(fVar1 == 20.0) << 0xe) == 0) {
        param_1[9] = 20.0;
      }
      if (param_1[9] < 1.0) {
        param_1[9] = 1.0;
        return;
      }
    }
    break;
  case 6:
    if (param_3 == 1) {
      fVar1 = param_4 * 0.1 + param_1[0xb];
      param_1[0xb] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1.0) << 8 | (ushort)(fVar1 == 1.0) << 0xe) == 0) {
        param_1[0xb] = 1.0;
      }
      if (param_1[0xb] < 0.0) {
        param_1[0xb] = 0.0;
      }
    }
    if (param_3 == 2) {
      fVar1 = param_4 * 0.2 + param_1[0xb];
      param_1[0xb] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1.0) << 8 | (ushort)(fVar1 == 1.0) << 0xe) == 0) {
        param_1[0xb] = 1.0;
      }
      if (param_1[0xb] < 0.0) {
        param_1[0xb] = 0.0;
      }
    }
    if (param_3 == 3) {
      fVar1 = param_4 * 0.3 + param_1[0xb];
      param_1[0xb] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1.0) << 8 | (ushort)(fVar1 == 1.0) << 0xe) == 0) {
        param_1[0xb] = 1.0;
      }
      if (param_1[0xb] < 0.0) {
        param_1[0xb] = 0.0;
      }
    }
    if (param_3 == 4) {
      fVar1 = param_4 * 0.4 + param_1[0xb];
      param_1[0xb] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1.0) << 8 | (ushort)(fVar1 == 1.0) << 0xe) == 0) {
        param_1[0xb] = 1.0;
      }
      if (param_1[0xb] < 0.0) {
        param_1[0xb] = 0.0;
      }
    }
    if (param_3 == 5) {
      fVar1 = param_4 * 0.45 + param_1[0xb];
      param_1[0xb] = fVar1;
      if ((ushort)((ushort)(fVar1 < 1.0) << 8 | (ushort)(fVar1 == 1.0) << 0xe) == 0) {
        param_1[0xb] = 1.0;
      }
      if (param_1[0xb] < 0.0) {
        param_1[0xb] = 0.0;
      }
    }
  }
  return;
}

