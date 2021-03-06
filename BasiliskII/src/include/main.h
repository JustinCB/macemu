/*
 *  main.h - General definitions
 *
 *  Basilisk II (C) 1997-2008 Christian Bauer
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MAIN_H
#define MAIN_H

extern char* romInfoStr;

extern void fillROMInfo();
extern char* getROMInfo();

extern size_t list_rom_resources(const char* buf);
extern size_t print_universal_info(uint32 info, const char* buf);
extern size_t list_universal_infos(const char* buf);
extern size_t get_rom_info(const char* buf);

extern void updateROMInfoWindow( char* info );

// CPU type (0 = 68000, 1 = 68010, 2 = 68020, 3 = 68030, 4 = 68040/060)
extern int CPUType;
extern bool CPUIs68060;         // Flag to distinguish 68040 and 68060

// FPU type (0 = no FPU, 1 = 68881, 2 = 68882)
extern int FPUType;

// 24-bit-addressing?
//extern bool TwentyFourBitAddressing;
extern "C" {
        bool getTwentyFourBitAddressing( );
        void setTwentyFourBitAddressingByComputer( bool b );
}

// 68k register structure (for Execute68k())
struct M68kRegisters {
        uint32 d[8];
        uint32 a[8];
        uint16 sr;
};

// General functions
extern bool InitAll(const char *vmdir);
extern void ExitAll(void);

// Platform-specific functions
extern void FlushCodeCache(void *start, uint32 size);           // Code was patched, flush caches if neccessary
extern void QuitEmulator(void);                                 // Quit emulator
extern void ErrorAlert(const char *text);                       // Display error alert
extern void ErrorAlert(int string_id);
extern void WarningAlert(const char *text);                     // Display warning alert
extern void WarningAlert(int string_id);
extern bool ChoiceAlert(const char *text, const char *pos, const char *neg);    // Display choice alert

// Mutexes (non-recursive)
struct B2_mutex;
extern B2_mutex *B2_create_mutex(void);
extern void B2_lock_mutex(B2_mutex *mutex);
extern void B2_unlock_mutex(B2_mutex *mutex);
extern void B2_delete_mutex(B2_mutex *mutex);

// Interrupt flags
enum {
        INTFLAG_60HZ = 1,       // 60.15Hz VBL
        INTFLAG_1HZ = 2,        // ~1Hz interrupt
        INTFLAG_SERIAL = 4,     // Serial driver
        INTFLAG_ETHER = 8,      // Ethernet driver
        INTFLAG_AUDIO = 16,     // Audio block read
        INTFLAG_TIMER = 32,     // Time Manager
        INTFLAG_ADB = 64,       // ADB
        INTFLAG_NMI = 128       // NMI
};

extern uint32 InterruptFlags;                                                                   // Currently pending interrupts
extern void SetInterruptFlag(uint32 flag);                                              // Set/clear interrupt flags
extern void ClearInterruptFlag(uint32 flag);

// Array length
#if __cplusplus >= 201103L || (_MSC_VER >= 1900 && defined __cplusplus)
template <typename T, size_t size>
constexpr size_t lengthof(T (& a)[size])
{
        return size;
}
#else
#define lengthof(a) (sizeof(a) / sizeof(a[0]))
#endif

// Mapping of Model IDs to Model names

struct mac_desc {
        const char *name;
        int32 id;
};

static mac_desc macDesc[] = {
        { "Classic"                             ,    1 }
      , { "Mac XL"                              ,    2 }
      , { "Mac 512KE"                           ,    3 }
      , { "Mac Plus"                            ,    4 }
      , { "Mac SE"                              ,    5 }
      , { "Mac II"                              ,    6 }
      , { "Mac IIx"                             ,    7 }
      , { "Mac IIcx"                            ,    8 }
      , { "Mac SE/030"                          ,    9 }
      , { "Mac Portable"                        ,   10 }
      , { "Mac IIci"                            ,   11 }
      , { "Mac IIfx"                            ,   13 }
      , { "Mac Classic"                         ,   17 }
      , { "Mac IIsi"                            ,   18 }
      , { "Mac LC"                              ,   19 }
      , { "Quadra 900"                          ,   20 }
      , { "PowerBook 170"                       ,   21 }
      , { "Quadra 700"                          ,   22 }
      , { "Classic II"                          ,   23 }
      , { "PowerBook 100"                       ,   24 }
      , { "PowerBook 140"                       ,   25 }
      , { "Quadra 950"                          ,   26 }
      , { "Mac LCIII/Performa 450"              ,   27 }
      , { "PowerBook Duo 210"                   ,   29 }
      , { "Centris 650"                         ,   30 }
      , { "PowerBook Duo 230"                   ,   32 }
      , { "PowerBook 180"                       ,   33 }
      , { "PowerBook 160"                       ,   34 }
      , { "Quadra 800"                          ,   35 }
      , { "Quadra 650"                          ,   36 }
      , { "Mac LCII"                            ,   37 }
      , { "PowerBook Duo 250"                   ,   38 }
      , { "Mac IIvi"                            ,   44 }
      , { "Mac IIvm/Performa 600"               ,   45 }
      , { "Mac IIvx"                            ,   48 }
      , { "Color Classic/Performa 250"          ,   49 }
      , { "PowerBook 165c"                      ,   50 }
      , { "Centris 610"                         ,   52 }
      , { "Quadra 610"                          ,   53 }
      , { "PowerBook 145"                       ,   54 }
      , { "Mac LC520"                           ,   56 }
      , { "Quadra/Centris 660AV"                ,   60 }
      , { "Performa 46x"                        ,   62 }
      , { "PowerBook 180c"                      ,   71 }
      , { "PowerBook 520/520c/540/540c"         ,   72 }
      , { "PowerBook Duo 270c"                  ,   77 }
      , { "Quadra 840AV"                        ,   78 }
      , { "Performa 550"                        ,   80 }
      , { "PowerBook 165"                       ,   84 }
      , { "PowerBook 190"                       ,   85 }
      , { "Mac TV"                              ,   88 }
      , { "Mac LC475/Performa 47x"              ,   89 }
      , { "Mac LC575"                           ,   92 }
      , { "Quadra 605"                          ,   94 }
      , { "Quadra 630"                          ,   98 }
      , { "Mac LC580"                           ,   99 }
      , { "PowerBook Duo 280"                   ,  102 }
      , { "PowerBook Duo 280c"                  ,  103 }
      , { "PowerBook 150"                       ,  115 }
      , { "unknown", -1 }
};

#endif
