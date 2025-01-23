read -p "Enter the limit: " limit

echo -n "The fibonacci series upto $limit term is: "

a=0
b=1

for ((i = 0; i < limit; i++)); do
    echo -n " $a"
    c=$((a + b))
    a=$b
    b=$c
done
echo
