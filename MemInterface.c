#include <stdio.h>
#include "BaseType.h"
#include "MemInterface.h"

static byte_t
    _r0,    // MBC1: 0x0000-0x1FFF.
    _r1,    // MBC1: 0x2000-0x3FFF.
    _r2,    // MBC1: 0x4000-0x5FFF.
    _r3;    // MBC1: 0x6000-0x7FFF.

static byte_t _tmp[2];
static word_t
    *pW_tmp = (word_t*)_tmp;

static byte_t   *vTarAddr = NULL;   // Target Address. 函数内要多次取址 arr[addr] ，即 *(arr + addr)，为避免不必要的偏移加法，故用此临时指针保存 arr + addr 的值，供下面多次调用。

static boolean isBattery = FALSE;   // 读取卡带类型时，用来记录是否需要电池记忆。

static void InitBaseMemFuncArr();
static void AssignRomOnly();
static int  AssignMBC1_ROM();
static void AssignMBC1_RAM(unsigned int);

extern byte_t   _gbMem[0xFFFF + 1];
extern byte_t   *_gbRomBuf;
extern byte_t   *_gbExtRam;
extern byte_t   addrFlag[0xFFFF + 1];   
extern MemInterFuncPtr_t memFuncArr[MAX_RW_FUNC_PAIR];

extern boolean colButton_0_A;
extern boolean colButton_1_B;
extern boolean colButton_2_Select;
extern boolean colButton_3_Start;

extern boolean colDirection_0_Right;
extern boolean colDirection_1_Left;
extern boolean colDirection_2_Up;
extern boolean colDirection_3_Down;

/* =====================================================
    从 ROM 缓存中读取。
    用处：ROM ONLY;
=======================================================*/
public byte_t R_DirectFromRomBuf(dword_t addr, byte_t **p)
{
    vTarAddr = (byte_t *)(_gbRomBuf + addr);
    
    if( p )
        *p = vTarAddr;
    
    return *vTarAddr;
}

/* =====================================================
    从不存在的地址空间中读取。
    用处：ROM ONLY;
=======================================================*/
public byte_t R_FromEmptySpace(dword_t addr, byte_t **p)
{
    // Ignore p.

    return 0xFF;
}

/* =====================================================
    从 GB 内存中读取。
    用处：略
=======================================================*/
public byte_t R_DirectFromMem(dword_t addr, byte_t **p)
{
    vTarAddr = (byte_t *)(_gbMem + addr);

    if( p )
        *p = vTarAddr;
    
    return *vTarAddr;
}

public byte_t R_FF00_JOYP(dword_t addr, byte_t **p)
{
    byte_t v = _gbMem[0xFF00] | 0XCF;   //使 v 的 bit 7,6,3,2,1,0 位置 1。 bit 5,4 取 0xFF00 内存值.

    switch( _gbMem[0xFF00] & MSK_4_5 ) {
        case 0x10:  // Button col selected.
                    if( colButton_0_A ) v &= 0xFE;          // Reset bit 0
                    if( colButton_1_B ) v &= 0xFD;          // Reset bit 1
                    if( colButton_2_Select ) v &= 0xFB;     // Reset bit 2
                    if( colButton_3_Start ) v &= 0xF7;      // Reset bit 3
                    return v;
        
        case 0x20:  // Direction col selected.
                    if( colDirection_0_Right ) v &= 0xFE;   // Reset bit 0
                    if( colDirection_1_Left ) v &= 0xFD;    // Reset bit 1
                    if( colDirection_2_Up ) v &= 0xFB;      // Reset bit 2
                    if( colDirection_3_Down ) v &= 0xF7;    // Reset bit 3
                    return v;
        default: return _gbMem[0xFF00];
    }

}

public byte_t R_MBC1_0000_3FFF(dword_t addr, byte_t **p)
{
    vTarAddr = (byte_t *)(_gbRomBuf + addr);

    if( p )
        *p = vTarAddr;
    
    return *vTarAddr;
}

public byte_t R_MBC1_4000_7FFF(dword_t addr, byte_t **p)
{
    if( _r3 )
        addr += _r1 << 14;                          // _r1 * 0x4000.
    else addr += ( (_r2 << 5) + _r1 ) << 14;        // ( (_r2 * 32) + _r1 ) * 0x4000.

    vTarAddr = (byte_t *)(_gbRomBuf + addr);

    if( p )
        *p = vTarAddr;
    
    return *vTarAddr;
}

public byte_t R_MBC1_A000_BFFF(dword_t addr, byte_t **p)
{
    if( _r3 )
        addr = (addr - 0xA000) + ( _r2 << 13 ); // (addr - 0xA000) + ( _r2 * 0x2000 );.
    else addr -= 0xA000;

    vTarAddr = (byte_t *)(_gbExtRam + addr);

    if( p )
        *p = vTarAddr;

    return *vTarAddr;
        
}

public byte_t R_ECHO_E000_FDFF(dword_t addr, byte_t **p)
{
    addr -= 0x2000;

    vTarAddr = (byte_t *)(_gbMem + addr);

    if( p )
        *p = vTarAddr;

    return *vTarAddr;
}

/* =====================================================
    写入时会重置该地址数据。
    用处：一些内存寄存器，Reset when Writtin.
=======================================================*/
public void W_Reset(dword_t addr, byte_t v)
{
    // Ignore v.
    _gbMem[addr] = 0x00;
}

public void W_DoNothing(dword_t addr, byte_t v)
{
    // Do nothing.
}

public void W_FF00_JOYP(dword_t addr, byte_t v)
{
    v &= 0x30;                                          // 只接受 bit 4,5 的改变。
    _gbMem[0xFF00] = ( _gbMem[0xFF00] & 0xCF ) + v;     // 保留除 bit 4,5 外的位，并写入 bit 4,5 的新值。
}


public void W_DirectToMem(dword_t addr, byte_t v)
{
    _gbMem[addr] = v;
}

public void W_OAM_DMA(dword_t addr, byte_t v)
{   
    // 0xFF46   OAM DMA function.
    word_t i;

    //fprintf(stderr, "W_OAM_DMA() begin! \n"); // DEBUG.
    
    if( v > 0xF1)
        v = 0xF1;

    _tmp[H] = v;
    _tmp[L] = 0x00;

    for(i = 0xFE00; i < 0xFEA0; i++) {
        _gbMem[i] = _gbMem[W(_tmp)];
        W(_tmp)++;
    }

    //fprintf(stderr, "W_OAM_DMA() done. \n");
    //_getch(); // DEBUG.
}

public void W_MBC1_0000_1FFF(dword_t addr, byte_t v)
{
    if( (v &= 0x0F) == 0x0A )
        _r0 = v;
    else _r0 = 0x00;
}

public void W_MBC1_2000_3FFF(dword_t addr, byte_t v)
{
    _r1 = v & 0x1F; // Only cares low 5 bits.
    if( !_r1)
        _r1 = 0x01;
}

public void W_MBC1_4000_5FFF(dword_t addr, byte_t v)
{
    _r2 = v & 0x03;
}

public void W_MBC1_6000_7FFF(dword_t addr, byte_t v)
{
    _r3 = v & 0x01;
}

public void W_MBC1_A000_BFFF(dword_t addr, byte_t v)
{
    if( _r3 )
        addr += _r2 << 13;  // _r2 * 0x2000;

    _gbExtRam[addr] = v;
}

public void W_ECHO_E000_FDFF(dword_t addr, byte_t v)
{
    addr -= 0x2000;

    _gbMem[addr] = v;
}

public void ResetMemInterface()
{
    _r0 = 0x00;
    _r1 = 0x01;
    _r2 = 0x00;
    _r3 = 0x00;
    vTarAddr = NULL;
}

static void InitBaseMemFuncArr()
{
    int i;

    // Construct R/W function pair of GB system reserved address.

        // Type 1
    (memFuncArr[0]).r = R_DirectFromMem;
    (memFuncArr[0]).w = W_Reset;

        // Type 2
    (memFuncArr[1]).r = R_FromEmptySpace;
    (memFuncArr[1]).w = W_OAM_DMA;

        // Type 3
    (memFuncArr[2]).r = R_DirectFromMem;
    (memFuncArr[2]).w = W_DoNothing;

        // Type 4
    (memFuncArr[3]).r = R_DirectFromMem;
    (memFuncArr[3]).w = W_DirectToMem;

        // Type 5
    (memFuncArr[4]).r = R_FF00_JOYP;
    (memFuncArr[4]).w = W_FF00_JOYP;

    
    // 先把全部 addrFlag 的项都置为 type 4 !
    for(i = 0; i < 0xFFFF + 2; i++)
        addrFlag[i] = 3;

    // Assign corresponding address flag.

        // P1/JOYP
    addrFlag[0xFF00] = 4;

        // DIV (R/W)
    addrFlag[0xFF04] = 0;

        // STAT
    addrFlag[0xFF41] = 2;

        // LY (Read ONLY)
    addrFlag[0xFF44] = 0;

        // OAM DMA (Write ONLY)
    addrFlag[0xFF46] = 1;

}

static void AssignRomOnly()
{
    unsigned int pos = MAX_RW_FUNC_PAIR - 1;
    unsigned int i;

        // Type 1
    (memFuncArr[pos]).r = R_DirectFromRomBuf;
    (memFuncArr[pos]).w = W_DoNothing;

    // Assign type 1 to 0x0000-0x7FFF.
    for(i = 0x0000; i < 0x8000; i++) {
        addrFlag[i] = pos;
    }

    pos--;  // Next position.

        // Type 2
    (memFuncArr[pos]).r = R_DirectFromMem;
    (memFuncArr[pos]).w = W_DirectToMem;

    // Assign type 2 to 0xA000-0xBFFF.
    for(i = 0xA000; i < 0xC000; i++) {
        addrFlag[i] = pos;
    }

}

/* =====================================================
    描述： 构造完一个 R/W 函数对，就马上分配这个函数对，
            然后移动到下一个可用位置，继续构造，分配......
    返回值：下一个可用的空白 addrFlag 元素，供接下来放置 R/W 函数对使用。
            当不需要继续放置函数对时，就忽略。
=======================================================*/
static int AssignMBC1_ROM()
{
    unsigned int pos = MAX_RW_FUNC_PAIR - 1;
    unsigned int i;

        // Type 3
    (memFuncArr[pos]).r = R_DirectFromRomBuf;
    (memFuncArr[pos]).w = W_MBC1_0000_1FFF;

    // Assign type 3 to 0x0000-0x1FFF.
    for(i = 0x0000; i < 0x2000; i++) {
        addrFlag[i] = pos;
    }

    pos--;

        // Type 4
    (memFuncArr[pos]).r = R_DirectFromRomBuf;
    (memFuncArr[pos]).w = W_MBC1_2000_3FFF;

    // Assign type 4 to 0x2000-0x3FFF.
    for(i = 0x2000; i < 0x4000; i++) {
        addrFlag[i] = pos;
    }

    pos--;

        // Type 5
    (memFuncArr[pos]).r = R_MBC1_4000_7FFF;
    (memFuncArr[pos]).w = W_MBC1_4000_5FFF;

    // Assign type 5 to 0x4000-0x5FFF.
    for(i = 0x4000; i < 0x6000; i++) {
        addrFlag[i] = pos;
    }

    pos--;

        // Type 6
    (memFuncArr[pos]).r = R_MBC1_4000_7FFF;
    (memFuncArr[pos]).w = W_MBC1_6000_7FFF;

    // Assign type 6 to 0x6000-0x7FFF.
    for(i = 0x6000; i < 0x8000; i++) {
        addrFlag[i] = pos;
    }

    pos--;

    return pos;
}

/* =====================================================
    并不是每一种 MBC1 类型卡带都需要 RAM ，
    所以把分配 RAM 函数对的这部分代码单独写入这个函数，
    需要时再调用。
=======================================================*/
static void AssignMBC1_RAM(unsigned int pos)
{
    unsigned int i;

        // Type 7
    (memFuncArr[pos]).r = R_MBC1_A000_BFFF;
    (memFuncArr[pos]).w = W_MBC1_A000_BFFF;

    // Assign type 7 to 0xA000-0xBFFF.
    for(i = 0xA000; i < 0xC000; i++) {
        addrFlag[i] = pos;
    }
}

public int InitMemInterface()
{
    unsigned int pos;

    // 实现：initialize Title data memory interface.

    InitBaseMemFuncArr();

    switch(_gbRomBuf[0x0147]) {
        case 0x00:{ AssignRomOnly();
                    isBattery = FALSE;
                    break;}     //  ROM ONLY.
        
        case 0x01:{ AssignMBC1_ROM();
                    isBattery = FALSE;
                    break;}     //  MBC1.

        case 0x02:{ pos = AssignMBC1_ROM();
                    AssignMBC1_RAM(pos);
                    isBattery = FALSE;
                    break;}     //  MBC1+RAM.

        case 0x03:{ pos = AssignMBC1_ROM();
                    AssignMBC1_RAM(pos);
                    isBattery = TRUE;
                    break;}     //  MBC1+RAM+BATTERY.
        
        //case 0x0F:{ break;}   //  MBC3+TIMER+BATTERY.
        //case 0x10:{ break;}   //  MBC3+TIMER+RAM+BATTERY.
        //etc type.
        default :{  fprintf(stderr, "Unsupported cart type \n");    // DEBUG.
                    return ERROR;
                 }
    }

    return SUCCESS;
}