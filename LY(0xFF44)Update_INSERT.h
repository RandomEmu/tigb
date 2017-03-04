/* === 0xFF44 LY 更新 === */
CyclesLY -= instrCycles;        // 正常行扫描速度。
//CyclesLY -= ( instrCycles * 70 ); // DEBUG.加快 LY 增加速度。
if( CyclesLY < 0 ) {
    CyclesLY = LY_MAX;
    ( _gbMem[0xFF44] )++;
    if( _gbMem[0xFF44] == 154 ) {   // 若用取余来归零可能会更慢，因为要做除法。猜想而已，没测试过。
        _gbMem[0xFF44] = 0;
    }
    
    /*if(_gbMem[0xFF44] > 0x8E) {
        DebugDisp();
        _getch();
    }   // DEBUG.*/                         
}