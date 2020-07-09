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
6
0 1 2 3 4 5
EOS
)"
expected1="$(cat << EOS
3

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
3
0 0 0
EOS
)"
expected2="$(cat << EOS
6
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
54
0 0 1 0 1 2 1 2 3 2 3 3 4 4 5 4 6 5 7 8 5 6 6 7 7 8 8 9 9 10 10 11 9 12 10 13 14 11 11 12 12 13 13 14 14 15 15 15 16 16 16 17 17 17
EOS
)"
expected3="$(cat << EOS
115295190
EOS
)"
try "$input3" "$expected3"

# echo "[Sample4]"
# input4="$(cat << EOS
#
# EOS
# )"
# expected4="$(cat << EOS
#
# EOS
# )"
# try "$input4" "$expected4"

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
