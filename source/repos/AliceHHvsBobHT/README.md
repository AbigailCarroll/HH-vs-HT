This is a somewhat hackey program to prove a statistics problem that I didn't believe at first. 
The problem is as follows:
You flip 100 fair coins in a row, and note the results and the order. For each sequence 'HH' Alice scores a point
,for each sequence 'HT' Bob scores a point. Who is more likely to win?

The answer is Bob, by about 6%.

This program recursively takes all permutations of the 100 coint flips (all equally likely) and finds
who wins for that sequence, then outputs the number of wins for Alice and Bob.