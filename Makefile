CXX := g+
SRC := $(wildcard src/*.cpp)
SNIP_NODIR := $(notdir $(SRC:%.cpp=%.snip))
SNIP := $(addprefix ./snip/, ${SNIP_NODIR})
GEN_SNIP := ./genSnip

all:	${SNIP}

debug:
	@echo "CXX = ${CXX}"
	@echo "SRC = ${SRC}" | tr ' ' '\n'
	@echo "SNIP_NODIR = ${SNIP_NODIR}" | tr ' ' '\n'
	@echo "SNIP = ${SNIP}" | tr ' ' '\n'

./snip/%.snip:	src/%.cpp ${GEN_SNIP}
	${GEN_SNIP} $< -d snip/

${GEN_SNIP}:	./_hoge/genSnip.cpp ./_hoge/cmdline.h
	${CXX} $< -o $@

.PHONY:	all
