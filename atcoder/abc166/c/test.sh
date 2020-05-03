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
4 3
1 2 3 4
1 3
2 3
2 4
EOS
)"
expected1="$(cat << EOS
2

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
6 5
8 6 9 1 2 1
1 3
4 2
4 3
4 6
4 6
EOS
)"
expected2="$(cat << EOS
3
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
