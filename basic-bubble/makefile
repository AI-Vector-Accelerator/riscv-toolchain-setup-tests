RV_COMPILER_OPTIONS = -Os -g -static -mabi=ilp32 -march=rv32imc -Wall -pedantic
RV_LINKING_OPTIONS = ${RV_COMPILER_OPTIONS} -nostartfiles

LINKER_SCRIPT = ./lib/link.ld
LIB_DIR = ./lib/

SOURCE_FILES = $(wildcard source/*.c)
HEADER_FILES = $(wildcard header/*.h)
OBJ_FILES = $(SOURCE_FILES:source/%.c=build/%.o) main.o

TC_PREFIX = riscv32-unknown-elf-

CC = ${TC_PREFIX}gcc
OBJCOPY = ${TC_PREFIX}objcopy

SPIKE_OPTIONS = --isa=RV32GC

build/main.hex: build/main.elf 
	${OBJCOPY} -O verilog main.elf main.hex 

build/main.elf: ${MAIN_O_FILE} ${OBJ_FILES} ${HEADER_FILES}
	${CC} ${RV_LINKING_OPTIONS} -o main.elf -I./header \
		-L ${LIB_DIR} -lcv-verif -T ${LINKER_SCRIPT} ${OBJ_FILES}

build/%.o : source/%.c
	${CC} ${RV_COMPILER_OPTIONS} -I./header -c -o $@ $< 

%.o : %.c
	${CC} ${RV_COMPILER_OPTIONS} -I./header -c -o $@ $<


.PHONY : all
all:
	make
	make run

.PHONY : run
run: 
	testbench_verilator "+firmware=./main.hex"

.PHONY : clean
clean:
	-rm ${OBJ_FILES}
	-rm *.hex *.elf

