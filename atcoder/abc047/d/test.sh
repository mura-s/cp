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
100 50 200
EOS
)"
expected1="$(cat << EOS
1

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
5 8
50 30 40 10 20
EOS
)"
expected2="$(cat << EOS
2
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
10 100
7 10 4 5 9 3 6 8 2 1
EOS
)"
expected3="$(cat << EOS
2
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
