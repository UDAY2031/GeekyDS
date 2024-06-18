#include <stdio.h>
#include <stdbool.h>

#define N 3 // Number of men and women

// Function to perform Gale-Shapley algorithm
void galeShapley(int menPref[N][N], int womenPref[N][N]) {
    int womenPartner[N]; // Array to store partner of each woman
    bool menFree[N]; // Array to store the availability of men
    int menNextProposal[N]; // Array to store the next woman each man will propose to

    for (int i = 0; i < N; i++) {
        womenPartner[i] = -1; // No woman is initially engaged
        menFree[i] = true; // All men are initially free
        menNextProposal[i] = 0; // Initialize next proposal to the first woman in their list
    }

    int freeCount = N; // Count of free men

    while (freeCount > 0) {
        int man;
        for (man = 0; man < N; man++) {
            if (menFree[man]) {
                break;
            }
        }

        int woman = menPref[man][menNextProposal[man]];
        menNextProposal[man]++;

        if (womenPartner[woman] == -1) {
            womenPartner[woman] = man;
            menFree[man] = false;
            freeCount--;
        } else {
            int currentPartner = womenPartner[woman];
            int newPartnerPreference = -1;
            int currentPartnerPreference = -1;

            for (int i = 0; i < N; i++) {
                if (womenPref[woman][i] == man) {
                    newPartnerPreference = i;
                }
                if (womenPref[woman][i] == currentPartner) {
                    currentPartnerPreference = i;
                }
            }

            if (newPartnerPreference < currentPartnerPreference) {
                womenPartner[woman] = man;
                menFree[man] = false;
                menFree[currentPartner] = true;
            }
        }
    }

    printf("Stable marriages are:\n");
    for (int i = 0; i < N; i++) {
        printf("Woman %d is married to Man %d\n", i, womenPartner[i]);
    }
}

int main() {
    int menPref[N][N] = {
        {0, 1, 2}, // Man A's preferences
        {1, 0, 2}, // Man B's preferences
        {0, 1, 2}  // Man C's preferences
    };

    int womenPref[N][N] = {
        {0, 1, 2}, // Woman V's preferences
        {1, 2, 0}, // Woman W's preferences
        {2, 0, 1}  // Woman X's preferences
    };

    galeShapley(menPref, womenPref);

    return 0;
}

