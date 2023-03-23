# Minimal makefile for prog1

PROGRAM = monty
FILES.c = main.c push.c pall.c
FILES.h = monty.h
FILES.o = ${FILES.c:.c=.o}

CC      = gcc
SFLAGS  = -std=c89
GFLAGS  = -g
OFLAGS  = -O3
WFLAG1  = -Wall
WFLAG2  = -Wextra
WFLAG3  = -Werror
WFLAG4  = -Wstrict-prototypes
WFLAG5  = -Wmissing-prototypes
WFLAGS  = ${WFLAG1} ${WFLAG2} ${WFLAG3} ${WFLAG4} ${WFLAG5}
UFLAGS  = # Set on command line only

CFLAGS  = ${SFLAGS} ${GFLAGS} ${OFLAGS} ${WFLAGS} ${UFLAGS}
LDFLAGS =
LDLIBS  =

all:    ${PROGRAM}

${PROGRAM}: ${FILES.o}
    ${CC} -o $@ ${CFLAGS} ${FILES.o} ${LDFLAGS} ${LDLIBS}

main.o: ${FILES.h}
push.o: ${FILES.h}
pall.o: ${FILES.h}

# If it exists, prog1.dSYM is a directory on macOS
DEBRIS = a.out core *~ *.dSYM
RM_FR  = rm -fr

clean:
    ${RM_FR} ${FILES.o} ${PROGRAM} ${DEBRIS}
