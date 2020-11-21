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
4 10
1 3 5
2 4 4
3 10 6
2 4 1

EOS
)"
expected1="$(cat << EOS
No

EOS
)"
try "$input1" "$expected1"

echo "[Sample2]"
input2="$(cat << EOS
4 10
1 3 5
2 4 4
3 10 6
2 3 1

EOS
)"
expected2="$(cat << EOS
Yes

EOS
)"
try "$input2" "$expected2"

echo "[Sample3]"
input3="$(cat << EOS
6 1000000000
0 200000 999999999
2 20 1
20 200 1
200 2000 1
2000 20000 1
20000 200000 1

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

