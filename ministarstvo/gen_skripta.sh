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



