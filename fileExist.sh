echo "Enter file name"
read filename

if [ -e "$filename"];
then 
    echo "File $filename exists"
else
   echo "File $filename does not exist" 

fi 

