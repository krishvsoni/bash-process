echo "Enter a number"
read num


is_even(){
    if [ $((num % 2)) -eq 0 ]; then
        return 0
    else
       return 1
    fi
}

echo "Even number upto $num are:"
for(( i=1;i<=num;i++)); do
    if [ $((i % 2)) -eq 0 ]; then
        echo $i
    fi
done

