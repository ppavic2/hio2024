#!/bin/sh

for f in test/*.in*;
do
  echo $f
  sed -i 's/\s*$//' $f
done

