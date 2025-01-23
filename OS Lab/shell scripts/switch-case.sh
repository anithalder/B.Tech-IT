while ((1)); do
    echo

    echo -e "\t 1. Find largest and smallest."
    echo -e "\t 2. Find odd and even."
    echo -e "\t 3. Find prime and non-prime."
    echo -e "\t 0. Exit."

    echo

    read -p "Enter your choice: " choice
    case $choice in
    1)
        read -p "Enter two numbers: " a b
        if ((a > b)); then
            echo -e "\n\t $a is greater and $b is smaller \n"
        else
            echo -e "\n\t $b is greater and $a is smaller \n"
        fi
        ;;
    2)
        echo 2
        ;;
    3)
        echo 3
        ;;
    *)
        echo "\n\t Invalid Choice \n"
        ;;
    esac

done
echo
