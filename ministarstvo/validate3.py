#!/usr/bin/python3
"""Upotreba ./validate3.py test/*.in*"""

import string


def check(lines):
    nl = []   # ispravno formatirane linije
    E = "\n"  # line ending
    
    n = int(lines[0].strip())      
    assert len(lines) == n + 1, "krivi broj linija"
    nl.append(str(n) + E)
    c = []
    print(n)

    for i in range(n):
        t = list(lines[i + 1].strip().split())
        c.append(t)
        nl.append("{}{}".format(" ".join(t), E))
    for i in range(n):
        assert c[i][i] == "0", "nije 0 na dijagonali"
        for j in range(n):
            if i == j: 
                continue
            assert sorted([c[i][j], c[j][i]]) == ["0", "1"], "matrica nije asimetricna"
    assert lines == nl, "Krivi format (%s vs %s)" % (lines, nl)
    assert lines[-1][-1] == "\n", "Zadnji red ne zavrsava sa \\n"
    return {'n': n}


# Ocekivani clusteri! Ovo vjerojatno zelis promijeniti!
expected_clusters = {'s1': 1, 's2': 1}


def what_cluster(data):
    # na temelju povratne informacije iz check(lines)
    # zakljucuje za TP u kojoj je bodovnoj sekciji
    if data['n'] <= 5: return 's1'
    return 's2';


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
                if 'dummy' not in batch[0]:
                    bc[-1].append(c)
            except Exception as e:
                print("Greska!", e)
                raise
            else:
                print("Sve ok! (cluster {}, summary = {})".format(c, summary))

    clusters = {}
    for b in bc:
        print(b)
        for c in b:
            assert c == b[0], "Ima razlicitih cluster-a unutar batcha"
        if not b[0] in clusters:
            clusters[b[0]] = 0
        clusters[b[0]] += 1
    assert clusters == expected_clusters, "Kriva raspodjela clustera ({} vs {})".format(clusters, expected_clusters)

    # Buda test - provjeri duplikate
    hashes = set(hashlib.sha1(open(x, 'rb').read()).hexdigest() for x in f)
    assert len(hashes) == len(f), "Ima duplikata!"
