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
3 20
2 80
9 120
16 1
EOS
)"
expected1="$(cat << EOS
191

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
3 20
2 80
9 1
16 120
EOS
)"
expected2="$(cat << EOS
192

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
1 100000000000000
50000000000000 1
EOS
)"
expected3="$(cat << EOS
0

EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
15 10000000000
400000000 1000000000
800000000 1000000000
1900000000 1000000000
2400000000 1000000000
2900000000 1000000000
3300000000 1000000000
3700000000 1000000000
3800000000 1000000000
4000000000 1000000000
4100000000 1000000000
5200000000 1000000000
6600000000 1000000000
8000000000 1000000000
9300000000 1000000000
9700000000 1000000000
EOS
)"
expected4="$(cat << EOS
6500000000

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
