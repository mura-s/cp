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
3 2
5 1 4
2 3
1 5
EOS
)"
expected1="$(cat << EOS
14

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
10 3
1 8 5 7 100 4 52 33 13 5
3 10
4 30
1 4
EOS
)"
expected2="$(cat << EOS
338
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
3 2
100 100 100
3 99
3 99
EOS
)"
expected3="$(cat << EOS
300
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
11 3
1 1 1 1 1 1 1 1 1 1 1
3 1000000000
4 1000000000
3 1000000000
EOS
)"
expected4="$(cat << EOS
10000000001

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
