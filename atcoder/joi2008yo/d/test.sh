#!/bin/bash
all_ac=true

try() {
    input="$1"
    expected="$2"

    actual="$(echo $input | make run)"

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
8 5
6 4
4 3
7 10
0 10
10
10 5
2 7
9 7
8 10
10 2
1 2
8 1
6 7
6 0
0 9
EOS
)"
expected1="$(cat << EOS
2 -3

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
5
904207 809784
845370 244806
499091 59863
638406 182509
435076 362268
10
757559 866424
114810 239537
519926 989458
461089 424480
674361 448440
81851 150384
459107 795405
299682 6700
254125 362183
50795 541942
EOS
)"
expected2="$(cat << EOS
-384281 179674
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
