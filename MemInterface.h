#include "BaseType.h"

extern int InitMemInterface();




/* =====================================================
    byte_t F(dword_t addr, byte_t **p);
    根据 addr ，返回对应字节数值，同时，把对应的字节地
    址用 p 返回（若传入的 p 不为 0）。
=======================================================*/
extern byte_t    R_DirectFromMem(dword_t, byte_t **);   // Direct read from GB's memory.
extern byte_t R_DirectFromRomBuf(dword_t, byte_t **);
extern byte_t   R_FromEmptySpace(dword_t, byte_t **);
extern byte_t        R_FF00_JOYP(dword_t, byte_t **);

extern byte_t   R_MBC1_0000_3FFF(dword_t, byte_t **);   // Read from MBC1 fixed rom bank 0.
extern byte_t   R_MBC1_4000_7FFF(dword_t, byte_t **);   // Read from MBC1 switchable rom banks.
extern byte_t   R_MBC1_A000_BFFF(dword_t, byte_t **);   // Read from MBC1 switchable ram bank(s).

extern byte_t   R_ECHO_E000_FDFF(dword_t, byte_t **);



/* =====================================================
    void F(dword_t addr, byte_t v);
    把字节 v 数值写到由 addr 决定的地方。
    对写入数值的“修缮”应该在这些 write 函数里进行，
    因为一般 GB 程序是写得少，读得多。
=======================================================*/
extern void    W_DirectToMem(dword_t, byte_t);  // Direct write to GB's memory.
extern void      W_DoNothing(dword_t, byte_t);
extern void          W_Reset(dword_t, byte_t);
extern void      W_FF00_JOYP(dword_t, byte_t);

extern void W_MBC1_0000_1FFF(dword_t, byte_t);  // Write to MBC1 register 0.
extern void W_MBC1_2000_3FFF(dword_t, byte_t);  // Write to MBC1 register 1.
extern void W_MBC1_4000_5FFF(dword_t, byte_t);  // Write to MBC1 register 2.
extern void W_MBC1_6000_7FFF(dword_t, byte_t);  // Write to MBC1 register 3.
extern void W_MBC1_A000_BFFF(dword_t, byte_t);  // Write to MBC1 switchable ram bank(s).

extern void W_ECHO_E000_FDFF(dword_t, byte_t);
