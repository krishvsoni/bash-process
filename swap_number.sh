echo "Enter the first number:"
read num1

echo "Enter the second number:"
read num2

echo "Before Swapping"
echo "First number: $num1"
echo "Second number: $num2"

num1=$((num1 + num2))
num2=$((num1 - num2))
num1=$((num1 - num2))

echo "After Swapping"
echo "First number: $num1"
echo "Second number: $num2"
