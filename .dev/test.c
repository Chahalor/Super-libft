#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	ft_add_simd_asm(const float *a, const float *b, float *dst)
{
    // Addition SIMD sur 4 floats à la fois
    __asm__ volatile (
        "movups (%0), %%xmm0\n\t"
        "movups (%1), %%xmm1\n\t"
        "addps %%xmm1, %%xmm0\n\t"
        "movups %%xmm0, (%2)\n\t"
        :
        : "r"(a), "r"(b), "r"(dst)
        : "xmm0", "xmm1", "memory"
    );
}

void	ft_add_simd_loop(const float *a, const float *b, float *dst, size_t len)
{
    size_t i = 0;
    for (; i + 4 <= len; i += 4)
        ft_add_simd_asm(a + i, b + i, dst + i);
    for (; i < len; i++)
        dst[i] = a[i] + b[i];
}

void	ft_add_scalar(const float *a, const float *b, float *dst, size_t len)
{
    for (size_t i = 0; i < len; i++)
        dst[i] = a[i] + b[i];
}

int	main(void)
{
    const size_t N = 1000000000; // 100 millions
    const int REPEAT = 10;      // Répéter les calculs 10 fois
    float *a = malloc(N * sizeof(float));
    float *b = malloc(N * sizeof(float));
    float *dst_simd = malloc(N * sizeof(float));
    float *dst_scalar = malloc(N * sizeof(float));
    if (!a || !b || !dst_simd || !dst_scalar)
        return 1;

    for (size_t i = 0; i < N; i++) {
        a[i] = (float)i;
        b[i] = (float)(N - i);
    }

    clock_t t1 = clock();
    for (int r = 0; r < REPEAT; r++)
        ft_add_simd_loop(a, b, dst_simd, N);
    clock_t t2 = clock();
    for (int r = 0; r < REPEAT; r++)
        ft_add_scalar(a, b, dst_scalar, N);
    clock_t t3 = clock();

    printf("SIMD:   %ld ms\n", (t2 - t1) * 1000 / CLOCKS_PER_SEC);
    printf("Scalar: %ld ms\n", (t3 - t2) * 1000 / CLOCKS_PER_SEC);

    int ok = 1;
    for (size_t i = 0; i < N; i++) {
        if (dst_simd[i] != dst_scalar[i]) {
            ok = 0;
            break;
        }
    }
    printf("Résultat identique : %s\n", ok ? "oui" : "non");

    free(a);
    free(b);
    free(dst_simd);
    free(dst_scalar);
    return 0;
}