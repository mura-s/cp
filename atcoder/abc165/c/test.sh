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
3 4 3
1 3 3 100
1 2 2 10
2 3 2 10
EOS
)"
expected1="$(cat << EOS
110

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
4 6 10
2 4 1 86568
1 4 0 90629
2 3 0 90310
3 4 1 29211
3 4 3 78537
3 4 2 8580
1 2 1 96263
1 4 2 2156
1 2 0 94325
1 4 3 94328
EOS
)"
expected2="$(cat << EOS
357500
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
10 10 1
1 10 9 1
EOS
)"
expected3="$(cat << EOS
1
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
