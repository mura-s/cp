#!/bin/bash
all_ac=true

try() {
    input="$1"
    expected="$2"

    actual="$(echo $input | ./main)"

    if [ "$actual" != "$expected" ]; then
        echo "WA"
        echo "expected:"
        echo "$expected"
        echo
        echo "actual:"
        echo "$actual"
        echo

        all_ac=false
        return
    fi
    echo "AC"
    echo
}

# test cases
echo "[Sample1]"
input1="$(cat << EOS
5 2 2
1 2 3 4 5
EOS
)"
expected1="$(cat << EOS
4.500000
1

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
4 2 3
10 20 10 10
EOS
)"
expected2="$(cat << EOS
15.000000
3

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
5 1 5
1000000000000000 999999999999999 999999999999998 999999999999997 999999999999996
EOS
)"
expected3="$(cat << EOS
1000000000000000.000000
1
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
50 1 50
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
EOS
)"
expected4="$(cat << EOS
1.000000
1125899906842623
EOS
)"
try "$input4" "$expected4"

echo "[Sample5]"
input5="$(cat << EOS
50 15 47
795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 473967724102502 795366679311762 766773867637913 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 439731685157627 795366679311762 795366679311762 471191222541265 795366679311762 795366679311762 46850942397740 795366679311762 795366679311762 784226790884208 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 795366679311762 464071351364335 795366679311762 2686647787570 795366679311762 795366679311762 541409169452649 795366679311762 12207400133349
EOS
)"
expected5="$(cat << EOS
795366679311762.000000
1055151574004
EOS
)"
try "$input5" "$expected5"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"