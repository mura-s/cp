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
2 3 3 1 3 1
EOS
)"
expected1="$(cat << EOS
3

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
6
5 2 4 2 8 8
EOS
)"
expected2="$(cat << EOS
0

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
32
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4 3 3 8 3 2 7 9 5
EOS
)"
expected3="$(cat << EOS
22
EOS
)"
try "$input3" "$expected3"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
