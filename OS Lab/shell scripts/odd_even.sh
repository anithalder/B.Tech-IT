read -p "Enter the limit: " limit

echo -n "The even number list is: "

for ((i = 1; i <= limit; i++)); do
    if ((i % 2 == 0)); then
        echo -n " $i"
    fi
done

echo

echo -n "The odd number list is: "

for ((i = 1; i <= limit; i++)); do
    if ((i % 2 != 0)); then
        echo -n " $i"
    fi
done
echo
