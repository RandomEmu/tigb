/* === 0xFF04 DIV 更新 === */
CyclesDIV -= instrCycles;
if( CyclesDIV < 0 ) {
    CyclesDIV = DIV_MAX;
    ( _gbMem[0xFF04] )++;
}