
    // base %= k;
    // b %= k;
    while (b > 0)
    {
        if (b & 1)
        {
            ans *= base;
            ans %= k;
        }
        base *= base;
        base %= k;
        b >>= 1;
    }
    return ans;