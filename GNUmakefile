################################################################
#	THIS MAKEFILE IS MEANT FOR THE N64 SDK FOR LINUX       #
#	BY CRASHOVERIDE. IF USING Partner-N64 SDK PLEASE       #
#	USE THE OTHER makefile!!!!!!!!!!!!!!!!!!!!!!!!!!       #
################################################################

################################################################
#                    Code files and ROM name                   #
################################################################

ASMFILES    = asm/entry.s asm/rom_header.s
ASMOBJECTS  =	$(ASMFILES:.s=.o)
CODECFILES  = nuboot.c main.c graphic.c helper.c stage00.c sausage/sausage64.c
CODEHFILES  =

DEBUG_DIR = debug
DEBUGFILES = $(DEBUG_DIR)/debug.c $(DEBUG_DIR)/usb.c

ELF		= game.elf
TARGETS	= game.z64
MAP		= game.map

LD_SCRIPT	= game.ld
CP_LD_SCRIPT	= game_cp.ld


################################################################
#                         Nusys Config                         #
################################################################

NUSYSINC  = /usr/include/n64/nusys
NUSYSLIB  = /usr/lib/n64/nusys
# Note on July 16th, this was already commented out before we started messing
# with ivf debugging
# further note, apparently we didn't need either of these, somewhere Buu
# has this stuff already set up for this ROM/game template from Sausage that we borrowed
#NUOBJ		= $(NUSYSLIB)/nusys_rom.o
#NUOBJ		= $(NUSYSLIB)/nusys_isv.o

################################################################
#                         Make Commands                        #
################################################################

default: $(TARGETS)


################################################################
#     Don't touch below unless you know what you're doing!     #
################################################################

include $(N64_ROOT)/usr/include/make/PRdefs

BOOT		= /usr/lib/n64/PR/bootcode/boot.6102
BOOT_OBJ	= boot.6102.o
CODESEGMENT = codesegment.o
OBJECTS     = $(ASMOBJECTS) $(BOOT_OBJ) $(CODESEGMENT)


################################################################
#                     ROM debug mode check                     #
################################################################

ifeq ($(DEBUG_MODE), 0)
    CODEOBJECTS     = $(CODECFILES:.c=.o) $(NUOBJ)
    OPTIMIZER       = -O2
    LCDEFS          = -D_FINALROM -DNDEBUG -DF3DEX_GBI_2
    N64LIB          = -lnusys -lultra_rom
    MAKEROMFLAGS    = 
else
    CODEOBJECTS     = $(CODECFILES:.c=.o) $(NUOBJ) $(DEBUGFILES:.c=.o)
    OPTIMIZER       = -g
    LCDEFS          = -DDEBUG  -DF3DEX_GBI_2
    N64LIB          = -lnusys_d -lultra_d
    MAKEROMFLAGS    = -d
endif


################################################################
#                        Linker Settings                       #
################################################################

LCINCS =	-I. -I./assets -I./debug -I./sausage -I$(N64_ROOT)/usr/include/PR -I$(N64_ROOT)/usr/include -I$(NUSYSINC) -I$(N64_ROOT)/usr/include/nustd
LCOPTS =	-G 0
LDIRT  =	$(ELF) $(CP_LD_SCRIPT) $(TARGETS) $(MAP) $(ASMOBJECTS)
LDFLAGS=	$(MKDEPOPT) -L$(N64_ROOT)/usr/lib -L$(N64_ROOT)/usr/lib/PR -L$(NUSYSLIB) $(N64LIB) -L$(N64_LIBGCCDIR) -lgcc -lnustd


################################################################
#                          Compilation                         #
################################################################

include $(COMMONRULES)

.s.o:
	$(AS) -Wa,-Iasm -o $@ $<

$(CODESEGMENT):	$(CODEOBJECTS)
	$(LD) -o $(CODESEGMENT) -r $(CODEOBJECTS) $(LDFLAGS)

$(BOOT_OBJ): $(BOOT)
	$(OBJCOPY) -I binary -B mips -O elf32-bigmips $< $@

$(CP_LD_SCRIPT): $(LD_SCRIPT)
	cpp -P -Wno-trigraphs -I$(NUSYSINC) -o $@ $<

$(TARGETS): $(OBJECTS) $(CP_LD_SCRIPT)
	$(LD) -L. -T $(CP_LD_SCRIPT) -Map $(MAP) -o $(ELF) 
	$(OBJCOPY) --pad-to=0x100000 --gap-fill=0xFF $(ELF) $(TARGETS) -O binary
	makemask $(TARGETS)
