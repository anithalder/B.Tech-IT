read -p "Enter the limit: " num

echo -n "The natural numbers from 1 to $num is: "

for ((i = 1; i < num; i++)); do
    echo -n "$i "
done
