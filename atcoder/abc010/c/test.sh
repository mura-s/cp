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
1 1 8 2 2 4
1
4 5
EOS
)"
expected1="$(cat << EOS
NO
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
1 1 8 2 2 6
1
4 5
EOS
)"
expected2="$(cat << EOS
YES
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
1 1 8 2 2 5
1
4 5
EOS
)"
expected3="$(cat << EOS
YES
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
7 7 1 1 3 4
3
8 1
1 7
9 9
EOS
)"
expected4="$(cat << EOS
YES
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
