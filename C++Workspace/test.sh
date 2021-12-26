#!/bin/bash
problemname=$1
oj dl "https://atcoder.jp/contests/typical90/tasks/${problemname}"
#oj dl "https://${problemname:0:6}.contest.atcoder.jp/tasks/${problemname:0:8}" #abc,arc,agc
#oj dl "https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_${problemname:0:1}"
g++ -Wall -std=c++14 ./solved/${problemname}.cpp
oj test
rm -f a.out
rm -rf test 