for f in test/*.in*;
do
  echo $f
  output=$(echo $f | sed 's/in/out/g') 
  time ./$1 < $f > tmp
  diff -w $output tmp
  echo ''
done
