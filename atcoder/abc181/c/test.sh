#!/bin/bash
all_ac=true

try() {
    input="$1"
    expected="$2"

    actual=`echo "$input" | python main.py`

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
4
0 1
0 2
0 3
1 1

EOS
)"
expected1="$(cat << EOS
Yes

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
14
5 5
0 1
2 5
8 0
2 1
0 0
3 6
8 6
5 9
7 9
3 4
9 2
9 8
7 2

EOS
)"
expected2="$(cat << EOS
No

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
9
8 2
2 3
1 3
3 7
1 0
8 8
5 6
9 7
0 1

EOS
)"
expected3="$(cat << EOS
Yes

EOS
)"
try "$input3" "$expected3"

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

