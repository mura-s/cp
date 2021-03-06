#!/bin/bash
try() {
    input="$1"
    expected="$2"

    actual="$(echo $input | ./main)"

    if [ "$actual" != "$expected" ]; then
        echo "$expected expected, but got $actual"
        exit 1
    fi
}

# test cases
echo "start"

# sample1
input1="$(cat << EOS
4 5
s####
....#
#####
#...g
EOS
)"
expected1="$(cat << EOS
No
EOS
)"
try "$input1" "$expected1"
echo "sample1 ok"

# sample2
input2="$(cat << EOS
4 4
...s
....
....
.g..
EOS
)"
expected2="$(cat << EOS
Yes
EOS
)"
try "$input2" "$expected2"
echo "sample2 ok"

# sample3
input3="$(cat << EOS
10 10
s.........
#########.
#.......#.
#..####.#.
##....#.#.
#####.#.#.
g.#.#.#.#.
#.#.#.#.#.
###.#.#.#.
#.....#...
EOS
)"
expected3="$(cat << EOS
No
EOS
)"
try "$input3" "$expected3"
echo "sample3 ok"

# sample4
input4="$(cat << EOS
10 10
s.........
#########.
#.......#.
#..####.#.
##....#.#.
#####.#.#.
g.#.#.#.#.
#.#.#.#.#.
#.#.#.#.#.
#.....#...
EOS
)"
expected4="$(cat << EOS
Yes
EOS
)"
try "$input4" "$expected4"
echo "sample4 ok"

# sample5
input5="$(cat << EOS
1 10
s..####..g
EOS
)"
expected5="$(cat << EOS
No
EOS
)"
try "$input5" "$expected5"
echo "sample5 ok"

echo "ok"
