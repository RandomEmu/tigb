/* === 产生 Joypad 中断 === */
while( SDL_PollEvent(&ev) ) {
    switch( ev.type ) {
        case SDL_QUIT:  isUserQuit = TRUE;
                        break;
        
        case SDL_KEYDOWN:   switch( ev.key.keysym.sym ) {
                                case SDLK_e:    debugIsDebug = TRUE;
                                                debugIsStep = TRUE;
                                                break;

                                case SDLK_w:    colDirection_2_Up = TRUE;
                                                SetJoypadInt();
                                                isHalt = FALSE;
                                                //fprintf(stderr, "SDLK_w pressed \n" );
                                                //fprintf(stderr, " (0xFF80) : 0x%02X\n", _gbMem[0xFF80]);      // GB俄罗斯方块保存按键状态的字节。
                                                break;
                                case SDLK_s:    colDirection_3_Down = TRUE;
                                                SetJoypadInt();
                                                isHalt = FALSE;
                                                //fprintf(stderr, "SDLK_s pressed \n" );
                                                //fprintf(stderr, " (0xFF80) : 0x%02X\n", _gbMem[0xFF80]);
                                                break;
                                case SDLK_a:    colDirection_1_Left = TRUE;
                                                SetJoypadInt();
                                                isHalt = FALSE;
                                                //fprintf(stderr, "SDLK_a pressed \n" );
                                                //fprintf(stderr, " (0xFF80) : 0x%02X\n", _gbMem[0xFF80]);
                                                break;
                                case SDLK_d:    colDirection_0_Right = TRUE;
                                                SetJoypadInt();
                                                isHalt = FALSE;
                                                //fprintf(stderr, "SDLK_d pressed \n" );
                                                //fprintf(stderr, " (0xFF80) : 0x%02X\n", _gbMem[0xFF80]);
                                                break;
                                case SDLK_k:    colButton_0_A = TRUE;
                                                SetJoypadInt();
                                                isHalt = FALSE;
                                                //fprintf(stderr, "SDLK_k pressed \n" );
                                                //fprintf(stderr, " (0xFF80) : 0x%02X\n", _gbMem[0xFF80]);
                                                break;
                                case SDLK_j:    colButton_1_B = TRUE;
                                                SetJoypadInt();
                                                isHalt = FALSE;
                                                //fprintf(stderr, "SDLK_j pressed \n" );
                                                //fprintf(stderr, " (0xFF80) : 0x%02X\n", _gbMem[0xFF80]);
                                                break;
                                case SDLK_n:    colButton_2_Select = TRUE;
                                                SetJoypadInt();
                                                isHalt = FALSE;
                                                //fprintf(stderr, "SDLK_n pressed \n" );
                                                //fprintf(stderr, " (0xFF80) : 0x%02X\n", _gbMem[0xFF80]);
                                                break;
                                case SDLK_m:    colButton_3_Start = TRUE;
                                                SetJoypadInt();
                                                isHalt = FALSE;
                                                //fprintf(stderr, "SDLK_m pressed \n" );
                                                //fprintf(stderr, " (0xFF80) : 0x%02X\n", _gbMem[0xFF80]);
                                                break;
                                case SDLK_ESCAPE:   isUserQuit = TRUE; break;
                                default:        break;
                            }
                            break;
        case SDL_KEYUP:     switch( ev.key.keysym.sym ) {
                                case SDLK_w:    colDirection_2_Up = FALSE;
                                                //fprintf(stderr, "SDLK_w released \n" );
                                                //fprintf(stderr, " (0xFF80) : 0x%02X\n", _gbMem[0xFF80]);      // GB俄罗斯方块保存按键状态的字节。
                                                break;
                                case SDLK_s:    colDirection_3_Down = FALSE;
                                                //fprintf(stderr, "SDLK_s released \n" );
                                                break;
                                case SDLK_a:    colDirection_1_Left = FALSE;
                                                //fprintf(stderr, "SDLK_a released \n" );
                                                break;
                                case SDLK_d:    colDirection_0_Right = FALSE;
                                                //fprintf(stderr, "SDLK_d released \n" );
                                                break;
                                case SDLK_k:    colButton_0_A = FALSE;
                                                //fprintf(stderr, "SDLK_k released \n" );
                                                break;
                                case SDLK_j:    colButton_1_B = FALSE;
                                                //fprintf(stderr, "SDLK_j released \n" );
                                                break;
                                case SDLK_n:    colButton_2_Select = FALSE;
                                                //fprintf(stderr, "SDLK_n released \n" );
                                                break;
                                case SDLK_m:    colButton_3_Start = FALSE;
                                                //fprintf(stderr, "SDLK_m pressed \n" );
                                                break;
                                default:        break;
                            }
                            break;
        
        default : break;
    }
}