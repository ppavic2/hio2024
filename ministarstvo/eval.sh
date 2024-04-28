for f in test/*.in*;
do
  echo $f
  output=$(echo $f | sed 's/\.in/\.out/g') 
  ./$1 < $f > tmp
  ./turncolchecker $f $output tmp
  echo ''
done