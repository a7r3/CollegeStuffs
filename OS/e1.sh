# Write a shell script to display top 10 processes in descending order
# -r -- Reverse sort
# -k4 -- Sort by the 4th column (key)
echo "Top 10 Processes, by name"
ps -e | sort -rk4 | head -10
