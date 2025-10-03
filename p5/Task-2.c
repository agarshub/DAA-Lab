#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "AABCBDC";
    int n = strlen(str);

    int dp[101][101];

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str[i - 1] == str[j - 1] && i != j)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                if (dp[i - 1][j] >= dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    printf("Length of Longest Repeating Subsequence: %d\n", dp[n][n]);

    int index = dp[n][n];
    char lrs[index + 1];
    lrs[index] = '\0';

    int i = n;
    int j = n;

    while (i > 0 && j > 0)
    {
        if (str[i - 1] == str[j - 1] && i != j)
        {
            lrs[index - 1] = str[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("Longest Repeating Subsequence: %s\n", lrs);

    return 0;
}