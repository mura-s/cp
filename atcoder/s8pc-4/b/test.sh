#!/bin/bash
all_ac=true

try() {
    input="$1"
    expected="$2"

    actual="$(echo $input | make run)"

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
5 5
3949 3774 3598 3469 3424
EOS
)"
expected1="$(cat << EOS
1541

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
5 3
7 4 2 6 4
EOS
)"
expected2="$(cat << EOS
7

EOS
)"
try "$input2" "$expected2"

echo "[Sample4]"
input4="$(cat << EOS
1 1
1000
EOS
)"
expected4="$(cat << EOS
0
EOS
)"
try "$input4" "$expected4"

echo "[Sample5]"
input5="$(cat << EOS
5 2
1 2 3 4 5
EOS
)"
expected5="$(cat << EOS
0
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
