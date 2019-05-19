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
1
100
30
EOS
)"
expected1="$(cat << EOS
2100.000000000000000
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
2
60 50
34 38
EOS
)"
expected2="$(cat << EOS
2632.000000000000000
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
3
12 14 2
6 2 7
EOS
)"
expected3="$(cat << EOS
76.000000000000000
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
1
9
10
EOS
)"
expected4="$(cat << EOS
20.250000000000000
EOS
)"
try "$input4" "$expected4"

echo "[Sample5]"
input5="$(cat << EOS
10
64 55 27 35 76 119 7 18 49 100
29 19 31 39 27 48 41 87 55 70
EOS
)"
expected5="$(cat << EOS
20291.000000000000000
EOS
)"
try "$input5" "$expected5"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
