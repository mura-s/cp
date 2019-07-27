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
??2??5
EOS
)"
expected1="$(cat << EOS
768

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
?44
EOS
)"
expected2="$(cat << EOS
1

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
7?4
EOS
)"
expected3="$(cat << EOS
0

EOS
)"
try "$input3" "$expected3"

echo "[Sample4]"
input4="$(cat << EOS
?6?42???8??2??06243????9??3???7258??5??7???????774????4?1??17???9?5?70???76???
EOS
)"
expected4="$(cat << EOS
153716888

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
