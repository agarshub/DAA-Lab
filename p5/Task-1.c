#include <stdio.h>
#include <string.h>

int main()
{
    char X[] = "AGCCCTAAGGGCTACCTAGCTT";
    char Y[] = "GACAGCCTACAAGCGTTAGCTTG";

    int m = strlen(X);
    int n = strlen(Y);

    int dp[101][101];
    char direction[101][101];

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                direction[i][j] = 'D';
            }
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                direction[i][j] = 'U';
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                direction[i][j] = 'L';
            }
        }
    }

    printf("Cost Matrix (LCS Lengths):\n");
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%2d ", dp[i][j]);
        }
        printf("\n");
    }

    printf("\nDirection Matrix:\n");
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf(" %c ", direction[i][j]);
        }
        printf("\n");
    }

    printf("\nLength of LCS: %d\n", dp[m][n]);

    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m;
    int j = n;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("LCS: %s\n", lcs);

    return 0;
}