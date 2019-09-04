CXX := g++
CXX_OPTION ?= -std=c++14 -O2 -lm -Wall -Wextra -Wno-sign-compare -Wno-char-subscripts

SRC := $(wildcard src/*.cpp)
SNIP_NODIR := $(notdir $(SRC:%.cpp=%.snip))
SNIP := $(addprefix ./snip/, ${SNIP_NODIR})
GEN_SNIP := ./genSnip

GEN_TEMPLATE := ./genTemplate.sh
TEMPLATE_CPP := ./src/.template.cpp
COMMON_HEADER_HPP := ./src/commonHeader.hpp

BITS_STDCPP_GCH := ./src/bits/stdc++.h.gch
BITS_STDCPP_H := ./src/bits/stdc++.h



all:	${SNIP} ${TEMPLATE_CPP} ${BITS_STDCPP_GCH}

.PHONY:	all


./snip/%.snip:	src/%.cpp ${GEN_SNIP}
	${GEN_SNIP} $< -d snip/


${TEMPLATE_CPP}:	${COMMON_HEADER_HPP} ${GEN_TEMPLATE}
	${GEN_TEMPLATE} < ${COMMON_HEADER_HPP} > $@


${GEN_SNIP}:	./_hoge/genSnip.cpp ./_hoge/cmdline.h
	${CXX} ${CXX_OPTION} $< -o $@


${BITS_STDCPP_GCH}:	${BITS_STDCPP_H}
	${CXX} ${CXX_OPTION} -c $< -o $@


debug:
	@echo "CXX = ${CXX}"
	@echo "CXX_OPTION = ${CXX_OPTION}"
	@echo "SRC = ${SRC}" | tr ' ' '\n'
	@echo "SNIP = ${SNIP}" | tr ' ' '\n'
