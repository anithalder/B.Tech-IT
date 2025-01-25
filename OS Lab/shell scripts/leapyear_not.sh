read -p "Enter the year: " year

if ((year % 400 == 0 && year % 100 == 0 || year % 4 == 0)); then
    echo -e "\n$year year is leap year\n"
else
    echo -e "\nThe year is not leap year\n"
fi
