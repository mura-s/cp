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
AC
TLE
AC
AC
WA
TLE
EOS
)"
expected1="$(cat << EOS
AC x 3
WA x 1
TLE x 2
RE x 0

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
10
AC
AC
AC
AC
AC
AC
AC
AC
AC
AC
EOS
)"
expected2="$(cat << EOS
AC x 10
WA x 0
TLE x 0
RE x 0
EOS
)"
try "$input2" "$expected2"

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
