RV_COMPILER_OPTIONS = -Os -g -static -mabi=ilp32 -march=rv32imc -Wall -pedantic
RV_LINKING_OPTIONS = ${RV_COMPILER_OPTIONS} -static -nostartfiles ${LIB_DIR}crtbegin.o

LINKER_SCRIPT = ./lib/link.ld
LIB_DIR = ./lib/

SOURCE_FILES = $(wildcard source/*.c)
SOURCE_FILES += $(wildcard source/*.cpp)
HEADER_FILES = $(wildcard header/*.h)
OBJ_FILES = $(SOURCE_FILES:source/%.c=build/%.o) $(SOURCE_FILES:source/%.cpp=build/%.o)

OBJ_FILES += Suduko_Solver.o

TC_PREFIX = riscv32-unknown-elf-

CC = ${TC_PREFIX}gcc
CXX= ${TC_PREFIX}g++
OBJCOPY = ${TC_PREFIX}objcopy

SPIKE_OPTIONS = --isa=RV32GC

build/Suduko_Solver-riscv.hex: build/Suduko_Solver-riscv.elf 
	${OBJCOPY} -O verilog Suduko_Solver-riscv.elf Suduko_Solver-riscv.hex 

build/Suduko_Solver-riscv.elf: ${OBJ_FILES} ${HEADER_FILES}
	${CXX} ${RV_LINKING_OPTIONS} -o Suduko_Solver-riscv.elf -I./header \
		-L ${LIB_DIR} -lcv-verif -T ${LINKER_SCRIPT} ${OBJ_FILES} 

build/%.o : source/%.cpp
	${CXX} ${RV_COMPILER_OPTIONS} -I./header -c -o $@ $< 

build/%.o : source/%.c
	${CC} ${RV_COMPILER_OPTIONS} -I./header -c -o $@ $< 

%.o : %.cpp
	${CXX} ${RV_COMPILER_OPTIONS} -I./header -c -o $@ $<

%.o : %.c
	${CC} ${RV_COMPILER_OPTIONS} -I./header -c -o $@ $<


.PHONY : 
	-rm ${OBJ_FILES}
	make


.PHONY : all
all:
	-rm Suduko_Solver.o
	make
	make run

.PHONY : run
run: 
	testbench_verilator "+firmware=./Suduko_Solver-riscv.hex"

.PHONY : clean
clean:
	-rm Suduko_Solver-riscv.hex Suduko_Solver-riscv.elf
	-rm ${OBJ_FILES}
