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
4 3 1
1 2 2
2 3 9
2 4 5
EOS
)"
expected1="$(cat << EOS
16
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
5 6 2
1 2 5
1 3 3
2 3 4
2 5 7
3 4 6
4 5 5
EOS
)"
expected2="$(cat << EOS
12
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
