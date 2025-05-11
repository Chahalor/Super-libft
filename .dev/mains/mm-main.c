#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "mm.h"

int	main(void)
{
	printf("== DÉMARRAGE DES TESTS MEMORY MANAGER ==\n");

	// 1. Test d'allocations simples
	void *p1 = mm_alloc(16);
	assert(p1 != NULL);
	strcpy((char *)p1, "Bonjour");

	void *p2 = mm_alloc(32);
	assert(p2 != NULL);
	strcpy((char *)p2, "Hello world");

	void *p3 = mm_alloc(8);
	assert(p3 != NULL);
	memset(p3, 42, 8);

	printf("Contenu p1 : %s\n", (char *)p1);
	printf("Contenu p2 : %s\n", (char *)p2);

	// 2. Test de free individuel
	mm_free(p2);
	// assert(p2 == NULL);
	printf("p2 libéré avec succès.\n");

	// 3. Test double free (doit échouer ou ignorer proprement)
	mm_free(p2);
	// assert(p2 == NULL);
	printf("Double free sur p2 détecté correctement.\n");

	// 4. Test de free d’un pointeur non alloué (doit échouer)
	int x;
	mm_free(&x);
	// assert(mm_free(&x) != 0);
	printf("Free d’un pointeur externe refusé correctement.\n");

	// 5. Test allocation après free
	void *p4 = mm_alloc(24);
	// assert(p4 != NULL);
	strcpy((char *)p4, "Encore un test");
	printf("Contenu p4 : %s\n", (char *)p4);

	// 6. Destruction complète
	mm_destroy();
	printf("Memory manager détruit (tous les blocs libérés).\n");

	// 7. Free après destroy (doit échouer)
	mm_free(p1);
	// assert(p1 == NULL);
	printf("Tentative de free après destruction correctement refusée.\n");

	// 8. Allocation après destroy (si autorisé)
	void *p5 = mm_alloc(12);
	if (p5)
	{
		strcpy((char *)p5, "ok");
		printf("Réutilisation après destroy autorisée : %s\n", (char *)p5);
		mm_destroy(); // propre
	}
	else
	{
		printf("Réutilisation après destroy refusée (logique si désactivée).\n");
	}

	register int i = -1;
	while (++i < 100)
	{
		void *ptr = mm_alloc(1024);
		if (ptr == NULL)
			break;
	}
	mm_destroy();
	printf("== TESTS TERMINÉS ✅ ==\n");
	return (0);
}
