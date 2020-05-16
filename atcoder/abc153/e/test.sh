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
9 3
8 3
4 2
2 1
EOS
)"
expected1="$(cat << EOS
4

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
100 6
1 1
2 3
3 9
4 27
5 81
6 243
EOS
)"
expected2="$(cat << EOS
100

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
9999 10
540 7550
691 9680
700 9790
510 7150
415 5818
551 7712
587 8227
619 8671
588 8228
176 2461
EOS
)"
expected3="$(cat << EOS
139815
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
