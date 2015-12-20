CC		:=	clang
AS		:=	clang
AR		:=	ar
LD		:=	ld#.gold
OBJCOPY	:=	objcopy

RDIR	:=	bin
ODIR	:=	build
SDIR	:=	source
IDIRS	:=	-I. -Iinclude
LDIRS	:=	-L. -Llib

CFLAGS	:=	$(IDIRS) -O2 -Wall -pedantic -std=c11
SFLAGS	:=
LFLAGS	:=	$(LDIRS)

CFILES	:=	$(wildcard $(SDIR)/*.c)
SFILES	:=	$(wildcard $(SDIR)/*.s)
OBJS	:=	$(patsubst $(SDIR)/%.c, build/%.o, $(CFILES)) $(patsubst $(SDIR)/%.s, build/%.o, $(SFILES))

LIBS	:=

TARGET = $(RDIR)/resolve#$(shell basename $(CURDIR))

$(TARGET): $(ODIR) $(OBJS)
	@mkdir -p $@
	@rmdir $@
	$(CC) $(ODIR)/*.o -o $(TARGET) $(CFLAGS) $(LFLAGS) $(LIBS)

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.s
	$(AS) -c -o $@ $< $(SFLAGS)

$(ODIR):
	@mkdir $@

.PHONY: clean

clean:
	rm -fR $(RDIR) $(ODIR)
