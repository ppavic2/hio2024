#!/usr/bin/python3
"""Upotreba ./validate3.py test/*.in*"""

import string


def check(lines):
    nl = []   # ispravno formatirane linije
    E = "\n"  # line ending
    
    n, q = map(int, lines[0].strip().split())      
    assert len(lines) == q + 2, "krivi broj linija"
    nl.append("{} {}{}".format(n, q, E))
    c = []
    v = list(lines[1].strip().split())
    nl.append("{}{}".format(" ".join(v), E)) 
    
    assert len(v) == n, "kriva duljina niza"
    cnt = [0 for i in range(n + 1)]
    for i in range(n):
        v[i] = int(v[i])
        cnt[v[i]] += 1
        assert 1 <= v[i] <= n
    for i in range(q):
        tl, tr = map(int, lines[i + 2].strip().split())
        assert 1 <= tl < tr <= n
        
        nl.append("{} {}{}".format(tl, tr, E))
    assert lines == nl, "Krivi format (%s vs %s)" % (lines, nl)
    assert lines[-1][-1] == "\n", "Zadnji red ne zavrsava sa \\n"
    return {'n': n, 'q' : q, 'max_v' : max(v), 'max_cnt' : max(cnt)}


# Ocekivani clusteri! Ovo vjerojatno zelis promijeniti!
expected_clusters = {'s1': 1, 's2': 1, 's3' : 1, 's4' : 1, 's5' : 1}


def what_cluster(data):
    # na temelju povratne informacije iz check(lines)
    # zakljucuje za TP u kojoj je bodovnoj sekciji
    where = ['s5']
    if data['max_v'] <= 10: where += ['s1']
    if data['max_cnt'] <= 2: where += ['s2']
    if data['n'] <= 2000 and data['q'] <= 2000: where += ['s3']
    if data['n'] <= 100000 and data['q'] <= 100000: where += ['s4']
    return where;


################### Zadatak-specifican kod iznad ove linije #########################

import sys
import glob
import hashlib


def group_in_batches(files):
    # mnozenje.in.1a, mnozenje.in.1b sprema u isti batch

    files.sort()
    B = []
    for f in files:
        if len(B) == 0:
            B.append([f])            
            continue
        if "dummy" in f:
            B.append([f])
            continue
        s = f
        i = -1
        while s[i].isalpha():
            i -= 1
        ss = B[-1][-1]
        j = -1
        while ss[j].isalpha():
            j -= 1
        if ss[j] == s[i]:
            B[-1].append(f)
        else:
            B.append([f])
    return B


if __name__ == "__main__":
    f = []
    for pattern in sys.argv[1:]:
        for filename in glob.glob(pattern):
            f.append(filename)

    bc = []
    for batch in group_in_batches(f):
        if 'dummy' not in batch[0]:
            bc.append([])
        for filename in batch:
            print("{}: ".format(filename), end="")
            try:
                lines = open(filename).readlines()
                summary = check(lines)
                c = what_cluster(summary)
                if not 'dummy' in filename:
                    s = int(filename[-2])
                    assert ("s" + str(s)) in c, "primjer ne pripada subtasku"
                    
                if 'dummy' not in batch[0]:
                    bc[-1].append(c)
            except Exception as e:
                print("Greska!", e)
                raise
            else:
                print("Sve ok! (cluster {}, summary = {})".format(c, summary))


# Bolji validator! - ppavic, 2023

