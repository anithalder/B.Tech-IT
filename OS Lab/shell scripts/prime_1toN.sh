read -p "Enter the limit: " limit
if ((limit <= 0)); then
    echo -e "\n\tInvalid input\n"
    exit
fi
echo -n "The prime numbers up to $limit are: "
for ((i = 1; i <= limit; i++)); do
    count=0
    for ((j = 2; j <= i / 2; j++)); do
        if ((i % j == 0)); then
            ((count++))
        fi
    done
    if ((!count)); then
        echo -n "$i "
    fi
done
echo
