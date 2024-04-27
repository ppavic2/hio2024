zadatak="sirologija"


((n = 1))

./gen $n 10 0 > ./test/"$zadatak".in."$n"a
./gen $n 10 0 > ./test/"$zadatak".in."$n"b
./gen $n 10 0 > ./test/"$zadatak".in."$n"c
./gen $n 10 0 > ./test/"$zadatak".in."$n"d
./gen $n 50 0 > ./test/"$zadatak".in."$n"e
./gen $n 50 0 > ./test/"$zadatak".in."$n"f
./gen $n 50 0 > ./test/"$zadatak".in."$n"g
./gen $n 50 0 > ./test/"$zadatak".in."$n"h
./gen $n 50 0 > ./test/"$zadatak".in."$n"i
./gen $n 50 0 > ./test/"$zadatak".in."$n"j
./gen $n 90 0 > ./test/"$zadatak".in."$n"k
./gen $n 90 0 > ./test/"$zadatak".in."$n"l
./gen $n 90 0 > ./test/"$zadatak".in."$n"m
./gen $n 90 0 > ./test/"$zadatak".in."$n"n
./gen $n 90 0 > ./test/"$zadatak".in."$n"o
./gen $n 0 4 > ./test/"$zadatak".in."$n"p

broj1=(-1 -1 3 20 20 1000 1000 )
broj2=(-1 -1 5 50 50 2000 2000 )
broj3=(-1 -1 10 100 100 3000 3000 )

for ((n=2;n<=6;n++))
do
	./gen $n 10 0 > ./test/"$zadatak".in."$n"a
	./gen $n 10 0 > ./test/"$zadatak".in."$n"b
	./gen $n 20 0 > ./test/"$zadatak".in."$n"c
	./gen $n 20 0 > ./test/"$zadatak".in."$n"d
	./gen $n 25 0 > ./test/"$zadatak".in."$n"e
	./gen $n 25 0 > ./test/"$zadatak".in."$n"f
	
	./gen $n ${broj1[$n]} 1 > ./test/"$zadatak".in."$n"g
	./gen $n ${broj1[$n]} 1 > ./test/"$zadatak".in."$n"h
	./gen $n ${broj2[$n]} 1 > ./test/"$zadatak".in."$n"i
	./gen $n ${broj2[$n]} 1 > ./test/"$zadatak".in."$n"j
	./gen $n ${broj3[$n]} 1 > ./test/"$zadatak".in."$n"k
	./gen $n ${broj3[$n]} 1 > ./test/"$zadatak".in."$n"l

	./gen $n 20 2 > ./test/"$zadatak".in."$n"m
	./gen $n 30 2 > ./test/"$zadatak".in."$n"n
	./gen $n 50 2 > ./test/"$zadatak".in."$n"o
	./gen $n 70 2 > ./test/"$zadatak".in."$n"p
	./gen $n 99 2 > ./test/"$zadatak".in."$n"q
	./gen $n 100 2 > ./test/"$zadatak".in."$n"r

	./gen $n 20 3 > ./test/"$zadatak".in."$n"s
	./gen $n 30 3 > ./test/"$zadatak".in."$n"t
	./gen $n 50 3 > ./test/"$zadatak".in."$n"u
	./gen $n 70 3 > ./test/"$zadatak".in."$n"v
	./gen $n 99 3 > ./test/"$zadatak".in."$n"w
	./gen $n 100 3 > ./test/"$zadatak".in."$n"x
	
	./gen $n 0 4 > ./test/"$zadatak".in."$n"y
	./gen $n 0 5 > ./test/"$zadatak".in."$n"z
done

for f in test/*.in*;
do
  echo $f
  output=$(echo $f | sed 's/in/out/g') 
  ./pavic < $f > $output
  cat $output
done
