#include "printf.h"

int main()
{
	char *a = "asdaasdassd";
	char *b = "asdaasdassdsadsda";
	char *c = "asdaasdassdsavgadt";
	int ab = 532132;
	char ac = 'a';
	void *abc;

	printf("%p\n", a);
	ft_putptr(a);
	ft_putchar('\n');

	printf("%p\n", b);
	ft_putptr(b);
	ft_putchar('\n');

	printf("%p\n", c);
	ft_putptr(c);
	ft_putchar('\n');

	printf("%p\n", &ac);
	ft_putptr(&ac);
	ft_putchar('\n');

	printf("void -> %p\n", &abc);
	ft_putptr(&abc);
	ft_putchar('\n');

	printf("%p\n", &ab);
	ft_putptr(&ab);
	return 0;
}