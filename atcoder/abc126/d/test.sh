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
3
1 2 2
2 3 1
EOS
)"
expected1="$(cat << EOS
0
0
1
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
5
2 5 2
2 3 10
1 3 8
3 4 2
EOS
)"
expected2="$(cat << EOS
1
0
1
0
1
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
