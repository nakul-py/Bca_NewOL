# Using head and tail to display the first and last n lines of a file

#  head
echo "Enter File Name to display first lines: "
read file
# Check if file exists
if [ -f $file ]; then
    echo "$file exists."
else
    echo "$file does not exist."
fi
echo "Number of Lines in $file: "
read lines
head -n $lines $file

printf "___\n___\n"

#  tail
echo "Enter File Name tp display last lines: "
read file
# Check if file exists
if [ -f $file ]; then
    echo "$file exists."
else
    echo "$file does not exist."
fi
echo "Number of Lines in $file: "
read lines
tail -n $lines $file
