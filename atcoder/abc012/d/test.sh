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
3 2
1 2 10
2 3 10

EOS
)"
expected1="$(cat << EOS
10

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
5 5
1 2 12
2 3 14
3 4 7
4 5 9
5 1 18

EOS
)"
expected2="$(cat << EOS
26

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
4 6
1 2 1
2 3 1
3 4 1
4 1 1
1 3 1
4 2 1

EOS
)"
expected3="$(cat << EOS
1

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
