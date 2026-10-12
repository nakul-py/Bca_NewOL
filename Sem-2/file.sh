if [ $# -ne 3 ]; then
    echo "Usage: $0 file1 file2 output_file"
    exit 1
fi

file1=$1
file2=$2
file3=$3

# Check if input files exist
if [ ! -f "$file1" ]; then
    echo "Error: $file1 does not exist"
    exit 1
fi

if [ ! -f "$file2" ]; then
    echo "Error: $file2 does not exist"
    exit 1
fi

# Combine files (append in order)
cat "$file1" "$file2" > "$file3"

echo "Files merged successfully into $file3"

# Display word count
echo "Word count of merged file:"
wc "$file3"