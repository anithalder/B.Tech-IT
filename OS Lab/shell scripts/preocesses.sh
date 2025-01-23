#!/bin/bash

# Assignment: Process Management in Shell Script

# Function to create a process
create_process() {
    echo "Creating a process..."
    sleep 100 &  # This creates a dummy process that runs in the background
    echo "Process created with PID: $!"
}

# Function to kill a process
kill_process() {
    echo "Enter the PID of the process to kill:"
    read pid
    kill $pid
    if [ $? -eq 0 ]; then
        echo "Process $pid killed successfully."
    else
        echo "Failed to kill process $pid."
    fi
}

# Function to display process scheduling information
schedule_process() {
    echo "Process scheduling information:"
    ps -eo pid,comm,pri,nice,state,etime --sort=-pri | head -n 10
}

# Function to change process priority
change_priority() {
    echo "Enter the PID of the process to change priority:"
    read pid
    echo "Enter the new priority (-20 to 19, lower is higher priority):"
    read priority
    renice $priority -p $pid
    if [ $? -eq 0 ]; then
        echo "Priority of process $pid changed to $priority."
    else
        echo "Failed to change priority of process $pid."
    fi
}

# Function to display the currently running process
current_process() {
    echo "Currently running processes:"
    ps -eo pid,comm,user,state,%cpu,%mem,etime --sort=-%cpu | head -n 10
}

# Function to handle background processes
background_process() {
    echo "Background processes:"
    jobs -l
}

# Function to show all information about processes
display_all_info() {
    echo "All process information:"
    ps -eo pid,ppid,comm,user,pri,nice,state,%cpu,%mem,etime,start,time --sort=-%cpu
}

# Menu to perform the actions
while true; do
    echo -e "\nProcess Management Options:"
    echo "1. Create a process"
    echo "2. Kill a process"
    echo "3. Display process scheduling information"
    echo "4. Change process priority"
    echo "5. Display currently running processes"
    echo "6. Show background processes"
    echo "7. Display all process information"
    echo "8. Exit"

    echo -n "Choose an option (1-8):"
    read choice

    case $choice in
        1)
            create_process
            ;;
        2)
            kill_process
            ;;
        3)
            schedule_process
            ;;
        4)
            change_priority
            ;;
        5)
            current_process
            ;;
        6)
            background_process
            ;;
        7)
            display_all_info
            ;;
        8)
            echo "Exiting..."
            break
            ;;
        *)
            echo "Invalid option. Please choose again."
            ;;
    esac
done

