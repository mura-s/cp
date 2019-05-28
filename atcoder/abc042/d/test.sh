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
2 3 1 1
EOS
)"
expected1="$(cat << EOS
2

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
10 7 3 4
EOS
)"
expected2="$(cat << EOS
3570

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
100000 100000 99999 99999
EOS
)"
expected3="$(cat << EOS
1
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
100000 100000 44444 55555
EOS
)"
expected4="$(cat << EOS
738162020
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
