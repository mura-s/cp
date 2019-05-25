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
2 10 20
EOS
)"
expected1="$(cat << EOS
30
50
90
170
330
650
1290
2570
5130
10250

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
4 40 60
EOS
)"
expected2="$(cat << EOS
200
760
3000
11960
47800
191160
764600
3058360
12233400
48933560
EOS
)"
try "$input2" "$expected2"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
