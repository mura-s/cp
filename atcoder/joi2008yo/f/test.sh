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
3 8
1 3 1 10
0 2 3
1 2 3 20
1 1 2 5
0 3 2
1 1 3 7
1 2 1 9
0 2 3
EOS
)"
expected1="$(cat << EOS
-1
15
12

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
5 16
1 1 2 343750
1 1 3 3343
1 1 4 347392
1 1 5 5497
1 2 3 123394
1 2 4 545492
1 2 5 458
1 3 4 343983
1 3 5 843468
1 4 5 15934
0 2 1
0 4 1
0 3 2
0 4 2
0 4 3
0 5 3
EOS
)"
expected2="$(cat << EOS
5955
21431
9298
16392
24774
8840
EOS
)"
try "$input2" "$expected2"

# echo "[Sample4]"
# input4="$(cat << EOS
#
# EOS
# )"
# expected4="$(cat << EOS
#
# EOS
# )"
# try "$input4" "$expected4"

# echo "[Sample5]"
# input5="$(cat << EOS
#
# EOS
# )"
# expected5="$(cat << EOS
#
# EOS
# )"
# try "$input5" "$expected5"

echo "[Result]"
if ! $all_ac; then
    echo "WA"
    echo
    exit 1
fi
echo "All AC"
