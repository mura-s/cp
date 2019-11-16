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
0 0
1 0
0 1
EOS
)"
expected1="$(cat << EOS
2.2761423749

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
2
-879 981
-866 890
EOS
)"
expected2="$(cat << EOS
91.9238815543

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
8
-406 10
512 859
494 362
-955 -475
128 553
-986 -885
763 77
449 310
EOS
)"
expected3="$(cat << EOS
7641.9817824387
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
