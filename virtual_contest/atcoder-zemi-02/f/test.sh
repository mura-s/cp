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
5 1
1 0 1 0 1
1 2
2 3
2 4
1 5
EOS
)"
expected1="$(cat << EOS
6

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
3 2
0 1 0
1 2
2 3
EOS
)"
expected2="$(cat << EOS
0

EOS
)"
try "$input2" "$expected2"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
