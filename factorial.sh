echo "Enter a number:"
read num

factorial=1

for (( i=1; i<=num; i++ ))
do
    factorial=$((factorial * i))
done

echo "The factorial of $num is $factorial"
