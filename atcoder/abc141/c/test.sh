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
6 3 4
3
1
3
2
EOS
)"
expected1="$(cat << EOS
No
No
Yes
No
No
No

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
6 5 4
3
1
3
2
EOS
)"
expected2="$(cat << EOS
Yes
Yes
Yes
Yes
Yes
Yes
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
10 13 15
3
1
4
1
5
9
2
6
5
3
5
8
9
7
9
EOS
)"
expected3="$(cat << EOS
No
No
No
No
Yes
No
No
No
Yes
No
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
