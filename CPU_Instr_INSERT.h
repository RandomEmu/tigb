case 0x00:{ // Do nothing.
            instrCycles = 4;
            _PC++;
            //fprintf(stderr, "NOP\n");
            //_getch();
            break; }    /* NOP */
            
case 0x01:{ W(_BC) = *( (word_t *)(instrPtr + 1) );
            instrCycles = 12;
            _PC += 3;
            //fprintf(stderr, "LD BC,d16\n");
            //_getch();
            break; }    /* LD BC,d16 */

case 0x02:{ Wbyte(W(_BC), _A);
            instrCycles = 8;
            _PC++;
            break; }    /* LD (BC),A */

case 0x03:{ (W(_BC))++;
            instrCycles = 8;
            _PC++;
            break; }    /* INC BC */

case 0x04:{ v8Before = _BC[B] & MSK_3;
            (_BC[B])++;
            v8After  = _BC[B] & MSK_3;
            if( (v8Before == 0x08) && (! v8After) )
                SetH();
            else ResetH();
            if( _BC[B] )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* INC B */

case 0x05:{ v8Before = _BC[B] & MSK_3;
            (_BC[B])--;
            v8After  = _BC[B] & MSK_3;
            if( (! v8Before) && (v8After == 0x08) )
                SetH();
            else ResetH();
            if( _BC[B] )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* DEC B */

case 0x06:{ _BC[B] = instrPtr[1];
            instrCycles = 8;
            _PC += 2;
            break; }    /* LD B,d8 */

case 0x07:{ v8Before = _A & MSK_7;      //记录第 7 位。
            _A <<= 1;
            if(v8Before) {
                SetC();
                _A |= MSK_0;
            } else ResetC();
            ResetZ();
            ResetN();
            ResetH();
            instrCycles = 4;
            _PC++ ;
            break; }    /* RLCA */

case 0x08:{ W(_WZ) = *( (word_t *)(instrPtr + 1) );
            Wbyte(W(_WZ), pB_SP[L]);
            W(_WZ)++;
            Wbyte(W(_WZ), pB_SP[H]);
            instrCycles = 20;
            _PC += 3 ;
            break; }    /* LD (a16),SP */

case 0x09:{ v16Before = (W(_HL) & MSK_0_11) + (W(_BC) & MSK_0_11);
            if( v16Before & MSK_12 )
                SetH();
            else ResetH();                       
            v32Carry = W(_HL) + W(_BC);
            if( v32Carry & MSK_16)
                SetC();
            else ResetC();
            W(_HL) += W(_BC);
            ResetN();
            instrCycles = 8;
            _PC++;
            break; }    /* ADD HL,BC */

case 0x0A:{ _A = Rbyte(W(_BC), NULL);
            instrCycles = 8;
            _PC++ ;
            break; }    /* LD A,(BC) */

case 0x0B:{ W(_BC)--;
            instrCycles = 8;
            _PC++;
            break; }    /* DEC BC */

case 0x0C:{ //fprintf(stderr, "INC C _BC[C] = %02X \n", _BC[C]);
            v8Before = _BC[C] & MSK_3;
            (_BC[C])++;
            v8After  = _BC[C] & MSK_3;
            if( (v8Before == 0x08) && (! v8After) )
                SetH();
            else ResetH();
            if( _BC[C] )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            //fprintf(stderr, "INC C _BC[C] = %02X \n", _BC[C]);
            break; }    /* INC C */

case 0x0D:{ v8Before = _BC[C] & MSK_3;
            (_BC[C])--;
            v8After  = _BC[C] & MSK_3;
            if( (! v8Before) && (v8After == 0x08) )
                SetH();
            else ResetH();
            if( _BC[C] )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* DEC C */

case 0x0E:{ _BC[C] = instrPtr[1];
            instrCycles = 8;
            _PC += 2;
            break; }    /* LD C,d8 */

case 0x0F:{ v8Before = _A & MSK_0;
            _A >>= 1;
            if(v8Before) {
                SetC();
                _A |= MSK_7;
            } else ResetC();
            ResetZ();
            ResetN();
            ResetH();
            instrCycles = 4;
            _PC++ ;
            break; }    /* RRCA */

case 0x10:{ isStop = TRUE;
            instrCycles = 4;
            _PC += 2;
            break; }    /* STOP 0 */

case 0x11:{ W(_DE) = *( (word_t *)(instrPtr + 1) );
            instrCycles = 12;
            _PC += 3;
            break; }    /* LD DE,d16 */

case 0x12:{ Wbyte(W(_DE), _A);
            instrCycles = 8;
            _PC++;
            break; }    /* LD (DE),A */

case 0x13:{ (W(_DE))++;
            instrCycles = 8;
            _PC++;
            break; }    /* INC DE */

case 0x14:{ v8Before = _DE[D] & MSK_3;
            (_DE[D])++;
            v8After  = _DE[D] & MSK_3;
            if( (v8Before == 0x08) && (! v8After) )
                SetH();
            else ResetH();
            if( _DE[D] )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* INC D */

case 0x15:{ v8Before = _DE[D] & MSK_3;
            (_DE[D])--;
            v8After  = _DE[D] & MSK_3;
            if( (! v8Before) && (v8After == 0x08) )
                SetH();
            else ResetH();
            if( _DE[D] )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* DEC D */

case 0x16:{ _DE[D] = instrPtr[1];
            instrCycles = 8;
            _PC += 2;
            break; }    /* LD D,d8 */

case 0x17:{ v8Before = _A & MSK_7;  //记录第 7 位。
            _A <<= 1;               //如果宿主默认是补 0 的话，此实现才成立。
            if( _F & MSK_4 )        //如果 C 标志位是 1 的话，就把左移后的 A 的第 0 位置 1 。否则保持其为 0 不变。
                _A |= MSK_0;
            if(v8Before)            //如果移位前 A 的第 7 位是 1 的话，则把 C 标志位置 1 ，否则把 C 清零。
                SetC();
            else ResetC();
            ResetZ();
            ResetN();
            ResetH();
            instrCycles = 4;
            _PC++;
            break; }    /* RLA */

case 0x18:{ instrCycles = 12;
            _PC += (sbyte_t)(instrPtr[1]);      // 本指令的实现涉及有符号数的补码，以及有符号数的位扩展。
            _PC += 2;                           // 别忘记。
            //fprintf(stderr, "JR %04X\n", _PC);    // DEBUG.
            break; }    /* JR r8 */

case 0x19:{ v16Before = (W(_HL) & MSK_0_11) + (W(_DE) & MSK_0_11);
            if( v16Before & MSK_12 )
                SetH();
            else ResetH();
            v32Carry = W(_HL) + W(_DE);
            if( v32Carry & MSK_16)
                SetC();
            else ResetC();
            W(_HL) += W(_DE);
            ResetN();
            instrCycles = 8;
            _PC++;
            break; }    /* ADD HL,DE */

case 0x1A:{ _A = Rbyte(W(_DE), NULL);
            instrCycles = 8;
            _PC++ ;
            break; }    /* LD A,(DE) */

case 0x1B:{ W(_DE)--;
            instrCycles = 8;
            _PC++;
            break; }    /* DEC DE */

case 0x1C:{ v8Before = _DE[E] & MSK_3;
            (_DE[E])++;
            v8After  = _DE[E] & MSK_3;
            if( (v8Before == 0x08) && (! v8After) )
                SetH();
            else ResetH();
            if( _DE[E] )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* INC E */

case 0x1D:{ v8Before = _DE[E] & MSK_3;
            (_DE[E])--;
            v8After  = _DE[E] & MSK_3;
            if( (! v8Before) && (v8After == 0x08) )
                SetH();
            else ResetH();
            if( _DE[E] )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* DEC E */

case 0x1E:{ _DE[E] = instrPtr[1];
            instrCycles = 8;
            _PC += 2;
            break; }    /* LD E,d8 */

case 0x1F:{ v8Before = _A & MSK_0;
            _A >>= 1;
            if(_F & MSK_4)
                _A |= MSK_7;
            if(v8Before)
                SetC();
            else ResetC();
            ResetZ();
            ResetN();
            ResetH();
            instrCycles = 4;
            _PC++;
            break; }    /* RRA */

case 0x20:{ _PC += 2;
            if( _F & MSK_7 ) {
                instrCycles = 8;
            } else {
                instrCycles = 12;
                _PC += (sbyte_t)( instrPtr[1] );
                //fprintf(stderr, "JR NZ %04X\n", _PC); // DEBUG.
            }
            break; }    /* JR NZ,r8 */

case 0x21:{ W(_HL) = *( (word_t *)(instrPtr + 1) );
            instrCycles = 12;
            _PC += 3;
            break; }    /* LD HL,d16 */

case 0x22:{ Wbyte(W(_HL), _A);
            (W(_HL))++;             // 这个自增“一定不能”写在上一句的宏函数里。
            instrCycles = 8;
            _PC++;
            break; }    /* LD (HL+),A */

case 0x23:{ (W(_HL))++;
            instrCycles = 8;
            _PC++;
            break; }    /* INC HL */

case 0x24:{ v8Before = _HL[H] & MSK_3;
            (_HL[H])++;
            v8After  = _HL[H] & MSK_3;
            if( (v8Before == 0x08) && (! v8After) )
                SetH();
            else ResetH();
            if( _HL[H] )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* INC H */

case 0x25:{ v8Before = _HL[H] & MSK_3;
            (_HL[H])--;
            v8After  = _HL[H] & MSK_3;
            if( (! v8Before) && (v8After == 0x08) )
                SetH();
            else ResetH();
            if( _HL[H] )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* DEC H */

case 0x26:{ _HL[H] = instrPtr[1];
            instrCycles = 8;
            _PC += 2;
            break; }    /* LD H,d8 */

case 0x27:{ v8Before = _A & MSK_4_7;    // Get bit 7-4 of A.
            v8After  = _A & MSK_0_3;    // Get bit 3-0 of A.
            switch( _F & MSK_4_6 ) {    // Get N, H, C flags.
                case 0x00:{ if( (v8Before >= 0x00) && (v8Before < 0x91) && (v8After >= 0x00) && (v8After < 0x0A) ) {  // H:0-9 L:0-9
            /* NHC = 000 */     // Add 0x00 to A. In fact do nothing to A.
                                ResetC();
                                break;
                            };
                            if( (v8Before >= 0x00) && (v8Before < 0x81) && (v8After >  0x09) && (v8After < 0x10) ) {  // H:0-8 L:A-F
                                _A += 0x06;
                                ResetC();
                                break;
                            };
                            if( (v8Before >  0x8F) && (v8Before < 0xF1) && (v8After >  0x09) && (v8After < 0x10) ) {  // H:9-F L:A-F
                                _A += 0x66;
                                SetC();
                                break;
                            };
                            if( (v8Before >  0xBF) && (v8Before < 0xF1) && (v8After >= 0x00) && (v8After < 0x0A) ) {  // H:A-F L:0-9
                                _A += 0x60;
                                SetC();
                                break;
                            };
                            break; }

                case 0x10:{ if( (v8Before >= 0x00) && (v8Before < 0x21) && (v8After >= 0x00) && (v8After < 0X0A) ) {  // H:0-2 L:0-9
            /* NHC = 001 */     _A += 0x60;
                                SetC();
                                break;
                            };
                            if( (v8Before >= 0x00) && (v8Before < 0x21) && (v8After > 0x09) && (v8After < 0x10) ) {  // H:0-2 L:A-F
                                _A += 0x66;
                                SetC();
                                break;
                            };
                            break; }

                case 0x20:{ if( (v8Before >= 0x00) && (v8Before < 0x91) && (v8After >= 0x00) && (v8After < 0x04) ) {  // H:0-9 L:0-3
            /* NHC = 010 */     _A += 0x06;
                                ResetC();
                                break;
                            };
                            if( (v8Before >  0xBF) && (v8Before < 0xF1) && (v8After >= 0x00) && (v8After < 0x04) ) {  // H:A-F L:0-3
                                _A += 0x66;
                                SetC();
                                break;
                            };
                            break; }

                case 0x30:{ if( (v8Before >= 0x00) && (v8Before < 0x31) && (v8After >= 0x00) && (v8After < 0x04) ) {  // H:0-3 L:0-3
            /* NHC = 011 */     _A += 0x66;
                                SetC();
                                break;
                            };
                            break; }

                case 0x40:{ if( (v8Before >= 0x00) && (v8Before < 0x91) && (v8After >= 0x00) && (v8After < 0x0A) ) {  // H:0-9 L:0-9
            /* NHC = 100 */     // Add 0x00 to A. In fact do nothing to A.
                                ResetC();
                                break;
                            };
                            break; }

                case 0x50:{ if( (v8Before > 0x6F) && (v8Before < 0xF1) && (v8After >= 0x00) && (v8After < 0x0A) ) {  // H:7-F L:0-9
            /* NHC = 101 */     _A += 0xA0;
                                SetC();
                                break;
                            };
                            break; }

                case 0x60:{ if( (v8Before >= 0x00) && (v8Before < 0x81) && (v8After > 0x05) && (v8After < 0x10) ) {  // H:0-8 L:6-F
            /* NHC = 110 */     _A += 0xFA;
                                ResetC();
                                break;
                            };
                            break; }

                case 0x70:{ if( (v8Before >  0x5F) && (v8Before < 0xF1) && (v8After > 0x05) && (v8After < 0x10) ) {  // H:6-F L:6-F
            /* NHC = 111 */     _A += 0x9A;
                                SetC();
                                break;
                            };
                            break; }

                default  :{ break; } 
            };  // switch( _F & MSK_4_6 )
            if( _A )
                ResetZ();
            else SetZ();
            ResetH();
            instrCycles = 4;
            _PC++;
            break; }    /* DAA */

case 0x28:{ _PC += 2;
            if( _F & MSK_7 ) {
                instrCycles = 12;
                _PC += (sbyte_t)( instrPtr[1] );
                //fprintf(stderr, "JR Z %04X\n", _PC);  // DEBUG.
            } else {
                instrCycles = 8;
            }
            break; }    /* JR Z,r8 */

case 0x29:{ v16Before = (W(_HL) & MSK_0_11) + (W(_HL) & MSK_0_11);
            if( v16Before & MSK_12 )
                SetH();
            else ResetH();
            v32Carry = W(_HL) + W(_HL);
            if( v32Carry & MSK_16)
                SetC();
            else ResetC();
            W(_HL) += W(_HL);
            ResetN();
            instrCycles = 8;
            _PC++;
            break; }    /* ADD HL,HL */

case 0x2A:{ _A = Rbyte(W(_HL), NULL);
            W(_HL)++;
            instrCycles = 8;
            _PC++ ;
            break; }    /* LD A,(HL+) */

case 0x2B:{ W(_HL)--;
            instrCycles = 8;
            _PC++;
            break; }    /* DEC HL */

case 0x2C:{ v8Before = _HL[L] & MSK_3;
            _HL[L]++;
            v8After  = _HL[L] & MSK_3;
            if( (v8Before == 0x08) && (! v8After) )
                SetH();
            else ResetH();
            if( _HL[L] )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* INC L */

case 0x2D:{ v8Before = _HL[L] & MSK_3;
            _HL[L]--;
            v8After  = _HL[L] & MSK_3;
            if( (! v8Before) && (v8After == 0x08) )
                SetH();
            else ResetH();
            if( _HL[L] )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* DEC L */

case 0x2E:{ _HL[L] = instrPtr[1];
            instrCycles = 8;
            _PC += 2;
            break; }    /* LD L,d8 */

case 0x2F:{ _A = ~(_A);
            SetN();
            SetH();
            instrCycles = 4;
            _PC++;
            break; }    /* CPL */

case 0x30:{ _PC += 2;
            if( _F & MSK_4 ) {
                instrCycles = 8;
            } else {
                instrCycles = 12;
                _PC += (sbyte_t)( instrPtr[1] );
                //fprintf(stderr, "JR NC %04X\n", _PC); // DEBUG.
            }
            break; }    /* JR NC,r8 */

case 0x31:{ _SP = *( (word_t *)(instrPtr + 1) );
            instrCycles = 12;
            _PC += 3;
            break; }    /* LD SP,d16 */

case 0x32:{ Wbyte(W(_HL), _A);
            W(_HL)--;               // 这个自增“一定不能”写在上一句的宏函数里。
            instrCycles = 8;
            _PC++;
            break; }    /* LD (HL-),A */

case 0x33:{ _SP++;
            instrCycles = 8;
            _PC++;
            break; }    /* INC SP */

case 0x34:{ _WZ[Z] = Rbyte(W(_HL), NULL);
            v8Before = (_WZ[Z]) & MSK_3;
            (_WZ[Z])++;
            v8After  = (_WZ[Z]) & MSK_3;
            Wbyte(W(_HL), _WZ[Z]);
            
            if( (v8Before == 0x08) && ( ! v8After) )
                SetH();
            else ResetH();
            
            if( _WZ[Z] )
                ResetZ();
            else SetZ();
            
            ResetN();
            instrCycles = 12;
            _PC++;
            break; }    /* INC (HL) */

case 0x35:{ _WZ[Z] = Rbyte(W(_HL), NULL);
            v8Before = (_WZ[Z]) & MSK_3;
            (_WZ[Z])--;
            v8After  = (_WZ[Z]) & MSK_3;
            Wbyte(W(_HL), _WZ[Z]);
            
            if( ( ! v8Before) && (v8After == 0x08) )
                SetH();
            else ResetH();
            
            if( _WZ[Z] )
                ResetZ();
            else SetZ();
            
            ResetN();
            instrCycles = 12;
            _PC++;
            break; }    /* DEC (HL) */

case 0x36:{ Wbyte(W(_HL), instrPtr[1]);
            instrCycles = 12;
            _PC += 2;
            break; }    /* LD (HL),d8 */

case 0x37:{ SetC();
            ResetN();
            ResetH();
            instrCycles = 4;
            _PC++;
            break; }    /* SCF */

case 0x38:{ _PC += 2;
            if( _F & MSK_4 ) {
                instrCycles = 12;
                _PC += (sbyte_t)( instrPtr[1] );
                //fprintf(stderr, "JR C %04X\n", _PC);  // DEBUG.
            } else {
                instrCycles = 8;
            }
            break; }    /* JR C,r8 */

case 0x39:{ v16Before = (W(_HL) & MSK_0_11) + (_SP & MSK_0_11);
            if( v16Before & MSK_12 )
                SetH();
            else ResetH();
            v32Carry = W(_HL) + _SP;
            if( v32Carry & MSK_16)
                SetC();
            else ResetC();
            W(_HL) += _SP;
            ResetN();
            instrCycles = 8;
            _PC++;
            break; }    /* ADD HL,SP */

case 0x3A:{ _A = Rbyte(W(_HL), NULL);
            W(_HL)--;
            instrCycles = 8;
            _PC++ ;
            break; }    /* LD A,(HL-) */

case 0x3B:{ _SP--;
            instrCycles = 8;
            _PC++;
            break; }    /* DEC SP */

case 0x3C:{ v8Before = _A & MSK_3;
            _A++;
            v8After  = _A & MSK_3;
            if( (v8Before == 0x08) && (! v8After) )
                SetH();
            else ResetH();
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* INC A */

case 0x3D:{ v8Before = _A & MSK_3;
            _A--;
            v8After  = _A & MSK_3;
            if( (! v8Before) && (v8After == 0x08) )
                SetH();
            else ResetH();
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* DEC A */

case 0x3E:{ _A = instrPtr[1];
            instrCycles = 8;
            _PC += 2;
            break; }    /* LD A,d8 */

case 0x3F:{ if( _F & MSK_4)
                ResetC();
            else SetC();
            ResetN();
            ResetH();
            instrCycles = 4;
            _PC++;
             break; }   /* CCF */

case 0x40:{ _BC[B] = _BC[B];
            instrCycles = 4;
            _PC++;
            break; }    /* LD B,B */

case 0x41:{ _BC[B] = _BC[C];
            instrCycles = 4;
            _PC++;
            break; }    /* LD B,C */

case 0x42:{ _BC[B] = _DE[D];
            instrCycles = 4;
            _PC++;
            break; }    /* LD B,D */

case 0x43:{ _BC[B] = _DE[E];
            instrCycles = 4;
            _PC++;
            break; }    /* LD B,E */

case 0x44:{ _BC[B] = _HL[H];
            instrCycles = 4;
            _PC++;
            break; }    /* LD B,H */

case 0x45:{ _BC[B] = _HL[L];
            instrCycles = 4;
            _PC++;
            break; }    /* LD B,L */

case 0x46:{ _BC[B] = Rbyte(W(_HL), NULL);
            instrCycles = 8;
            _PC++;
            break; }    /* LD B,(HL) */

case 0x47:{ _BC[B] = _A;
            instrCycles = 4;
            _PC++;
            break; }    /* LD B,A */

case 0x48:{ _BC[C] = _BC[B];
            instrCycles = 4;
            _PC++;
            break; }    /* LD C,B */

case 0x49:{ _BC[C] = _BC[C];
            instrCycles = 4;
            _PC++;
            break; }    /* LD C,C */

case 0x4A:{ _BC[C] = _DE[D];
            instrCycles = 4;
            _PC++;
            break; }    /* LD C,D */

case 0x4B:{ _BC[C] = _DE[E];
            instrCycles = 4;
            _PC++;
            break; }    /* LD C,E */

case 0x4C:{ _BC[C] = _HL[H];
            instrCycles = 4;
            _PC++;
            break; }    /* LD C,H */

case 0x4D:{ _BC[C] = _HL[L];
            instrCycles = 4;
            _PC++;
            break; }    /* LD C,L */

case 0x4E:{ _BC[C] = Rbyte(W(_HL), NULL);
            instrCycles = 8;
            _PC++;
            break; }    /* LD C,(HL) */

case 0x4F:{ _BC[C] = _A;
            instrCycles = 4;
            _PC++;
            break; }    /* LD C,A */

case 0x50:{ _DE[D] = _BC[B];
            instrCycles = 4;
            _PC++;
            break; }    /* LD D,B */

case 0x51:{ _DE[D] = _BC[C];
            instrCycles = 4;
            _PC++;
            break; }    /* LD D,C */

case 0x52:{ _DE[D] = _DE[D];
            instrCycles = 4;
            _PC++;
            break; }    /* LD D,D */

case 0x53:{ _DE[D] = _DE[E];
            instrCycles = 4;
            _PC++;
            break; }    /* LD D,E */

case 0x54:{ _DE[D] = _HL[H];
            instrCycles = 4;
            _PC++;
            break; }    /* LD D,H */

case 0x55:{ _DE[D] = _HL[L];
            instrCycles = 4;
            _PC++;
            break; }    /* LD D,L */

case 0x56:{ _DE[D] = Rbyte(W(_HL), NULL);
            instrCycles = 8;
            _PC++;
            break; }    /* LD D,(HL) */

case 0x57:{ _DE[D] = _A;
            instrCycles = 4;
            _PC++;
            break; }    /* LD D,A */

case 0x58:{ _DE[E] = _BC[B];
            instrCycles = 4;
            _PC++;
            break; }    /* LD E,B */

case 0x59:{ _DE[E] = _BC[C];
            instrCycles = 4;
            _PC++;
            break; }    /* LD E,C */

case 0x5A:{ _DE[E] = _DE[D];
            instrCycles = 4;
            _PC++;
            break; }    /* LD E,D */

case 0x5B:{ _DE[E] = _DE[E];
            instrCycles = 4;
            _PC++;
            break; }    /* LD E,E */

case 0x5C:{ _DE[E] = _HL[H];
            instrCycles = 4;
            _PC++;
            break; }    /* LD E,H */

case 0x5D:{ _DE[E] = _HL[L];
            instrCycles = 4;
            _PC++;
            break; }    /* LD E,L */

case 0x5E:{ _DE[E] = Rbyte(W(_HL), NULL);
            instrCycles = 8;
            _PC++;
            break; }    /* LD E,(HL) */

case 0x5F:{ _DE[E] = _A;
            instrCycles = 4;
            _PC++;
            break; }    /* LD E,A */

case 0x60:{ _HL[H] = _BC[B];
            instrCycles = 4;
            _PC++;
            break; }    /* LD H,B */

case 0x61:{ _HL[H] = _BC[C];
            instrCycles = 4;
            _PC++;
            break; }    /* LD H,C */

case 0x62:{ _HL[H] = _DE[D];
            instrCycles = 4;
            _PC++;
            break; }    /* LD H,D */

case 0x63:{ _HL[H] = _DE[E];
            instrCycles = 4;
            _PC++;
            break; }    /* LD H,E */

case 0x64:{ _HL[H] = _HL[H];
            instrCycles = 4;
            _PC++;
            break; }    /* LD H,H */

case 0x65:{ _HL[H] = _HL[L];
            instrCycles = 4;
            _PC++;
            break; }    /* LD H,L */

case 0x66:{ _HL[H] = Rbyte(W(_HL), NULL);
            instrCycles = 8;
            _PC++;
            break; }    /* LD H,(HL) */

case 0x67:{ _HL[H] = _A;
            instrCycles = 4;
            _PC++;
            break; }    /* LD H,A */

case 0x68:{ _HL[L] = _BC[B];
            instrCycles = 4;
            _PC++;
            break; }    /* LD L,B */

case 0x69:{ _HL[L] = _BC[C];
            instrCycles = 4;
            _PC++;
            break; }    /* LD L,C */

case 0x6A:{ _HL[L] = _DE[D];
            instrCycles = 4;
            _PC++;
            break; }    /* LD L,D */

case 0x6B:{ _HL[L] = _DE[E];
            instrCycles = 4;
            _PC++;
            break; }    /* LD L,E */

case 0x6C:{ _HL[L] = _HL[H];
            instrCycles = 4;
            _PC++;
            break; }    /* LD L,H */

case 0x6D:{ _HL[L] = _HL[L];
            instrCycles = 4;
            _PC++;
            break; }    /* LD L,L */

case 0x6E:{ _HL[L] = Rbyte(W(_HL), NULL);
            instrCycles = 8;
            _PC++;
            break; }    /* LD L,(HL) */

case 0x6F:{ _HL[L] = _A;
            instrCycles = 4;
            _PC++;
            break; }    /* LD L,A */

case 0x70:{ Wbyte(W(_HL), _BC[B]);
            instrCycles = 8;
            _PC++;
            break; }    /* LD (HL),B */

case 0x71:{ Wbyte(W(_HL), _BC[C]);          
            instrCycles = 8;
            _PC++;
            break; }    /* LD (HL),C */

case 0x72:{ Wbyte(W(_HL), _DE[D]);
            instrCycles = 8;
            _PC++;
            break; }    /* LD (HL),D */

case 0x73:{ Wbyte(W(_HL), _DE[E]);
            instrCycles = 8;
            _PC++;
            break; }    /* LD (HL),E */

case 0x74:{ Wbyte(W(_HL), _HL[H]);  
            instrCycles = 8;
            _PC++;
            break; }    /* LD (HL),H */

case 0x75:{ Wbyte(W(_HL), _HL[L]);
            instrCycles = 8;
            _PC++;
            break; }    /* LD (HL),L*/

case 0x76:{ isHalt = TRUE;
            instrCycles = 4;
            _PC++;
            //fprintf(stderr, "HALT \n");
            //DebugDisp(); _getch();        // DEBUG.
            //debugIsDebug = TRUE; debugIsStep = TRUE;              // DEBUG.
            break; }    /* HALT */

case 0x77:{ Wbyte(W(_HL), _A);
            instrCycles = 8;
            _PC++;
            break; }    /* LD (HL),A */

case 0x78:{ _A = _BC[B];
            instrCycles = 4;
            _PC++;
            break; }    /* LD A,B */

case 0x79:{ _A = _BC[C];
            instrCycles = 4;
            _PC++;
            break; }    /* LD A,C */

case 0x7A:{ _A = _DE[D];
            instrCycles = 4;
            _PC++;
            break; }    /* LD A,D */

case 0x7B:{ _A = _DE[E];
            instrCycles = 4;
            _PC++;
            break; }    /* LD A,E */

case 0x7C:{ _A = _HL[H];
            instrCycles = 4;
            _PC++;
            break; }    /* LD A,H */

case 0x7D:{ _A = _HL[L];
            instrCycles = 4;
            _PC++;
            break; }    /* LD A,L */

case 0x7E:{ _A = Rbyte(W(_HL), NULL);
            instrCycles = 8;
            _PC++;
            break; }    /* LD A,(HL) */

case 0x7F:{ _A = _A;
            instrCycles = 4;
            _PC++;
            break; }    /* LD A,A */

case 0x80:{ v8Before = _A & MSK_0_3;
            v8Before += (_BC[B] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _BC[B];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if(_A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADD A,B */

case 0x81:{ v8Before = _A & MSK_0_3;
            v8Before += (_BC[C] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _BC[C];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADD A,C */

case 0x82:{ v8Before = _A & MSK_0_3;
            v8Before += (_DE[D] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _DE[D];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADD A,D */

case 0x83:{ v8Before = _A & MSK_0_3;
            v8Before += (_DE[E] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _DE[E];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADD A,E */

case 0x84:{ v8Before = _A & MSK_0_3;
            v8Before += (_HL[H] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _HL[H];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADD A,H */

case 0x85:{ v8Before = _A & MSK_0_3;
            v8Before += (_HL[L] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _HL[L];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADD A,L */

case 0x86:{ _WZ[Z] = Rbyte(W(_HL), NULL);
            v8Before = _A & MSK_0_3;
            v8Before += (_WZ[Z] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _WZ[Z];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADD A,(HL) */

case 0x87:{ v8Before = _A & MSK_0_3;
            v8Before += (_A & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _A;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADD A,A */

case 0x88:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = _A & MSK_0_3;
            v8Before += ( _BC[B] & MSK_0_3 ) + v8After;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _BC[B] + v8After;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADC A,B */

case 0x89:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = _A & MSK_0_3;
            v8Before += ( _BC[C] & MSK_0_3 ) + v8After;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _BC[C] + v8After;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADC A,C */

case 0x8A:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = _A & MSK_0_3;
            v8Before += ( _DE[D] & MSK_0_3 ) + v8After;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _DE[D] + v8After;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADC A,D */

case 0x8B:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = _A & MSK_0_3;
            v8Before += ( _DE[E] & MSK_0_3 ) + v8After;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _DE[E] + v8After;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADC A,E */

case 0x8C:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = _A & MSK_0_3;
            v8Before += ( _HL[H] & MSK_0_3 ) + v8After;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _HL[H] + v8After;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADC A,H */

case 0x8D:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = _A & MSK_0_3;
            v8Before += ( _HL[L] & MSK_0_3 ) + v8After;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _HL[L] + v8After;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADC A,L */

case 0x8E:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            _WZ[Z] = Rbyte(W(_HL), NULL);
            v8Before = _A & MSK_0_3;
            v8Before += ( _WZ[Z] & MSK_0_3 ) + v8After;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _WZ[Z] + v8After;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADC A,(HL) */

case 0x8F:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = _A & MSK_0_3;
            v8Before += ( _A & MSK_0_3 ) + v8After;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += _A + v8After;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 4;
            _PC++;
            break; }    /* ADC A,A */

case 0x90:{ v8Before = _A & MSK_0_3;
            v8Before -= (_BC[B] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _BC[B];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SUB B */

case 0x91:{ v8Before = _A & MSK_0_3;
            v8Before -= (_BC[C] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _BC[C];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SUB C */

case 0x92:{ v8Before = _A & MSK_0_3;
            v8Before -= (_DE[D] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _DE[D];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SUB D */

case 0x93:{ v8Before = _A & MSK_0_3;
            v8Before -= (_DE[E] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _DE[E];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SUB E */

case 0x94:{ v8Before = _A & MSK_0_3;
            v8Before -= (_HL[H] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _HL[H];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SUB H */

case 0x95:{ v8Before = _A & MSK_0_3;
            v8Before -= (_HL[L] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _HL[L];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SUB L */

case 0x96:{ _WZ[Z] = Rbyte(W(_HL), NULL);
            v8Before = _A & MSK_0_3;
            v8Before -= (_WZ[Z] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _WZ[Z];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SUB (HL) */

case 0x97:{ v8Before = _A & MSK_0_3;
            v8Before -= (_A & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _A;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SUB A */

case 0x98:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = ( _A & MSK_0_3 ) - v8After;
            v8Before -= _BC[B] & MSK_0_3 ;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A - v8After;
            v16Before -= _BC[B];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SBC A,B */

case 0x99:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = ( _A & MSK_0_3 ) - v8After;
            v8Before -= _BC[C] & MSK_0_3 ;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A - v8After;
            v16Before -= _BC[C];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SBC A,C */

case 0x9A:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = ( _A & MSK_0_3 ) - v8After;
            v8Before -= _DE[D] & MSK_0_3 ;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A - v8After;
            v16Before -= _DE[D];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SBC A,D */

case 0x9B:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = ( _A & MSK_0_3 ) - v8After;
            v8Before -= _DE[E] & MSK_0_3 ;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A - v8After;
            v16Before -= _DE[E];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SBC A,E */

case 0x9C:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = ( _A & MSK_0_3 ) - v8After;
            v8Before -= _HL[H] & MSK_0_3 ;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A - v8After;
            v16Before -= _HL[H];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SBC A,H */

case 0x9D:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = ( _A & MSK_0_3 ) - v8After;
            v8Before -= _HL[L] & MSK_0_3 ;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A - v8After;
            v16Before -= _HL[L];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SBC A,L */

case 0x9E:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            _WZ[Z] = Rbyte(W(_HL), NULL);
            v8Before = ( _A & MSK_0_3 ) - v8After;
            v8Before -= _WZ[Z] & MSK_0_3 ;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A - v8After;
            v16Before -= _WZ[Z];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SBC A,(HL) */

case 0x9F:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = ( _A & MSK_0_3 ) - v8After;
            v8Before -= _A & MSK_0_3 ;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A - v8After;
            v16Before -= _A;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* SBC A,A */

case 0xA0:{ _A &= _BC[B];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            SetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* AND B */

case 0xA1:{ _A &= _BC[C];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            SetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* AND C */

case 0xA2:{ _A &= _DE[D];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            SetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* AND D */

case 0xA3:{ _A &= _DE[E];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            SetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* AND E */

case 0xA4:{ _A &= _HL[H];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            SetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* AND H */

case 0xA5:{ _A &= _HL[L];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            SetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* AND L */

case 0xA6:{ _A &= Rbyte(W(_HL), NULL);
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            SetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* AND (HL) */

case 0xA7:{ _A &= _A;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            SetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* AND A */

case 0xA8:{ _A ^= _BC[B];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* XOR B */

case 0xA9: { _A ^= _BC[C];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* XOR C */

case 0xAA:{ _A ^= _DE[D];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* XOR D */

case 0xAB:{ _A ^= _DE[E];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* XOR E */

case 0xAC:{ _A ^= _HL[H];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* XOR H */

case 0xAD:{ _A ^= _HL[L];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* XOR L */

case 0xAE:{ _A ^= Rbyte(W(_HL), NULL);
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* XOR (HL) */

case 0xAF:{ _A ^= _A;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;
            break; }    /* XOR A */

case 0xB0:{ _A |= _BC[B];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;                       
            break; }    /* OR B */

case 0xB1:{ _A |= _BC[C];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;                       
            break; }    /* OR C */

case 0xB2:{ _A |= _DE[D];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;                       
            break; }    /* OR D */

case 0xB3:{ _A |= _DE[E];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;                       
            break; }    /* OR E */

case 0xB4:{ _A |= _HL[H];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;                       
            break; }    /* OR H */

case 0xB5:{ _A |= _HL[L];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;                       
            break; }    /* OR L */

case 0xB6:{ _A |= Rbyte(W(_HL), NULL);
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;                       
            break; }    /* OR (HL) */

case 0xB7:{ _A |= _A;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 4;
            _PC++;                       
            break; }    /* OR A */

case 0xB8:{ v8Before = _A & MSK_0_3;
            v8Before -= (_BC[B] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _BC[B];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            if( v16Before & MSK_0_7 )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* CP B */

case 0xB9:{ v8Before = _A & MSK_0_3;
            v8Before -= (_BC[C] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _BC[C];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            if( v16Before & MSK_0_7 )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* CP C */

case 0xBA:{ v8Before = _A & MSK_0_3;
            v8Before -= (_DE[D] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _DE[D];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            if( v16Before & MSK_0_7 )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* CP D */

case 0xBB:{ v8Before = _A & MSK_0_3;
            v8Before -= (_DE[E] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _DE[E];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            if( v16Before & MSK_0_7 )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* CP E */

case 0xBC:{ v8Before = _A & MSK_0_3;
            v8Before -= (_HL[H] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _HL[H];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            if( v16Before & MSK_0_7 )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* CP H */

case 0xBD:{ v8Before = _A & MSK_0_3;
            v8Before -= (_HL[L] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _HL[L];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            if( v16Before & MSK_0_7 )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* CP L */

case 0xBE:{ _WZ[Z] = Rbyte(W(_HL), NULL);
            v8Before = _A & MSK_0_3;
            v8Before -= (_WZ[Z] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _WZ[Z];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            if( v16Before & MSK_0_7 )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* CP (HL) */

case 0xBF:{ v8Before = _A & MSK_0_3;
            v8Before -= (_A & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= _A;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            if( v16Before & MSK_0_7 )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 4;
            _PC++;
            break; }    /* CP A */

case 0xC0:{ if( _F & MSK_7 ) {
                instrCycles = 8;
                _PC++;
            } else {
                _PC = *( (word_t*)&(_gbMem[_SP]) );     // 不经内存界面，直接从 GB 工作内存中读取，出错了再改成用内存界面！
                _SP += 2;
                instrCycles = 20;
                //fprintf(stderr, "RET NZ _gbMem[_SP] = %04X\n", *( (word_t*)&(_gbMem[_SP]) ) );    DebugDisp();_getch();// DEBUG.
            }
            break; }    /* RET NZ */

case 0xC1:{ W(_BC) = *( (word_t*)&(_gbMem[_SP]) );
            _SP += 2;
            instrCycles = 12;
            _PC++;
            break; }    /* POP BC */

case 0xC2:{ if( _F & MSK_7 ) {
                _PC += 3;
                instrCycles = 12;
            } else {
                _PC = *( (word_t*)&(instrPtr[1]) );
                instrCycles = 16;
                //fprintf(stderr, "JP NZ %04X\n", _PC); // DEBUG.
            }
            break; }    /* JP NZ,a16 */

case 0xC3:{ _PC = *( (word_t*)&(instrPtr[1]) );
            instrCycles = 16;
            //fprintf(stderr, "JP %04X\n", _PC);    // DEBUG.
            break; }    /* JP a16 */

case 0xC4:{ _PC += 3;
            if( _F & MSK_7 ) {
                instrCycles = 12;
            } else {
                _SP -= 2;
                pW = (word_t*)&( _gbMem[_SP] );
                *pW = _PC;
                _PC = *( (word_t*)&(instrPtr[1]) );
                instrCycles = 24;
                //fprintf(stderr, "CALL NZ %04X \n", _PC);  DebugDisp(); _getch();// DEBUG.
            }
            break; }    /* CALL NZ,a16 */

case 0xC5:{ _gbMem[_SP - 1] = _BC[B];
            _gbMem[_SP - 2] = _BC[C];
            _SP -= 2;
            instrCycles = 16;
            _PC++;
            break; }    /* PUSH BC */

case 0xC6:{ v8Before = _A & MSK_0_3;
            v8Before += (instrPtr[1] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += instrPtr[1];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 8;
            _PC += 2;
            break; }    /* ADD A,d8 */

case 0xC7:{ _PC++;
            _SP -= 2;
            pW = (word_t*)&(_gbMem[_SP]);
            *pW = _PC;
            _PC = 0x0000;
            instrCycles = 16;
            //isStop = TRUE;    // DEBUG.
            break; }    /* RST 00H */

case 0xC8:{ if( _F & MSK_7 ) {
                _PC = *( (word_t*)&(_gbMem[_SP]) );
                _SP += 2;
                instrCycles = 20;
                //fprintf(stderr, "RET Z _gbMem[_SP] = %04X\n", *( (word_t*)&(_gbMem[_SP]) ) ); DebugDisp();_getch();// DEBUG.
            } else {
                instrCycles = 8;
                _PC++;
            }
            break; }    /* RET Z */

case 0xC9:{ _PC = *( (word_t*)&(_gbMem[_SP]) );
            _SP += 2;
            instrCycles = 16;
            //fprintf(stderr, "RET _gbMem[_SP] = %04X\n", *( (word_t*)&(_gbMem[_SP]) ) );   DebugDisp(); _getch();// DEBUG.
            break; }    /* RET */

case 0xCA:{ if( _F & MSK_7 ) {
                _PC = *( (word_t*)&(instrPtr[1]) );
                instrCycles = 16;
                //fprintf(stderr, "JP Z %04X\n", _PC);  // DEBUG.
            } else {
                _PC += 3;
                instrCycles = 12;
            }
            break; }    /* JP Z,a16 */

case 0xCB:{ //printf("PREFIX CB \n\n");  //debug.

            switch( instrPtr[1] ) {
                
                #include "CPU_Instr_CB_INSERT.h"

                default : { isStop = TRUE; printf("Unknown CB instr. \n"); break;}
            }
            break; }    /* PREFIX CB */

case 0xCC:{ _PC += 3;
            if( _F & MSK_7 ) {
                _SP -= 2;
                pW = (word_t*)&( _gbMem[_SP] );
                *pW = _PC;
                _PC = *( (word_t*)&(instrPtr[1]) );
                instrCycles = 24;
                //fprintf(stderr, "CALL Z %04X \n", _PC);    DebugDisp(); _getch();// DEBUG.
            } else {
                instrCycles = 12;
            }
            break; }    /* CALL Z,a16 */

case 0xCD:{ _PC += 3;
            _SP -= 2;
            pW = (word_t*)&( _gbMem[_SP] );
            *pW = _PC;
            _PC = *( (word_t*)&(instrPtr[1]) );
            instrCycles = 24;
            //fprintf(stderr, "CALL %04X \n", _PC);  DebugDisp(); _getch();// DEBUG.
            /*if( _PC == 0x27C3) {
                fprintf(stderr, "CALL a16 (%04X)\n", _PC);
                _getch();
            }   // DEBUG.*/
            break; }    /* CALL a16 */

case 0xCE:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = _A & MSK_0_3;
            v8Before += ( instrPtr[1] & MSK_0_3 ) + v8After;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before += instrPtr[1] + v8After;
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            instrCycles = 8;
            _PC += 2;
            break; }    /* ADC A,d8 */

case 0xCF:{ _PC++;
            _SP -= 2;
            pW = (word_t*)&(_gbMem[_SP]);
            *pW = _PC;
            _PC = 0x0008;
            instrCycles = 16;
            //isStop = TRUE;    // DEBUG.
            break; }    /* RST 08H */

case 0xD0:{ if( _F & MSK_4 ) {
                instrCycles = 8;
                _PC++;
            } else {
                _PC = *( (word_t*)&(_gbMem[_SP]) );
                _SP += 2;
                instrCycles = 20;
                //fprintf(stderr, "RET NC _gbMem[_SP] = %04X\n", *( (word_t*)&(_gbMem[_SP]) ) );    DebugDisp();_getch();// DEBUG.
            }
            break; }    /* RET NC */

case 0xD1:{ W(_DE) = *( (word_t*)&(_gbMem[_SP]) );
            _SP += 2;
            instrCycles = 12;
            _PC++;
            break; }    /* POP DE */

case 0xD2:{ if( _F & MSK_4 ) {
                _PC += 3;
                instrCycles = 12;
            } else {
                _PC = *( (word_t*)&(instrPtr[1]) );
                instrCycles = 16;
                //fprintf(stderr, "JP NC %04X\n", _PC); // DEBUG.
            }
            break; }    /* JP NC,a16 */

case 0xD3:{ isStop = TRUE;
            break; }    /* EMPTY */

case 0xD4:{ _PC += 3;
            if( _F & MSK_4 ) {
                instrCycles = 12;
            } else {
                _SP -= 2;
                pW = (word_t*)&( _gbMem[_SP] );
                *pW = _PC;
                _PC = *( (word_t*)&(instrPtr[1]) );
                instrCycles = 24;
                //fprintf(stderr, "CALL NC %04X \n", _PC); DebugDisp(); _getch();// DEBUG.
            }
            break; }    /* CALL NC,a16 */

case 0xD5:{ _gbMem[_SP - 1] = _DE[D];
            _gbMem[_SP - 2] = _DE[E];
            _SP -= 2;
            instrCycles = 16;
            _PC++;
            break; }    /* PUSH DE */

case 0xD6:{ v8Before = _A & MSK_0_3;
            v8Before -= (instrPtr[1] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= instrPtr[1];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 8;
            _PC += 2;
            break; }    /* SUB d8 */

case 0xD7:{ _PC++;
            _SP -= 2;
            pW = (word_t*)&(_gbMem[_SP]);
            *pW = _PC;
            _PC = 0x0010;
            instrCycles = 16;
            //isStop = TRUE;    // DEBUG.
            break; }    /* RST 10H */

case 0xD8:{ if( _F & MSK_4 ) {
                _PC = *( (word_t*)&(_gbMem[_SP]) );
                _SP += 2;
                instrCycles = 20;
                //fprintf(stderr, "RET C _gbMem[_SP] = %04X\n", *( (word_t*)&(_gbMem[_SP]) ) ); DebugDisp();_getch();// DEBUG.
            } else {
                instrCycles = 8;
                _PC++;
            }
            break; }    /* RET C */

case 0xD9:{ _IME = TRUE;
            _PC = *( (word_t*)&(_gbMem[_SP]) );
            _SP += 2;
            instrCycles = 16;
            //fprintf(stderr, "RETI _gbMem[_SP] = %04X\n", *( (word_t*)&(_gbMem[_SP]) ) );  DebugDisp();_getch();// DEBUG.
            break; }    /* RETI */

case 0xDA:{ if( _F & MSK_4 ) {
                _PC = *( (word_t*)&(instrPtr[1]) );
                instrCycles = 16;
                //fprintf(stderr, "JP C %04X\n", _PC);  // DEBUG.
            } else {
                _PC += 3;
                instrCycles = 12;
            }
            break; }    /* JP C,a16 */

case 0xDB:{ isStop = TRUE;
            break; }    /* EMPTY */

case 0xDC:{ _PC += 3;
            if( _F & MSK_4 ) {
                _SP -= 2;
                pW = (word_t*)&( _gbMem[_SP] );
                *pW = _PC;
                _PC = *( (word_t*)&(instrPtr[1]) );
                instrCycles = 24;
                //fprintf(stderr, "CALL C %04X \n", _PC);    DebugDisp(); _getch();// DEBUG.
            } else {
                instrCycles = 12;
            }
            break; }    /* CALL C,a16 */

case 0xDD:{ isStop = TRUE;
            break; }    /* EMPTY */

case 0xDE:{ if( _F & MSK_4 )
                v8After  = 0x01;
            else v8After  = 0x00;
            v8Before = ( _A & MSK_0_3 ) - v8After;
            v8Before -= instrPtr[1] & MSK_0_3 ;
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A - v8After;
            v16Before -= instrPtr[1];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            _A = v16Before;
            if( _A )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 8;
            _PC += 2;
            break; }    /* SBC A,d8 */

case 0xDF:{ _PC++;
            _SP -= 2;
            pW = (word_t*)&(_gbMem[_SP]);
            *pW = _PC;
            _PC = 0x0018;
            instrCycles = 16;
            //isStop = TRUE;    // DEBUG.
            break; }    /* RST 18H */

case 0xE0:{ _WZ[Z] = instrPtr[1];
            _WZ[W] = 0xFF;
            Wbyte(W(_WZ), _A);
            instrCycles = 12;
            _PC += 2;
            break; }    /* LDH (a8),A */

case 0xE1:{ W(_HL) = *( (word_t*)&(_gbMem[_SP]) );
            _SP += 2;
            instrCycles = 12;
            _PC++;
            break; }    /* POP HL */

case 0xE2:{ _WZ[Z] = _BC[C];
            _WZ[W] = 0xFF;
            Wbyte(W(_WZ), _A);
            instrCycles = 8;
            _PC++;
            break; }    /* LD (C),A */

case 0xE3:{ isStop = TRUE;
            break; }    /* EMPTY */

case 0xE4:{ isStop = TRUE;
            break; }    /* EMPTY */

case 0xE5:{ _gbMem[_SP - 1] = _HL[H];
            _gbMem[_SP - 2] = _HL[L];
            _SP -= 2;
            instrCycles = 16;
            _PC++;
            break; }    /* PUSH HL */

case 0xE6:{ _A &= instrPtr[1];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            SetH();
            ResetC();
            instrCycles = 8;
            _PC += 2;
            break; }    /* AND d8 */

case 0xE7:{ _PC++;
            _SP -= 2;
            pW = (word_t*)&(_gbMem[_SP]);
            *pW = _PC;
            _PC = 0x0020;
            instrCycles = 16;
            //isStop = TRUE;    // DEBUG.
            break; }    /* RST 20H */


case 0xE8:{ v16Before = _SP & MSK_0_11;
            v16Before += ( (sword_t)( (sbyte_t)(instrPtr[1]) ) & MSK_0_11 );    // 先转成 sbyte_t ，再转成 sword_t ，目的是把有符号操作数的符号位正确地扩展到第 15 位。若直接转成 sword_t ，就不能正确地扩展负数的符号位，原因显然。下同。          
            if( v16Before & MSK_12 )
                SetH();
            else ResetH();
            v32Carry = _SP;
            v32Carry += ( (sdword_t)( (sword_t)( (sbyte_t)(instrPtr[1]) ) ) ) & MSK_0_15;
            if( v32Carry & MSK_16)
                SetC();
            else ResetC();
            _SP += (sbyte_t)(instrPtr[1]);
            ResetZ();
            ResetN();
            instrCycles = 16;
            _PC += 2;
            break; }    /* ADD SP,r8 */

case 0xE9:{ _PC = W(_HL);
            instrCycles = 4;
            //fprintf(stderr, "JP %04X\n", W(_HL)); // DEBUG.
            break; }    /* JP (HL) */

case 0xEA:{ _WZ[Z] = instrPtr[1];
            _WZ[W] = instrPtr[2];
            Wbyte(W(_WZ), _A);
            instrCycles = 16;
            _PC += 3;
            break; }    /* LD (a16),A */

case 0xEB:{ isStop = TRUE;
            break; }    /* EMPTY */

case 0xEC:{ isStop = TRUE;
            break; }    /* EMPTY */

case 0xED:{ isStop = TRUE;
            break; }    /* EMPTY */

case 0xEE:{ _A ^= instrPtr[1];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 8;
            _PC += 2;
            break; }    /* XOR d8 */

case 0xEF:{ _PC++;
            _SP -= 2;
            pW = (word_t*)&(_gbMem[_SP]);
            *pW = _PC;
            _PC = 0x0028;
            instrCycles = 16;
            //isStop = TRUE;    // DEBUG.
            break; }    /* RST 28H */

case 0xF0:{ _WZ[Z] = instrPtr[1];
            _WZ[W] = 0xFF;
            _A = Rbyte(W(_WZ), NULL);
            instrCycles = 12;
            _PC += 2;
            break; }    /* LDH A,(a8) */

case 0xF1:{ _F = _gbMem[_SP];
            _A = _gbMem[_SP + 1];
            _SP += 2;
            instrCycles = 12;
            _PC++;
            break; }    /* POP AF */

case 0xF2:{ _WZ[Z] = _BC[C];
            _WZ[W] = 0xFF;
            _A = Rbyte(W(_WZ), NULL);
            instrCycles = 8;
            _PC++;
            break; }    /* LD A,(C) */

case 0xF3:{ _IME = FALSE;
            instrCycles = 4;
            _PC++;
            break; }    /* DI */

case 0xF4:{ isStop = TRUE;
            break; }    /* EMPTY */

case 0xF5:{ _gbMem[_SP - 1] = _A;
            _gbMem[_SP - 2] = _F;
            _SP -= 2;
            instrCycles = 16;
            _PC++;
            break; }    /* PUSH AF */

case 0xF6:{ _A |= instrPtr[1];
            if( _A )
                ResetZ();
            else SetZ();
            ResetN();
            ResetH();
            ResetC();
            instrCycles = 8;
            _PC += 2;                        
            break; }    /* OR d8 */

case 0xF7:{ _PC++;
            _SP -= 2;
            pW = (word_t*)&(_gbMem[_SP]);
            *pW = _PC;
            _PC = 0x0030;
            instrCycles = 16;
            //isStop = TRUE;    // DEBUG.
            break; }    /* RST 30H */

case 0xF8:{ v16Before = _SP & MSK_0_11;
            v16Before += ( (sword_t)( (sbyte_t)(instrPtr[1]) ) & MSK_0_11 );
            if( v16Before & MSK_12 )
                SetH();
            else ResetH();
            v32Carry = _SP;
            v32Carry += ( (sdword_t)( (sword_t)( (sbyte_t)(instrPtr[1]) ) ) ) & MSK_0_15;
            if( v32Carry & MSK_16)
                SetC();
            else ResetC();
            W(_HL) = (word_t)( _SP + (sbyte_t)(instrPtr[1]) );
            ResetZ();
            ResetN();
            instrCycles = 12;
            _PC += 2;
            break; }    /* LD HL,SP+r8 */

case 0xF9:{ _SP = W(_HL);
            instrCycles = 8;
            _PC++;
            break; }    /* LD SP,HL */

case 0xFA:{ _WZ[Z] = instrPtr[1];
            _WZ[W] = instrPtr[2];
            _A = Rbyte(W(_WZ), NULL);
            instrCycles = 16;
            _PC += 3;
            break; }    /* LD A,(a16) */

case 0xFB:{ _IME = TRUE;
            instrCycles = 4;
            _PC++;
            break; }    /* EI */

case 0xFC:{ isStop = TRUE;
            break; }    /* EMPTY */

case 0xFD:{ isStop = TRUE;
            break; }    /* EMPTY */

case 0xFE:{ v8Before = _A & MSK_0_3;
            v8Before -= (instrPtr[1] & MSK_0_3);
            if( v8Before & MSK_4 )
                SetH();
            else ResetH();
            v16Before = _A;
            v16Before -= instrPtr[1];
            if( v16Before & MSK_8 )
                SetC();
            else ResetC();
            //fprintf(stderr, "instrPtr[1] =%u \n", instrPtr[1]);   // DEBUG.
            //fprintf(stderr, "v16Before 0_7=%u \n", v16Before & MSK_0_7);  // DEBUG.
            if( v16Before & MSK_0_7 )
                ResetZ();
            else SetZ();
            SetN();
            instrCycles = 8;
            _PC += 2;
            break; }    /* CP d8 */

case 0xFF:{ _PC++;
            _SP -= 2;
            pW = (word_t*)&(_gbMem[_SP]);
            *pW = _PC;
            _PC = 0x0038;
            instrCycles = 16;
            //isStop = TRUE;    // DEBUG.
            break; }    /* RST 38H */

