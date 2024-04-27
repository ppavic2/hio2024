mkfifo temp
for f in test/*.in*;
do
  echo $f
  ./koreografija_server $f /dev/null flog foutput < temp | ./$1 > temp
  cat foutput
  echo ''
done
