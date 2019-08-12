#!/usr/bin/env bash

set -eu

readonly sourceFile="./src/commonHeader.hpp"
readonly targetFile="./src/.template.cpp"

main()
{
    echo '#include "bits/stdc++.h"'

    local writeFlg=false

    while IFS= read line;
    do
        # ${line,,} は $line を全て小文字に変換する
        if [[ ${line,,} == *header*{{{* ]]; then writeFlg=true; fi

        if "$writeFlg"; then echo "${line}"; fi

        if [[ ${line,,} == *}}}*header* ]]; then writeFlg=false; fi
    done

    # ----------------------------------------
cat << EOT

signed main()
{
    // ios::sync_with_stdio(false); cin.tie(nullptr);

    return 0;
}
EOT
    # ----------------------------------------
}

main < ${sourceFile} > ${targetFile}

# vim: set foldmethod=manual :
