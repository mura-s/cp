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
7
beat
vet
beet
bed
vet
bet
beet
EOS
)"
expected1="$(cat << EOS
beet
vet

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
8
buffalo
buffalo
buffalo
buffalo
buffalo
buffalo
buffalo
buffalo
EOS
)"
expected2="$(cat << EOS
buffalo
EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
7
bass
bass
kick
kick
bass
kick
kick
EOS
)"
expected3="$(cat << EOS
kick
EOS
)"
try "$input3" "$expected3"

echo "[Sample3]"
input3="$(cat << EOS
4
ushi
tapu
nichia
kun
EOS
)"
expected3="$(cat << EOS
kun
nichia
tapu
ushi
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
