# Addition, subtraction, multiplication.

echo "Enter two numbers: "
read num1 num2
echo "Addition: $(expr $num1 + $num2)"
echo "Subtraction: $(expr $num1 - $num2)"
echo "Multiplication: $(expr $num1 \* $num2)"
echo "Division: $(expr $num2 / $num1)"