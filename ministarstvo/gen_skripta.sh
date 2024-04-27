rm test/*

#dummy tests
./gen 1 > test/ministarstvo.dummy.in.1
./gen 2 > test/ministarstvo.dummy.in.2
./gen 3 > test/ministarstvo.dummy.in.3

#subtask 1
./gen 4 10   452849528 > test/ministarstvo.in.1a
./gen 4 100  120371092 > test/ministarstvo.in.1b
./gen 4 1000 593749857 > test/ministarstvo.in.1c
./gen 5 1000 703758433 > test/ministarstvo.in.1d
./gen 6 1000 809384720 > test/ministarstvo.in.1e
./gen 9 20             > test/ministarstvo.in.1f
./gen 9 50             > test/ministarstvo.in.2g
./gen 9 200            > test/ministarstvo.in.1h
./gen 9 400            > test/ministarstvo.in.1i
./gen 9 800            > test/ministarstvo.in.1j
./gen 10 500           > test/ministarstvo.in.1k
./gen 10 1000          > test/ministarstvo.in.1l
./gen 11 1000          > test/ministarstvo.in.1m
./gen 12 1000 23984783 > test/ministarstvo.in.1n
./gen 12 1000 96706555 > test/ministarstvo.in.1o
./gen 12 1000 47092260 > test/ministarstvo.in.1p


#subtask 2
./gen 6 5    234987534 > test/ministarstvo.in.2a
./gen 5 5    398704039 > test/ministarstvo.in.2b
./gen 7 1              > test/ministarstvo.in.2c
./gen 7 2              > test/ministarstvo.in.2d
./gen 7 3              > test/ministarstvo.in.2e
./gen 4 4    129321747 > test/ministarstvo.in.2f
./gen 4 4    732047230 > test/ministarstvo.in.2g
./gen 4 5    674938573 > test/ministarstvo.in.2h
./gen 4 5    402380329 > test/ministarstvo.in.2i
./gen 4 5    398432473 > test/ministarstvo.in.2j
./gen 4 4    382932873 > test/ministarstvo.in.2k
./gen 4 4    983286345 > test/ministarstvo.in.2l
./gen 4 5    182739712 > test/ministarstvo.in.2m
./gen 4 5    449836429 > test/ministarstvo.in.2n
./gen 4 5    967045457 > test/ministarstvo.in.2o

#subtask 3
./gen 4 1000 543987459 > test/ministarstvo.in.3a
./gen 4 1000 892507477 > test/ministarstvo.in.3b
./gen 4 1000 511638113 > test/ministarstvo.in.3c
./gen 4 1000 156949717 > test/ministarstvo.in.3d
./gen 4 1000 897031225 > test/ministarstvo.in.3e
./gen 5 1000 901867649 > test/ministarstvo.in.3f
./gen 6 1000 656342116 > test/ministarstvo.in.3g
./gen 6 1000 435750616 > test/ministarstvo.in.3h
./gen 8 1              > test/ministarstvo.in.3i
./gen 8 2              > test/ministarstvo.in.3j
./gen 9 10             > test/ministarstvo.in.3k
./gen 9 100            > test/ministarstvo.in.3l
./gen 9 500            > test/ministarstvo.in.3m
./gen 9 1000           > test/ministarstvo.in.3n
./gen 10 400           > test/ministarstvo.in.3o
./gen 10 900           > test/ministarstvo.in.3p
./gen 11 900           > test/ministarstvo.in.3q
./gen 4 1000 542324981 > test/ministarstvo.in.3r
./gen 4 1000 931098570 > test/ministarstvo.in.3s
./gen 4 1000 686510420 > test/ministarstvo.in.3t
./gen 4 1000 606835587 > test/ministarstvo.in.3u
./gen 4 1000 771370762 > test/ministarstvo.in.3v
./gen 12 1000 34069386 > test/ministarstvo.in.3w
./gen 12 1000 68374053 > test/ministarstvo.in.3x
./gen 12 1000 12922070 > test/ministarstvo.in.3y
./gen 12 1000 59667093 > test/ministarstvo.in.3z

