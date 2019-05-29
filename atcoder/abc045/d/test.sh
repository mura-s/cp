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
4 5 8
1 1
1 4
1 5
2 3
3 1
3 2
3 4
4 4
EOS
)"
expected1="$(cat << EOS
0
0
0
2
4
0
0
0
0
0

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
10 10 20
1 1
1 4
1 9
2 5
3 10
4 2
4 7
5 9
6 4
6 6
6 7
7 1
7 3
7 7
8 1
8 5
8 10
9 2
10 4
10 9
EOS
)"
expected2="$(cat << EOS
4
26
22
10
2
0
0
0
0
0
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
1000000000 1000000000 0
EOS
)"
expected3="$(cat << EOS
999999996000000004
0
0
0
0
0
0
0
0
0
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
