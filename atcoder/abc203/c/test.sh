#!/bin/bash
all_ac=true

try() {
    input="$1"
    expected="$2"

    actual=`echo "$input" | python main.py`

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
2 3
2 1
5 10

EOS
)"
expected1="$(cat << EOS
4

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
5 1000000000
1 1000000000
2 1000000000
3 1000000000
4 1000000000
5 1000000000

EOS
)"
expected2="$(cat << EOS
6000000000

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
3 2
5 5
2 1
2 2

EOS
)"
expected3="$(cat << EOS
10

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

