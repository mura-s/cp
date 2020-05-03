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
84 97 66
79 89 11
61 59 7
7
89
7
87
79
24
84
30
EOS
)"
expected1="$(cat << EOS
Yes

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
41 7 46
26 89 2
78 92 8
5
6
45
16
57
17
EOS
)"
expected2="$(cat << EOS
No

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
60 88 34
92 41 43
65 73 48
10
60
43
88
11
48
73
65
41
92
34
EOS
)"
expected3="$(cat << EOS
Yes

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
