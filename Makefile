PREFIX  := prefix
INCLUDE := $(PREFIX)/include $(PREFIX)/include/libatomic_ops
NQPLIB  := $(PREFIX)/share/nqp/lib
BCSIZE   = $(shell stat --printf="%s" mambo.moarvm)

build: mambo.exe
clean:; rm -rf mambo.exe mambo.moarvm

mambo.moarvm: mambo.nqp
	nqp --target=mbc --output=$@ $<

mambo.exe: main.c libperl.dll.a libmoar.dll.a bc.s mambo.moarvm
	gcc -O3 $(INCLUDE:%=-I%) '-DNQPLIB="$(NQPLIB)"' -DBCSIZE=$(BCSIZE) -o $@ main.c bc.s -L. -lmoar
