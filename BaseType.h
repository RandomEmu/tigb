#ifndef BASETYPE_H
    #define BASETYPE_H

    #define public                  // 空宏，三个作用，
                                    // 一是和 OOP 的 public 同义，
                                    // 二是和 static, extern 相同长度，用来对齐函数声明,
                                    // 三是把函数声明添加到 .h 时，可以用来替换成 extern .

    #define W(x)        (*pW##x)
    #define Rbyte(x, y) ( ((memFuncArr[ (addrFlag[(x)]) ]).r)((x), (y)) )       // 注意， x “绝对不能”是需要复杂求值的东西，否则会造成效率下降。
    #define Wbyte(x, y) ( ((memFuncArr[ (addrFlag[(x)]) ]).w)((x), (y)) )
    #define SetZ()      _F |= 0x80                                              // Set Z flag.
    #define SetN()      _F |= 0x40                                              // Set N flag.
    #define SetH()      _F |= 0x20                                              // Set H flag.
    #define SetC()      _F |= 0x10                                              // Set C flag.
    #define ResetZ()    _F &= 0x70                                              // Reset Z flag.
    #define ResetN()    _F &= 0xB0                                              // Reset N flag.
    #define ResetH()    _F &= 0xD0                                              // Reset H flag.
    #define ResetC()    _F &= 0xE0                                              // Reset C flag.

    #define SIZE_2MB    0x200000    // 2MB
    #define SIZE_2KB    2048        // 2KB
    #define SIZE_8KB    8192        // 8KB
    #define SIZE_32KB   32768       // 32KB

    #define MAX_RW_FUNC_PAIR    50  // memFuncArr[] 的长度，可以改长一些以容纳更多 R/W 函数对。

    #define MSK_0       0x01
    #define MSK_1       0x02
    #define MSK_2       0x04
    #define MSK_3       0x08
    #define MSK_4       0x10
    #define MSK_5       0x20
    #define MSK_6       0x40
    #define MSK_7       0x80
    #define MSK_8       0x0100
    #define MSK_12      0x1000
    #define MSK_16      0x00010000
    #define MSK_0_7     0x00FF
    #define MSK_1_7     0xFE
    #define MSK_2_7     0xFC
    #define MSK_4_5     0x30
    #define MSK_4_6     0x70
    #define MSK_4_7     0xF0
    #define MSK_0_1     0x03
    #define MSK_0_3     0x0F
    #define MSK_0_11    0x0FFF
    #define MSK_0_15    0x0000FFFF

    #define LY_MAX              456         // LY 自增 1 所需要消耗的 CPU 周期数。（数据来源：http://imrannazar.com/GameBoy-Emulation-in-JavaScript:-GPU-Timings）
    #define VBK_MAX             70224       // 产生一次 V-Blank 所需要消耗的 CPU 周期数。（数据来源同上）
    
    #define STAT_MODE_0_MAX     204         // （数据来源同上）
    #define STAT_MODE_2_MAX     80          // （数据来源同上）
    #define STAT_MODE_3_MAX     172         // （数据来源同上）

    
    #define DIV_MAX             256         // 4194304 / 16384= 256
    #define TIMA_4096_MAX       1024        // 4194304 / 4096=  1024
    #define TIMA_262144_MAX     16          // 4194304 / 262144 = 16
    #define TIMA_65536_MAX      64          // 4194304 / 65536  = 64
    #define TIMA_16384_MAX      256         // 4194304 / 16384  = 256
    

    #define SetVBlankInt()      _gbMem[0xFF0F] |= MSK_0                         // Set V-Blank interrupt flag.
    #define ResetVBlankInt()    _gbMem[0xFF0F] &= MSK_1_7                       // Reset V-Blank interrupt flag.

    #define SetTimerInt()       _gbMem[0xFF0F] |= MSK_2                         // Set Timer interrupt flag.
    #define ResetTimerInt()     _gbMem[0xFF0F] &= 0xFB                          // Reset Timer interrupt flag.

    #define SetJoypadInt()      _gbMem[0xFF0F] |= MSK_4                         // Set Joypad interrupt flag.
    #define ResetJoypadInt()    _gbMem[0xFF0F] &= 0xEF                          // Reset Joypad interrupt flag.

    #ifndef NULL
        #define NULL        0
    #endif

    #ifndef BOOLEAN
        #define BOOLEAN
        typedef unsigned int boolean;
    #endif  
    
    #ifndef FALSE
        #define FALSE       0
    #endif

    #ifndef TRUE
        #define TRUE        1
    #endif

    #define ERROR   0
    #define SUCCESS 1

    typedef unsigned char   byte_t;
    typedef unsigned short  word_t;
    typedef unsigned int    dword_t;
    typedef   signed char   sbyte_t;    
    typedef   signed short  sword_t;    
    typedef   signed int    sdword_t;

    typedef struct              // Memory Interface Function Pointer.
    {
        byte_t (*r)(dword_t, byte_t **);
        void   (*w)(dword_t, byte_t);
    } MemInterFuncPtr_t;

    enum {C=0, B=1};
    enum {E=0, D=1};
    enum {L=0, H=1};
    enum {Z=0, W=1};
    enum {MBC1=0, MBC2=1, MBC3=2};
    
#endif
