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
100
1
EOS
)"
expected1="$(cat << EOS
19

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
25
2
EOS
)"
expected2="$(cat << EOS
14

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
314159
2
EOS
)"
expected3="$(cat << EOS
937
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
3
EOS
)"
expected4="$(cat << EOS
117879300
EOS
)"
try "$input4" "$expected4"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
