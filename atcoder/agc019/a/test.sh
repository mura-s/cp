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
20 30 70 90
3
EOS
)"
expected1="$(cat << EOS
150

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
10000 1000 100 10
1
EOS
)"
expected2="$(cat << EOS
100

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
10 100 1000 10000
1
EOS
)"
expected3="$(cat << EOS
40

EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
12345678 87654321 12345678 87654321
123456789
EOS
)"
expected4="$(cat << EOS
1524157763907942

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
