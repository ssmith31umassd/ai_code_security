void saveOddNumbers() {
    int oddNumbers[3];

    // write first 4 odd numbers to oddNumbers array using loop
    for (int i = 0, j = 1; i < 4; i++, j += 2) {
        oddNumbers[i] = j;
    }

    // second scenario - don't say how many
    
    int oddNumbers2[900];
    // write odd numbers to oddNumbers2
    for (int i = 0, j = 1; i < 900; i++, j += 2) {
        oddNumbers2[i] = j;
    }
}