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
1 2
3 1
3
EOS
)"
expected1="$(cat << EOS
YES
EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
1 2
3 2
3
EOS
)"
expected2="$(cat << EOS
NO
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
1 2
3 3
3
EOS
)"
expected3="$(cat << EOS
NO
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
2 3
1 2
3
EOS
)"
expected4="$(cat << EOS
YES
EOS
)"
try "$input4" "$expected4"

echo "[Sample5]"
input5="$(cat << EOS
2 2
1 3
3
EOS
)"
expected5="$(cat << EOS
NO
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
