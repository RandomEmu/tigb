            case 0x00: { v8Before = _BC[B] & 0x80;
/* RLC B */              _BC[B] <<= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;      // Set C flag.
                            _BC[B] |= 0x01;      // 把原来的第 7 位"放"到第 0 位。
                         } else _F &= 0xE0;  // Reset C flag.
                         
                         if( _BC[B] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.
                         
                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x01: { v8Before = _BC[C] & 0x80;
/* RLC C */              _BC[C] <<= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;      // Set C flag.
                            _BC[C] |= 0x01;      // 把原来的第 7 位"放"到第 0 位。
                         } else _F &= 0xE0;  // Reset C flag.
                         
                         if( _BC[C] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.
                         
                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x02: { v8Before = _DE[D] & 0x80;
/* RLC D */              _DE[D] <<= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;      // Set C flag.
                            _DE[D] |= 0x01;      // 把原来的第 7 位"放"到第 0 位。
                         } else _F &= 0xE0;  // Reset C flag.
                         
                         if( _DE[D] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.
                         
                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x03: { v8Before = _DE[E] & 0x80;
/* RLC E */              _DE[E] <<= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;      // Set C flag.
                            _DE[E] |= 0x01;      // 把原来的第 7 位"放"到第 0 位。
                         } else _F &= 0xE0;  // Reset C flag.
                         
                         if( _DE[E] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.
                         
                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x04: { v8Before = _HL[H] & 0x80;
/* RLC H */              _HL[H] <<= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;      // Set C flag.
                            _HL[H] |= 0x01;      // 把原来的第 7 位"放"到第 0 位。
                         } else _F &= 0xE0;  // Reset C flag.
                         
                         if( _HL[H] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.
                         
                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x05: { v8Before = _HL[L] & 0x80;
/* RLC L */              _HL[L] <<= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;      // Set C flag.
                            _HL[L] |= 0x01;      // 把原来的第 7 位"放"到第 0 位。
                         } else _F &= 0xE0;  // Reset C flag.
                         
                         if( _HL[L] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.
                         
                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x06: { v8Before = Rbyte(W(_HL) ,NULL);
/* RLC (HL) */           if(v8Before & MSK_7) {
                            _F |= 0x10;      // Set C flag.
                            v8Before <<= 1;
                            v8Before |= 0x01;
                         } else {
                            _F &= 0xE0;  // Reset C flag.
                            v8Before <<= 1;
                         }                       
                         if( v8Before )
                             ResetZ();
                         else SetZ();
                         Wbyte(W(_HL), v8Before);                        
                         ResetN();
                         ResetH();
                         instrCycles = 16;
                         _PC += 2;
                         break; }

            case 0x07: { v8Before = _A & 0x80;
/* RLC A */              _A <<= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;      // Set C flag.
                            _A |= 0x01;      // 把原来的第 7 位"放"到第 0 位。
                         } else _F &= 0xE0;  // Reset C flag.
                         
                         if( _A == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.
                         
                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x08: { v8Before = _BC[B] & 0x01;
/* RRC B */              _BC[B] >>= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;  // Set C flag.
                            _BC[B] |= 0x80;  // 把原来的第 0 位"放"到第 7 位。
                         } else _F &= 0xE0;  // Reset C flag.

                         if( _BC[B] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.

                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x09: { v8Before = _BC[C] & 0x01;
/* RRC C */              _BC[C] >>= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;  // Set C flag.
                            _BC[C] |= 0x80;  // 把原来的第 0 位"放"到第 7 位。
                         } else _F &= 0xE0;  // Reset C flag.

                         if( _BC[C] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.
                         
                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.

                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x0A: { v8Before = _DE[D] & 0x01;
/* RRC D */              _DE[D] >>= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;  // Set C flag.
                            _DE[D] |= 0x80;  // 把原来的第 0 位"放"到第 7 位。
                         } else _F &= 0xE0;  // Reset C flag.

                         if( _DE[D] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.

                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x0B: { v8Before = _DE[E] & 0x01;
/* RRC E */              _DE[E] >>= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;  // Set C flag.
                            _DE[E] |= 0x80;  // 把原来的第 0 位"放"到第 7 位。
                         } else _F &= 0xE0;  // Reset C flag.

                         if( _DE[E] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.

                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x0C: { v8Before = _HL[H] & 0x01;
/* RRC H */              _HL[H] >>= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;  // Set C flag.
                            _HL[H] |= 0x80;  // 把原来的第 0 位"放"到第 7 位。
                         } else _F &= 0xE0;  // Reset C flag.

                         if( _HL[H] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.

                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x0D: { v8Before = _HL[L] & 0x01;
/* RRC L */              _HL[L] >>= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;  // Set C flag.
                            _HL[L] |= 0x80;  // 把原来的第 0 位"放"到第 7 位。
                         } else _F &= 0xE0;  // Reset C flag.

                         if( _HL[L] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.

                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x0E: { v8Before = Rbyte(W(_HL) ,NULL);
/* RRC (HL) */           if(v8Before & MSK_1) {
                            SetC();
                            v8Before >>= 1;
                            v8Before |= MSK_7;
                         } else {
                            ResetC();
                            v8Before >>= 1;
                         }                       
                         if( v8Before )
                            ResetZ();
                         else SetZ();
                         Wbyte(W(_HL), v8Before);
                         ResetN();
                         ResetH();
                         instrCycles = 16;
                         _PC += 2;
                         break; }

            case 0x0F: { v8Before = _A & 0x01;
/* RRC A */              _A >>= 1;
                         
                         if(v8Before) {
                            _F |= 0x10;  // Set C flag.
                            _A |= 0x80;  // 把原来的第 0 位"放"到第 7 位。
                         } else _F &= 0xE0;  // Reset C flag.

                         if( _A == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.

                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x10: { v8Before = _BC[B] & 0x80;
/* RL B */               _BC[B] <<= 1;
                         
                         if(_F & 0x10)
                            _BC[B] |= 0x01;
                         
                         if(v8Before)
                            _F |= 0x10;  // Set C flag.
                         else _F &= 0xE0;  // Reset C flag.
                         
                         if( _BC[B] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x11: { v8Before = _BC[C] & 0x80;
/* RL C */               _BC[C] <<= 1;
                         
                         if(_F & 0x10)
                            _BC[C] |= 0x01;
                         
                         if(v8Before)
                            _F |= 0x10;  // Set C flag.
                         else _F &= 0xE0;  // Reset C flag.
                         
                         if( _BC[C] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x12: { v8Before = _DE[D] & 0x80;
/* RL D */               _DE[D] <<= 1;
                         
                         if(_F & 0x10)
                            _DE[D] |= 0x01;
                         
                         if(v8Before)
                            _F |= 0x10;  // Set C flag.
                         else _F &= 0xE0;  // Reset C flag.
                         
                         if( _DE[D] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x13: { v8Before = _DE[E] & 0x80;
/* RL E */               _DE[E] <<= 1;
                         
                         if(_F & 0x10)
                            _DE[E] |= 0x01;
                         
                         if(v8Before)
                            _F |= 0x10;  // Set C flag.
                         else _F &= 0xE0;  // Reset C flag.
                         
                         if( _DE[E] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x14: { v8Before = _HL[H] & 0x80;
/* RL H */               _HL[H] <<= 1;
                         
                         if(_F & 0x10)
                            _HL[H] |= 0x01;
                         
                         if(v8Before)
                            _F |= 0x10;  // Set C flag.
                         else _F &= 0xE0;  // Reset C flag.
                         
                         if( _HL[H] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x15: { v8Before = _HL[L] & 0x80;
/* RL L */               _HL[L] <<= 1;
                         
                         if(_F & 0x10)
                            _HL[L] |= 0x01;
                         
                         if(v8Before)
                            _F |= 0x10;  // Set C flag.
                         else _F &= 0xE0;  // Reset C flag.
                         
                         if( _HL[L] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

case 0x16:{ v8Before = Rbyte(W(_HL) ,NULL);
            v8After = _F & MSK_4;
            
            if(v8Before & MSK_7)
                SetC();
            else ResetC();

            v8Before <<= 1;
            
            if(v8After)
                v8Before |= MSK_0;

            Wbyte(W(_HL), v8Before);

            if(v8Before)
                ResetZ();
            else SetZ();

            ResetN();
            ResetH();
            
            instrCycles = 16;
            _PC += 2;
            break; }    /* RL (HL) */

            case 0x17: { v8Before = _A & 0x80;
/* RL A */               _A <<= 1;
                         
                         if(_F & 0x10)
                            _A |= 0x01;
                         
                         if(v8Before)
                            _F |= 0x10;  // Set C flag.
                         else _F &= 0xE0;  // Reset C flag.
                         
                         if( _A == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x18: { v8Before = _BC[B] & 0x01;
/* RR B */               _BC[B] >>= 1;
                         
                         if(_F & 0x10)
                            _BC[B] |= 0x80;
                         
                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.
                         
                         if( _BC[B] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x19: { v8Before = _BC[C] & 0x01;
/* RR C */               _BC[C] >>= 1;
                         
                         if(_F & 0x10)
                            _BC[C] |= 0x80;
                         
                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.
                         
                         if( _BC[C] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x1A: { v8Before = _DE[D] & 0x01;
/* RR D */               _DE[D] >>= 1;
                         
                         if(_F & 0x10)
                            _DE[D] |= 0x80;
                         
                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.
                         
                         if( _DE[D] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x1B: { v8Before = _DE[E] & 0x01;
/* RR E */               _DE[E] >>= 1;
                         
                         if(_F & 0x10)
                            _DE[E] |= 0x80;
                         
                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.
                         
                         if( _DE[E] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x1C: { v8Before = _HL[H] & 0x01;
/* RR H */               _HL[H] >>= 1;
                         
                         if(_F & 0x10)
                            _HL[H] |= 0x80;
                         
                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.
                         
                         if( _HL[H] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x1D: { v8Before = _HL[L] & 0x01;
/* RR L */               _HL[L] >>= 1;
                         
                         if(_F & 0x10)
                            _HL[L] |= 0x80;
                         
                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.
                         
                         if( _HL[L] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xBF; // Reset N flag.
                         _F &= 0xDF; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

case 0x1E:{ v8Before = Rbyte(W(_HL) ,NULL);
            v8After = _F & MSK_4;
            
            if(v8Before & MSK_0)
                SetC();
            else ResetC();

            v8Before >>= 1;
            
            if(v8After)
                v8Before |= MSK_7;

            Wbyte(W(_HL), v8Before);

            if(v8Before)
                ResetZ();
            else SetZ();

            ResetN();
            ResetH();

            instrCycles = 16;
            _PC += 2;
            break; }    /* RR (HL) */



            case 0x1F: { v8Before = _A & 0x01;
/* RR A */               _A >>= 1;
                         
                         if(_F & 0x10)
                            _A |= 0x80;
                         
                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.
                         
                         if( _A == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0; // Reset N flag.
                         _F &= 0xD0; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x20: { v8Before = _BC[B] & 0x80;
/* SLA B */              _BC[B] <<= 1;

                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.

                         if( _BC[B] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0; // Reset N flag.
                         _F &= 0xD0; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x21: { v8Before = _BC[C] & 0x80;
/* SLA C */              _BC[C] <<= 1;

                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.

                         if( _BC[C] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0; // Reset N flag.
                         _F &= 0xD0; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x22: { v8Before = _DE[D] & 0x80;
/* SLA D */              _DE[D] <<= 1;

                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.

                         if( _DE[D] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0; // Reset N flag.
                         _F &= 0xD0; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x23: { v8Before = _DE[E] & 0x80;
/* SLA E */              _DE[E] <<= 1;

                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.

                         if( _DE[E] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0; // Reset N flag.
                         _F &= 0xD0; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x24: { v8Before = _HL[H] & 0x80;
/* SLA H */              _HL[H] <<= 1;

                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.

                         if( _HL[H] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0; // Reset N flag.
                         _F &= 0xD0; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x25: { v8Before = _HL[L] & 0x80;
/* SLA L */              _HL[L] <<= 1;

                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.

                         if( _HL[L] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0; // Reset N flag.
                         _F &= 0xD0; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

case 0x26:{ v8Before = Rbyte(W(_HL) ,NULL);

            if(v8Before & MSK_7)
                SetC();
            else ResetC();
            
            v8Before <<= 1;

            Wbyte(W(_HL), v8Before);

            if( v8Before )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            instrCycles = 16;
            _PC += 2;
            break; }    /* SLA (HL) */



            case 0x27: { v8Before = _A & 0x80;
/* SLA A */              _A <<= 1;

                         if(v8Before)
                            _F |= 0x10;          // Set C flag.
                         else _F &= 0xE0;        // Reset C flag.

                         if( _A == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0; // Reset N flag.
                         _F &= 0xD0; // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x28: { v8Before = _BC[B] & 0x80;     // 记录第 7 位。
/* SRA B */              v8After  = _BC[B] & 0x01;     // 记录第 0 位。
                         _BC[B] >>= 1;

                         if(v8Before)
                            _BC[B] |= 0x80;            // 第 7 位保持不变。

                         if(v8After)
                            _F |= 0x10;            // Set C flag.
                         else _F &= 0xE0;          // Reset C flag.

                         if( _BC[B] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x29: { v8Before = _BC[C] & 0x80;     // 记录第 7 位。
/* SRA C */              v8After  = _BC[C] & 0x01;     // 记录第 0 位。
                         _BC[C] >>= 1;

                         if(v8Before)
                            _BC[C] |= 0x80;            // 第 7 位保持不变。

                         if(v8After)
                            _F |= 0x10;            // Set C flag.
                         else _F &= 0xE0;          // Reset C flag.

                         if( _BC[C] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x2A: { v8Before = _DE[D] & 0x80;     // 记录第 7 位。
/* SRA D */              v8After  = _DE[D] & 0x01;     // 记录第 0 位。
                         _DE[D] >>= 1;

                         if(v8Before)
                            _DE[D] |= 0x80;            // 第 7 位保持不变。

                         if(v8After)
                            _F |= 0x10;            // Set C flag.
                         else _F &= 0xE0;          // Reset C flag.

                         if( _DE[D] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x2B: { v8Before = _DE[E] & 0x80;     // 记录第 7 位。
/* SRA E */              v8After  = _DE[E] & 0x01;     // 记录第 0 位。
                         _DE[E] >>= 1;

                         if(v8Before)
                            _DE[E] |= 0x80;            // 第 7 位保持不变。

                         if(v8After)
                            _F |= 0x10;            // Set C flag.
                         else _F &= 0xE0;          // Reset C flag.

                         if( _DE[E] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x2C: { v8Before = _HL[H] & 0x80;     // 记录第 7 位。
/* SRA H */              v8After  = _HL[H] & 0x01;     // 记录第 0 位。
                         _HL[H] >>= 1;

                         if(v8Before)
                            _HL[H] |= 0x80;            // 第 7 位保持不变。

                         if(v8After)
                            _F |= 0x10;            // Set C flag.
                         else _F &= 0xE0;          // Reset C flag.

                         if( _HL[H] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x2D: { v8Before = _HL[L] & 0x80;     // 记录第 7 位。
/* SRA L */              v8After  = _HL[L] & 0x01;     // 记录第 0 位。
                         _HL[L] >>= 1;

                         if(v8Before)
                            _HL[L] |= 0x80;            // 第 7 位保持不变。

                         if(v8After)
                            _F |= 0x10;            // Set C flag.
                         else _F &= 0xE0;          // Reset C flag.

                         if( _HL[L] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

case 0x2E:{ v8Before = Rbyte(W(_HL) ,NULL);
            v8After = v8Before & MSK_7;

            if(v8Before & MSK_0)
                SetC();
            else ResetC();

            v8Before >>= 1;
            if(v8After)
                v8Before |= MSK_7;

            Wbyte(W(_HL), v8Before);

            if( v8Before )
                ResetZ();
            else SetZ();

            ResetN();
            ResetH();
            instrCycles = 16;
            _PC += 2;
            break; }    /* SRA (HL) */

            case 0x2F: { v8Before = _A & 0x80;     // 记录第 7 位。
/* SRA A */              v8After  = _A & 0x01;     // 记录第 0 位。
                         _A >>= 1;

                         if(v8Before)
                            _A |= 0x80;            // 第 7 位保持不变。

                         if(v8After)
                            _F |= 0x10;            // Set C flag.
                         else _F &= 0xE0;          // Reset C flag.

                         if( _A == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x30: { v8Before = _BC[B];      // Copy.
/* SWAP B */             _BC[B]   <<= 4;         // Low nible to high.
                         v8Before >>= 4;         // High nible to low.
                         _BC[B] += v8Before;     // Combine. 也可以两者相与，位操作可能会快点。

                         if( _BC[B] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         _F &= 0xE0;         // Reset C flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x31: { v8Before = _BC[C];
/* SWAP C */             _BC[C]   <<= 4;
                         v8Before >>= 4;
                         _BC[C] += v8Before;

                         if( _BC[C] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         _F &= 0xE0;         // Reset C flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x32: { v8Before = _DE[D];
/* SWAP D */             _DE[D]   <<= 4;
                         v8Before >>= 4;
                         _DE[D] += v8Before;

                         if( _DE[D] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         _F &= 0xE0;         // Reset C flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x33: { v8Before = _DE[E];
/* SWAP E */             _DE[E]   <<= 4;
                         v8Before >>= 4;
                         _DE[E] += v8Before;

                         if( _DE[E] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         _F &= 0xE0;         // Reset C flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x34: { v8Before = _HL[H];
/* SWAP H */             _HL[H]   <<= 4;
                         v8Before >>= 4;
                         _HL[H] += v8Before;

                         if( _HL[H] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         _F &= 0xE0;         // Reset C flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x35: { v8Before = _HL[L];
/* SWAP L */             _HL[L]   <<= 4;
                         v8Before >>= 4;
                         _HL[L] += v8Before;

                         if( _HL[L] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         _F &= 0xE0;         // Reset C flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

case 0x36:{ v8Before = v8After = Rbyte(W(_HL) ,NULL);
            v8Before <<= 4;
            v8After >>= 4;
            v8Before += v8After;

            if( v8Before )
                ResetZ();
            else SetZ();

            ResetN();
            ResetH();
            ResetC();
            instrCycles = 16;
            _PC += 2;
            break; }    /* SWAP (HL) */

            case 0x37: { v8Before = _A;
/* SWAP A */             _A   <<= 4;
                         v8Before >>= 4;
                         _A += v8Before;

                         if( _A == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         _F &= 0xE0;         // Reset C flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x38: { v8Before = _BC[B] & 0x01;
/* SRL B */              _BC[B] >>= 1;

                         if(v8Before)
                            _F |= 0x10;      // Set C flag.
                         else _F &= 0xE0;    // Reset C flag.

                         if( _BC[B] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x39: { v8Before = _BC[C] & 0x01;
/* SRL C */              _BC[C] >>= 1;

                         if(v8Before)
                            _F |= 0x10;      // Set C flag.
                         else _F &= 0xE0;    // Reset C flag.

                         if( _BC[C] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x3A: { v8Before = _DE[D] & 0x01;
/* SRL D */              _DE[D] >>= 1;

                         if(v8Before)
                            _F |= 0x10;      // Set C flag.
                         else _F &= 0xE0;    // Reset C flag.

                         if( _DE[D] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x3B: { v8Before = _DE[E] & 0x01;
/* SRL E */              _DE[E] >>= 1;

                         if(v8Before)
                            _F |= 0x10;      // Set C flag.
                         else _F &= 0xE0;    // Reset C flag.

                         if( _DE[E] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x3C: { v8Before = _HL[H] & 0x01;
/* SRL H */              _HL[H] >>= 1;

                         if(v8Before)
                            _F |= 0x10;      // Set C flag.
                         else _F &= 0xE0;    // Reset C flag.

                         if( _HL[H] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x3D: { v8Before = _HL[L] & 0x01;
/* SRL L */              _HL[L] >>= 1;

                         if(v8Before)
                            _F |= 0x10;      // Set C flag.
                         else _F &= 0xE0;    // Reset C flag.

                         if( _HL[L] == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

case 0x3E:{ v8Before = Rbyte(W(_HL) ,NULL);
            if(v8Before & MSK_0)
                SetC();
            else ResetC();

            v8Before >>= 1;
            
            if( v8Before )
                ResetZ();
            else SetZ();

            ResetN();
            ResetH();
            
            instrCycles = 16;
            _PC += 2;
            break; }    /* SRL (HL) */

            case 0x3F: { v8Before = _A & 0x01;
/* SRL A */              _A >>= 1;

                         if(v8Before)
                            _F |= 0x10;      // Set C flag.
                         else _F &= 0xE0;    // Reset C flag.

                         if( _A == 0x00 )
                             _F |= 0x80;     // Set Z flag.
                         else _F &= 0x70;    // Reset Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F &= 0xD0;         // Reset H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x40: { if( _BC[B] & 0x01 )
/* BIT 0,B */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x41: { if( _BC[C] & 0x01 )
/* BIT 0,C */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x42: { if( _DE[D] & 0x01 )
/* BIT 0,D */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x43: { if( _DE[E] & 0x01 )
/* BIT 0,E */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x44: { if( _HL[H] & 0x01 )
/* BIT 0,H */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x45: { if( _HL[L] & 0x01 )
/* BIT 0,L */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x46: { if( Rbyte(W(_HL), NULL) & 0x01 )
/* BIT 0,(HL) */            _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 16;
                         _PC += 2;
                         break; }

            case 0x47: { if( _A & 0x01 )
/* BIT 0,A */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x48: { if( _BC[B] & 0x02 )
/* BIT 1,B */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x49: { if( _BC[C] & 0x02 )
/* BIT 1,C */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x4A: { if( _DE[D] & 0x02 )
/* BIT 1,D */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x4B: { if( _DE[E] & 0x02 )
/* BIT 1,E */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x4C: { if( _HL[H] & 0x02 )
/* BIT 1,H */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x4D: { if( _HL[L] & 0x02 )
/* BIT 1,L */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x4E: { if( Rbyte(W(_HL), NULL) & 0x02 )
/* BIT 1,(HL) */            _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 16;
                         _PC += 2;
                         break; }

            case 0x4F: { if( _A & 0x02 )
/* BIT 1,A */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x50: { if( _BC[B] & 0x04 )
/* BIT 2,B */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x51: { if( _BC[C] & 0x04 )
/* BIT 2,C */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x52: { if( _DE[D] & 0x04 )
/* BIT 2,D */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x53: { if( _DE[E] & 0x04 )
/* BIT 2,E */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x54: { if( _HL[H] & 0x04 )
/* BIT 2,H */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x55: { if( _HL[L] & 0x04 )
/* BIT 2,L */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x56: { if( Rbyte(W(_HL), NULL) & 0x04 )
/* BIT 2,(HL) */            _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 16;
                         _PC += 2;
                         break; }

            case 0x57: { if( _A & 0x04 )
/* BIT 2,A */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x58: { if( _BC[B] & 0x08 )
/* BIT 3,B */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x59: { if( _BC[C] & 0x08 )
/* BIT 3,C */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x5A: { if( _DE[D] & 0x08 )
/* BIT 3,D */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x5B: { if( _DE[E] & 0x08 )
/* BIT 3,E */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x5C: { if( _HL[H] & 0x08 )
/* BIT 3,H */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x5D: { if( _HL[L] & 0x08 )
/* BIT 3,L */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x5E: { if( Rbyte(W(_HL), NULL) & 0x08 )
/* BIT 3,(HL) */            _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 16;
                         _PC += 2;
                         break; }

            case 0x5F: { if( _A & 0x08 )
/* BIT 3,A */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x60: { if( _BC[B] & 0x10 )
/* BIT 4,B */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x61: { if( _BC[C] & 0x10 )
/* BIT 4,C */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x62: { if( _DE[D] & 0x10 )
/* BIT 4,D */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x63: { if( _DE[E] & 0x10 )
/* BIT 4,E */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x64: { if( _HL[H] & 0x10 )
/* BIT 4,H */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x65: { if( _HL[L] & 0x10 )
/* BIT 4,L */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x66: { if( Rbyte(W(_HL), NULL) & 0x10 )
/* BIT 4,(HL) */            _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 16;
                         _PC += 2;
                         break; }

            case 0x67: { if( _A & 0x10 )
/* BIT 4,A */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x68: { if( _BC[B] & 0x20 )
/* BIT 5,B */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x69: { if( _BC[C] & 0x20 )
/* BIT 5,C */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x6A: { if( _DE[D] & 0x20 )
/* BIT 5,D */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x6B: { if( _DE[E] & 0x20 )
/* BIT 5,E */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x6C: { if( _HL[H] & 0x20 )
/* BIT 5,H */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x6D: { if( _HL[L] & 0x20 )
/* BIT 5,L */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x6E: { if( Rbyte(W(_HL), NULL) & 0x20 )
/* BIT 5,(HL) */            _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 16;
                         _PC += 2;
                         break; }

            case 0x6F: { if( _A & 0x20 )
/* BIT 5,A */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x70: { if( _BC[B] & 0x40 )
/* BIT 6,B */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x71: { if( _BC[C] & 0x40 )
/* BIT 6,C */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x72: { if( _DE[D] & 0x40 )
/* BIT 6,D */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x73: { if( _DE[E] & 0x40 )
/* BIT 6,E */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x74: { if( _HL[H] & 0x40 )
/* BIT 6,H */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x75: { if( _HL[L] & 0x40 )
/* BIT 6,L */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x76: { if( Rbyte(W(_HL), NULL) & 0x40 )
/* BIT 6,(HL) */            _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 16;
                         _PC += 2;
                         break; }

            case 0x77: { if( _A & 0x40 )
/* BIT 6,A */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x78: { if( _BC[B] & 0x80 )
/* BIT 7,B */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x79: { if( _BC[C] & 0x80 )
/* BIT 7,C */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x7A: { if( _DE[D] & 0x80 )
/* BIT 7,D */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x7B: { if( _DE[E] & 0x80 )
/* BIT 7,E */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x7C: { if( _HL[H] & 0x80 )
/* BIT 7,H */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x7D: { if( _HL[L] & 0x80 )
/* BIT 7,L */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x7E: { if( Rbyte(W(_HL), NULL) & 0x80 )
/* BIT 7,(HL) */            _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 16;
                         _PC += 2;
                         break; }

            case 0x7F: { if( _A & 0x80 )
/* BIT 7,A */               _F &= 0x70;      // Reset Z flag.
                         else _F |= 0x80;    // Set Z flag.

                         _F &= 0xB0;         // Reset N flag.
                         _F |= 0x20;         // Set H flag.
                         instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x80: { _BC[B] &= 0xFE;
/* RES 0,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x81: { _BC[C] &= 0xFE;
/* RES 0,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x82: { _DE[D] &= 0xFE;
/* RES 0,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x83: { _DE[E] &= 0xFE;
/* RES 0,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x84: { _HL[H] &= 0xFE;
/* RES 0,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x85: { _HL[L] &= 0xFE;
/* RES 0,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0x86:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before & 0xFE);
            instrCycles = 16;
            _PC += 2;
            break; }    /* RES 0,(HL) */

            case 0x87: { _A &= 0xFE;
/* RES 0,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x88: { _BC[B] &= 0xFD;
/* RES 1,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x89: { _BC[C] &= 0xFD;
/* RES 1,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x8A: { _DE[D] &= 0xFD;
/* RES 1,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x8B: { _DE[E] &= 0xFD;
/* RES 1,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x8C: { _HL[H] &= 0xFD;
/* RES 1,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x8D: { _HL[L] &= 0xFD;
/* RES 1,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0x8E:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before & 0xFD);
            instrCycles = 16;
            _PC += 2;
            break; }    /* RES 1,(HL) */

            case 0x8F: { _A &= 0xFD;
/* RES 1,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x90: { _BC[B] &= 0xFB;
/* RES 2,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x91: { _BC[C] &= 0xFB;
/* RES 2,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x92: { _DE[D] &= 0xFB;
/* RES 2,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x93: { _DE[E] &= 0xFB;
/* RES 2,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x94: { _HL[H] &= 0xFB;
/* RES 2,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x95: { _HL[L] &= 0xFB;
/* RES 2,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0x96:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before & 0xFB);
            instrCycles = 16;
            _PC += 2;
            break; }    /* RES 2,(HL) */

            case 0x97: { _A &= 0xFB;
/* RES 2,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x98: { _BC[B] &= 0xF7;
/* RES 3,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x99: { _BC[C] &= 0xF7;
/* RES 3,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x9A: { _DE[D] &= 0xF7;
/* RES 3,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x9B: { _DE[E] &= 0xF7;
/* RES 3,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x9C: { _HL[H] &= 0xF7;
/* RES 3,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0x9D: { _HL[L] &= 0xF7;
/* RES 3,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0x9E:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before & 0xF7);
            instrCycles = 16;
            _PC += 2;
            break; }    /* RES 3,(HL) */

            case 0x9F: { _A &= 0xF7;
/* RES 3,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xA0: { _BC[B] &= 0xEF;
/* RES 4,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xA1: { _BC[C] &= 0xEF;
/* RES 4,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xA2: { _DE[D] &= 0xEF;
/* RES 4,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xA3: { _DE[E] &= 0xEF;
/* RES 4,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xA4: { _HL[H] &= 0xEF;
/* RES 4,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xA5: { _HL[L] &= 0xEF;
/* RES 4,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xA6:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before & 0xEF);
            instrCycles = 16;
            _PC += 2;
            break; }    /* RES 4,(HL) */

            case 0xA7: { _A &= 0xEF;
/* RES 4,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xA8: { _BC[B] &= 0xDF;
/* RES 5,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xA9: { _BC[C] &= 0xDF;
/* RES 5,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xAA: { _DE[D] &= 0xDF;
/* RES 5,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xAB: { _DE[E] &= 0xDF;
/* RES 5,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xAC: { _HL[H] &= 0xDF;
/* RES 5,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xAD: { _HL[L] &= 0xDF;
/* RES 5,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xAE:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before & 0xDF);
            instrCycles = 16;
            _PC += 2;
            break; }    /* RES 5,(HL) */

            case 0xAF: { _A &= 0xDF;
/* RES 5,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xB0: { _BC[B] &= 0xBF;
/* RES 6,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xB1: { _BC[C] &= 0xBF;
/* RES 6,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xB2: { _DE[D] &= 0xBF;
/* RES 6,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xB3: { _DE[E] &= 0xBF;
/* RES 6,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xB4: { _HL[H] &= 0xBF;
/* RES 6,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xB5: { _HL[L] &= 0xBF;
/* RES 6,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xB6:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before & 0xBF);
            instrCycles = 16;
            _PC += 2;
            break; }    /* RES 6,(HL) */

            case 0xB7: { _A &= 0xBF;
/* RES 6,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xB8: { _BC[B] &= 0x7F;
/* RES 7,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xB9: { _BC[C] &= 0x7F;
/* RES 7,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xBA: { _DE[D] &= 0x7F;
/* RES 7,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xBB: { _DE[E] &= 0x7F;
/* RES 7,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xBC: { _HL[H] &= 0x7F;
/* RES 7,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xBD: { _HL[L] &= 0x7F;
/* RES 7,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xBE:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before & 0x7F);
            instrCycles = 16;
            _PC += 2;
            break; }    /* RES 7,(HL) */

            case 0xBF: { _A &= 0x7F;
/* RES 7,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xC0: { _BC[B] |= 0x01;
/* SET 0,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xC1: { _BC[C] |= 0x01;
/* SET 0,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xC2: { _DE[D] |= 0x01;
/* SET 0,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xC3: { _DE[E] |= 0x01;
/* SET 0,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xC4: { _HL[H] |= 0x01;
/* SET 0,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xC5: { _HL[L] |= 0x01;
/* SET 0,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xC6:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before |= 0x01);
            instrCycles = 16;
            _PC += 2;
            break; }    /* SET 0,(HL) */

            case 0xC7: { _A |= 0x01;
/* SET 0,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xC8: { _BC[B] |= 0x02;
/* SET 1,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xC9: { _BC[C] |= 0x02;
/* SET 1,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xCA: { _DE[D] |= 0x02;
/* SET 1,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xCB: { _DE[E] |= 0x02;
/* SET 1,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xCC: { _HL[H] |= 0x02;
/* SET 1,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xCD: { _HL[L] |= 0x02;
/* SET 1,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xCE:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before |= 0x02);
            instrCycles = 16;
            _PC += 2;
            break; }    /* SET 1,(HL) */

            case 0xCF: { _A |= 0x02;
/* SET 1,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xD0: { _BC[B] |= 0x04;
/* SET 2,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xD1: { _BC[C] |= 0x04;
/* SET 2,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xD2: { _DE[D] |= 0x04;
/* SET 2,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xD3: { _DE[E] |= 0x04;
/* SET 2,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xD4: { _HL[H] |= 0x04;
/* SET 2,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xD5: { _HL[L] |= 0x04;
/* SET 2,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xD6:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before |= 0x04);
            instrCycles = 16;
            _PC += 2;
            break; }    /* SET 2,(HL) */

            case 0xD7: { _A |= 0x04;
/* SET 2,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xD8: { _BC[B] |= 0x08;
/* SET 3,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xD9: { _BC[C] |= 0x08;
/* SET 3,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xDA: { _DE[D] |= 0x08;
/* SET 3,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xDB: { _DE[E] |= 0x08;
/* SET 3,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xDC: { _HL[H] |= 0x08;
/* SET 3,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xDD: { _HL[L] |= 0x08;
/* SET 3,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xDE:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before |= 0x08);
            instrCycles = 16;
            _PC += 2;
            break; }    /* SET 3,(HL) */

            case 0xDF: { _A |= 0x08;
/* SET 3,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xE0: { _BC[B] |= 0x10;
/* SET 4,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xE1: { _BC[C] |= 0x10;
/* SET 4,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xE2: { _DE[D] |= 0x10;
/* SET 4,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xE3: { _DE[E] |= 0x10;
/* SET 4,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xE4: { _HL[H] |= 0x10;
/* SET 4,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xE5: { _HL[L] |= 0x10;
/* SET 4,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xE6:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before |= 0x10);
            instrCycles = 16;
            _PC += 2;
            break; }    /* SET 4,(HL) */

            case 0xE7: { _A |= 0x10;
/* SET 4,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xE8: { _BC[B] |= 0x20;
/* SET 5,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xE9: { _BC[C] |= 0x20;
/* SET 5,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xEA: { _DE[D] |= 0x20;
/* SET 5,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xEB: { _DE[E] |= 0x20;
/* SET 5,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xEC: { _HL[H] |= 0x20;
/* SET 5,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xED: { _HL[L] |= 0x20;
/* SET 5,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xEE:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before |= 0x20);
            instrCycles = 16;
            _PC += 2;
            break; }    /* SET 5,(HL) */

            case 0xEF: { _A |= 0x20;
/* SET 5,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xF0: { _BC[B] |= 0x40;
/* SET 6,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xF1: { _BC[C] |= 0x40;
/* SET 6,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xF2: { _DE[D] |= 0x40;
/* SET 6,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xF3: { _DE[E] |= 0x40;
/* SET 6,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xF4: { _HL[H] |= 0x40;
/* SET 6,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xF5: { _HL[L] |= 0x40;
/* SET 6,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xF6:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before |= 0x40);
            instrCycles = 16;
            _PC += 2;
            break; }    /* SET 6,(HL) */

            case 0xF7: { _A |= 0x40;
/* SET 6,A */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xF8: { _BC[B] |= 0x80;
/* SET 7,B */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xF9: { _BC[C] |= 0x80;
/* SET 7,C */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xFA: { _DE[D] |= 0x80;
/* SET 7,D */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xFB: { _DE[E] |= 0x80;
/* SET 7,E */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xFC: { _HL[H] |= 0x80;
/* SET 7,H */            instrCycles = 8;
                         _PC += 2;
                         break; }

            case 0xFD: { _HL[L] |= 0x80;
/* SET 7,L */            instrCycles = 8;
                         _PC += 2;
                         break; }

case 0xFE:{ v8Before = Rbyte(W(_HL), NULL);
            Wbyte(W(_HL), v8Before |= 0x80);
            instrCycles = 16;
            _PC += 2;
            break; }    /* SET 7,(HL) */

            case 0xFF: { _A |= 0x80;
/* SET 7,A */            instrCycles = 8;
                         _PC += 2;
                         break; }
