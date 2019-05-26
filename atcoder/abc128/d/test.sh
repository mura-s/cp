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
6 4
-10 8 2 1 2 6
EOS
)"
expected1="$(cat << EOS
14

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
6 4
-6 -100 50 -2 -5 -3
EOS
)"
expected2="$(cat << EOS
44
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
6 3
-6 -100 50 -2 -5 -3
EOS
)"
expected3="$(cat << EOS
0

EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
1 5
50
EOS
)"
expected4="$(cat << EOS
50
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
