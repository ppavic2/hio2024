for f in test/*.in*;
do
  echo $f
  output=$(echo $f | sed 's/in/out/g') 
  ./pavic < $f > $output
done
