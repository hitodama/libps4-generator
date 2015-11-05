TEXT	:=	0x926200000
DATA	:=	0x926300000

OBJCOPY	:=	objcopy

RDIR	:=	bin
ODIR	:=	build
SDIR	:=	source
IDIRS	:=	-I$(LIBPS4)/include -I. -Iinclude
LDIRS	:=	-L$(LIBPS4)/lib -L. -Llib

ifeq ($(CC),gcc)
   CC		:=	gcc
   AS		:=	gcc
   AR		:=	ar
   LD		:=	ld#.gold
   TCFLAGS	:=	-nostartfiles -march=btver2 -mtune=btver2 -mabi=sysv
   TSFLAGS	:=	-nostartfiles -march=btver2 -mtune=btver2 -mabi=sysv -nostdlib
else
   CC		:=	clang
   AS		:=	clang
   AR		:=	ar
   LD		:=	ld#.gold
   TCFLAGS	:=	-fPIC -target x86_64-scei-ps4-elf
   TSFLAGS	:=	-target x86_64-scei-ps4-elf
endif
CFLAGS	:=	$(TCFLAGS) $(IDIRS) -O2 -Wall -pedantic -std=c11 -Wl,--build-id=none -m64 -mcmodel=large -ffreestanding -nostdlib -nostdinc -fno-builtin
SFLAGS	:=	$(TSFLAGS) -m64
LFLAGS	:=	$(LDIRS) -Ttext $(TEXT) -Tdata $(DATA) -nostartfiles

CFILES	:=	$(wildcard $(SDIR)/*.c)
SFILES	:=	$(wildcard $(SDIR)/*.s)
OBJS	:=	$(patsubst $(SDIR)/%.c, build/%.o, $(CFILES)) $(patsubst $(SDIR)/%.s, build/%.o, $(SFILES))

LIBS	:= -lps4

TARGET = $(RDIR)/resolver#$(shell basename $(CURDIR))

$(TARGET): $(ODIR) $(OBJS)
	@mkdir -p $@
	@rmdir $@
	$(CC) $(LIBPS4)/crt0.s $(ODIR)/*.o -o $(TARGET).elf $(CFLAGS) $(LFLAGS) $(LIBS)
	@$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin
	@rm -f $(TARGET).elf

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.s
	$(AS) -c -o $@ $< $(SFLAGS)

$(ODIR):
	@mkdir $@

.PHONY: clean

clean:
	rm -fR $(RDIR) $(ODIR)/*.o
