echo "merging files"
read f
echo "another file"
read g
cat $f $g > merged.txt
result=$(wc -c merged.txt)
echo "the number of characters in merged file is = $result"