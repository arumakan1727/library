#!/bin/bash
# Reference : https://online-judge-tools.readthedocs.io/en/master/run-ci-on-your-library.html

set -eu

which oj > /dev/null

CXX=${CXX:-g++}
CXXFLAGS="${CXX_OPTION}"
ulimit -s unlimited

run() {
    file="$1"
    url="$(grep -o '^# *define \+PROBLEM \+\(https\?://.*\)' < "$file" | sed 's/.* http/http/')"
    dir=testcases/$(echo -n "$url" | md5sum | sed 's/ .*//')
    mkdir -p ${dir}
    $CXX $CXXFLAGS -I . -o ${dir}/a.out "$file"
    if [[ -n ${url} ]] ; then
        if [[ ! -e ${dir}/test ]] ; then
            sleep 1
            oj download --system "$url" -d ${dir}/test
        fi
        oj test --tle 2 --c ${dir}/a.out -d ${dir}/test
    else
        ${dir}/a.out
    fi
}

if [ $# -eq 0 ] ; then
    for f in $(find . -name \*.test.cpp) ; do
        run $f
    done
else
    for f in "$@" ; do
        run "$f"
    done
fi
