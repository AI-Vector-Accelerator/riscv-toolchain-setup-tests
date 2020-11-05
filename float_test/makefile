RV_COMPILER_OPTIONS = -Os -g -static -mabi=ilp32 -march=rv32imc -Wall -pedantic
RV_LINKING_OPTIONS = ${RV_COMPILER_OPTIONS} -static -nostartfiles ${LIB_DIR}crtbegin.o --specs=nano.specs

LINKER_SCRIPT = ./lib/link.ld
LIB_DIR = ./lib/

CC_SOURCE_FILES = $(wildcard source/*.c)
CXX_SOURCE_FILES += $(wildcard source/*.cpp)
HEADER_FILES = $(wildcard header/*.h)
OBJ_FILES = $(CC_SOURCE_FILES:source/%.c=build/%.o) $(CXX_SOURCE_FILES:source/%.cpp=build/%.o)

OBJ_FILES += main.o

TC_PREFIX = riscv32-unknown-elf-

CC = ${TC_PREFIX}gcc
CXX= ${TC_PREFIX}g++
OBJCOPY = ${TC_PREFIX}objcopy

SPIKE_OPTIONS = --isa=RV32GC

build/main-riscv.hex: build/main-riscv.elf 
	${OBJCOPY} -O verilog main-riscv.elf main-riscv.hex 

build/main-riscv.elf: ${OBJ_FILES} ${HEADER_FILES}
	${CXX} ${RV_LINKING_OPTIONS} -o main-riscv.elf -I./header \
		-L ${LIB_DIR} -lcv-verif -T ${LINKER_SCRIPT} ${OBJ_FILES} 

build/%.o : source/%.cpp
	${CXX} ${RV_COMPILER_OPTIONS} -I./header -c -o $@ $< 

build/%.o : source/%.c
	${CC} ${RV_COMPILER_OPTIONS} -I./header -c -o $@ $< 

%.o : %.cpp
	${CXX} ${RV_COMPILER_OPTIONS} -I./header -c -o $@ $<

%.o : %.c
	${CC} ${RV_COMPILER_OPTIONS} -I./header -c -o $@ $<


.PHONY : all
all:
	make
	make run

.PHONY : run
run: 
	testbench_verilator "+firmware=./main-riscv.hex"

.PHONY : clean
clean:
	-rm main-riscv.hex helloworld-riscv.elf
	-rm ${OBJ_FILES}
