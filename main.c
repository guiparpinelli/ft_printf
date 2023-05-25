#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
    printf("\n%i\n", ft_printf(" %c %c %c ", '0', 0, '1'));
    printf("\n%i\n", printf(" %c %c %c ", '0', 0, '1'));
    printf("\n%i\n", ft_printf(" %c %c %c ", '1', '2', '3'));
    printf("\n%i\n", printf(" %c %c %c ", '1', '2', '3'));
    printf("\n%i\n", ft_printf(" %c %c %c ", '2', '1', 0));
    printf("\n%i\n", printf(" %c %c %c ", '2', '1', 0));
	return (0);
}

/*
- %c Prints a single character.
- %s Prints a string (as defined by the common C convention).
- %p The void * pointer argument has to be printed in hexadecimal format.
- %d Prints a decimal (base 10) number.
- %i Prints an integer in base 10.
- %u Prints an unsigned decimal (base 10) number.
- %x Prints a number in hexadecimal (base 16) lowercase format.
- %X Prints a number in hexadecimal (base 16) uppercase format.
- %% Prints a percent sign.
*/
