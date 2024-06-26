# use normal make for this Makefile
#
# Makefile for building user programs to run on top of Nachos
#
# Several things to be aware of:
#
#    Nachos assumes that the location of the program startup routine (the
# 	location the kernel jumps to when the program initially starts up)
#       is at location 0.  This means: start.o must be the first .o passed 
# 	to ld, in order for the routine "Start" to be loaded at location 0
#

# if you are cross-compiling, you need to point to the right executables
# and change the flags to ld and the build procedure for as

GCCDIR = ../../../gnu-decstation-ultrix/decstation-ultrix/2.95.3/

LDFLAGS = -T script -N
ASFLAGS = -mips2
CPPFLAGS = $(INCDIR)

# if you aren't cross-compiling:
# GCCDIR =
# LDFLAGS = -N -T 0
# ASFLAGS =
# CPPFLAGS = -P $(INCDIR)

PATH = $(GCCDIR):/lib:/usr/bin:/bin

CC = $(GCCDIR)gcc -B../../../gnu-decstation-ultrix/
AS = $(GCCDIR)as
LD = $(GCCDIR)ld

CPP = gcc -E
INCDIR =-I../userprog -I../threads
CFLAGS = -G 0 -c $(INCDIR)

# ---------------------------------------------------------------------------------------
all: halt ping pong scheduler scan passenger scan_passenger
# ---------------------------------------------------------------------------------------
start.o: start.s ../userprog/syscall.h
	$(CPP) $(CPPFLAGS) start.c > strt.s
	$(AS) $(ASFLAGS) -o start.o strt.s
	rm strt.s

# ---------------------------------------------------------------------------------------
halt.o: halt.c
	$(CC) $(CFLAGS) -c halt.c
halt: halt.o start.o
	$(LD) $(LDFLAGS) start.o halt.o -o halt.coff
	../bin/coff2noff halt.coff halt

# ---------------------------------------------------------------------------------------
ping.o: ping.c
	$(CC) $(CFLAGS) -c ping.c
ping: ping.o start.o
	$(LD) $(LDFLAGS) start.o ping.o -o ping.coff
	../bin/coff2noff ping.coff ping

# ---------------------------------------------------------------------------------------
pong.o: pong.c
	$(CC) $(CFLAGS) -c pong.c
pong: pong.o pong.o
	$(LD) $(LDFLAGS) start.o pong.o -o pong.coff
	../bin/coff2noff pong.coff pong

# ---------------------------------------------------------------------------------------
scheduler.o: scheduler.c
	$(CC) $(CFLAGS) -c scheduler.c
scheduler: scheduler.o start.o
	$(LD) $(LDFLAGS) start.o scheduler.o -o scheduler.coff
	../bin/coff2noff scheduler.coff scheduler

# ---------------------------------------------------------------------------------------
scan.o: scan.c
	$(CC) $(CFLAGS) -c scan.c
scan: scan.o start.o
	$(LD) $(LDFLAGS) start.o scan.o -o scan.coff
	../bin/coff2noff scan.coff scan

# ---------------------------------------------------------------------------------------
passenger.o: passenger.c
	$(CC) $(CFLAGS) -c passenger.c
passenger: passenger.o start.o
	$(LD) $(LDFLAGS) start.o passenger.o -o passenger.coff
	../bin/coff2noff passenger.coff passenger

# ---------------------------------------------------------------------------------------
scan_passenger.o: scan_passenger.c
	$(CC) $(CFLAGS) -c scan_passenger.c
scan_passenger: scan_passenger.o start.o
	$(LD) $(LDFLAGS) start.o scan_passenger.o -o scan_passenger.coff
	../bin/coff2noff scan_passenger.coff scan_passenger


