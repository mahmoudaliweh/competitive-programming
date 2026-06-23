#### Solution:
Problem looks scary at first but it's easy, we don't have to calculate the good sequences, we just calculate the bad sequences and minus it from all the possible sequences.

Calculating the bad sequence is fairly easy because all we need to do is divide our tree into trees of red nodes only (divide only if needed) and then for every red nodes island we can easily calculate the number of bad sequences within that island  using the n^k Formula given.