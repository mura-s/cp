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
6
khabarovsk 20
moscow 10
kazan 50
kazan 35
moscow 60
khabarovsk 40
EOS
)"
expected1="$(cat << EOS
3
4
6
1
5
2

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
10
yakutsk 10
yakutsk 20
yakutsk 30
yakutsk 40
yakutsk 50
yakutsk 60
yakutsk 70
yakutsk 80
yakutsk 90
yakutsk 100
EOS
)"
expected2="$(cat << EOS
10
9
8
7
6
5
4
3
2
1
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
