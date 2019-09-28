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
2 3
10 1
1
15 1
2
30 2
1 2
EOS
)"
expected1="$(cat << EOS
25

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
12 1
100000 1
2
EOS
)"
expected2="$(cat << EOS
-1

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
4 6
67786 3
1 3 4
3497 1
2
44908 3
2 3 4
2156 3
2 3 4
26230 1
2
86918 1
3
EOS
)"
expected3="$(cat << EOS
69942
EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
2 3
30 2
1 2
10 1
1
15 1
2
EOS
)"
expected4="$(cat << EOS
25

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
