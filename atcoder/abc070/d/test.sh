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
5
1 2 1
1 3 1
2 4 1
3 5 1
3 1
2 4
2 3
4 5
EOS
)"
expected1="$(cat << EOS
3
2
4

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
7
1 2 1
1 3 3
1 4 5
1 5 7
1 6 9
1 7 11
3 2
1 3
4 5
6 7
EOS
)"
expected2="$(cat << EOS
5
14
22

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
10
1 2 1000000000
2 3 1000000000
3 4 1000000000
4 5 1000000000
5 6 1000000000
6 7 1000000000
7 8 1000000000
8 9 1000000000
9 10 1000000000
1 1
9 10
EOS
)"
expected3="$(cat << EOS
17000000000
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
