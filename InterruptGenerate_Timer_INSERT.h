/* === 产生 0xFF05 TIMA 中断 === */
/* === 这个实现，对每种频率使用独立计数器 === */
if( _gbMem[0xFF07] & MSK_2 ) {
    switch( _gbMem[0xFF07] & MSK_0_1 ) {
        case 0x00:{ CyclesTIMA4096 += instrCycles;
                    if( CyclesTIMA4096 > ( TIMA_4096_MAX - 1 ) ) {
                        CyclesTIMA4096 = 0;
                        ( _gbMem[0xFF05] )++;
                    }
                    break; }
        case 0x01:{ CyclesTIMA262144 += instrCycles;
                    if( CyclesTIMA262144 > ( TIMA_262144_MAX - 1 ) ) {
                        CyclesTIMA262144 = 0;
                        ( _gbMem[0xFF05] )++;
                    }
                    break; }
        case 0x02:{ CyclesTIMA65536 += instrCycles;
                    if( CyclesTIMA65536 > ( TIMA_65536_MAX - 1 ) ) {
                        CyclesTIMA65536 = 0;
                        ( _gbMem[0xFF05] )++;
                    }
                    break; }
        case 0x03:{ CyclesTIMA16384 += instrCycles;
                    if( CyclesTIMA16384 > ( TIMA_16384_MAX - 1 ) ) {
                        CyclesTIMA16384 = 0;
                        ( _gbMem[0xFF05] )++;
                    }
                    break; }
        default:    break;
    }
    if( _gbMem[0xFF05] == 0xFF ) {
        _gbMem[0xFF05] = _gbMem[0xFF06];        // Load TMA into TIMA.
        SetTimerInt();
    }
}