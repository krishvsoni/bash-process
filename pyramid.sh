read -p "Enter the height of the pyramid:" height
for(( i=1 ;i<=height;i++)); do
    for(( j=1;j<=height-i;j++)); do
        echo -n " "
    done
    for(( k=1;k<=i;k++)); do
        echo -n "*"
    done
    for(( l=1;l<=i-1;l++)); do
        echo -n "*"
    done
    echo
done