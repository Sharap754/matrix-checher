output=$(printf "2\n1 2\n3 4\n1 3\n2 4\n" | usr/bin/matrix_check)

if [[ "$output" == *"YES"* ]]; then
    echo "Test 1 OK"
else
    echo "Test 1 FAIL"
    exit 1
fi
