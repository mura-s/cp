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
3 3 10
60 2 2 4
70 8 7 9
50 2 3 9
EOS
)"
expected1="$(cat << EOS
120

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
3 3 10
100 3 1 4
100 1 5 9
100 2 6 5
EOS
)"
expected2="$(cat << EOS
-1

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
8 5 22
100 3 7 5 3 1
164 4 5 2 7 8
334 7 2 7 2 9
234 4 7 2 8 2
541 5 4 3 3 6
235 4 8 6 9 7
394 3 6 1 6 2
872 8 4 3 7 2
EOS
)"
expected3="$(cat << EOS
1067
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
