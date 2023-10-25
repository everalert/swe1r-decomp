float GetDecelFactor(float interval, float dt) {
    static float factor = (float)0x42055556; // 33.333..
    return 1.0f - dt * factor / (dt * factor + interval);
}

//  EXE+80650 - D9 44 24 08           - fld dword ptr [esp+08]
//  EXE+80654 - D8 0D 9CDF4A00        - fmul dword ptr [EXE+ADF9C] { (33.33) }
//  EXE+8065A - D9C0                  - fld st(0)
//  EXE+8065C - D8 44 24 04           - fadd dword ptr [esp+04]
//  EXE+80660 - DEF9                  - fdivp st(1),st(0)
//  EXE+80662 - D8 2D A0DF4A00        - fsubr dword ptr [EXE+ADFA0] { (1.00) }
//  EXE+80668 - C3                    - ret
