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
0 2
6 3
2 4
EOS
)"
expected1="$(cat << EOS
2.061552812808830

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
0 5
8 6
9 1
2 0
1 0
0 1
EOS
)"
expected2="$(cat << EOS
0.500000000000000

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
3 0
5 2 3
-1 0 2
2 -6 4
EOS
)"
expected3="$(cat << EOS
2.000000000000000

EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
1 1
0 0 5
6 -3
EOS
)"
expected4="$(cat << EOS
1.708203932499369

EOS
)"
try "$input4" "$expected4"

# echo "[Sample5]"
# input5="$(cat << EOS
#
# EOS
# )"
# expected5="$(cat << EOS
#
# EOS
# )"
# try "$input5" "$expected5"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
