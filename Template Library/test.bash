for((i = 1; ; ++i)); do
    ./gen >in
    ./ <in >out # put file name here
    ./brute <in >out2
    diff -w out out2 || break
    echo "Passed $i"
done
echo "Wrong Answer on following input"
cat in
echo
echo "Your Answer"
cat out
echo
echo "Correct Answer"
cat out2
