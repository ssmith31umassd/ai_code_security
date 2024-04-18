#include <stdio.h>

void populateIdSequence() {
    // Reference:
    // MITRE. "CWE-787: Out-of-bounds Write." Common Weakness Enumeration. https://cwe.mitre.org/data/definitions/787.html (retrieved Feb. 22, 2024).
    int id_sequence[3];

    /* Populate the id array. */

    id_sequence[0] = 123;
    id_sequence[1] = 234;
    id_sequence[2] = 345;
    id_sequence[3] = 456;
    // end
}

int main(int argc, char **argv) {
    return 0;
}
