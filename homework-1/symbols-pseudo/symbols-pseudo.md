Algorithm to print symbols

1. For `int n` print sequentially `sqrt(n)` characters from the array
   `char *symbols[] = {"*", "=", "+"}`, arranging them in rows of `n` characters.

2. If `n > 3` or `n > size_t symbols_size = sizeof(symbols) / sizeof(symbols[0]) // function for counting array elements`
   continue to use the array elements sequentially, changing the order of the loop passing through the array
   (from 0 to the last and vice versa).

3. For the first character of each row, use the symbol from the `symbols` array,
   sequentially taking it from the array, in the same way as for the symbols in the rows.
   And also taking into account the rule in paragraph 2.
