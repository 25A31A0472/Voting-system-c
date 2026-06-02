#include <stdio.h>
#include <stdlib.h>

struct Vote {
    int candidate;
};

void castVote() {
    struct Vote v;
    FILE *fp = fopen("votes.dat", "ab");

    printf("\nCandidates:\n");
    printf("1. Alice\n2. Bob\n3. Charlie\n");
    printf("Enter your vote (1-3): ");
    scanf("%d", &v.candidate);

    if (v.candidate < 1 || v.candidate > 3) {
        printf("Invalid vote!\n");
    } else {
        fwrite(&v, sizeof(v), 1, fp);
        printf("Vote cast successfully!\n");
    }

    fclose(fp);
}

void countVotes() {
    struct Vote v;
    int c1 = 0, c2 = 0, c3 = 0;
    FILE *fp = fopen("votes.dat", "rb");

    while (fread(&v, sizeof(v), 1, fp)) {
        if (v.candidate == 1) c1++;
        else if (v.candidate == 2) c2++;
        else if (v.candidate == 3) c3++;
    }

    fclose(fp);

    printf("\n=== RESULTS ===\n");
    printf("Alice: %d votes\n", c1);
    printf("Bob: %d votes\n", c2);
    printf("Charlie: %d votes\n", c3);

    if (c1 > c2 && c1 > c3)
        printf("Winner: Alice\n");
    else if (c2 > c1 && c2 > c3)
        printf("Winner: Bob\n");
    else if (c3 > c1 && c3 > c2)
        printf("Winner: Charlie\n");
    else
        printf("It's a tie!\n");
}

int main() {
    int choice;

    do {
        printf("\n\n=== VOTING SYSTEM ===");
        printf("\n1. Cast Vote");
        printf("\n2. Show Results");
        printf("\n3. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: castVote(); break;
            case 2: countVotes(); break;
            case 3: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 3);

    return 0;
}