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
1 2 2 2 1
2 4
5 1
3
EOS
)"
expected1="$(cat << EOS
12

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
2 2 2 2 2
8 6
9 1
2 1
EOS
)"
expected2="$(cat << EOS
25
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
2 2 4 4 4
11 12 13 14
21 22 23 24
1 2 3 4
EOS
)"
expected3="$(cat << EOS
74
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
